#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum)
{
  printf("Hello World!\n");
  alarm(1); // Schedule the next SIGALRM for 1 second
}

int main(int argc, char *argv[])
{
  signal(SIGALRM, handler); // Register handler to handle SIGALRM
  alarm(1); // Schedule the initial SIGALRM for 1 second
  
  while (1) {
    pause(); // Wait for a signal to be delivered
    printf("Turing was right!\n"); // Print the additional message
  }
  
  return 0;
}
