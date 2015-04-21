#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid, pid1;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork Failed\n\r");
        return 1;
    }
    else if (pid == 0) {
        pid1 = getpid();
        printf("child: pid = %d\n\r",pid);
        printf("child: pid1 = %d\n\r",pid1);
    }
    else {
        pid1 = getpid();
        printf("parent: pid = %d\n\r",pid);
        printf("parent: pid1 = %d\n\r",pid1);
        wait(NULL);
    }

    return 0;
}
