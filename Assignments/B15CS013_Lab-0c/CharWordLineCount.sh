#!/bin/bash
echo "enter file name"
read filename
mystring=`cat $filename| wc -w`
echo "no of words is $mystring"
mystring=`cat $filename| wc -c`
echo "no of characters is $mystring"
mystring=`cat $filename| wc -l`
mystring=`expr $mystring + 1`
echo "no of line in the file is $mystring"