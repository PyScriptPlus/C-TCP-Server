#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 2525

int main() {

	int sockfd;
	struct sockaddr_in servaddr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		// printf("Creation failed!\n");
		perror("Creation failed!\n");
		return -1;
	}

	// Sets all values inside the structure to 0
	memset(&servaddr, 0, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	if(bind(sockfd, (const struct sockaddr*)&servaddr, 
		sizeof(servaddr)) < 0)
	{
		perror("bind failed\n!");
	}

	return 0;
}
