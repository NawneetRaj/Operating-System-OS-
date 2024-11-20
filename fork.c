#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

int main() {
    pid_t pid = getpid();
    pid_t ppid = getppid();

    printf("Current Process ID: %d\n", pid);
    printf("Parent Process ID: %d\n", ppid);

    const char *dirPath = ".";
    DIR *dir = opendir(dirPath);

    if (dir == NULL) {
        perror("opendir failed");
        exit(EXIT_FAILURE);
    }

    printf("\nContents of directory '%s':\n", dirPath);
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("  %s\n", entry->d_name);
    }

    if (closedir(dir) == -1) {
        perror("closedir failed");
        exit(EXIT_FAILURE);
    }

    pid_t child_pid = fork();
    if (child_pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        printf("\n[Child] This is the child process. PID: %d, PPID: %d\n", getpid(), getppid());
    } else {
        printf("[Parent] This is the parent process. PID: %d, Child PID: %d\n", getpid(), child_pid);
    }

    return 0;
}
