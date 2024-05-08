#!/bin/bash

#	2. Write a shell script to display menu like “1. Date, 2. Cal, 3. Ls, 4. Pwd, 5. Exit” and
#		execute the commands depending on user choice.

echo -e "1.Date\n2.Cal\n3.Ls\n4.Pwd\n5.Exit"
echo -n "Enter your choice : "
read choice

case $choice in
1)
	echo "Todays date: "
	date
	;;

2)
	echo "calender of this month is: "
	cal
	;;

3)	
	echo "list of files of current directory: "
	ls
	;;

4)
	echo "Path of current working directory: "
	pwd
	;;

5)
	echo "Exit "
	exit
	;;

*)
	echo "Invalid operation"
	;;
esac
