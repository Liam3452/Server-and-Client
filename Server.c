#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main(){

	char server_ms[256] = " Hi this is my Server";
	
	//create the server socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	//define the server address	
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;

	//bind the socket to our specified IP and port
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

	listen(server_socket, 5);

	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);
	
	//send the message
	send(client_socket, server_ms, sizeof(server_ms), 0);

	return 0;
}
