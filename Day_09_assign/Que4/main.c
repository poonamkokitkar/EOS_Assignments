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

int main(int argc, char *argv[]){
	int rad =5,side=4,len=2,bre=5,res1,res2,res3,ret1,ret2,ret3,ret4,ret5,ret6,err,s;
	res1 = circle_area(rad);
	printf("area of circle is: %d\n",res1);
	res2 = square_area(side);
	printf("area of square is: %d\n",res2);
	res3 = rect_area(len,bre);
	printf("area of rectangle is: %d\n",res3);
	
	ret1 = fork();
	if(ret1 == 0) {
		// child process
		err = execl("/usr/bin/gcc", "gcc", "-c", "circle.c", NULL);
		if(err < 0) {
				perror("exec() failed");
				_exit(1);
			}
	}
	else {
		// parent process
		wait(&s);
		printf("child exit status: %d\n", WEXITSTATUS(s));
	}
	
		
	ret2 = fork();
	if(ret2 == 0) {
		// child process
		err = execl("/usr/bin/gcc", "gcc", "-c", "square.c", NULL);
		if(err < 0) {
				perror("exec() failed");
				_exit(1);
			}
	}
	else {
		// parent process
		wait(&s);
		printf("child exit status: %d\n", WEXITSTATUS(s));
	}
	return 0;


	ret3 = fork();
	if(ret3 == 0) {
		// child process
		err = execl("/usr/bin/gcc", "gcc", "-c", "rectangle.c", NULL);
		if(err < 0) {
				perror("exec() failed");
				_exit(1);
			}
	}
	else {
		// parent process
		wait(&s);
		printf("child exit status: %d\n", WEXITSTATUS(s));
	}


	ret4 = fork();
	if(ret4 == 0) {
		// child process
		err = execl("/usr/bin/gcc", "gcc", "-c", "main.c", NULL);
		if(err < 0) {
				perror("exec() failed");
				_exit(1);
			}
	}
	else {
		// parent process
		wait(&s);
		printf("child exit status: %d\n", WEXITSTATUS(s));
	}


	ret5 = fork();
	if(ret5 == 0) {
		// child process
		err = execl("/usr/bin/gcc", "-o", "program", "circle.o", "square.o", "rectangle.o", "main.o",  NULL);
		if(err < 0) {
				perror("exec() failed");
				_exit(1);
			}
	}
	else {
		// parent process
		wait(&s);
		printf("child exit status: %d\n", WEXITSTATUS(s));
	}

	
	ret6 = fork();
	if(ret6 == 0) {
		// child process
		err = execl("/home/poonam/Desktop/Day09/Que3/program", "program", NULL);
		if(err < 0) {
				perror("exec() failed");
				_exit(1);
			}
	}
	else {
		// parent process
		wait(&s);
		printf("child exit status: %d\n", WEXITSTATUS(s));
	}
}
