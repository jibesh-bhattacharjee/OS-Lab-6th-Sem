#!/bin/bash

echo -n "Enter number : "
read n

if [ $n -eq 0 ]
then
	echo "Reverse: 0"
else
	digit=0
	rev=""
	on=$n
	while [ $n -gt 0 ]
	do
	    digit=$(( $n % 10 ))
	    n=$(( $n / 10 ))
	    rev=$( echo ${rev}${digit} )
	done
	echo "Reverse: $rev"
fi
