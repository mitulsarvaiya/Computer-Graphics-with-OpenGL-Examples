/*
 * line.h
 *
 *  Created on: 31-Aug-2018
 *      Author: root
 */

#ifndef LINE_H_
#define LINE_H_
#include <GL/glut.h>
void line(int x1, int y1, int x2, int y2){
	//glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2);
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

#endif /* LINE_H_ */
