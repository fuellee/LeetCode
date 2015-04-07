#! /bin/sh
#
# Valid_Phone_Numbers.sh
# Copyright (C) 2015 fuel <fuel@fuel-7420>
#
# Distributed under terms of the MIT license.
#

grep -Ex '((\([0-9]{3}\) |[0-9]{3}-)[0-9]{3}-[0-9]{4})' file.txt
# -x ; --line-regexp : Select only those matches that exactly match the whole line
grep -P '^(\(\d{3}\) |\d{3}-)\d{3}-\d{4}$' file.t
# `\d` is a Perl-flavored regular expression
