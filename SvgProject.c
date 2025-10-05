#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
        FILE* my_file = fopen("test.svg", "w");

        int i = 0;
        bool addForme = true;
        char WantOtherForme[5] = "A";

        int sizeViewportStartX = 0;
        int sizeViewportEndX = 0;
        int sizeViewportStartY = 0;
        int sizeViewportEndY = 0;
    
        printf("Rentrer la dimension du tableau\n");
        printf("X de depart : \n");
        scanf("%d", &sizeViewportStartX);
        printf("X de fin : \n");
        scanf("%d", &sizeViewportEndX);
        printf("Y de depart : \n");
        scanf("%d", &sizeViewportStartY);
        printf("Y de fin : \n");
        scanf("%d", &sizeViewportEndY);

        char formeChose[1000] = "";
        char sizeViewport[1000];
        sprintf(sizeViewport, "<svg viewBox='%d %d %d %d' xmlns='http://www.w3.org/2000/svg'>\n", sizeViewportStartX, sizeViewportStartY, sizeViewportEndX, sizeViewportEndY);
        strcpy(formeChose, sizeViewport);

        char formeToDraw[10000] = "";

        while (i < 10)
        {
            if (addForme == true) {

                typedef enum forme_e {
                    INCONNUE = 0,
                    CERCLE,
                    RECTANGLE,
                    CARRE
                } forme_et;

                forme_et activeForme;
                activeForme = RECTANGLE;
                char forme[20] = "A";

                printf("Quelle forme voulez vous dessinez ? : ");
                scanf("%s",&forme);
                printf("%s\n", forme);

                if (strcmp(forme, "cercle") == 0) {
                    activeForme = CERCLE;
                } else if (strcmp(forme, "rectangle") == 0) {
                    activeForme = RECTANGLE;
                } else if (strcmp(forme, "carre") == 0) {
                    activeForme = CARRE;
                } else {
                    activeForme = INCONNUE;
                }

                printf("%d\n", activeForme);

                int positionX = 0;
                int positionY = 0;
                //char formeChose[1000] = "A";

                switch (activeForme)
                {
                case CERCLE:
                    printf("A quelle position X, Y voulez vous dessinez votre cercle ?\n");
                    //scanf("Position X : %d, Position Y : %d", &positionX, &positionY);
                    scanf("%d %d", &positionX, &positionY);
                    printf("%d, %d\n", positionX, positionY);
                    printf("Vous avez dessinez un cercle !\n");
                    char cercle[1000];
                    sprintf(cercle, "  <circle cx='%d' cy='%d' r='50' fill='green' /> \n", positionX, positionY);
                    //strcpy(formeChose, cercle);
                    strcat(formeChose, cercle);
                    break;
                case RECTANGLE:
                    printf("A quelle position X, Y voulez vous dessinez votre rectangle ?\n");
                    scanf("%d %d", &positionX, &positionY);
                    printf("%d, %d\n", positionX, positionY);
                    printf("Vous avez dessinez un rectangle !\n");
                    char rectangle[1000];
                    sprintf(rectangle, "  <rect x='%d' y='%d' width='100' height='100' /> \n", positionX, positionY);
                    strcat(formeChose, rectangle);
                    break;
                case CARRE:
                    printf("Vous avez dessinez un carre !\n");
                    break;
                
                default:
                    printf("Faites une forme valide !\n");
                    break;
                }

                strcpy(formeChose, formeChose);
                printf("%s", formeChose);
                strcpy(formeToDraw, formeChose);


                printf("Voulez vous ajoutez une autre forme ? ");
                scanf("%s", &WantOtherForme);

                if (strcmp(WantOtherForme, "oui") == 0)
                {
                    addForme = true;
                } else {
                    addForme = false;
                    strcat(formeToDraw, "</svg>");
                    //printf("%s", formeToDraw);
                    fprintf(my_file, formeToDraw);
                    fclose(my_file);
                    break;
                }
            } else {
                break;
            }
        }
    return 0;
}