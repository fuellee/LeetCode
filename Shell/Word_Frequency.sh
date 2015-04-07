#! /bin/bash
#
# Word_Frequency.sh
# Copyright (C) 2015 fuel <fuel@fuel-7420>
#
# Distributed under terms of the MIT license.
#

sed --regexp-extended 's/ {1,}/\n/g' words.txt |
grep -vE "^$" | # remove blank line
sort | uniq -c |
sort -nr |
awk '{print $2,$1}'
