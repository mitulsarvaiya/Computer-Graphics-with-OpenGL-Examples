/*
 ============================================================================
 Name        : polygon_points.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "line.h"
int x[' '],y[' '],n,i;
int y_min, y_max, x_min, x_max,count;
void polygon(){
	glClear(GL_COLOR_BUFFER_BIT);
	for(i=0; i< n-1; i++){
		line(x[i], y[i], x[i+1], y[i+1]);
	}
	line(x[i], y[i],x[0], y[0]);

	//find X and Y Min and Max
	x_max=x[0];
	y_max=y[0];
	x_min=x[0];
	y_min=y[0];
	for(i=0; i<n; i++){
		if(x_max < x[i])
			x_max = x[i];
		if(y_max < y[i])
			y_max = y[i];
		if(x_min > x[i])
			x_min = x[i];
		if(y_min > x[i])
			y_min = x[i];
	}
	printf("\nX_MAX = %d Y_MAX = %d X_MIN = %d Y_MIN = %d", x_max, y_max, x_min, y_min);
}
int main(int argc, char **argv) {
	printf("\nEnter Number of Vertex.....");
	scanf("%d",&n);
	for(i=0; i<n; i++){
		printf("\nEnter value of X[%d] and Y[%d].......", i+1, i+1);
		scanf("%d %d",&x[i], &y[i]);
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Polygon");
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-600, 600, -600, 600);
	glutDisplayFunc(polygon);
	glutMainLoop();
	polygon();
	return EXIT_SUCCESS;
}
