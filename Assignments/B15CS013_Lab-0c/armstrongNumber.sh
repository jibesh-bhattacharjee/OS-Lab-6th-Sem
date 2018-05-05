#!/bin/bash

echo -n "Enter the number: "
read n
len=${#n}
Sum=0
num=$n

while [ $n -ne  0 ]
do
     Rem=$((n%10))
     n=$((n/10))
     Power=$(echo "$Rem ^ $len" | bc )
     Sum=$((Sum+$Power))
done

if [ $Sum -eq $num ]
then
    echo "$num is an Armstrong number"
else
    echo "$num is not an Armstrong number"
fi
