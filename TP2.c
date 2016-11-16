#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char ** argv)
{
	int fd1, fd2;
	charc;
	off_t pos;

	fd1 = open("to_revert.txt", O_RDONLY);
	fd2 = open("reverted.txt", O_WRONLY|OCREAT, 0666);

	pos=lseek(fd1, -1, SEEK_END);

	while(pos >= 0) {
		read(fd1, &c, 1);
		write(fd2, &c, 1);
		pos=lseek(fd1, -2, SEEK_CUR);
	}

	return 0;
}