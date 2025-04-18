#!/usr/bin/env bash
find $CWD -type f -name '*' ! -name '*.*' -exec file {} + | grep 'ELF' | cut -d: -f1 | xargs rm -f
find $CWD -name *.exe -delete
