#!/usr/bin/env bash
cxx=g++
src=$1
bin=${1%.*}
shift 1
if [[ "$(uname)" == "Darwin" ]]; then
    # cxx=clang++
    cxx=g++-15
    bin=${bin}.bin
fi
# flags="-std=c++20 -Wall -Wextra -Wpedantic -Werror -Wno-unused-variable"
flags="-std=c++20 -Wall -Wextra -Werror -Wno-unused-variable -Wno-keyword-macro"
echo "$bin $@" 1>&2
$cxx $src -o $bin $flags && $(realpath $bin) $@
echo Press any key to continue... 1>&2
read
