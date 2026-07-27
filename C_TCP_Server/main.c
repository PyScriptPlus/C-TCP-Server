#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 2525
#define MAX 1024

void receiveCl(int *sockClient) {

	char buff[MAX];
	int bytes = recv(*sockClient, buff, sizeof(buff) - 1, 0);
	if(bytes > 0)
	{
		buff[bytes] = '\0';
	}
	printf("Client message: %s", buff);
	return;
}


int main() {

	int sockfd;
	struct sockaddr_in servaddr, client;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		// printf("Creation failed!\n");
		perror("Creation failed!");
		return -1;
	}

	// Sets all values inside the structure to 0
	memset(&servaddr, 0, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	if(bind(sockfd, (struct sockaddr*)&servaddr, 
		sizeof(servaddr)) < 0)
	{
		perror("bind failed!");
		return -1;
	}

	int backlog = 10;
	if(listen(sockfd, backlog) < 0)
	{
		perror("Listen failed!");
		return -1;
	}

	memset(&client, 0, sizeof(client));
	
	socklen_t lenClient = sizeof(client);
	int sockClient = accept(sockfd, (struct sockaddr*)&client, &lenClient);
	if(sockClient < 0)
	{
		perror("Accept client failed!");
		return -1;
	}

	receiveCl(&sockClient);

	return 0;
}
