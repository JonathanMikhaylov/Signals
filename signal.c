#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

static void sighandler(int signo){
  if (signo == SIGINT){
    int f = open("signals",O_CREAT|O_WRONLY|O_APPEND,0644);
    printf("SIGINT Caught: Exiting");
    write(f, "exited\n", 8);
    close(f);
    exit(0);
  }
  if (signo == SIGUSR1){
    printf("PPID: %d\n\n", getppid());
  }
}

int main(){
  signal(SIGINT,sighandler);
  signal(SIGUSR1,sighandler);
  
  while(1){
    printf("PID: %d\n", getpid());
    sleep(1);    
  }
  return 0;
}
