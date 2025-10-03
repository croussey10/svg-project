#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
        FILE* my_file = fopen("test.svg", "w");

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

        char cerle[1000];
        sprintf(cerle, "<svg viewBox='%d %d %d %d' xmlns='http://www.w3.org/2000/svg'>\n  <circle cx='100' cy='100' r='50' fill='green' /> \n</svg>", sizeViewportStartX, sizeViewportStartY, sizeViewportEndX, sizeViewportEndY);
        char rectangle[1000];
        sprintf(rectangle, "<svg viewBox='%d %d %d %d' xmlns='http://www.w3.org/2000/svg'>\n  <rect x='0' y='0' width='100' height='100' /> \n</svg>", sizeViewportStartX, sizeViewportStartY, sizeViewportEndX, sizeViewportEndY);

        printf("%s", cerle);
        
        if (fprintf(my_file, cerle) < 0)
            printf("BOGOSS");

        fclose(my_file);

    return 0;
}