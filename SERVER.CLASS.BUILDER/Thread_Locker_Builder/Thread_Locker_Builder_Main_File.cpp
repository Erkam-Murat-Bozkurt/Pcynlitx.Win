
 #include "Thread_Locker_Builder.h"
 #include <iostream>

 int main(int argc, char** argv){

     Thread_Locker_Builder Builder;

     char Newly_Constructed_Directory [] = "/home/erkam/TestDirectory";

     Builder.Receive_Supervisor_Newly_Constructed_Include_Directory(Newly_Constructed_Directory);

     Builder.Build_Thread_Locker();

     Builder.Run_System_Commands();

     Builder.Clear_Dynamic_Memory();

     std::cout << "\n\n The end of the program ..\n\n";

     return 0;
 };
