
/*

 * Copyright (C) { Erkam Murat Bozkurt } - All Rights Reserved
 * 
 * This source code is protected under international copyright law.  All rights
 * reserved and protected by the copyright holders.
 * 
 * This file is confidential and only available to authorized individuals with the
 * permission of the copyright holders.  If you encounter this file and do not have
 * permission, please contact the copyright holders and delete this file.

*/

#include "Project_Folder_Lister.h"

Project_Folder_Lister::Project_Folder_Lister(wxDataViewTreeCtrl * TreeCtrl){

     this->treeCtrl = TreeCtrl;

     this->is_project_directory_open = false;

     this->tree_item_list = nullptr;

     this->Item_Path = wxT("");

     this->Short_Path = wxT("");

     this->total_item_number = 0;

     this->item_counter = 0;

    this->Initialize_Properties();

}

Project_Folder_Lister::~Project_Folder_Lister(){

     if(!this->Memory_Delete_Condition){

         this->treeCtrl->DeleteAllItems();

        if(this->tree_item_list != nullptr){

           delete [] this->tree_item_list;

           this->tree_item_list = nullptr;
        }
     }
}


void Project_Folder_Lister::Initialize_Properties(){

     wxSize size = this->treeCtrl->FromDIP(wxSize(16, 16));

     this->Folder_Icon.LoadFile(wxT("C:\\Program Files\\Pcynlitx\\icons\\Folder.png"),wxBITMAP_TYPE_PNG);

     this->File_Icon = wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, size);
}


