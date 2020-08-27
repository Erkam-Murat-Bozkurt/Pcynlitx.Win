
DEBIAN_RELEASE=~/PCYNLITX.PROJECT.LIBRARY/PCYNLITX_RELEASE_PACKAGES/DEBIAN_RELEASE

bash update_debian_package.sh

cd $DEBIAN_RELEASE

sudo chown root:root pcynlitx_debian

sudo chmod 0777 pcynlitx_debian

sudo dpkg-deb --build pcynlitx_debian

sudo chmod 0777 pcynlitx_debian.deb
