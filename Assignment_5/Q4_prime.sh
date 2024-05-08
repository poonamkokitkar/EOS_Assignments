#!/bin/bash


echo "Enter number: "
read num
flag=0

if [ $num -eq 0 -o $num -eq 1 ]
then 
	flag=1
fi

for (( i=2; i<=num/2; i++ ))
do 
	a=`expr $num % $i`
	if [ $a -eq 0 ]
	then 
		flag=1
	fi
done

if [ $flag -eq 0 ]
then 
	echo "prime"
else
	echo "non prime"
fi
