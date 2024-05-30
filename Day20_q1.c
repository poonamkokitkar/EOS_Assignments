/*
	1. Implement fast ﬁle copy program (assume max ﬁle size = 1 GB).
		step 1: open src ﬁle in rdonly mode.
		step 2: get size of src ﬁle (fstat() syscall)
		step 3: map src ﬁle contents to memory using mmap()
		step 4: create dest ﬁle in rdwr mode.
		step 5: make size of dest ﬁle, same as size of src ﬁle using ftruncate()
		step 6: map dest ﬁle contents to memory using mmap() -- MAP_SHARED.
		step 7: copy src ﬁle to dest ﬁle using memcpy()
		step 8: close src and dest ﬁles.
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main() {
	struct stat st;
	int fd,fd1,ret;
	int *p1;
	//void *ptr, *ptr1;
	void *src, *des;
	fd = open("/home/poonam/data.txt", O_RDONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}
	ret = fstat(fd, &st);
	if(ret < 0) {
		perror("fstat() failed");
		close(fd);
		_exit(2);
	}
	sleep(1);
	printf("reading file of size: %lu\n",st.st_size);

	src = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if(src == (void*)-1) {
		perror("mmap() failed");
		close(fd);
		_exit(3);
	}
	
	fd1 = open("/home/poonam/MMAP.txt", O_CREAT | O_RDWR, 0777);
      if(fd1 < 0) {
          perror("open() failed");
          _exit(1);
      }

	ftruncate( fd1, st.st_size);

	des = mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd1, 0);
      if(des == (void*)-1) {
          perror("mmap() failed");
          close(fd1);
          _exit(3);
      }

	//p1 =(int *)memcpy("/home/poonam/MMAP.txt", "/home/poonam/data.txt", st.st_size);
	memcpy(des, src, st.st_size);
	// stdout=1
	write(1, des, st.st_size);

	close(fd);
	close(fd1);
	return 0;
}


