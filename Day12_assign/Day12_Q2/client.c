#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/un.h>
// client

#define SOCKET_PATH "/home/poonam/Desktop/12_pra/desd_client"

int main() {
	int cli_fd, ret,sum, num1, num2;
	struct sockaddr_un serv_addr;
	char sun_path[102];
	cli_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(cli_fd < 0) {
		perror("socket() failed");
		_exit(1);
	}

	serv_addr.sun_family = AF_UNIX;
	strcpy(serv_addr.sun_path, SOCKET_PATH);
	//serv_addr.sin_port = htons(SERV_PORT);
//	inet_aton(SERV_IP, &serv_addr.sin_addr);
	ret = connect(cli_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	if(ret < 0) {
		perror("connect() failed");
		_exit(2);
	}
		printf("enter two numbers:\n");
		scanf("%d %d",&num1,&num2);
		write(cli_fd, &num1, sizeof(num1));
		write(cli_fd, &num2, sizeof(num2));


	    read(cli_fd, &sum, sizeof(sum));
		printf("the addition is %d\n",sum);

/*
	do {
		printf("client: ");
		gets(str);
		write(cli_fd, str, strlen(str)+1);

		read(cli_fd, str, sizeof(str));
		printf("server: %s\n", str);
	}while(strcmp(str, "bye")!=0);
*/
	close(cli_fd);
	return 0;
}
