#!/usr/bin/env sh

./clean-build.sh
./display-header.sh
./cmake-build-debug/sym_der --diff "x * sin(x)" --by x