void Project_Folder_Lister::Load_Project_Directory(wxString Folder){

     this->total_item_number = 0;

     this->treeCtrl->DeleteAllItems();

     if(this->tree_item_list != nullptr){

        delete [] this->tree_item_list;

        this->tree_item_list = nullptr;
     }

     this->count_sub_directories(Folder);

     // The sub directory number is determined

     this->tree_item_list = new Tree_Item [5*this->total_item_number];

     wxString Root_Folder = this->Determine_Short_Path(Folder);

     this->item_counter = 0;


     this->tree_item_list[this->item_counter+1].item_number 
     
     = this->treeCtrl->AppendContainer(this->tree_item_list[this->item_counter].item_number,Root_Folder,-1,-1);

     this->item_counter++;

     this->treeCtrl->SetItemIcon(this->tree_item_list[this->item_counter].item_number,this->Folder_Icon);

     this->tree_item_list[this->item_counter].Item_Path = Folder;

     this->Append_Items(Folder,this->tree_item_list[this->item_counter].item_number);

     // Total item number is determined exactly after appending the Append_Items

     // and it is set.

    this->total_item_number = 2*this->item_counter;

    this->is_project_directory_open = true;
 }




 void Project_Folder_Lister::Append_Items(wxString Folder, wxDataViewItem Item){

      // Appending the directories recursively

      wxString dirname  = wxT("");

      wxDataViewItem setpoint_item_number;

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

                  setpoint_item_number = this->Append_Directory_To_Tree(Item,dirname,setpoint_path);

                  if(this->Does_it_have_SubDir(setpoint_path)){

                     this->Append_Items(setpoint_path,setpoint_item_number);
                  }
                  else{

                       this->Append_Files(setpoint_path,setpoint_item_number);
                  }

                  while(dirCtrl.GetNext(&dirname)){

                    setpoint_path = Folder + wxT("\\") + dirname;

                    setpoint_item_number = this->Append_Directory_To_Tree(Item,dirname,setpoint_path);

                    if(this->Does_it_have_SubDir(setpoint_path)){

                       this->Append_Items(setpoint_path,setpoint_item_number);
                    }
                    else{

                        this->Append_Files(setpoint_path,setpoint_item_number);
                    }
                  }
                }

                this->Append_Files(Folder,Item);

              }
              else{

                   this->Append_Files(setpoint_path,Item);
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






 wxDataViewItem Project_Folder_Lister::Append_Directory_To_Tree(wxDataViewItem Item, wxString Directory, wxString Path){

      if(!this->Is_Item_Already_Exist(Path)){

         this->tree_item_list[this->item_counter+1].item_number =

              this->treeCtrl->AppendContainer(Item,Directory,-1,-1,NULL);

         this->appended_item = this->tree_item_list[this->item_counter+1].item_number;

         this->tree_item_list[this->item_counter+1].Item_Path = Path;

         this->treeCtrl->SetItemIcon(this->tree_item_list[this->item_counter+1].item_number,this->Folder_Icon);

         this->item_counter++;

         return this->appended_item;
      }
 }


 wxDataViewItem Project_Folder_Lister::Append_File_To_Tree(wxDataViewItem Item, wxString File, wxString Path){

      if(!this->Is_Item_Already_Exist(Path)){
          
          this->tree_item_list[this->item_counter+1].item_number =

              this->treeCtrl->AppendItem(Item,File,-1,NULL);

          this->appended_item = this->tree_item_list[this->item_counter+1].item_number;

          this->tree_item_list[this->item_counter+1].Item_Path = Path;

          this->treeCtrl->SetItemIcon(this->tree_item_list[this->item_counter+1].item_number,this->File_Icon);

          this->item_counter++;

          return this->appended_item;

      }
 }


 void Project_Folder_Lister::Append_Files(wxString Folder, wxDataViewItem Item){      

      wxString filename  = wxT("");

      wxString file_path = wxT("");

      wxDir File_dirCtrl;

      File_dirCtrl.Open(Folder);

      if(File_dirCtrl.IsOpened()){

         bool cond = File_dirCtrl.GetFirst(&filename,wxEmptyString,

              wxDIR_FILES  | wxDIR_NO_FOLLOW);

         if(cond){

           file_path = Folder + wxT("\\") + filename;

            this->Append_File_To_Tree(Item,filename,file_path);

             while(cond){

                   cond = File_dirCtrl.GetNext(&filename);

                   if(cond){

                     file_path = Folder + wxT("\\") + filename;

                      this->Append_File_To_Tree(Item,filename,file_path);
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

 size_t Project_Folder_Lister::Get_Sub_Directory_Name_Size(wxString Item_Path){

        this->Short_Path_Name_Size = 0;

        for(size_t k=Item_Path.Length();k>0;k--){

            if(Item_Path[k] == '\\'){

               break;
            }

            this->Short_Path_Name_Size++;
        }

        return  this->Short_Path_Name_Size;
 }

 wxString Project_Folder_Lister::Determine_Short_Path(wxString Item_Path)
 {
     //  This Function extracts the short path of the file or folder
     //  from the long path

     // Consider the directory D:\ ---- \Name >

     // The Name is extracted

     this->Short_Path = wxT("");

     size_t Sub_Dir_Name_Size = this->Get_Sub_Directory_Name_Size(Item_Path);

     size_t Sub_Dir_Start_Point = Item_Path.Length( ) - Sub_Dir_Name_Size +1;

     for(size_t k=Sub_Dir_Start_Point; k<Item_Path.Length();k++){

         this->Short_Path = this->Short_Path + Item_Path[k];
     }

     return this->Short_Path;
 }

 wxDataViewTreeCtrl * Project_Folder_Lister::GetTreeCtrl(){

      return this->treeCtrl;
 }

 wxDataViewItem Project_Folder_Lister::GetItemId_FromPath(wxString path){

       wxDataViewItem IDNUM = this->tree_item_list[0].item_number;

       for(int i=0;i<this->total_item_number;i++){

           if(path == this->tree_item_list[i].Item_Path){

              IDNUM = this->tree_item_list[i].item_number;

              break;
           }
       }

       return IDNUM;
}




 wxString Project_Folder_Lister::GetItemPath(wxDataViewItem item_number){

          this->Item_Path = wxT("");

          for(int i=0;i<this->total_item_number;i++){

              if(this->tree_item_list[i].item_number == item_number){

                 this->Item_Path = this->tree_item_list[i].Item_Path;
              }
          }

          return this->Item_Path;
}


bool Project_Folder_Lister::Is_Item_Already_Exist(wxString Path){

     bool is_exist = false;

     for(int i=0;i<this->item_counter;i++){

         if(this->tree_item_list[i].Item_Path == Path){

            is_exist = true;

            return is_exist;
         }
     }

     return is_exist;
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

     this->treeCtrl->Expand(this->tree_item_list[1].item_number);
}


void Project_Folder_Lister::Expand_Path(wxString path){

     wxDataViewItem Item_Number = this->GetItemId_FromPath(path);

     this->treeCtrl->Expand(Item_Number);
}

void Project_Folder_Lister::Expand_Selected_Item(){

     this->treeCtrl->Expand(this->treeCtrl->GetSelection());
}

int Project_Folder_Lister::GetTotalItemNum(wxString Folder){

    this->total_item_number = 0;

    this->count_sub_directories(Folder);
 
    return this->total_item_number;
}