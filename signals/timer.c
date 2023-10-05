#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

volatile int alarm_count = 0;
time_t start_time;

void alarm_handler(int signum)
{
    alarm_count++;
    printf("Hello World!\n");
    alarm(1); // Schedule the next SIGALRM for 1 second
}

void ctrl_c_handler(int signum)
{
    time_t end_time = time(NULL);
    double execution_time = difftime(end_time, start_time);
    printf("\nTotal alarms: %d\n", alarm_count);
    printf("Execution time: %.2lf seconds\n", execution_time);
    exit(0);
}

int main(int argc, char *argv[])
{
  signal(SIGALRM, alarm_handler);
  signal(SIGINT, ctrl_c_handler);

  start_time = time(NULL);

  alarm(1); // Schedule the initial SIGALRM for 1 second
  
  while (1) {
    pause(); // Wait for a signal to be delivered
    printf("Turing was right!\n"); // Print the additional message
  }
  
  return 0;
}

