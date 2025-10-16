#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shapes.h"

int main()
{   

    FILE* my_file = fopen("file.svg", "w");
    fprintf(my_file, "<svg viewBox='0 0 100 100' xmlns='http://www.w3.org/2000/svg'>\n");

    List* head;
    head = NULL;
    int count = 1;

    for (int j = 0; j < 3; j++)
    {   
        char shapeChoose[100];

        printf("Quelle forme voulez vous dessinez ? ");
        scanf("%s", shapeChoose);

        if (strcmp(shapeChoose, "cercle") == 0) {
            head = create_and_insert_circle(head, j);
        } else if (strcmp(shapeChoose, "ellipse") == 0) {
            head = create_and_insert_ellipse(head, j);
        } else if (strcmp(shapeChoose, "carre") == 0) {
            head = create_and_insert_carre(head, j);
        } else if (strcmp(shapeChoose, "rectangle") == 0) {
            head = create_and_insert_rectangle(head, j);
        } else if (strcmp(shapeChoose, "ligne") == 0) {
            head = create_and_insert_line(head, j);
        } else if (strcmp(shapeChoose, "polyligne") == 0) {
            head = create_and_insert_polyline(head, j);
        } else if (strcmp(shapeChoose, "polygone") == 0) {
            head = create_and_insert_polygone(head, j);
        } 
        else {
            printf("Forme non valide\n");
            j--;
        }

        //print_list(head);
        count++;
    }

    List* current = head;
    while (current != NULL) {
        generate_svg_line(current, my_file); 
        current = current->next;
    }

    fprintf(my_file, "</svg>");
    fclose(my_file);
    return 0;
}
 