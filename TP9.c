#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

/* Signal Handler for SIGINT */
void sigHandler(int sig_num)
{
  sigset_t set;

  sigemptyset(&set);
  sigaddset(&set, SIGINT);
  sigprocmask(SIG_UNBLOCK, &set, NULL);
}

int main(int argc, char ** argv)
{

  sigset_t set;
  sigaddset(&set, SIGINT);
  sigprocmask(SIG_BLOCK, &set, NULL);

  signal(SIGTSTP, sigHandler);

  // Infinite Loop
  while(1)
  {
  }

	return 0;
}
