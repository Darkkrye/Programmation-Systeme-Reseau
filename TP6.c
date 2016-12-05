#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char ** argv)
{
  // Générer une valeur random
  srand(time(NULL) + getpid());
  int valeur = rand()%30;

	return 0;
}
