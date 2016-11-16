#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/*int main(int argc, char** argv) {
	printf("Hello, World !\n");
	return 0;
}


// TP1_ex1 :
int main(int argc, char** argv) {
	int fd = open("text.txt", O_WRONLY, 0666);
	char tmp = 'A';
	write(fd, &tmp, sizeof(tmp));

	int fd2 = open("text.txt", O_WRONLY, 0666);
	char tmp2[1];
	read(fd2, tmp2, sizeof(char));

	printf("%s\n", tmp2);

	return 0;
}*/

// TP1_ex2 :
void clean_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int main(int argc, char** argv) {
	int fd, nbecrits, i;
	char lettres[6];
	fd=open("my_first_tab", O_RDWR | O_CREAT, 0666);

	if (fd < 0)
	{
		printf("Erreur d'ouverture\n");
		return -1;
	}

	for (int i = 0; i < 6; i++)
	{
		printf("\nEntre la lettre numéro %d/6 : ", i+1);
		scanf("%c", &lettres[i]);
		clean_buffer();
	}

	nbecrits=write(fd, lettres, 6*sizeof(char)); // Ici lettres est l'adresse du tableau de lettres
	
	if (nbecrits < 0)
	{
		printf("Erreur d'écriture\n");
		return -1;
	} else if (nbecrits < sizeof(char))
	{
		printf("Disque plein\n");
	}
}