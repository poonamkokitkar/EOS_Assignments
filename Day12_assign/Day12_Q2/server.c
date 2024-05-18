#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define SOCKET_PATH "/home/poonam/Desktop/12_pra/desd_client"

int main(){
	int serv_fd,sum,num1,num2, cli_fd, ret;
	struct sockaddr_un serv_addr, cli_addr;
	socklen_t socklen;
	char sun_path[102];
	serv_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(serv_fd < 0){
		perror("socket() failed");
		_exit(0);
	}

	serv_addr.sun_family = AF_UNIX;
	strcpy(serv_addr.sun_path, SOCKET_PATH);
	
//	inet_aton(SERV_IP, &serv_addr.sun_addr);
	ret = bind(serv_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	if(ret < 0) {
		perror("bind() failed");
		_exit(2);
	}

	listen(serv_fd, 5);
while(1){
	socklen = sizeof(cli_addr);
	cli_fd = accept(serv_fd, (struct sockaddr*)&cli_addr, &socklen);
	if(cli_fd < 0) {
		perror("accept() failed");
		_exit(3);
	}
		read(cli_fd, &num1, sizeof(num1));
		read(cli_fd, &num2, sizeof(num2));
		sum = num1 + num2;
		write(cli_fd, &sum, sizeof(sum));
	}
/*
	do {
		read(cli_fd, str, sizeof(str));
		printf("client: %s\n", str);

		printf("server: ");
		gets(str);
		write(cli_fd, str, strlen(str)+1);
	}while(strcmp(str, "bye")!=0);
*/
	close(cli_fd);

	shutdown(serv_fd, SHUT_RDWR);
	return 0;
}
