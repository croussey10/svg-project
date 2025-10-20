#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "shapes.h"

int ask_for_int(char* message) {
    int value = 0;
    printf("%s", message);
    scanf("%d", &value);
    return value;
}

char* Make_Viewport() {
    sizeViewport_st viewport;
    char* viewport_str = malloc(100 * sizeof(char));
    viewport.startX = ask_for_int("Saisir la posX start du viewport : ");
    viewport.endX = ask_for_int("Saisir la posX end du viewport : ");
    viewport.startY = ask_for_int("Saisir la posY start du viewport : ");
    viewport.endY = ask_for_int("Saisir la posX end du viewport : ");

    printf("Votre viewport fait du '%d','%d' par '%d','%d' \n",
        viewport.startX,
        viewport.endX,
        viewport.startY,
        viewport.endY);
    snprintf(viewport_str, 100, "<svg viewBox='%d %d %d %d' xmlns='http://www.w3.org/2000/svg'>\n",
        viewport.startX,
        viewport.endX,
        viewport.startY,
        viewport.endY);
    return viewport_str;
}

ListSvg_st* create_and_insert_circle(ListSvg_st* head) {
    cercle_st cercle;
    shapesData_un data;
    color_st color;
    cercle.posX = ask_for_int("Saisir la posX du cercle : ");
    cercle.posY = ask_for_int("Saisir la posY du cercle : ");
    cercle.rayon = ask_for_int("Saisir le rayon du cercle : ");

    printf("Saisir une couleur : ");
    scanf("%s", color.color);

    printf("La posX/Y et le rayon de votre Cercle sont '%d', '%d' et '%d', la couleur est '%s' \n",
        cercle.posX, 
        cercle.posY, 
        cercle.rayon,
        color.color);
    data.cercle = cercle;
    return make_new_node(head, CERCLE, data, color);
}

ListSvg_st* create_and_insert_ellipse(ListSvg_st* head) {
    ellipse_st ellipse;
    shapesData_un data;
    color_st color;
    ellipse.posX = ask_for_int("Saisir la posX de l'ellipse : ");
    ellipse.posY = ask_for_int("Saisir la posY de l'ellipse : ");
    ellipse.rayonX = ask_for_int("Saisir le rayonX de l'ellipse : ");
    ellipse.rayonY = ask_for_int("Saisir le rayonY de l'ellipse : ");

    printf("Saisir une couleur : ");
    scanf("%s", color.color);

    printf("La posX/Y et le rayon de votre Ellipse sont '%d', '%d' et '%d', '%d', la couleur est '%s' \n",
        ellipse.posX, 
        ellipse.posY, 
        ellipse.rayonX, 
        ellipse.rayonY,
        color.color);
    data.ellipse = ellipse;
    return make_new_node(head, ELLIPSE, data, color);    
}

ListSvg_st* create_and_insert_carre(ListSvg_st* head) {
    carre_st carre;
    shapesData_un data;
    color_st color;
    carre.posX = ask_for_int("Saisir la posX du carre : ");
    carre.posY = ask_for_int("Saisir la posY du carre : ");
    carre.size = ask_for_int("Saisir la taille du carre : ");

    printf("Saisir une couleur : ");
    scanf("%s", color.color);

    printf("La posX/Y et la taille de votre Carre sont '%d', '%d' et '%d', la couleur est '%s' \n",
        carre.posX, 
        carre.posY, 
        carre.size,
        color.color);
    data.carre = carre;
    return make_new_node(head, CARRE, data, color);
}

ListSvg_st* create_and_insert_rectangle(ListSvg_st* head) {
    rectangle_st rectangle;
    shapesData_un data;
    color_st color;
    rectangle.posX = ask_for_int("Saisir la posX du rectangle : ");
    rectangle.posY = ask_for_int("Saisir la posY du rectangle : ");
    rectangle.width = ask_for_int("Saisir la largeur du rectangle : ");
    rectangle.height = ask_for_int("Saisir la hauteur du rectangle : ");

    printf("Saisir une couleur : ");
    scanf("%s", color.color);

    printf("La posX/Y et la largeur/longueur de votre Rectangle sont '%d', '%d' et '%d', '%d', la couleur est '%s' \n",
        rectangle.posX, 
        rectangle.posY, 
        rectangle.width, 
        rectangle.height,
        color.color);
    data.rectangle = rectangle;
    return make_new_node(head, RECTANGLE, data, color);
}   

ListSvg_st* create_and_insert_line(ListSvg_st* head) {
    line_st ligne;
    shapesData_un data;
    color_st color;
    ligne.startX = ask_for_int("Saisir la posX start de la ligne : ");
    ligne.startY = ask_for_int("Saisir la posY start de la ligne : ");
    ligne.endX = ask_for_int("Saisir la posX fin de la ligne : ");
    ligne.endY = ask_for_int("Saisir la posY fin de la ligne : ");

    printf("Saisir une couleur : ");
    scanf("%s", color.color);

    printf("La posX/Y et la largeur/longueur de votre Rectangle[] sont '%d', '%d' et '%d', '%d', la couleur est '%s' \n",
        ligne.startX, 
        ligne.startY, 
        ligne.endX, 
        ligne.endY,
        color.color);
    data.ligne = ligne;
    return make_new_node(head, LIGNE, data, color);
}

ListSvg_st* create_and_insert_polyline(ListSvg_st* head) {
    polyline_st polyline;
    shapesData_un data;
    color_st color;
    point_st* points_head = NULL;
    int num_points;

    printf("Combien de points souhaitez-vous ajouter a la Polyligne ? ");
    scanf("%d", &num_points);

    for (int i = 0; i < num_points; i++) {
        int x = ask_for_int("Saisir la coordonnée X du point : ");
        int y = ask_for_int("Saisir la coordonnée Y du point : ");
        points_head = make_new_point(points_head, x, y);
    }

    printf("Saisir une couleur : ");
    scanf("%s", color.color);
    
    polyline.headPoints = points_head;
    data.polyline = polyline;
    return make_new_node(head, POLYLINE, data, color);
}

ListSvg_st* create_and_insert_polygone(ListSvg_st* head) {
    polygone_st polygone;
    shapesData_un data;
    color_st color;
    point_st* points_head = NULL;
    int num_points;

    printf("Combien de points souhaitez-vous ajouter au Polygone ? ");
    scanf("%d", &num_points);

    for (int i = 0; i < num_points; i++) {
        int x = ask_for_int("Saisir la coordonnée X du point : ");
        int y = ask_for_int("Saisir la coordonnée Y du point : ");
        points_head = make_new_point(points_head, x, y);
    }

    printf("Saisir une couleur : ");
    scanf("%s", color.color);
    
    polygone.headPoints = points_head;
    data.polygone = polygone;
    return make_new_node(head, POLYGONE, data, color);
}
