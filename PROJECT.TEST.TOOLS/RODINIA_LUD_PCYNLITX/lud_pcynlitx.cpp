#include <iostream>
#include <stdio.h>
#include <thread>
#include "common.h"

#define BS 16

#define AA(_i,_j) a[offset*size+_i*size+_j+offset]
#define BB(_i,_j) a[_i*size+_j]

extern func_ret_t lud_verify(float *m, float *lu, int matrix_dim);


void lud_diagonal(float* a, int size, int offset){

    int i, j, k;
    for (i = 0; i < BS; i++) {
        for (j = i; j < BS; j++) {
            for (k = 0; k < i ; k++) {
                AA(i,j) = AA(i,j) - AA(i,k) * AA(k,j);
            }
        }

        float temp = 1.f/AA(i,i);
        for (j = i+1; j < BS; j++) {
            for (k = 0; k < i ; k++) {
                AA(j,i) = AA(j,i) - AA(j,k) * AA(k,i);
            }
            AA(j,i) = AA(j,i)*temp;
        }
    }
}

// implements block LU factorization

void lud_computation(float * a,int size){

     int offset, chunk_idx, size_inter, chunks_in_inter_row, chunks_per_inter;

     for (offset = 0; offset < size - BS ; offset += BS){

          // lu factorization of left-top corner block diagonal matrix
          //
          lud_diagonal(a, size, offset);

          size_inter = size - offset -  BS;

          chunks_in_inter_row  = size_inter/BS;

          // calculate perimeter block matrices
          //

          for ( chunk_idx = 0; chunk_idx < chunks_in_inter_row; chunk_idx++){

              int i, j, k, i_global, j_global, i_here, j_here;
              float sum;
              float temp[BS*BS] __attribute__ ((aligned (64)));

              for (i = 0; i < BS; i++) {

                   for (j =0; j < BS; j++){

                        temp[i*BS + j] = a[size*(i + offset) + offset + j ];
                   }
              }

              i_global = offset;
              j_global = offset;

              // processing top perimeter
              //
              j_global += BS * (chunk_idx+1);

              for (j = 0; j < BS; j++) {

                  for (i = 0; i < BS; i++) {

                      sum = 0.f;

                      for (k=0; k < i; k++) {

                           sum += temp[BS*i +k] * BB((i_global+k),(j_global+j));
                      }

                      i_here = i_global + i;

                      j_here = j_global + j;

                      BB(i_here, j_here) = BB(i_here,j_here) - sum;
                  }
              }

              // processing left perimeter
              //

              j_global = offset;

              i_global += BS * (chunk_idx + 1);

              for (i = 0; i < BS; i++) {

                  for (j = 0; j < BS; j++) {

                       sum = 0.f;

                       for (k=0; k < j; k++) {

                            sum += BB((i_global+i),(j_global+k)) * temp[BS*k + j];
                       }

                       i_here = i_global + i;

                       j_here = j_global + j;

                       a[size*i_here + j_here] = ( a[size*i_here+j_here] - sum )

                              / a[size*(offset+j) + offset+j];
                  }
              }
          }

          // update interior block matrices
          //
          chunks_per_inter = chunks_in_inter_row*chunks_in_inter_row;

          for  (chunk_idx =0; chunk_idx < chunks_per_inter; chunk_idx++){

                int i, j, k, i_global, j_global;

                float temp_top[BS*BS] __attribute__ ((aligned (64)));

                float temp_left[BS*BS] __attribute__ ((aligned (64)));

                float sum[BS] __attribute__ ((aligned (64))) = {0.f};

                i_global = offset + BS * (1 +  chunk_idx/chunks_in_inter_row);

                j_global = offset + BS * (1 + chunk_idx%chunks_in_inter_row);

                for (i = 0; i < BS; i++) {

                     for (j =0; j < BS; j++){

                          temp_top[i*BS + j]  = a[size*(i + offset) + j + j_global ];

                          temp_left[i*BS + j] = a[size*(i + i_global) + offset + j];
                     }
                }

                for (i = 0; i < BS; i++){

                    for (k=0; k < BS; k++) {

                        for (j = 0; j < BS; j++) {

                            sum[j] += temp_left[BS*i + k] * temp_top[BS*k + j];
                        }
                    }

                    for (j = 0; j < BS; j++) {

                        BB((i+i_global),(j+j_global)) -= sum[j];

                        sum[j] = 0.f;
                    }
               }
             }
          }

          lud_diagonal(a, size, offset);
}

void lud_pcynlitx_function(pcynlitx::thds * thread_data){

     pcynlitx::TM_Client Manager(thread_data,"lud_pcynlitx_function");

     pcynlitx::data_holder_Client holder(thread_data);

     int threadNumber = Manager.Get_Thread_Number();

     // calculate perimeter block matrices

     float * mt = holder.get_Matrix(threadNumber);

     float * duplicated_matrix = holder.get_duplicated_matrix();

     int size  = holder.get_Matrix_Size();

     lud_computation(mt,size);

     lud_verify(duplicated_matrix,mt,size);

     Manager.Exit();
}
