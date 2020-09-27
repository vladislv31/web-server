#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <string.h>


int main()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0) {
        perror("cant create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address = {0};
    int addrlen = sizeof(address);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(8888);

    int server_bind = bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    if (server_bind < 0) {
        perror("cant bind socket");
        exit(EXIT_FAILURE);
    }

    int server_listen = listen(server_fd, 10);

    if (server_listen < 0) {
        perror("listen error");
        exit(EXIT_FAILURE);
    }

    int new_socket;
    int valread;
    char *resp = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";

    while (1 == 1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }

        char buffer[3000] = {0};
        valread = read(new_socket, buffer, 3000);
        printf("%s\n", buffer);
        write(new_socket, resp, strlen(resp));
        close(new_socket);
    }

    return 0;
}










