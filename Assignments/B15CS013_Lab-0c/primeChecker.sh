#!/bin/bash

echo -n "Enter a number: "
read num
i=2

if [ $num -eq 1 ]
then
	echo "1 is neither prime nor composite."
else

	while [ $i -lt $num ]
	do
	  if [ $(($num % $i)) -eq 0 ]
	  then
	      echo "$num is not a prime number"
	      exit
	  fi
	  i=$(($i + 1))
	done

	echo "$num is a prime number "
fi
