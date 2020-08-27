
/*

Copyright ©  2019,  Erkam Murat Bozkurt

This file is part of the research project which is carried by Erkam Murat Bozkurt.

This is a free software: you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation
either version 3 of the License, or any later version.

This software is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program. If not, see <http://www.gnu.org/licenses/>.

*/

#include "Thread_Locker_Header_File_Builder.h"

Thread_Locker_Header_File_Builder::Thread_Locker_Header_File_Builder(){

};

Thread_Locker_Header_File_Builder::Thread_Locker_Header_File_Builder(const Thread_Locker_Header_File_Builder & orig){

};

Thread_Locker_Header_File_Builder::~Thread_Locker_Header_File_Builder(){

};

void Thread_Locker_Header_File_Builder::Receive_Descriptor_File_Reader(Descriptor_File_Reader * Pointer){

     this->Reader_Pointer = Pointer;
}

void Thread_Locker_Header_File_Builder::Build_thread_locker_header_file(){

     char * Namespace = this->Reader_Pointer->Get_Namespace();

     this->FileManager.SetFilePath("Thread_Locker.h");

     this->FileManager.FileOpen(RWC);

     this->FileManager.WriteToFile("\n #ifndef THREAD_LOCKER_H");

     this->FileManager.WriteToFile("\n #define THREAD_LOCKER_H");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n #include <mutex>");

     this->FileManager.WriteToFile("\n #include <cstdio>");

     this->FileManager.WriteToFile("\n #include <thread>");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n namespace ");

     this->FileManager.WriteToFile(Namespace);

     this->FileManager.WriteToFile(" {");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n   class Thread_Locker");

     this->FileManager.WriteToFile("\n   {");

     this->FileManager.WriteToFile("\n   public:");

     this->FileManager.WriteToFile("\n     Thread_Locker();");

     this->FileManager.WriteToFile("\n     Thread_Locker(const Thread_Locker & orig);");

     this->FileManager.WriteToFile("\n     virtual ~Thread_Locker();");

     this->FileManager.WriteToFile("\n     void lock();");

     this->FileManager.WriteToFile("\n     void unlock();");

     this->FileManager.WriteToFile("\n   private:");

     this->FileManager.WriteToFile("\n     std::mutex lock_mutex;");

     this->FileManager.WriteToFile("\n   };");

     this->FileManager.WriteToFile("\n };");

     this->FileManager.WriteToFile("\n");

     this->FileManager.WriteToFile("\n #endif");

     this->FileManager.FileClose();

     this->FileManager.Clear_Dynamic_Memory();
}
