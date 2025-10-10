#ifndef SHAPES_STRUCTURE
#define SHAPES_STRUCTURE 

typedef struct sizeVewport_s
{
    int startX;
    int startY;
    int endX;
    int endY;
} sizeVewport_st;

typedef struct circle_s
{
    int positionX;
    int positionY;
    int rayon;
} circle_st;

typedef struct rectangle_s
{
    int positionX;
    int positionY;
    int width;
    int height;
} rectangle_st;

typedef struct line_s
{
    int startX;
    int endX;
    int startY;
    int endY;
} line_st;


sizeVewport_st *CreateViewport(int a, int b, int c, int d);

circle_st *CreateCircle(int a, int b, int c);

rectangle_st *CreateRectangle(int a, int b, int c, int d);

line_st *CreateLine(int a, int b, int c, int d);

#endif