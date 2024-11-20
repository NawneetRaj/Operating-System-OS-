#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("example.txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    const char *text = "Hello, this is a test.\n";
    if (write(fd, text, 23) < 0) {
        perror("Failed to write to file");
        close(fd);
        return 1;
    }

    lseek(fd, 0, SEEK_SET);

    char buffer[50];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead < 0) {
        perror("Failed to read from file");
        close(fd);
        return 1;
    }
    buffer[bytesRead] = '\0';

    printf("Read from file: %s", buffer);
    close(fd);

    return 0;
}
