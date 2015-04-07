#! /bin/bash
#
# Transpose_File.sh
# Copyright (C) 2015 fuel <fuel@fuel-7420>
#
# Distributed under terms of the MIT license.
#
python - <<-EOF
M = [line.split() for line in file("file.txt").read().splitlines()]
for line in zip(*M):
    print " ".join(line)
EOF
