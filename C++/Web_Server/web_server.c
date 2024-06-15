// Code for minimalist web server in C
//
#include <sys/socket.h>
#include <string.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <unistd.h>
#include <netinet/in.h>

void main() {
        int s = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in addr = {
                AF_INET,
                0x901f,
                0
        };
        bind(s, &addr, sizeof(addr));
        listen(s, 10);
        int client_fd = accept(s, 0, 0);
        char buffer[256] = {0};
        recv(client_fd, buffer, 256, 0);

        // GET /file.html .... so you can skip the first 5 spaces in order to get to the file
        char* f = buffer + 5;
        *strchr(f, ' ') = 0; // just find the spaces, turns it to a \0 so now it looks like file.html\0 so we just get the file name
        int opened_fd = open(f, O_RDONLY); // The actual file on the file system
        // send to the client socket with sendfile
        sendfile(client_fd, opened_fd, 0, 256);
        close(opened_fd);
        close(client_fd);
}
