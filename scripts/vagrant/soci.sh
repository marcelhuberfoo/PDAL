#!/bin/bash -e
# Installs SOCI library

git clone https://github.com/hobu/soci.git soci
cd soci/src
cmake . -DCMAKE_INSTALL_PREFIX=/usr
make
sudo make install