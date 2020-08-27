
#include "Description_Printer.h"

 int main(int argc, char** argv){

     Description_Printer Printer;

     Printer.Receive_Descriptor_File_Directory(argv[1]);

     Printer.Read_Descriptions();

     Printer.Print_Descriptions();

     return 0;
}
