#pragma once
typedef struct
{
	double red, green, blue;
} COLOR;

void init();

void display();

void DrawPyramid(COLOR& pyramid, COLOR& pyramid_secondary, const GLdouble& pyramid_center_x, const GLdouble& pyramid_center_y, const GLdouble& pyramid_height, const GLdouble& pyramid_base_length);
