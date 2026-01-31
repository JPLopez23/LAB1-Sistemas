#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 3) return 1;
    int fd_origen = open(argv[1], O_RDONLY);
    int fd_destino = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char buffer[1024];
    int bytes;

    while ((bytes = read(fd_origen, buffer, 1024)) > 0) {
        write(fd_destino, buffer, bytes);
    }

    close(fd_origen);
    close(fd_destino);
    return 0;
}