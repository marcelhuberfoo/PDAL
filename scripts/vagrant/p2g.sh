#!/bin/bash -e
# Installs points2grid library

git clone https://github.com/CRREL/points2grid.git
cd points2grid
cmake . -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_CXX_FLAGS="-fPIC" -DCMAKE_C_FLAGS="-fPIC"
make
sudo make install