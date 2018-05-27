#!/bin/bash
cd $(dirname ${BASH_SOURCE[0]})

mkdir -p ../build
cd ../build
cmake -DCMAKE_CXX_FLAGS=-pthread -DCMAKE_EXE_LINKER_FLAGS="-lnettle -lgnutls -lldap -llber -lz -ldl -lmariadb -lssl -lcrypto" ../
