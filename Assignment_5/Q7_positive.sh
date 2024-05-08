#!/bin/bash

echo -n "Enter a number: "
read num

if [ $num -lt 0 ]
then
	echo "The given number is negative"

elif [ $num -eq 0 ]
then 
	echo "The given number is equal to zero"

else
	echo "The given number is positive"
fi
