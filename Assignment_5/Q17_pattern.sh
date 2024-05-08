#!/bin/bash

echo -n "Enter the number to print pattern: "
read num

for (( i=0; i<num; i++ ))
do
	for (( j=0; j<=i; j++ ))
	do
		echo -n " * "
	done
echo " "  
done
