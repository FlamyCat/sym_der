#!/usr/bin/env sh

./clean-build.sh
./display-header.sh
./cmake-build-debug/sym_der --eval "x * y" x=10 y=12