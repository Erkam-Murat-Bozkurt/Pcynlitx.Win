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

     this->tree_item_list = new Tree_Item [10*this->total_item_number];

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



 bool Project_Folder_Lister::Does_it_have_SubDir(wxString Folder){

      this->does_it_have_sub_dir = false;

      wxDir dirCtrl;

      if(dirCtrl.Exists(Folder)){

         dirCtrl.Open(Folder);

         if(dirCtrl.IsOpened()){

           if(dirCtrl.HasSubDirs()){

             this->does_it_have_sub_dir = true;
           }

           dirCtrl.Close();
         }
         else{

            wxMessageOutput::Get()->Printf("Folder %s can not be openned",Folder);
         }
      }

      return this->does_it_have_sub_dir;
 }

 wxTreeItemId Project_Folder_Lister::Append_Directory_To_Tree(wxTreeItemId Id, wxString Directory, wxString Path){

      this->tree_item_list[this->item_counter].item_id =

              this->treeCtrl->AppendItem(Id,Directory,0,0,NULL);

      this->appended_item_id = this->tree_item_list[this->item_counter].item_id;

      this->tree_item_list[this->item_counter].Item_Path = Path;

      this->item_counter++;

      return this->appended_item_id;
 }


 wxTreeItemId Project_Folder_Lister::Append_File_To_Tree(wxTreeItemId Id, wxString File, wxString Path){

      this->tree_item_list[this->item_counter].item_id =

              this->treeCtrl->AppendItem(Id,File,1,1,NULL);

      this->appended_item_id = this->tree_item_list[this->item_counter].item_id;

      this->tree_item_list[this->item_counter].Item_Path = Path;

      this->item_counter++;

      return this->appended_item_id;
 }

 void Project_Folder_Lister::count_sub_directories(wxString Folder){

      wxDir dirCtrl;

      if(dirCtrl.Exists(Folder)){

         dirCtrl.Open(Folder);

         wxString dirname  = wxT("");

         wxString setpoint_path = Folder;

         if(dirCtrl.IsOpened()){

            this->total_item_number++;

            if(dirCtrl.HasSubDirs()){

              bool cond = dirCtrl.GetFirst(&dirname,wxEmptyString,

                     wxDIR_DIRS | wxDIR_NO_FOLLOW);

              if(cond){

                this->total_item_number++;

                setpoint_path = Folder + wxT("\\") + dirname;

                if(this->Does_it_have_SubDir(setpoint_path)){

                   this->count_sub_directories(setpoint_path);
                }

                this->Count_Files(Folder);

                while(dirCtrl.GetNext(&dirname)){

                  this->total_item_number++;

                  setpoint_path = Folder + wxT("\\") + dirname;

                  if(this->Does_it_have_SubDir(setpoint_path)){

                     this->count_sub_directories(setpoint_path);
                  }

                  this->Count_Files(Folder);
                }
              }
            }

            dirCtrl.Close();

          }
          else{

                wxMessageOutput::Get()->Printf("Folder %s can not be openned",Folder);
          }
      }
      else{

            wxMessageOutput::Get()->Printf("Folder: %s does not exist",Folder);
      }
 }

 void Project_Folder_Lister::Append_Items(wxString Folder, wxTreeItemId Id){

      // Appending the directories recursively

      wxString dirname  = wxT("");

      wxTreeItemId setpoint_id;

      wxString setpoint_path = Folder;

      wxDir dirCtrl;

      if(dirCtrl.Exists(Folder)){

         dirCtrl.Open(Folder);

         if(dirCtrl.IsOpened()){

            if(dirCtrl.HasSubDirs()){

               bool cond = dirCtrl.GetFirst(&dirname,wxEmptyString,

                      wxDIR_DIRS  | wxDIR_NO_FOLLOW);

               if(cond){

                  setpoint_path = Folder + wxT("\\") + dirname;

                  setpoint_id = this->Append_Directory_To_Tree(Id,dirname,setpoint_path);

                  if(this->Does_it_have_SubDir(setpoint_path)){

                     this->Append_Items(setpoint_path,setpoint_id);
                  }

                  this->Append_Files(setpoint_path,setpoint_id);

                  while(dirCtrl.GetNext(&dirname)){

                    setpoint_path = Folder + wxT("\\") + dirname;

                    setpoint_id = this->Append_Directory_To_Tree(Id,dirname,setpoint_path);

                    if(this->Does_it_have_SubDir(setpoint_path)){

                      this->Append_Items(setpoint_path,setpoint_id);
                    }

                    this->Append_Files(setpoint_path,setpoint_id);
                  }
                }

                this->Append_Files(Folder,Id);

              }
              else{

                   this->Append_Files(setpoint_path,Id);
              }

              dirCtrl.Close();
            }
            else{

                   wxMessageOutput::Get()->Printf("Folder %s can not be openned",Folder);
            }
        }
        else{

              wxMessageOutput::Get()->Printf("Folder: %s does not exist",Folder);
        }
 }

 void Project_Folder_Lister::Append_Files(wxString Folder, wxTreeItemId Id){

      wxString filename  = wxT("");

      wxString file_path = wxT("");

      wxDir File_dirCtrl;

      File_dirCtrl.Open(Folder);

      if(File_dirCtrl.IsOpened()){

         bool cond = File_dirCtrl.GetFirst(&filename,wxEmptyString,

              wxDIR_FILES  | wxDIR_NO_FOLLOW);

         if(cond){

           file_path = Folder + wxT("\\") + filename;

            this->Append_File_To_Tree(Id,filename,file_path);

             while(cond){

                   cond = File_dirCtrl.GetNext(&filename);

                   if(cond){

                     file_path = Folder + wxT("\\") + filename;

                      this->Append_File_To_Tree(Id,filename,file_path);
                   }
             }
           }
       }
 }


  void Project_Folder_Lister::Count_Files(wxString Folder){

       wxString filename  = wxT("");

       wxDir File_dirCtrl;

       File_dirCtrl.Open(Folder);

       if(File_dirCtrl.IsOpened()){

          bool cond = File_dirCtrl.GetFirst(&filename,wxEmptyString,

               wxDIR_FILES  | wxDIR_NO_FOLLOW);

          if(cond){

              while(File_dirCtrl.GetNext(&filename)){

                this->total_item_number++;

              }
          }
       }
  }



 size_t Project_Folder_Lister::Get_Sub_Directory_Name_Size(wxString Item){

        this->Short_Path_Name_Size = 0;

        for(size_t k=Item.Length();k>0;k--){

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

     size_t Sub_Dir_Start_Point = Item.Length( ) - Sub_Dir_Name_Size +1;

     for(size_t k=Sub_Dir_Start_Point; k<Item.Length();k++){

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
