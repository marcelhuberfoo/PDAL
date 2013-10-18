git clone https://github.com/PDAL/PDAL.git pdal
cd pdal

cmake   -G "Unix Makefiles"  \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX=/usr/local \
        -DPDAL_EMBED_BOOST=ON \
        -DWITH_GDAL=ON \
        -DWITH_ICONV=ON \
        -DWITH_GEOTIFF=ON \
        -DWITH_LASZIP=ON \
        -DWITH_LIBXML2=ON \
        -DWITH_PYTHON=ON \
        -DWITH_SOCI=ON \
        -DWITH_P2G=ON \
        -DWITH_HEXER=ON \
        -DWITH_NITRO=ON \
        -DWITH_PGPOINTCLOUD=ON

make
sudo make install

