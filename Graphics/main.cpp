#include "glut.h"
#include <math.h>
#include <time.h>
#include "main.h"

const COLOR RIVER = { 0.501, 0.854, 0.921 }; // RGB: (128, 218, 235)
const COLOR PYRAMID_TINT = { 0.96, 0.827, 0.647 }; // RGB: (245, 211, 165)
const COLOR PYRAMID = { 0.76, 0.596, 0.368 }; // RGB: (194, 152, 94)
const COLOR PYRAMID_DARK = { 0.478, 0.309, 0.145 }; // RGB: (122, 79, 37)
const COLOR SAND = { 0.886, 0.67, 0.407 }; // RGB: (226, 171, 104)
const COLOR SAND_TINT = { 0.929, 0.788, 0.686 }; // RGB: (237, 201, 175)

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // defines matrices: 1. Color matric, 2. Video buffer
	glutInitWindowSize(600, 600); // Physical size of window (pixels)
	glutInitWindowPosition(200, 100);
	glutCreateWindow("Desert Sunrise");

	glutDisplayFunc(display); //  Refresh window function

	init();

	glutMainLoop();
	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT); // Clean frame buffer

	COLOR pyramid = PYRAMID;
	COLOR pyramid_secondary = PYRAMID_DARK;
	COLOR pyramid_third = PYRAMID_TINT;
	GLdouble pyramid_center_x = 0, pyramid_center_y = 0;
	GLdouble pyramid_base_length = 1, pyramid_height = 0.5;

	DrawPyramid(pyramid, pyramid_secondary, pyramid_center_x - 0.25, pyramid_center_y + 0.25, pyramid_height / 2, pyramid_base_length / 2); // Small left

	DrawPyramid(pyramid, pyramid_secondary, pyramid_center_x, pyramid_center_y, pyramid_height, pyramid_base_length); // Large mid

	DrawPyramid(pyramid, pyramid_third, pyramid_center_x + 0.6, pyramid_center_y + 0.4, pyramid_height / 2.5, pyramid_base_length / 2.5); // Small right

	glutSwapBuffers(); // Show everything
}

void DrawPyramid(COLOR& pyramid, COLOR& pyramid_secondary, const GLdouble& pyramid_center_x, const GLdouble& pyramid_center_y, const GLdouble& pyramid_height, const GLdouble& pyramid_base_length)
{
	glBegin(GL_POLYGON);

	glColor3d(pyramid.red, pyramid.green, pyramid.blue);

	GLdouble top_x = pyramid_center_x, top_y = pyramid_center_y + pyramid_height / 2;
	GLdouble bot_left_x = pyramid_center_x - pyramid_base_length / 2, bot_left_y = pyramid_center_y - pyramid_height / 2;
	GLdouble bot_right_x = pyramid_center_x + pyramid_base_length / 2, bot_right_y = pyramid_center_y - pyramid_height / 2;

	glVertex2d(top_x, top_y); // Top
	glVertex2d(bot_left_x, bot_left_y); // Bot Left
	glVertex2d(bot_right_x, bot_right_y); // Bot Right

	GLdouble secondary_height = pyramid_height / 5;
	glColor3d(pyramid_secondary.red, pyramid_secondary.green, pyramid_secondary.blue);
	glVertex2d(pyramid_center_x, pyramid_center_y - secondary_height); // Top
	glEnd();
}

void init()
{
	glClearColor(RIVER.red, RIVER.green, RIVER.blue, 0); // Window background color
	glOrtho(-1, 1, -1, 1, 1, -1);
}

