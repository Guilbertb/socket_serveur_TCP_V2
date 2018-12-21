/* Serveur en TCP simple */
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <unistd.h>

#define PORT 9002

int main(int argc, char ** argv)
{

    char server_message[256] = "Voila notre message du server !";
    int server_socket;
    int client_socket;

    /* creation de la socket */

    server_socket= socket( AF_INET, SOCK_STREAM, 0);

    struct  sockaddr_in  server_address;

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons (PORT); /* format pour */
    server_address.sin_addr.s_addr = INADDR_ANY;

    /*bind */
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    /* listen */
    listen (server_socket, 5); /* backlog */

    client_socket = accept (server_socket, NULL, NULL );


    /* envoi du message  */

    send(client_socket, server_message, sizeof(server_message), 0);


    close(server_socket);


    return EXIT_SUCCESS;
}
