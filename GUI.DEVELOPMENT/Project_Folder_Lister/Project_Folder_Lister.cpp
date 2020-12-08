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

Project_Folder_Lister::Project_Folder_Lister(Custom_wxTreeCtrl * TreeCtrl){

     this->treeCtrl = TreeCtrl;

     this->is_project_directory_open = false;

     this->tree_item_list = nullptr;

     this->imglist = nullptr;

     this->Item_Path = wxT("");

     this->Short_Path = wxT("");

     this->total_item_number = 0;

     this->item_counter = 0;
}

Project_Folder_Lister::~Project_Folder_Lister(){

     if(!this->Memory_Delete_Condition){

        if(this->tree_item_list != nullptr){

           delete [] this->tree_item_list;
        }
     }
}


void Project_Folder_Lister::Initialize_Properties(wxString Folder){

     wxSize size = this->treeCtrl->FromDIP(wxSize(16, 16));

     this->imglist = new wxImageList(size.x, size.y, true, 2);

     this->imglist->Add(wxArtProvider::GetBitmap(wxART_FOLDER, wxART_OTHER, size));

     this->imglist->Add(wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, size));

     this->treeCtrl->AssignImageList(this->imglist);
}


void Project_Folder_Lister::Load_Project_Directory(wxString Folder){

     this->Initialize_Properties(Folder);

     this->total_item_number = 0;

     this->item_counter = 0;


     this->count_sub_directories(Folder);

     // The sub directory number is determined


     wxArrayString Files;

     wxDir dirCtrl;

     size_t count = dirCtrl.GetAllFiles(Folder,&Files,wxEmptyString,wxDIR_DEFAULT);

     int file_number = (int) count;



     this->total_item_number = this->sub_directory_number + file_number +1;

     // Total item number is estimated in order to allocate memory

     // +1 item is for root item

     this->tree_item_list = new Tree_Item [5*this->total_item_number];

     wxString Root_Folder = this->Determine_Short_Path(Folder);


     this->tree_item_list[0].item_id = this->treeCtrl->AddRoot(Root_Folder,0,0,NULL);

     this->tree_item_list[0].Item_Path = Folder;

     this->item_counter++;

     this->Append_Items(Folder,this->tree_item_list[0].item_id);


     // Total item number is determined exactly after appending the Append_Items

     // and it is set.

    this->total_item_number = this->item_counter;

    this->treeCtrl->Expand(this->tree_item_list[0].item_id);

    this->is_project_directory_open = true;
 }

 void Project_Folder_Lister::count_sub_directories(wxString Folder){

      wxDir dirCtrl;

      dirCtrl.Open(Folder);

      wxString dirname  = wxT("");

      wxString setpoint = wxT("");

      wxString setpoint_path = Folder;

      if(dirCtrl.IsOpened()){

         if(dirCtrl.HasSubDirs()){

            bool cond = dirCtrl.GetFirst(&dirname,wxT(""),wxDIR_DIRS | wxDIR_NO_FOLLOW);

            if(cond){

               this->sub_directory_number++;
            }

            setpoint_path = Folder + wxT("\\") + dirname;

            this->count_sub_directories(setpoint_path);

            if(cond){

               while(cond){

                 cond = dirCtrl.GetNext(&dirname);

                 setpoint_path = Folder + wxT("\\") + dirname;

                 this->count_sub_directories(setpoint_path);

               }
             }
         }

         dirCtrl.Close();
      }
 }

 void Project_Folder_Lister::Append_Items(wxString Folder, wxTreeItemId Id){

      // Appending the directories recursively

      wxDir dirCtrl;

      dirCtrl.Open(Folder);

      wxString dirname  = wxT("");

      wxString setpoint = wxT("");

      wxTreeItemId setpoint_id;

      wxString setpoint_path = Folder;

      if(dirCtrl.IsOpened()){

        if(dirCtrl.HasSubDirs()){

           bool cond = dirCtrl.GetFirst(&dirname,wxT(""), wxDIR_DIRS  | wxDIR_NO_FOLLOW);

           if(cond){

              this->tree_item_list[this->item_counter].item_id =

                  this->treeCtrl->AppendItem(Id,dirname,0,0,NULL);

              setpoint_id = this->tree_item_list[this->item_counter].item_id;

              setpoint_path = Folder + wxT("\\") + dirname;

              this->tree_item_list[this->item_counter].Item_Path = setpoint_path;

              this->item_counter++;


              wxDir dir;

              dir.Open(setpoint_path);

              if(dir.IsOpened()){

                if(dir.HasSubDirs()){ // recurdive call for the next directory

                  this->Append_Items(setpoint_path,setpoint_id);
                }
              }

              dir.Close();
           }


           if(cond){

             while(cond){

               cond = dirCtrl.GetNext(&dirname);

               if(cond){

                 this->tree_item_list[this->item_counter].item_id =

                         this->treeCtrl->AppendItem(Id,dirname,0,0,NULL);

                 setpoint_id = this->tree_item_list[this->item_counter].item_id;

                 setpoint_path = Folder + wxT("\\") + dirname;

                 this->tree_item_list[this->item_counter].Item_Path = setpoint_path;

                 this->item_counter++;


                 wxDir dir;

                 dir.Open(setpoint_path);

                 if(dir.IsOpened()){

                   if(dir.HasSubDirs()){

                     this->Append_Items(setpoint_path,setpoint_id);
                   }
                 }

                 dir.Close();

               }
             }
           }
         }
       }

      dirCtrl.Close();

      // Appending the files plasing on the directory folder recursively

      wxString filename  = wxT("");

      wxString file_Path =  wxT("");

      dirCtrl.Open(Folder);

      if(dirCtrl.IsOpened()){

         bool cond = dirCtrl.GetFirst(&filename,wxT(""), wxDIR_FILES  | wxDIR_NO_FOLLOW);

         if(cond){

            this->tree_item_list[this->item_counter].item_id =

                  this->treeCtrl->AppendItem(Id,filename,1,1,NULL);

            setpoint_id = this->tree_item_list[this->item_counter].item_id;

            file_Path = Folder + wxT("\\") + filename;

            this->tree_item_list[this->item_counter].Item_Path = file_Path;

            this->item_counter++;


            if(cond){

              while(cond){

                cond = dirCtrl.GetNext(&filename);

                if(cond){

                  this->tree_item_list[this->item_counter].item_id =

                  this->treeCtrl->AppendItem(Id,filename,1,1,NULL);

                  file_Path = Folder + wxT("\\") + filename;

                  this->tree_item_list[this->item_counter].Item_Path = file_Path;

                  this->item_counter++;
                }
              }
            }
          }
      }
 }

 size_t Project_Folder_Lister::Get_Sub_Directory_Name_Size(wxString Item){

        this->Short_Path_Name_Size = 0;

        for(int k=Item.length();k>0;k--){

            if(Item[k] == '\\'){

               break;
            }

            this->Short_Path_Name_Size++;
        }

        return  this->Short_Path_Name_Size;
 }

 wxString Project_Folder_Lister::Determine_Short_Path(wxString Item)
 {
     //  This Function extracts the short path of the file or folder
     //  from the long path

     // Consider the directory D:\ ---- \Name >

     // The Name is extracted

     this->Short_Path = wxT("");

     size_t Sub_Dir_Name_Size = this->Get_Sub_Directory_Name_Size(Item);

     size_t Sub_Dir_Start_Point = Item.length( ) - Sub_Dir_Name_Size +1;

     for(size_t k=Sub_Dir_Start_Point; k<Item.length();k++){

         this->Short_Path = this->Short_Path + Item[k];
     }

     return this->Short_Path;
 }

 Custom_wxTreeCtrl * Project_Folder_Lister::GetTreeCtrl(){

      return this->treeCtrl;
 }

 wxString Project_Folder_Lister::GetItemPath(wxTreeItemId item_number){

          this->Item_Path = wxT("");

          for(int i=0;i<this->total_item_number;i++){

              if(this->tree_item_list[i].item_id == item_number){

                 this->Item_Path = this->tree_item_list[i].Item_Path;
              }
          }

          return this->Item_Path;
 }

void Project_Folder_Lister::RemoveProjectDirectory(){

     if(this->is_project_directory_open){

        this->is_project_directory_open = false;
     }
}

bool Project_Folder_Lister::GetProjectDirectoryOpenStatus(){

     return this->is_project_directory_open;
}

void Project_Folder_Lister::Expand_Root(){

     this->treeCtrl->Expand(this->tree_item_list[0].item_id);
}
