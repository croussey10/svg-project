#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shapes.h"

ListSvg_st* make_new_node(ListSvg_st* head, shapesType_en typeShape, shapesData_un dataShape, color_st colorShape) {
    ListSvg_st* newNode = malloc(sizeof(ListSvg_st));
    newNode->type = typeShape;
    newNode->data = dataShape;
    newNode->color = colorShape;
    newNode->next = head;
    return newNode;
}

point_st* make_new_point(point_st* head, int xNextPoint, int yNextPoint) {
    point_st* newPoint = malloc(sizeof(point_st));
    newPoint->x = xNextPoint;
    newPoint->y = yNextPoint;
    newPoint->next = head;
    return newPoint;
}

void free_points(point_st* head) {
    point_st* current = head;
    point_st* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void free_list(ListSvg_st* head) {
    ListSvg_st* current = head;
    ListSvg_st* next;
    
    while (current != NULL) {
        next = current->next;
        
        if (current->type == POLYLINE) {
            free_points(current->data.polyline.headPoints);
        } else if (current->type == POLYGONE) {
            free_points(current->data.polygone.headPoints);
        }
        free(current);
        current = next;
    }
}

void generate_svg(ListSvg_st* node, FILE* file) {
    if (node == NULL) return;

    switch (node->type) {
        case CERCLE:
            fprintf(file, "  <circle cx='%d' cy='%d' r='%d' style='fill: %s' />\n", 
                node->data.cercle.posX, 
                node->data.cercle.posY,
                node->data.cercle.rayon,
                node->color.color);
            break;
        case ELLIPSE:
            fprintf(file, "  <ellipse cx='%d' cy='%d' rx='%d' ry='%d' style='fill: %s' />\n", 
                node->data.ellipse.posX, 
                node->data.ellipse.posY, 
                node->data.ellipse.rayonX,
                node->data.ellipse.rayonY,
                node->color.color);
            break;
        case CARRE:
            fprintf(file, "  <rect x='%d' y='%d' width='%d' height='%d' style='fill: %s' />\n", 
                node->data.carre.posX, 
                node->data.carre.posY,
                node->data.carre.size,
                node->data.carre.size,
                node->color.color);
            break;
        case RECTANGLE:
            fprintf(file, "  <rect x='%d' y='%d' width='%d' height='%d' style='fill: %s' />\n", 
                node->data.rectangle.posX,
                node->data.rectangle.posY,
                node->data.rectangle.width,
                node->data.rectangle.height,
                node->color.color);
            break;
        case LIGNE:
            fprintf(file, "  <line x1='%d' y1='%d' x2='%d' y2='%d' stroke='%s' />\n", 
                node->data.ligne.startX,
                node->data.ligne.startY,
                node->data.ligne.endX,
                node->data.ligne.endY,
                node->color.color);
            break;
        case POLYLINE:
            fprintf(file, "  <polyline points='");
            point_st* current_point_polyline = node->data.polyline.headPoints;
            while (current_point_polyline != NULL) {
                fprintf(file, "%d,%d ", current_point_polyline->x, current_point_polyline->y);
                current_point_polyline = current_point_polyline->next;
            }
            fprintf(file, "' fill='none' stroke='%s' />\n",
                node->color.color);
            break;
        case POLYGONE:
            fprintf(file, "  <polygon points='");
            point_st* current_point_polygone = node->data.polygone.headPoints;
            while (current_point_polygone != NULL)
            {
                fprintf(file, "%d,%d ", current_point_polygone->x, current_point_polygone->y);
                current_point_polygone = current_point_polygone->next;
            }
            fprintf(file, "' fill='%s' />\n", 
                node->color.color);
            break;
        default:
            fprintf(file, "\n");
            break;
    }
}