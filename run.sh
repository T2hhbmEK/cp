#!/usr/bin/env bash
cxx=g++
src=$1
bin=${1%.*}
shift 1
if [[ "$(uname)" == "Darwin" ]]; then
    cxx=clang++
    bin=${bin}.bin
fi
flags="-std=c++20 -Wall -Wextra -Wpedantic -Werror"
echo "$bin $@" 1>&2
$cxx $src -o $bin $flags && $(realpath $bin) $@
echo Press any key to continue... 1>&2
read
