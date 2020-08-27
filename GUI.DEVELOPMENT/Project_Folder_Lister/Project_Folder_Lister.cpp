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

#include "Project_Folder_Lister.h"

Project_Folder_Lister::Project_Folder_Lister(Custom_wxDataViewTreeCtrl * TreeCtrl){

     this->Memory_Delete_Condition = true;

     this->tree_control = TreeCtrl;

     this->is_project_directory_open = false;

     this->dir_traverser = nullptr;

     this->dirCtrl = nullptr;

     this->tree_item_list = nullptr;
}

Project_Folder_Lister::~Project_Folder_Lister(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->Clear_Dynamic_Memory();
     }
}

void Project_Folder_Lister::Clear_Dynamic_Memory(){

     if(!this->Memory_Delete_Condition){

         this->Memory_Delete_Condition = true;

         this->tree_control->DeleteAllItems();

         this->dirCtrl->Close();

         if(this->dir_traverser != nullptr){

             delete this->dir_traverser;

             this->dir_traverser = nullptr;
         }

         if(this->dirCtrl != nullptr){

            delete this->dirCtrl;

            this->dirCtrl = nullptr;
         }

         if(this->tree_item_list != nullptr){

            delete [] this->tree_item_list;

            this->tree_item_list = nullptr;
         }
     }
}

