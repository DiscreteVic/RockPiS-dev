#!/bin/bash

sudo apt-get install libudev-dev libusb-1.0-0-dev dh-autoreconf pkg-config libusb-1.0


git clone https://github.com/rockchip-linux/rkdeveloptool
cd rkdeveloptool
aclocal
autoreconf -i
./configure
make
cp rkdeveloptool /opt/Rockchip/.
sudo ln -s -f /opt/Rockchip/rkdeveloptool /usr/bin/rkdeveloptool

# -- IF SOME ERRORS ARE SHOWN DURING INSTALATION --
# Apply patch below
# https://github.com/rockchip-linux/rkdeveloptool/issues/70 