#!/bin/bash

echo -n "Enter number : "
read n
 
digit=0 
sum=0
 

while [ $n -gt 0 ]
do
    digit=$(( $n % 10 )) 
    n=$(( $n / 10 ))  
    sum=$(( $sum + $digit ))
done
echo  "Sum of all digit  is $sum"
