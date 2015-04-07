#! /bin/bash
#
# Tenth_Line.sh
# Copyright (C) 2015 fuel <fuel@fuel-7420>
#
# Distributed under terms of the MIT license.
#
sed -n '10p' file.txt
awk 'NR==10' file.txt
tail -n+10 file.txt | head -n1
# tail -n+K : output lines starting with the Kth
