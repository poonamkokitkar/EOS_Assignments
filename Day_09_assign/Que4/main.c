//	Q4.Write a program that compiles above multi-ﬁle project. It runs commands "gcc -c circle.c", "gcc -c square.c", "gcc -c rectangle.c", "gcc -c main.c"
//		concurrently.



#include <stdio.h>
#include "circle.h"
#include "square.h"
#include "rectangle.h"
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include "circle.c"
#include "square.c"
#include "rectangle.c"

int main(){
	int rad =5,side=4,len=2,bre=5,res1,res2,res3,ret1,ret2,ret3,ret4,ret5,ret6,err,s;
	res1 = circle_area(rad);
	printf("area of circle is: %d\n",res1);
	res2 = square_area(side);
	printf("area of square is: %d\n",res2);
	res3 = rect_area(len,bre);
	printf("area of rectangle is: %d\n",res3);
	
	return 0;
}
