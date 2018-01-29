#!/bin/bash
read -p "Enter a number: " a
echo "Number entered: " $a

r=$(( $a % 2 ))

if [ $r -eq 0  ]
	then
		echo "EVEN"
	else
		echo "ODD"
fi
