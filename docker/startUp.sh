sudo apt-get install -y sudo git make vim pkg-config libusb-1.0 libudev-dev libusb-1.0-0-dev dh-autoreconf
git clone https://github.com/rockchip-linux/rkdeveloptool
cd rkdeveloptool
autoreconf -i
./configure
make
sudo cp rkdeveloptool /usr/local/bin
rm -rf rkdeveloptool