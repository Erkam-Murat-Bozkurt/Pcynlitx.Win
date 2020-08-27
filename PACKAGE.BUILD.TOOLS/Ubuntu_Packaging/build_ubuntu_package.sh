UBUNTU_RELEASE=~/PCYNLITX.PROJECT.LIBRARY/PCYNLITX_RELEASE_PACKAGES/UBUNTU_RELEASE

bash update_ubuntu_package.sh

cd $UBUNTU_RELEASE

sudo chown root:root pcynlitx_ubuntu

sudo chmod 0777 pcynlitx_ubuntu

sudo dpkg-deb --build pcynlitx_ubuntu

sudo chmod 0777 pcynlitx_ubuntu.deb
