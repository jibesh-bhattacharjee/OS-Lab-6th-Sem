#!/bin/bash

echo "Enter the first number :"
read a
echo "Enter the second number : "
read b

if [ $a -gt $b ]
then
	num=$a
	den=$b
else
	num=$b
	den=$a
fi


r=$(($num % $den))

while [ $r -ne 0 ]
do
	num=$den
	den=$r
	r=$(($num % $den))
done

gcd=$den
lcm=`expr $a \* $b / $gcd`

echo "LCM of $a and $b is : $lcm"
echo "GCD of $a and $b is : $gcd"
