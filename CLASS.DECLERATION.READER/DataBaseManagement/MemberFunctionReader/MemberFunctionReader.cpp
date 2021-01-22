/*

Copyright ©  2021,  Erkam Murat Bozkurt

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

#include "MemberFunctionReader.h"

MemberFunctionReader::MemberFunctionReader(){

    this->Memory_Delete_Condition = true;
};

MemberFunctionReader::MemberFunctionReader(const MemberFunctionReader & orig){

};

MemberFunctionReader::~MemberFunctionReader(){

     if(!this->Memory_Delete_Condition){

         this->Clear_Dynamic_Memory();
     }
};

void MemberFunctionReader::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Builder.Clear_Dynamic_Memory();
     }
}

void MemberFunctionReader::Receive_Include_Directory_PATH(char * IncludeDirectory){

     this->Reader.ReceiveIncludeDirectoryPATH(IncludeDirectory);
}

void MemberFunctionReader::Receive_Header_File_Path(char * HeaderFileName){

     this->Reader.Receive_Header_File_Path(HeaderFileName);
}

void MemberFunctionReader::Receive_Construction_Point(char * BaseDirectory){

     this->Reader.ReceiveDataBaseConstructionPoint(BaseDirectory);
}

void MemberFunctionReader::Read_Member_Functions(){

     this->Memory_Delete_Condition = false;

     this->Reader.ReadFunctionDeclerations();

     this->Builder.Build_DataBase(&this->Reader);

     this->Reader.Clear_Dynamic_Memory();
}

Method_Datas * MemberFunctionReader::GetPublicMethods(){

     return this->Builder.Get_Public_Method_Datas();
}

Method_Datas * MemberFunctionReader::GetPrivateMethods(){

     return this->Builder.Get_Private_Method_Datas();
}

Method_Datas * MemberFunctionReader::GetProtectedMethods(){

     return this->Builder.Get_Protected_Method_Datas();
}

char * MemberFunctionReader::Get_Class_Name(){

       return this->Builder.Get_Class_Name();
}

int MemberFunctionReader::Get_Public_Method_Number(){

    return this->Builder.Get_Public_Method_Number();
}

int MemberFunctionReader::Get_Private_Method_Number(){

    return this->Builder.Get_Private_Method_Number();
}

int MemberFunctionReader::Get_Protected_Method_Number(){

    return this->Builder.Get_Protected_Method_Number();
}
