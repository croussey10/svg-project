#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include "shapes.h" 

int ask_for_int(char* message);

char* Make_Viewport();

ListSvg_st* create_and_insert_circle(ListSvg_st* head);
ListSvg_st* create_and_insert_ellipse(ListSvg_st* head);
ListSvg_st* create_and_insert_carre(ListSvg_st* head);
ListSvg_st* create_and_insert_rectangle(ListSvg_st* head);
ListSvg_st* create_and_insert_line(ListSvg_st* head);
ListSvg_st* create_and_insert_polyline(ListSvg_st* head);
ListSvg_st* create_and_insert_polygone(ListSvg_st* head);

#endif