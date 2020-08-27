
sudo dnf groupinstall "Development Tools" "Development Libraries" -y

sudo dnf install rpmdevtools rpmlint -y

sudo cd ~

rpmdev-setuptree

cd ~/rpmbuild

if [ ! -e "BUILDROOT" ]
then
  mkdir BUILDROOT
fi
