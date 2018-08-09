/*
 ============================================================================
 Name        : dda_line.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

float x1,y1,x2,y2;

void dda_line(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
	float dx, dy, steps, x, y, i, Xcnt, Ycnt;
	dx = x2 - x1;
	dy = y2 - y1;

	if(abs(dx) > abs(dy)){
		steps = abs(dx);
	}
	else{
		steps = abs(dy);
	}
	Xcnt = dx / steps;
	Ycnt = dy / steps;

	x=x1;
	y=y1;
	glBegin(GL_POINTS);
	glVertex2d(x,y);
	glEnd();
	for(i=1; i<=steps; i++){
		x = x + Xcnt;
		y = y + Ycnt;
		glBegin(GL_POINTS);
		glVertex2d(x,y);
		glEnd();
	}
	glFlush();
}
void Init(){
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}
void main(int argc, char **argv){
	printf("Enter value of (x1,y1) :-");
	scanf("%f%f", &x1, &y1);
	printf("Enter value of (x2,y2) :-");
	scanf("%f%f", &x2, &y2);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("DDA LINE");
	Init();
	glutDisplayFunc(dda_line);
	glutMainLoop();
}
