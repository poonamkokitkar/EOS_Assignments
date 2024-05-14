#!/bin/bash

echo "enter a number: "
read num
fact=1

for (( i=1; i<=num; i++ ))
do
	a=`expr $fact * $i`
	echo`expr $fact=$a`
	ans=$fact
done

echo " $fact "
