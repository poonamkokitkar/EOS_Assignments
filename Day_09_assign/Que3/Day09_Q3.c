//	Q3.Create a multi-ﬁle project (main.c, circle.c/.h, square.c/.h, rectangle.c/.h). Compile the program using
//		"gcc" and execute it.


#include <stdio.h>
#include "circle.h"
#include "square.h"
#include "rect.h"
#include "circle.c"
#include "square.c"
#include "rect.c"

int main(){
	
	int rad =5,side=4,len=2,bre=5,res1,res2,res3;
	res1 = circle_area(rad);
	printf("area of circle is: %d\n",res1);
	res2 = square_area(side);
	printf("area of square is: %d\n",res2);
	res3 = rect_area(len,bre);
	printf("area of rectangle is: %d\n",res3);




	return 0;
}
