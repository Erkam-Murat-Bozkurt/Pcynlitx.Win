Name: Pcynlitx
Version: 1.0
Release: 1
Summary: A intelligent IDE which is specialized for multithreading
License: GPLv3
URL: http:://www.pcynlitx.tech
Source: https://github.com/Erkam-Murat-Bozkurt/Pcynlitx/releases/pcynlitx_fedora.rpm
Vendor: Erkam Murat Bozkurt
Packager: Erkam Murat Bozkurt <pcynlitx.help@gmail.com>
Requires: libgcc, libstdc++, gcc-c++
Requires: libstdc++-devel, glibc
Requires: wxBase3, wxBase3-devel, wxGTK3
Requires: wxGTK3-devel, wxGTK3-docs, wxGTK3-gl
Requires: wxGTK3-i18n, wxGTK3-media
Requires: compat-wxGTK3-gtk2, compat-wxGTK3-gtk2-gl
Requires: liberation-fonts-common, linux-libertine-fonts, gnome-terminal


%description
Pcynlitx is a free and open source ide. Pcynlitx is an intelligent integrated development environment that build application-specific multi-threading libraries according to your needs.

%files
/usr/bin/Description_Printer
/usr/bin/Description_Recorder
/usr/bin/Descriptor_File_Reader
/usr/bin/Empty_Process_Descriptor_File_Builder
/usr/bin/MT_Project_Builder
/usr/bin/Pcynlitx_Kernel
/usr/bin/Pcynlitx
/usr/share/Pcynlitx/Intro_File.png
/usr/share/Pcynlitx/icons/archive.png
/usr/share/Pcynlitx/icons/build_executable.png
/usr/share/Pcynlitx/icons/close.png
/usr/share/Pcynlitx/icons/close_tab.png
/usr/share/Pcynlitx/icons/pane_close_icon.png
/usr/share/Pcynlitx/icons/empty_project_file.png
/usr/share/Pcynlitx/icons/file.png
/usr/share/Pcynlitx/icons/file_save.png
/usr/share/Pcynlitx/icons/folder.png
/usr/share/Pcynlitx/icons/help_documents.png
/usr/share/Pcynlitx/icons/open_terminal.png
/usr/share/Pcynlitx/icons/open_tree_view.png
/usr/share/Pcynlitx/icons/pcynlitx.png
/usr/share/Pcynlitx/icons/print_descriptions.png
/usr/share/Pcynlitx/icons/select_project_file.png
/usr/share/applications/pcynlitx.desktop
/usr/share/doc/Copyright

%post
sudo chmod 0777 /usr/bin/Pcynlitx
sudo chmod 0777 /usr/bin/Pcynlitx_Kernel
sudo chmod 0777 /usr/bin/Description_Printer
sudo chmod 0777 /usr/bin/Descriptor_File_Reader
sudo chmod 0777 /usr/bin/Description_Recorder
sudo chmod 0777 /usr/bin/Empty_Process_Descriptor_File_Builder
sudo chmod 0777 /usr/bin/MT_Project_Builder
sudo chmod 0777 /usr/share/Pcynlitx/Intro_File.png
sudo chmod 0777 /usr/share/Pcynlitx/icons/archive.png
sudo chmod 0777 /usr/share/Pcynlitx/icons/build_executable.png
sudo chmod 0777 /usr/share/Pcynlitx/icons/close.png
sudo chmod 0777 /usr/share/Pcynlitx/icons/close_tab.png
sudo chmod 0777 /usr/share/Pcynlitx/icons/pane_close_icon.png
sudo chmod 0777 /usr/share/Pcynlitx/icons/empty_project_file.png
sudo chmod 0777 /usr/share/Pcynlitx/icons/file.png
sudo chmod 0777 /usr/share/Pcynlitx/icons/file_save.png
sudo chmod 0777 /usr/share/Pcynlitx/icons/folder.png
sudo chmod 0777 /usr/share/Pcynlitx/icons/help_documents.png
sudo chmod 0777 /usr/share/Pcynlitx/icons/open_terminal.png
sudo chmod 0777 /usr/share/Pcynlitx/icons/open_tree_view.png
sudo chmod 0777 /usr/share/Pcynlitx/icons/pcynlitx.png
sudo chmod 0777 /usr/share/Pcynlitx/icons/print_descriptions.png
sudo chmod 0777 /usr/share/Pcynlitx/icons/select_project_file.png
sudo chmod 0777 /usr/share/applications/pcynlitx.desktop
sudo chmod 0777 /usr/share/doc/Copyright
