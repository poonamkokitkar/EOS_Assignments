//	Q1. The client process send two numbers to the server process via one ﬁfo. The server process calculate the sum and return via another ﬁfo.
//		The client process print the result.

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(){
	int fd_w,fd_r,cnt,res,sum;
	int arr[2];
	fd_w = open("/home/poonam/Desktop/12_pra/send_data", O_WRONLY);
	if(fd_w < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("enter two numbers: ");
	scanf("%d %d", &arr[0],&arr[1]);


	cnt = write(fd_w, arr, sizeof(arr));
	//printf("written in fifo: %d bytes\n", cnt);


	fd_r = open("/home/poonam/Desktop/12_pra/rcv_data", O_RDONLY);
	if(fd_r < 0) {
		perror("open() failed");
		_exit(1);
	}

	cnt = read(fd_r, &sum, sizeof(sum));
//	printf("read from fifo: %d bytes -- %d\n", cnt1,(int)arr);
	printf("The result is: %d\n",sum);

	close(fd_w);
	close(fd_r);
	return 0;
}



