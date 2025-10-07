#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
        FILE* my_file = fopen("test.svg", "w");

        bool addForme = true;
        char WantOtherForme[5] = "";

        int sizeViewportStartX = 0;
        int sizeViewportEndX = 1000;
        int sizeViewportStartY = 0;
        int sizeViewportEndY = 1000;
        
    
        /*printf("Rentrer la dimension du tableau\n");
        printf("[X] de depart : \n");
        scanf("%d", &sizeViewportStartX);
        printf("[X] de fin : \n");
        scanf("%d", &sizeViewportEndX);
        printf("[Y] de depart : \n");
        scanf("%d", &sizeViewportStartY);
        printf("[Y] de fin : \n");
        scanf("%d", &sizeViewportEndY);*/

        char formeChoose[1000] = "";
        char sizeViewport[1000];
        sprintf(sizeViewport, "<svg viewBox='%d %d %d %d' xmlns='http://www.w3.org/2000/svg'>\n", sizeViewportStartX, sizeViewportStartY, sizeViewportEndX, sizeViewportEndY);
        //strcpy(formeChoose, sizeViewport);

        char formeToDraw[10000] = "";
        strcpy(formeToDraw, sizeViewport);
        char color[20] = "";
        int i = 0;

        char * arrayForme[10] = {NULL};

        while (i < 10)
        {
            if (addForme == true) {

                typedef enum forme_e {
                    INCONNUE = 0,
                    CERCLE,
                    RECTANGLE,
                    TRIANGLE
                } forme_et;

                forme_et activeForme;
                char forme[20] = "";

                printf("Quelle [FORME] voulez vous dessinez ? : ");
                scanf("%19s",forme);
                printf("%s\n", forme);

                if (strcmp(forme, "cercle") == 0) {
                    activeForme = CERCLE;
                } else if (strcmp(forme, "rectangle") == 0) {
                    activeForme = RECTANGLE;
                } else if (strcmp(forme, "triangle") == 0) {
                    activeForme = TRIANGLE;
                } else {
                    activeForme = INCONNUE;
                }

                printf("%d\n", activeForme);

                int positionX = 0;
                int positionY = 0;

                printf("A quelle position [X], [Y] voulez vous dessinez votre %s ?\n", forme);
                //scanf("Position X : %d, Position Y : %d", &positionX, &positionY);
                scanf("%d %d", &positionX, &positionY);
                printf("%d, %d\n", positionX, positionY);
                printf("Choisissez une [COULEUR] : \n");
                scanf("%19s", color);
                printf("Vous avez choisi la couleur '%s'\n", color);

                switch (activeForme)
                {
                case CERCLE:
                    int rayon = 0;
                    printf("Choisissez le [RAYON] de votre cercle : ");
                    scanf("%d", &rayon);
                    char cercle[1000];
                    sprintf(cercle, "  <circle cx='%d' cy='%d' r='%d' fill='%s' /> \n", positionX, positionY, rayon, color);
                    //strcat(formeChoose, cercle);
                    strcpy(formeChoose, cercle);
                    arrayForme[i] = malloc(strlen(formeChoose) + 1);
                    strcpy(arrayForme[i], formeChoose);
                    break;
                case RECTANGLE:
                    int width = 0;
                    int height = 0;
                    printf("Choisissez la [LARGEUR] et la [HAUTEUR] de votre rectangle : ");
                    scanf("%d %d", &width, &height);
                    char rectangle[1000];
                    sprintf(rectangle, "  <rect x='%d' y='%d' width='%d' height='%d' fill='%s' /> \n", positionX, positionY, width, height, color);
                    strcpy(formeChoose, rectangle);
                    arrayForme[i] = malloc(strlen(formeChoose) + 1);
                    strcpy(arrayForme[i], formeChoose);
                    break;
                case TRIANGLE:
                    double scale = 0;
                    printf("Chosissez le [SCALE] de votre triangle : ");
                    scanf("%lf", &scale);
                    char triangle[1000];
                    printf("%d %d", positionX, positionY);
                    sprintf(triangle, "  <polygon points='%lf,%lf %lf,%lf %lf,%lf' style='fill:%s' /> \n", scale * 1 + positionX, 0 + (double)positionY, 0 + (double)positionX, scale * 1.5 + positionY, scale * 2 + positionX, scale * 1.5 + positionY, color);
                    strcpy(formeChoose, triangle);
                    arrayForme[i] = malloc(strlen(formeChoose) + 1);
                    strcpy(arrayForme[i], formeChoose);
                    break;
                
                default:
                    printf("Faites une forme valide !\n");
                    break;
                }

                printf("Vous avez dessinez un %s !\n", forme);

                printf("%s", formeChoose);

                printf("Voulez vous ajoutez une autre forme [OUI/NON] ? ");
                scanf("%4s", WantOtherForme);

                int formeSupp = 0;

                if (strcmp(WantOtherForme, "oui") == 0)
                {   
                    addForme = true;
                } else if (strcmp(WantOtherForme, "non") == 0) {
                    addForme = false;

                    int j = 0;
                    while (j < 10)
                    {
                        printf("%s", arrayForme[j]);
                        if (arrayForme[j] != NULL) {
                            strcat(formeToDraw, arrayForme[j]);
                        }
                        j++;
                    }
                    
                    strcat(formeToDraw, "</svg>");
                    fprintf(my_file, formeToDraw);
                    fclose(my_file);
                    break;
                } else if (strcmp(WantOtherForme, "supp") == 0) {
                    printf("Quelle forme voulez vous supp ? ");
                    scanf("%d", &formeSupp);
                    arrayForme[formeSupp] = NULL;
                    char otherForme[5] = "";

                    printf("Voulez vous ajoutez d'autres formes ? ");
                    scanf("%s", &otherForme);
                    if (strcmp(otherForme, "non") == 0) {
                        int j = 0;
                        while (j < 10)
                        {
                            printf("%s", arrayForme[j]);
                            if (arrayForme[j] != NULL) {
                                strcat(formeToDraw, arrayForme[j]);
                            }
                            j++;
                        }
                        strcat(formeToDraw, "</svg>");
                        fprintf(my_file, formeToDraw);
                        fclose(my_file);
                        break;
                        }
                }
                
            } else {
                break;
            }
            i++;
        }
    return 0;
}