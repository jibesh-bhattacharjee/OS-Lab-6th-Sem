#!/bin/bash

echo -n "Enter n: "
read n

n1=0
n2=1
i=2

echo "Fibonacci Series up to $n terms :"

if [ $n -lt 2 ]
	then
		echo "$n1"
	else
		echo "$n1"
		echo "$n2"
		while [ $i -lt $n ]
		do
		    i=`expr $i + 1 `
		    z=`expr $n1 + $n2 `
		    echo "$z"
		    n1=$n2
		    n2=$z
		done	
fi