void Project_Folder_Lister::Load_Project_Directory(wxString Folder){

     this->Clear_Dynamic_Memory();

     this->Memory_Delete_Condition = false;

     this->dirCtrl = new wxDir;

     this->dir_traverser = new wxDirTraverser_executer(this->Folder_Index);

     wxIcon Folder_Icon;

     wxIcon File_Icon;

     Folder_Icon.LoadFile(wxT("/usr/share/Pcynlitx/icons/folder.png"),wxICON_DEFAULT_TYPE,-1,-1);

     File_Icon.LoadFile(wxT("/usr/share/Pcynlitx/icons/file.png"),wxICON_DEFAULT_TYPE,-1,-1);

     wxArrayString File_List;

     if(this->dirCtrl->Exists(Folder)){

        this->dirCtrl->Open(Folder);

        if(this->dirCtrl->IsOpened()){

           this->Sub_Directory_Number = this->dirCtrl->Traverse(*(this->dir_traverser),Folder,wxDIR_DIRS | wxDIR_FILES | wxDIR_NO_FOLLOW);

           if(this->Sub_Directory_Number == 0){

              this->Sub_File_Number = this->dirCtrl->GetAllFiles(Folder,&File_List,wxEmptyString,wxDIR_DIRS | wxDIR_FILES | wxDIR_NO_FOLLOW);
           }
        }
     }

     int Directory_Number = (int) this->Folder_Index.GetCount();

     this->Total_Item_Number = 0;

     if(((this->Sub_Directory_Number > 0) || (Directory_Number > 0))){

        for(size_t i=0;i<Directory_Number;i++){

            this->Total_Item_Number++;

            wxString Item = this->Folder_Index.Item(i);

            this->dirCtrl->Open(Item);

            if(!this->dirCtrl->HasSubDirs()){

                wxArrayString Files;

                size_t count = this->dirCtrl->GetAllFiles(Item,&Files,wxEmptyString,wxDIR_DEFAULT);

                this->Total_Item_Number = this->Total_Item_Number + (int) count;
            }

            this->dirCtrl->Close();
        }
     }
     else{

           this->Total_Item_Number = this->Sub_File_Number +1;
     }

     this->tree_item_list = new Tree_Item [5*this->Total_Item_Number];

     wxString Root_String;

     if(Folder.length() > 1){

        this->Determine_Tree_Item_String(Folder,Root_String);
     }
     else{

          if(Folder == wxT("/")){

             Root_String = wxT("/");
          }
     }

     this->tree_item_list[1].item_number = this->tree_control->AppendContainer(this->tree_item_list[0].item_number,Root_String,-1,-1);

     this->tree_item_list[1].Item_Path = Folder;

     this->tree_control->SetItemIcon(this->tree_item_list[1].item_number,Folder_Icon);

     int item_counter = 2;

     if(((this->Sub_Directory_Number > 0) || (Directory_Number > 0))){

        for(size_t i=0;i<Directory_Number;i++){

            wxString Tree_Item_String, Root_Item_String;

            wxString Item = this->Folder_Index.Item(i);

            wxDataViewItem Root_Item;

            int Tree_Item_Size = this->Determine_Tree_Item_String(Item,Tree_Item_String);

            this->Determine_Root_Item_String(Item,Root_Item_String,Tree_Item_Size);

            this->Determine_Root_Item(Root_Item,Root_Item_String,Item,Folder,item_counter);

            this->dirCtrl->Open(Item);

            if(this->dirCtrl->HasSubDirs()){

               this->tree_item_list[item_counter].item_number = this->tree_control->AppendContainer(Root_Item,Tree_Item_String,-1,-1);

               this->tree_item_list[item_counter].Item_Path = Item;

               this->tree_control->SetItemIcon(this->tree_item_list[item_counter].item_number,Folder_Icon);

               item_counter++;

               if(this->dirCtrl->HasFiles()){

                  wxArrayString Files;

                  size_t count = this->dirCtrl->GetAllFiles(Item,&Files,wxEmptyString,wxDIR_FILES);

                  for(size_t j=0;j<count;j++){

                      wxString File_Item = Files.Item(j);

                      bool is_this_hidden_file = false;

                      int Name_Size = 0, First_Character_Number = 0;

                      for(int k=Files.Item(j).length();k>0;k--){

                          if(Files.Item(j)[k] == '/'){

                             break;
                      }

                      Name_Size++;
                  }

                  First_Character_Number = Files.Item(j).length() - Name_Size +1;

                  if(Files.Item(j)[First_Character_Number] == '.'){

                     is_this_hidden_file = true;
                  }

                  if(!is_this_hidden_file){

                      Tree_Item_String = "";

                      Root_Item_String = "";

                      Tree_Item_Size = this->Determine_Tree_Item_String(File_Item,Tree_Item_String);

                      this->Determine_Root_Item_String(File_Item,Root_Item_String,Tree_Item_Size);

                      this->Determine_Root_Item(Root_Item,Root_Item_String,Item,Folder,item_counter);

                      this->tree_item_list[item_counter].item_number = this->tree_control->AppendItem(Root_Item,Tree_Item_String,-1);

                      this->tree_item_list[item_counter].Item_Path = File_Item;

                      this->tree_control->SetItemIcon(this->tree_item_list[item_counter].item_number,File_Icon);

                      item_counter++;
                   }
                 }
              }
          }
          else{

                if(this->dirCtrl->HasFiles()){

                   wxArrayString Files;

                   size_t count = this->dirCtrl->GetAllFiles(Item,&Files,wxEmptyString,wxDIR_DEFAULT);

                   this->tree_item_list[item_counter].item_number = this->tree_control->AppendContainer(Root_Item,Tree_Item_String,-1,-1);

                   this->tree_item_list[item_counter].Item_Path = Item;

                   this->tree_control->SetItemIcon(this->tree_item_list[item_counter].item_number,Folder_Icon);

                   item_counter++;

                   for(size_t j=0;j<count;j++){

                       wxString File_Item = Files.Item(j);

                       bool is_this_hidden_file = false;

                       int Name_Size = 0, First_Character_Number = 0;

                       for(int k=Files.Item(j).length();k>0;k--){

                           if(Files.Item(j)[k] == '/'){

                              break;
                           }

                           Name_Size++;
                       }

                       First_Character_Number = Files.Item(j).length() - Name_Size +1;

                       if(Files.Item(j)[First_Character_Number] == '.'){

                           is_this_hidden_file = true;
                       }

                       if(!is_this_hidden_file){

                          Tree_Item_String = "";

                          Root_Item_String = "";

                          Tree_Item_Size = this->Determine_Tree_Item_String(File_Item,Tree_Item_String);

                          this->Determine_Root_Item_String(File_Item,Root_Item_String,Tree_Item_Size);

                          this->Determine_Root_Item(Root_Item,Root_Item_String,Item,Folder,item_counter);

                          this->tree_item_list[item_counter].item_number = this->tree_control->AppendItem(Root_Item,Tree_Item_String,-1);

                          this->tree_item_list[item_counter].Item_Path = File_Item;

                          this->tree_control->SetItemIcon(this->tree_item_list[item_counter].item_number,File_Icon);

                          item_counter++;
                       }
                    }
                 }
                 else{

                       this->tree_item_list[item_counter].item_number = this->tree_control->AppendItem(Root_Item,Tree_Item_String,-1);

                       this->tree_item_list[item_counter].Item_Path = Item;

                       this->tree_control->SetItemIcon(this->tree_item_list[item_counter].item_number,Folder_Icon);

                       item_counter++;
                }
            }
         }

         if(this->Sub_File_Number > 0){

            wxArrayString Files;

            wxString Tree_Item_String, Root_Item_String;

            wxDataViewItem Root_Item;

            this->dirCtrl->Open(Folder);

            size_t count = this->dirCtrl->GetAllFiles(Folder,&Files,wxEmptyString,wxDIR_DEFAULT);

            for(size_t j=0;j<count;j++){

                bool is_this_hidden_file = false;

                int Name_Size = 0, First_Character_Number = 0;

                for(int k=Files.Item(j).length();k>0;k--){

                    if(Files.Item(j)[k] == '/'){

                       break;
                    }

                    Name_Size++;
                }

                First_Character_Number = Files.Item(j).length() - Name_Size +1;

                if(Files.Item(j)[First_Character_Number] == '.'){

                   is_this_hidden_file = true;
                }

                wxString File_Item = Files.Item(j);

                Tree_Item_String = "";

                Root_Item_String = "";

                Tree_Item_Size = this->Determine_Tree_Item_String(File_Item,Tree_Item_String);

                this->Determine_Root_Item_String(File_Item,Root_Item_String,Tree_Item_Size);

                if(Root_Item_String == Folder){

                   this->Determine_Root_Item(Root_Item,Root_Item_String,Folder,Folder,item_counter);

                   if(!is_this_hidden_file){

                       this->tree_item_list[item_counter].item_number = this->tree_control->AppendItem(Root_Item,Tree_Item_String,-1);

                       this->tree_item_list[item_counter].Item_Path = File_Item;

                       this->tree_control->SetItemIcon(this->tree_item_list[item_counter].item_number,File_Icon);

                       item_counter++;
                   }
                }
            }
        }
    }
    else{

         if(this->Sub_File_Number > 0){

           wxArrayString Files;

           wxString Tree_Item_String, Root_Item_String;

           wxDataViewItem Root_Item;

           this->dirCtrl->Open(Folder);

           size_t count = this->dirCtrl->GetAllFiles(Folder,&Files,wxEmptyString,wxDIR_DEFAULT);

           for(size_t j=0;j<count;j++){

               wxString File_Item = Files.Item(j);

               Tree_Item_String = "";

               Root_Item_String = "";

               Tree_Item_Size = this->Determine_Tree_Item_String(File_Item,Tree_Item_String);

               this->Determine_Root_Item_String(File_Item,Root_Item_String,Tree_Item_Size);

               this->Determine_Root_Item(Root_Item,Root_Item_String,Folder,Folder,item_counter);

               this->tree_item_list[item_counter].item_number = this->tree_control->AppendItem(Root_Item,Tree_Item_String,-1);

               this->tree_item_list[item_counter].Item_Path = File_Item;

               this->tree_control->SetItemIcon(this->tree_item_list[item_counter].item_number,File_Icon);

               item_counter++;
            }
         }
    }

    this->Total_Item_Number = item_counter;

    this->Folder_Index.Clear();

    this->tree_control->Expand(this->tree_item_list[1].item_number);

    this->tree_control->SetIndent(5);

    this->is_project_directory_open = true;
 }

 int Project_Folder_Lister::Determine_Tree_Item_String(wxString Item, wxString & Tree_Item_String){

     this->Tree_Item_Size = 0;

     for(int k=Item.length();k>0;k--){

         if(Item[k] == '/'){

            break;
         }

         this->Tree_Item_Size++;
     }

     Tree_Item_String = wxT(" ");

     for(int k=Item.length() - this->Tree_Item_Size +1; k<Item.length();k++){

         Tree_Item_String = Tree_Item_String + Item[k];
     }

     return this->Tree_Item_Size;
 }

 void Project_Folder_Lister::Determine_Root_Item_String(wxString Item, wxString & Root_Item_String, int Tree_Item_Size){

      for(int k=0;k<Item.length() - Tree_Item_Size;k++){

          Root_Item_String = Root_Item_String + Item[k];
      }
 }

 void Project_Folder_Lister::Determine_Root_Item(wxDataViewItem & Root_Item, wxString & Root_Item_String,wxString Item_String, wxString Folder, int  item_counter){

      wxString Upper_Directory_Name_String;

      this->Determine_Tree_Item_String(Root_Item_String,Upper_Directory_Name_String);

      if(Root_Item_String == Folder){

         Root_Item = this->tree_item_list[1].item_number;
      }
      else{

           for(int k =0;k<item_counter;k++){

                wxString search_string = this->tree_control->GetItemText(this->tree_item_list[k].item_number);

                 if(Upper_Directory_Name_String == search_string){

                     Root_Item = this->tree_item_list[k].item_number;

                     break;
                  }
              }
        }
 }

 Custom_wxDataViewTreeCtrl * Project_Folder_Lister::GetDataViewTreeCtrl(){

    return this->tree_control;
 }

 wxString Project_Folder_Lister::GetItemPath(wxDataViewItem item_number){

          for(int i=0;i<this->Total_Item_Number;i++){

              if(this->tree_item_list[i].item_number == item_number){

                 this->Item_Path = this->tree_item_list[i].Item_Path;
              }
          }

          return this->Item_Path;
 }

void Project_Folder_Lister::RemoveProjectDirectory(){

     if(this->is_project_directory_open){

        this->Clear_Dynamic_Memory();

        this->is_project_directory_open = false;
     }
}

bool Project_Folder_Lister::GetProjectDirectoryOpenStatus(){

     return this->is_project_directory_open;
}
