#!/usr/bin/env bash
find . -type f | xargs -I{} file {} | grep text | cut -d: -f1 | xargs -I{} dos2unix "{}"
