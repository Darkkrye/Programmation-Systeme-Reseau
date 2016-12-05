#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char ** argv)
{
  pid_t n;
  int i = 5;

  printf("Bonjour\n");

  n = fork();
  if (n == 0) {
    printf("Je suis le fils : pid=%d , mon père est pid=%d\n", getpid(), getppid());
    i = 10;
    printf("Fils : pour moi i=%d\n", i);
  } else if (n > 0) {
    printf("Je suis le père : pid=%d , mon fils est pid=%d\n", getpid(), n);
    printf("Père : pour moi i=%d\n", i);
  } else {
    printf("Erreur fork.\n");
    exit(-1);
  }

  printf("-------\n");

	return 0;
}
