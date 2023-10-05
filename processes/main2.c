#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define MAX_ITERATIONS 30
#define MAX_SLEEP_SECONDS 10

void childProcess(int childNum) {
    srand(time(NULL) + childNum);
    
    int i;
    for (i = 1; i <= MAX_ITERATIONS; i++) {
        printf("Child Pid: %d is going to sleep!\n", getpid());
        sleep(rand() % MAX_SLEEP_SECONDS + 1);
        printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", getpid(), getppid());
    }

    printf("Child Pid: %d has completed\n", getpid());
    exit(0);
}

int main() {
    pid_t child1, child2;
    int status1, status2;

    child1 = fork();

    if (child1 == 0) {
        // First child process
        childProcess(1);
    } else {
        child2 = fork();

        if (child2 == 0) {
            // Second child process
            childProcess(2);
        } else {
            // Parent process
            waitpid(child1, &status1, 0);
            waitpid(child2, &status2, 0);

            printf("Parent process has completed\n");
        }
    }

    return 0;
}
