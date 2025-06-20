#!/usr/bin/env bash
cxx=g++
src=$1
bin=${1%.*}
shift 1
if [[ "$(uname)" == "Darwin" ]]; then
    cxx=g++-15
    bin=${bin}.bin
fi
flags="-std=c++14 -Wall -Wextra -Wpedantic -Werror"
echo "$bin $@"
$cxx $src -o $bin $flags && $(realpath $bin) $@
echo Press any key to continue...
read
