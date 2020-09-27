#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <errno.h>


int main()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0) {
        perror("cant create socket");
        exit(EXIT_FAILURE);
    }

    

    return 0;
}
