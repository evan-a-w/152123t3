#include <stdlib.h>
#include <stdio.h>

#include <spawn.h>
#include <sys/wait.h>

extern char **environ;

int main(int argc, char **argv) {
    char *date_argv[3];
    date_argv[0] = "/usr/bin/date";
    date_argv[1] = "+%d-%m-%Y";
    date_argv[2] = NULL;

    // stdin  == fd 0
    // stdout == fd 1
    // stderr == fd 2

    // to capture output of posix_spawn, set fd 1 to be a different file

    pid_t pid;
    if (posix_spawn(&pid, date_argv[0], NULL, NULL, date_argv, environ) != 0) {
        perror("spawn");
        exit(1);
    }

    int exit_status;
    if (waitpid(pid, &exit_status, 0) == -1) {
        perror("waitpid");
        exit(1);
    }

    printf("DONE\n");
}
