/*
 ============================================================================
 Name        : Parametric_Circle.c
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
float x,y,xc,yc,r,theta;
void circle(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glPointSize(2.0);
	float i=0;
	for(i=0; i<=360; i=i+(1/r)){
		theta = 3.14*i/180;
		x=xc+(r*cos(theta));
		y=yc+(r*sin(theta));
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
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Simple Eq. Based Circle drawing");
	Init();
	glutDisplayFunc(circle);
	glutMainLoop();
}

