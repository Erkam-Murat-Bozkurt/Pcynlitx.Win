
#ifndef DATA_TYPES_H
#define DATA_TYPES_H

struct data_list {

    bool read_status;

    bool record_status;

    char * number_string;

    int position;
};

struct record_list {

    int record_number;

    int thread_number;

    int reputation;
};

struct acess_order_data
{
    int  * acess_data_holder;

    bool * empty_status;
};


#endif /* DATA_TYPES_H */
