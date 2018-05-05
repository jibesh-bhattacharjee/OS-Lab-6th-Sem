#!/bin/bash

echo -n "Enter number : "
read n

if [ $n -le 9 ]
then 
	echo "Palindrome"
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

	if [ $on -eq $rev ];
	then
		echo "Palindrome"
	else
		echo "NO....!!!!"
	fi
fi
