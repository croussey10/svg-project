#ifndef SHAPES_H
#define SHAPES_H

typedef struct {
    int startX;
    int endX;
    int startY;
    int endY;
} sizeViewport_st;

typedef struct {
    char color[20];
} color_st;

typedef enum {
    CERCLE,
    ELLIPSE,
    CARRE,
    RECTANGLE,
    LIGNE,
    POLYLINE,
    POLYGONE
} shapesType_en;

typedef struct {
    int posX;
    int posY;
    int rayon;
} cercle_st;

typedef struct {
    int posX;
    int posY;
    int rayonX;
    int rayonY;
} ellipse_st;

typedef struct {
    int posX;
    int posY;
    int size;
} carre_st;

typedef struct {
    int posX;
    int posY;
    int width;
    int height;
} rectangle_st;

typedef struct {
    int startX;
    int startY;
    int endX;
    int endY;
} line_st;

typedef struct point {
    int x;
    int y;
    struct point *next;
} point_st;

typedef struct {
    point_st* headPoints;
} polyline_st;

typedef struct {
    point_st* headPoints;
} polygone_st;

typedef union {
    cercle_st cercle;
    ellipse_st ellipse;
    carre_st carre;
    rectangle_st rectangle;
    line_st ligne;
    polyline_st polyline;
    polygone_st polygone;
} shapesData_un;

typedef struct listSvg {
    shapesType_en type;
    shapesData_un data;
    color_st color;
    struct listSvg *next;
} ListSvg_st;

ListSvg_st* make_new_node(ListSvg_st* head, shapesType_en typeShape, shapesData_un dataShape, color_st colorShape);
point_st* make_new_point(point_st* head, int xNextPoint, int yNextPoint);

void free_points(point_st* head);
void free_list(ListSvg_st* head);

void generate_svg(ListSvg_st* node, FILE* file);

#endif