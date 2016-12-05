#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

struct etudiant {
  char nom[20];
  int age;
  int id_ecole;
};

int main(int argc, char ** argv)
{
	/* TP3_ex1 */
  // Lecture de la string
  char str[80];
  int i;

  printf("Enter a string: ");
  fgets(str, 10, stdin);

  i = strlen(str)-1;
  if( str[ i ] == '\n')
      str[i] = '\0';

  printf("This is your string: %s", str);

  // Ecriture de la string dans le fichier
  FILE *fp;
  fp=fopen("tp3file.txt", "w"); // Ouverture du fichier

  if (fp != NULL)
  {
      fputs(str, fp); // Ecriture des données
      fclose(fp); // Fermeture du fichier
  }

  // --------------------------------------------------------------

  /* TP3_ex2 */
  FILE* fp2;
  struct etudiant etu[3]; // Déclaration de trois structures

  int i;
  size_t nblus;
  fp=fopen("etudiantbinaire", "w+");

  for (i = 0; i < 3; i++) {
    printf("Nom : ");
    scanf("%s\n", &etu[i].nom); // FAIRE DES FGETS A LA PLACE

    printf("Age : ");
    scanf("%s\n", &etu[i].age); // FAIRE DES FGETS A LA PLACE


    printf("ID de l'école : ");
    scanf("%s\n", &etu[i].id_ecole); // FAIRE DES FGETS A LA PLACE
  }

  nblus=fwrite(etu, size_of(struct etudiant), 3, fp);
  if (nblus < 3) {
    printf("Erreur ou fin de fichier atteinte.\n");
    exit(-1);
  }



  // Lecture
  FILE* fp3;
  struct etudiant et;

  int j;
  size_t nblus2;

  fp = fopen("etudiantbinaire", "r");
  while ((nbluse=fread(&etu, size_of(struct etudiant), 1, fp)) == 1) {
    printf("Nom : %s\n", etu.nom);
    printf("Age : %s\n", etu.age);
    printf("ID de l'école : %s\n", etu.id_ecole);
  }

	return 0;
}
