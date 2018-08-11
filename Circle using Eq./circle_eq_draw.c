/*
 ============================================================================
 Name        : circle_eq_draw.c
 Author      : MitulSRV
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
float x,y,xc,yc,r;
void circle(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
	glBegin(GL_POINTS);
	for(x=xc-r; x<=xc+r; x++){
		y=yc+sqrt((r*r)-((xc-x)*(xc-x)));
		glVertex2f(x,y);
		y=yc-sqrt((r*r)-((xc-x)*(xc-x)));
		glVertex2f(x,y);
	}
	glEnd();
	glFlush();
}
void Init(){
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}
void main(int argc, char **argv){
	printf("Enter value of Xcenter and Ycenter :-");
	scanf("%f%f", &xc, &yc);
	printf("Enter value of radius");
	scanf("%f", &r);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple Eq. Based Circle drawing");
	Init();
	glutDisplayFunc(circle);
	glutMainLoop();
}

