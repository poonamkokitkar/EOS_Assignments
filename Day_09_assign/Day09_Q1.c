#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

//  Q1.1. Input signal number and a process id from user. Send given signal to the given process using kill() syscall.


int kill_process(pid_t pid, int sig_num){
	int res;
	res = kill(pid, sig_num);

	if(res==0)
		printf("successfull execution\n");
	else
		printf("failed\n");
}

int main(){
	int pid, sig_num;
	printf("Enter pid and signal number\n");
	scanf("%d %d",&pid, &sig_num);
	kill_process(pid,sig_num);
	return 0;
}
