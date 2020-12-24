#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){

	//create a socket
	int net_socket;
	net_socket = socket(AF_INET, SOCK_STREAM, 0);

	//specify an address for socket 
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	int connection_stat = connect(net_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	//checks if error
	if (connection_stat == -1){
		printf("There was a error in the connection \n\n");
	
	}
	
	//recive data from server
	char server_response[256];
	recv(net_socket, &server_response, sizeof(server_response), 0);

	//we are going to print the data
	printf("The server data: %S\n", server_response);


	return 0;
}
