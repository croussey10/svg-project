#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
        
    char *colorArray[10];
    char choseColor[10];
    char delete[10];
    int valueDelete = 0;

    for (int i = 0; i < 3; i++)
    {   
        printf("Choisr une couleur : ");
        scanf("%9s", choseColor);
        printf("Vous avez chois la couleur : %s \n", choseColor);

        colorArray[i] = malloc(strlen(choseColor) + 1);
        //colorArray[i] = choseColor;

        strcpy(colorArray[i], choseColor);
    }

    printf("%s\n", colorArray[0]);
    printf("%s\n", colorArray[1]);
    printf("%s\n", colorArray[2]);

    printf("Voulez vous supprimez une couleur ? ");
    scanf("%9s", delete);
    if (strcmp(delete, "oui") == 0)
    {
        printf("Quelle valeur du tableau voulez vous supprimer ? ");
        scanf("%d", &valueDelete);
        colorArray[valueDelete] = NULL;
    }

    printf("%s\n", colorArray[0]);
    printf("%s\n", colorArray[1]);
    printf("%s\n", colorArray[2]);

    size_t nb_elem  = sizeof colorArray / sizeof *colorArray;
    printf ("nb_elem = %lu\n", (unsigned long) nb_elem);
    
    return 0;
}