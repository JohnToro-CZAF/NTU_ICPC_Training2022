#!/bin/sh

# filename
filename=$1
number=$2
# file extension
declare cnt=1
for letter in {A..Z}; do
    if  [ $cnt -le $number ] ; then
        cnt=$(($cnt + 1))
        cp -n ../../AlgoTemplate/ICPCTemplate/template_icpc.cpp ./$letter.cpp
    else 
        exit
    fi
done
exit

