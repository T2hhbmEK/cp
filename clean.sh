#!/usr/bin/env bash
find $CWD -type f -name '*' ! -name '*.*' -exec file -i {} + | grep 'ELF' | cut -d: -f1 | tee /dev/stderr | xargs -0 rm -f
find $CWD -name "*.exe" -print0 | tee /dev/stderr | xargs -0 rm -f
