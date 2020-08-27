
DEBIAN_RELEASE_BIN_DIR=~/PCYNLITX.PROJECT.LIBRARY/PCYNLITX_RELEASE_PACKAGES/DEBIAN_RELEASE/pcynlitx_debian/usr/bin
UBUNTU_RELEASE_BIN_DIR=~/PCYNLITX.PROJECT.LIBRARY/PCYNLITX_RELEASE_PACKAGES/UBUNTU_RELEASE/pcynlitx_ubuntu/usr/bin
FEDORA_RELEASE_BIN_DIR=~/PCYNLITX.PROJECT.LIBRARY/PCYNLITX_RELEASE_PACKAGES/FEDORA_RELEASE/pcynlitx_fedora/usr/bin

printf "\n   #\e[1;34m Project binary files will be updated .. \e[0m\n\n"

cd ~/PCYNLITX.PROJECT/EXECUTABLE.FILE.BUILDER/MT_Project_Builder

make -f auto_make_file.make

cd ~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.READER/Descriptor_File_Reader

make -f auto_make_file.make

cd ~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.WRITER/Empty_Process_Descriptor_File_Builder

make -f auto_make_file.make

cd ~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.WRITER/Process_Descriptions_Recorder

make -f auto_make_file.make

cd ~/PCYNLITX.PROJECT/KERNEL.DEVELOPMENT/Kernel

make -f auto_make_file.make

cd ~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.WRITER/Description_Printer

make -f auto_make_file.make

Library_Updater

cd ~/PCYNLITX.PROJECT/EXECUTABLE.FILE.BUILDER/MT_Project_Builder

Exe_Builder

sudo mv MT_Project_Builder.exe MT_Project_Builder

sudo cp MT_Project_Builder $DEBIAN_RELEASE_BIN_DIR

sudo cp MT_Project_Builder $UBUNTU_RELEASE_BIN_DIR

sudo cp MT_Project_Builder $FEDORA_RELEASE_BIN_DIR

sudo mv MT_Project_Builder /usr/bin

printf "   #\e[3;36m MT_Project_Builder binary has been updated .. \e[0m\n\n"

cd ~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.READER/Descriptor_File_Reader

Exe_Builder

sudo mv Descriptor_File_Reader.exe Descriptor_File_Reader

sudo cp Descriptor_File_Reader $DEBIAN_RELEASE_BIN_DIR

sudo cp Descriptor_File_Reader $UBUNTU_RELEASE_BIN_DIR

sudo cp Descriptor_File_Reader $FEDORA_RELEASE_BIN_DIR

sudo mv Descriptor_File_Reader /usr/bin

printf "   #\e[3;36m Descriptor_File_Reader binary has been updated .. \e[0m\n\n"

cd ~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.WRITER/Empty_Process_Descriptor_File_Builder

Exe_Builder

sudo mv Empty_Process_Descriptor_File_Builder.exe Empty_Process_Descriptor_File_Builder

sudo cp Empty_Process_Descriptor_File_Builder $DEBIAN_RELEASE_BIN_DIR

sudo cp Empty_Process_Descriptor_File_Builder $UBUNTU_RELEASE_BIN_DIR

sudo cp Empty_Process_Descriptor_File_Builder $FEDORA_RELEASE_BIN_DIR

sudo mv Empty_Process_Descriptor_File_Builder /usr/bin

printf "   #\e[3;36m Empty_Process_Descriptor_File_Builder binary has been updated .. \e[0m\n\n"

cd ~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.WRITER/Process_Descriptions_Recorder

Exe_Builder

sudo mv Process_Descriptions_Recorder.exe Description_Recorder

sudo cp Description_Recorder $DEBIAN_RELEASE_BIN_DIR

sudo cp Description_Recorder $UBUNTU_RELEASE_BIN_DIR

sudo cp Description_Recorder $FEDORA_RELEASE_BIN_DIR

sudo mv Description_Recorder /usr/bin

printf "   #\e[3;36m Description_Recorder binary has been updated .. \e[0m\n\n"

cd ~/PCYNLITX.PROJECT/KERNEL.DEVELOPMENT/Kernel

Exe_Builder

sudo mv Kernel.exe Pcynlitx_Kernel

sudo cp Pcynlitx_Kernel $DEBIAN_RELEASE_BIN_DIR

sudo cp Pcynlitx_Kernel $UBUNTU_RELEASE_BIN_DIR

sudo cp Pcynlitx_Kernel $FEDORA_RELEASE_BIN_DIR

sudo mv Pcynlitx_Kernel /usr/bin

printf "   #\e[3;36m Kernel binary has been updated .. \e[0m\n\n"

cd ~/PCYNLITX.PROJECT/DESCRIPTOR.FILE.WRITER/Description_Printer

Exe_Builder

sudo mv Description_Printer.exe Description_Printer

sudo cp Description_Printer $DEBIAN_RELEASE_BIN_DIR

sudo cp Description_Printer $UBUNTU_RELEASE_BIN_DIR

sudo cp Description_Printer $FEDORA_RELEASE_BIN_DIR

sudo mv Description_Printer /usr/bin

printf "   #\e[3;36m Description_Printer binary has been updated .. \e[0m\n\n"

printf "\n   #\e[1;34m Project binary files has been updated .. \e[0m\n\n"
