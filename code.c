#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int choice;
    pid_t pid;

    printf("\n===== Linux Process Resource Monitoring System =====\n");
    printf("1. Linux Information\n");
    printf("2. CPU Information\n");
    printf("3. Storage Information\n");
    printf("4. Running Processes\n");
    printf("5. System Activity\n");
    printf("6. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 6)
    {
        printf("Program Ended.\n");
        return 0;
    }  pid = fork();

    if(pid == 0)
    {
        printf("\nChild Process\n");
        printf("Child PID : %d\n", getpid());
        printf("Parent PID: %d\n\n", getppid());

        if(choice == 1)
            execlp("uname", "uname", "-a", NULL);

        else if(choice == 2)
            execlp("lscpu", "lscpu", NULL);

        else if(choice == 3)
            execlp("lsblk", "lsblk", NULL);

        else if(choice == 4)
            execlp("ps", "ps", NULL);

        else if(choice == 5)
            execlp("top", "top", NULL);

        else
            printf("Invalid Choice\n");
    }
    else
    {
        printf("\nParent Process\n");
        printf("Parent PID : %d\n", getpid());

        wait(NULL);

        printf("\nChild Process Completed.\n");
    }

    return 0;
}
