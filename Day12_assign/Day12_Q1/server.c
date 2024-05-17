#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// p2 -- reader
int main() {
	int fd_w,fd_r,sum,ans, cnt,res;
	int arr[2];
	fd_w = open("/home/poonam/Desktop/12_pra/send_data", O_RDONLY);
	if(fd_w < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("waiting for data...\n");
    cnt	= read(fd_w, &arr[0], sizeof(arr[0]));
	cnt = read(fd_w, &arr[1], sizeof(arr[1]));
printf(".....Numbers received......\n");
//	printf("read from fifo: %d bytes -- %d\n",cnt,arr);
  //  printf("read from fifo: %d bytes -- %d\n",cnt1,arr);
	
//	printf("the addition is.....\n");
	sum = arr[0] + arr[1];

	fd_r = open("/home/poonam/Desktop/12_pra/rcv_data", O_WRONLY);
      if(fd_r < 0) {
         perror("open() failed");
         _exit(1);
      }
	cnt = write(fd_r, &sum, sizeof(sum));
//	printf("read from fifo: %d bytes -- %d\n", cnt, ans);

	close(fd_w);
	close(fd_r);
	return 0;
}


