#ifndef SHAPES_H
#define SHAPES_H

typedef struct {
    int startX;
    int endX;
    int startY;
    int endY;
} sizeViewport_st;

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
} Point;

typedef struct {
    Point* head_points;
} polyline_st;

typedef struct {
    Point* head_points;
} polygone_st;

typedef enum {
    CERCLE,
    ELLIPSE,
    CARRE,
    RECTANGLE,
    LIGNE,
    POLYLINE,
    POLYGONE
} shapesType_en;

typedef union {
    cercle_st cercle;
    ellipse_st ellipse;
    carre_st carre;
    rectangle_st rectangle;
    line_st ligne;
    polyline_st polyline;
    polygone_st polygone;
} shapesData_un;

typedef struct list {
    shapesType_en type;
    shapesData_un data;
    struct list *next;
} List;

List* makeNewNode(List* head, shapesType_en type, shapesData_un data);
Point* makeNewPoint(Point* head, int x, int y);
//void print_list(List* head);
int ask_for_int(char* message);

List* create_and_insert_circle(List* head, int j);
List* create_and_insert_ellipse(List* head, int j);
List* create_and_insert_carre(List* head, int j);
List* create_and_insert_rectangle(List* head, int j);
List* create_and_insert_line(List* head, int j);
List* create_and_insert_polyline(List* head, int j);
List* create_and_insert_polygone(List* head, int j);

void Make_Viewport();

void generate_svg_line(List* node, FILE* file);


#endif