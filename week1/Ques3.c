#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
    }
    else if (pid == 0)
    {
        printf("Child process\n");
        execlp("ls", "ls", "-l", NULL);
        exit(1);
    }
    else
    {
        wait(NULL);
        printf("Parent process: child finished.\n");
    }

    return 0;
}
