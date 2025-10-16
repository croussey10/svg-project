#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shapes.h"

int ask_for_int(char* message) {
    int value = 0;
    printf("%s", message);
    scanf("%d", &value);
    return value;
}

List* makeNewNode(List* head, shapesType_en type, shapesData_un data) {
    List* new_node = malloc(sizeof(List));
    new_node->type = type;
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

Point* makeNewPoint(Point* head, int x, int y) {
    Point* new_point = malloc(sizeof(Point));
    new_point->x = x;
    new_point->y = y;
    new_point->next = head;
    return new_point;
}

void generate_svg_line(List* node, FILE* file) {
    if (node == NULL) return;

    switch (node->type) {
        case CERCLE:
            fprintf(file, "  <circle cx='%d' cy='%d' r='%d' />\n", 
                node->data.cercle.posX, 
                node->data.cercle.posY, 
                node->data.cercle.rayon);
            break;
        case ELLIPSE:
            fprintf(file, "  <ellipse cx='%d' cy='%d' rx='%d' ry='%d' />\n", 
                node->data.ellipse.posX, 
                node->data.ellipse.posY, 
                node->data.ellipse.rayonX,
                node->data.ellipse.rayonY);
            break;
        case CARRE:
            fprintf(file, "  <rect x='%d' y='%d' width='%d' height='%d' />\n", 
                node->data.carre.posX, 
                node->data.carre.posY,
                node->data.carre.size,
                node->data.carre.size);
            break;
        case RECTANGLE:
            fprintf(file, "  <rect x='%d' y='%d' width='%d' height='%d' />\n", 
                node->data.rectangle.posX, 
                node->data.rectangle.posY,
                node->data.rectangle.width,
                node->data.rectangle.height);
            break;
        case LIGNE:
            fprintf(file, "  <line x1='%d' y1='%d' x2='%d' y2='%d' stroke='black' />\n", 
                node->data.ligne.startX, 
                node->data.ligne.startY,
                node->data.ligne.endX,
                node->data.ligne.endY); 
            break;
        case POLYLINE:
            fprintf(file, "  <polyline points='");
            Point* current_point_polyline = node->data.polyline.head_points;
            while (current_point_polyline != NULL) {
                fprintf(file, "%d,%d ", current_point_polyline->x, current_point_polyline->y);
                current_point_polyline = current_point_polyline->next;
            }
            fprintf(file, "' stroke='black' fill='none' />\n");
            break;
        case POLYGONE:
            fprintf(file, "  <polygon points='");
            Point* current_point_polygone = node->data.polygone.head_points;
            while (current_point_polygone != NULL)
            {
                fprintf(file, "%d,%d ", current_point_polygone->x, current_point_polygone->y);
                current_point_polygone = current_point_polygone->next;
            }
            fprintf(file, "' />\n");
            break;
        default:
            fprintf(file, "\n");
            break;
    }
}

List* create_and_insert_circle(List* head, int j) {
    cercle_st cercle;
    shapesData_un data;
    cercle.posX = ask_for_int("Saisir la posX du cercle : ");
    cercle.posY = ask_for_int("Saisir la posY du cercle : ");
    cercle.rayon = ask_for_int("Saisir le rayon du cercle : ");
    printf("La posX/Y et le rayon de votre Cercle[%d] sont %d, %d et %d\n", j, cercle.posX, cercle.posY, cercle.rayon);
    data.cercle = cercle;
    return makeNewNode(head, CERCLE, data);
}

List* create_and_insert_ellipse(List* head, int j) {
    ellipse_st ellipse;
    shapesData_un data;
    ellipse.posX = ask_for_int("Saisir la posX de l'ellipse : ");
    ellipse.posY = ask_for_int("Saisir la posY de l'ellipse : ");
    ellipse.rayonX = ask_for_int("Saisir le rayonX de l'ellipse : ");
    ellipse.rayonY = ask_for_int("Saisir le rayonY de l'ellipse : ");
    printf("La posX/Y et le rayon de votre Ellipse[%d] sont %d, %d et %d, %d\n", j, ellipse.posX, ellipse.posY, ellipse.rayonX, ellipse.rayonY);
    data.ellipse = ellipse;
    return makeNewNode(head, ELLIPSE, data);    
}

List* create_and_insert_carre(List* head, int j) {
    carre_st carre;
    shapesData_un data;
    carre.posX = ask_for_int("Saisir la posX du carre : ");
    carre.posY = ask_for_int("Saisir la posY du carre : ");
    carre.size = ask_for_int("Saisir la taille du carre : ");
    printf("La posX/Y et la taille de votre Carre[%d] sont %d, %d et %d\n", j, carre.posX, carre.posY, carre.size);
    data.carre = carre;
    return makeNewNode(head, CARRE, data);
}   

List* create_and_insert_rectangle(List* head, int j) {
    rectangle_st rectangle;
    shapesData_un data;
    rectangle.posX = ask_for_int("Saisir la posX du rectangle : ");
    rectangle.posY = ask_for_int("Saisir la posY du rectangle : ");
    rectangle.width = ask_for_int("Saisir la largeur du rectangle : ");
    rectangle.height = ask_for_int("Saisir la hauteur du rectangle : ");
    printf("La posX/Y et la largeur/longueur de votre Rectangle[%d] sont %d, %d et %d, %d\n", j, rectangle.posX, rectangle.posY, rectangle.width, rectangle.height);
    data.rectangle = rectangle;
    return makeNewNode(head, RECTANGLE, data);
}   

List* create_and_insert_line(List* head, int j) {
    line_st ligne;
    shapesData_un data;
    ligne.startX = ask_for_int("Saisir la posX start de la ligne : ");
    ligne.startY = ask_for_int("Saisir la posY start de la ligne : ");
    ligne.endX = ask_for_int("Saisir la posX fin de la ligne : ");
    ligne.endY = ask_for_int("Saisir la posY fin de la ligne : ");
    printf("La posX/Y et la largeur/longueur de votre Rectangle[%d] sont %d, %d et %d, %d\n", j, ligne.startX, ligne.startY, ligne.endX, ligne.endY);
    data.ligne = ligne;
    return makeNewNode(head, LIGNE, data);
}

List* create_and_insert_polyline(List* head, int j) {
    polyline_st polyline;
    shapesData_un data;
    Point* points_head = NULL;
    int num_points;

    printf("Combien de points souhaitez-vous ajouter a la Polyligne[%d] ? ", j);
    scanf("%d", &num_points);

    for (int i = 0; i < num_points; i++) {
        int x = ask_for_int("Saisir la coordonnée X du point : ");
        int y = ask_for_int("Saisir la coordonnée Y du point : ");
        points_head = makeNewPoint(points_head, x, y);
    }
    
    polyline.head_points = points_head;
    data.polyline = polyline;
    return makeNewNode(head, POLYLINE, data);
}

List* create_and_insert_polygone(List* head, int j) {
    polygone_st polygone;
    shapesData_un data;
    Point* points_head = NULL;
    int num_points;

    printf("Combien de points souhaitez-vous ajouter au Polygone[%d] ? ", j);
    scanf("%d", &num_points);

    for (int i = 0; i < num_points; i++) {
        int x = ask_for_int("Saisir la coordonnée X du point : ");
        int y = ask_for_int("Saisir la coordonnée Y du point : ");
        points_head = makeNewPoint(points_head, x, y);
    }
    
    polygone.head_points = points_head;
    data.polygone = polygone;
    return makeNewNode(head, POLYGONE, data);
}

void Make_Viewport() {
    sizeViewport_st viewport;
    viewport.startX = ask_for_int("Saisir la posX start du viewport : ");
    viewport.endX = ask_for_int("Saisir la posX end du viewport : ");
    viewport.startY = ask_for_int("Saisir la posY start du viewport : ");
    viewport.endY = ask_for_int("Saisir la posX end du viewport : ");
}