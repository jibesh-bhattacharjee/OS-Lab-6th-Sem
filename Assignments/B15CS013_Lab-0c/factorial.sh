#!/bin/bash

echo -n "Enter Number: "
read num

factorial=1

while [ $num -gt 0 ]
do
   factorial=$(( $factorial * $num ))
   num=$(( $num - 1 ))
done

echo $factorial
