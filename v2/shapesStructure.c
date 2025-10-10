#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shapesStructure.h"
#include "interface.h"

sizeVewport_st* CreateViewport(int a, int b, int c, int d) {
    sizeVewport_st* viewport_pointeur = malloc(sizeof(sizeVewport_st));
    viewport_pointeur->startX = a;
    viewport_pointeur->endX = b;
    viewport_pointeur->startY = c;
    viewport_pointeur->endY = d;
    return viewport_pointeur;
}

circle_st* CreateCircle(int a, int b, int c) {
    circle_st* circle_pointeur = malloc(sizeof(circle_st));
    circle_pointeur->positionX = a;
    circle_pointeur->positionY = b;
    circle_pointeur->rayon = c;
    return circle_pointeur;
}

rectangle_st* CreateRectangle(int a, int b, int c, int d) {
    rectangle_st* rectangle_pointeur = malloc(sizeof(rectangle_st));
    rectangle_pointeur->positionX = a;
    rectangle_pointeur->positionY = b;
    rectangle_pointeur->width = c;
    rectangle_pointeur->height = d;
    return rectangle_pointeur;
}

line_st* CreateLine(int a, int b, int c, int d) {
    line_st* line_pointeur = malloc(sizeof(line_st));
    line_pointeur->startX = a;
    line_pointeur->endX = b;
    line_pointeur->startY = c;
    line_pointeur->endY = d;
    return line_pointeur;
}

void main()
{   
   
    //printf("La valeur de 'nombre' est : %d", nombre);

    sizeVewport_st* test = CreateViewport(
        ask_for_int("Rentrez un nombre"),
        ask_for_int("Rentrez un nombre"), 
        ask_for_int("Rentrez un nombre"), 
        ask_for_int("Rentrez un nombre"));
    printf("%d\n", test->startX);
    printf("%d\n", test->endX);
    printf("%d\n", test->startY);
    printf("%d\n", test->endY);

}
