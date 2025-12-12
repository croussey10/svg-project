#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shapes.h"
#include "menu.h"

int main()
{   

    FILE* my_file = fopen("file.svg", "w");
    char* sizeViewport = Make_Viewport();
    fprintf(my_file, sizeViewport);
    free(sizeViewport);

    ListSvg_st* head;
    head = NULL;
    int count = 1;

    for (int j = 0; j < count; j++)
    {   

        char addShape[4];
        printf("Voulez vous ajoutez une forme ?\n");
        scanf("%s", addShape);

        if (strcmp(addShape, "oui") == 0) {
            char shapeChoose[100];
            printf("Quelle forme voulez vous dessinez ? ");
            scanf("%s", shapeChoose);

            if (strcmp(shapeChoose, "cercle") == 0) {
                head = create_and_insert_circle(head);
            } else if (strcmp(shapeChoose, "ellipse") == 0) {
                head = create_and_insert_ellipse(head);
            } else if (strcmp(shapeChoose, "carre") == 0) {
                head = create_and_insert_carre(head);
            } else if (strcmp(shapeChoose, "rectangle") == 0) {
                head = create_and_insert_rectangle(head);
            } else if (strcmp(shapeChoose, "ligne") == 0) {
                head = create_and_insert_line(head);
            } else if (strcmp(shapeChoose, "polyligne") == 0) {
                head = create_and_insert_polyline(head);
            } else if (strcmp(shapeChoose, "polygone") == 0) {
                head = create_and_insert_polygone(head);
            } 
            else {
                printf("Forme non valide\n");
                j--;
            }
            count++;
        } else if (strcmp(addShape, "non") == 0) {
            break;
        } else {
            printf("Veuillez repondre par 'oui' ou 'non' !\n");
            j--;
        }
    }

    while (head != NULL) {
        generate_svg(head, my_file);
        head = head->next;
    }

    free_list(head);

    fprintf(my_file, "</svg>");
    fclose(my_file);
    return EXIT_SUCCESS;
}
 