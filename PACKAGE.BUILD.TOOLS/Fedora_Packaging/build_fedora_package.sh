
FEDORA_RELEASE=~/PCYNLITX.PROJECT.LIBRARY/PCYNLITX_RELEASE_PACKAGES/FEDORA_RELEASE
GUI_DEVELOPMENT=~/PCYNLITX.PROJECT/GUI.DEVELOPMENT
BASE_DIRECTORY_FOR_PACKAGE_BUILD=~/PCYNLITX.PROJECT/PACKAGE.BUILD.TOOLS/Fedora_Packaging
BUILDROOT_DIRECTORY=~/rpmbuild/BUILDROOT

cd $GUI_DEVELOPMENT

bash Update_Project_Binaries.sh > Compiler_Output

bash GUI_Compiler.sh > Compiler_Output

cd $BASE_DIRECTORY_FOR_PACKAGE_BUILD

bash update_fedora_package.sh

cd $FEDORA_RELEASE

sudo chown root:root pcynlitx_fedora

sudo chmod 0777 pcynlitx_fedora

cp -r pcynlitx_fedora ~/rpmbuild/BUILDROOT

cd ~/rpmbuild/BUILDROOT

mv pcynlitx_fedora Pcynlitx-1.0-1.x86_64

sudo chmod 0777 $BASE_DIRECTORY_FOR_PACKAGE_BUILD/Pcynlitx.spec

cp $BASE_DIRECTORY_FOR_PACKAGE_BUILD/Pcynlitx.spec ~/rpmbuild/SPECS

sudo chmod 0777 ~/rpmbuild/SPECS/Pcynlitx.spec

cd ~

rpmbuild -bb ~/rpmbuild/SPECS/Pcynlitx.spec

sudo chmod 0777 pcynlitx_fedora.rpm
