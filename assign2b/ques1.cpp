#include <bits/stdc++.h>
#include <GL/glut.h>
#include <time.h>
#include <unistd.h>

void init2D(float r, float g, float b)
{
	glClearColor(r, g, b, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-500.0, 500.0, -500.0, 500.0 );
}

void display(void)
{
 	float x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8,x9,y9,x10,y10;
 	 
 	x1 = 0;
 	y1 = 100;

 	x2 = 25;
 	y2 = 50;

 	x3 = 100;
 	y3 = 50;

 	x4 = 50;
 	y4 = 0;

 	x5 = 75;
 	y5 = -75;

 	x6 = 0;
 	y6 = -50;

 	x7 = -75;
 	y7 = -75;

 	x8 = -50;
 	y8 = 0;

 	x9 = -100;
 	y9 = 50;

 	x10 = -25;
 	y10 = 50;


	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glVertex2f(x2,y2);
	glVertex2f(x3,y3);
	glVertex2f(x3,y3);
	glVertex2f(x4,y4);
	glVertex2f(x4,y4);
	glVertex2f(x5,y5);
	glVertex2f(x5,y5);
	glVertex2f(x6,y6);
	glVertex2f(x6,y6);
	glVertex2f(x7,y7);
	glVertex2f(x7,y7);
	glVertex2f(x8,y8);
	glVertex2f(x8,y8);
	glVertex2f(x9,y9);
	glVertex2f(x9,y9);
	glVertex2f(x10,y10);
	glVertex2f(x10,y10);
	glVertex2f(x1,y1);
        glEnd();
        glFlush();

	for (int i = 1; i <= 10; ++i)
	{
		if(i == 4){
			continue;
		}
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_LINES);
		glVertex2f(i * 0.25 * x1,i * 0.25 * y1);
		glVertex2f(i * 0.25 * x2,i * 0.25 * y2);
		glVertex2f(i * 0.25 * x2,i * 0.25 * y2);
		glVertex2f(i * 0.25 * x3,i * 0.25 * y3);
		glVertex2f(i * 0.25 * x3,i * 0.25 * y3);
		glVertex2f(i * 0.25 * x4,i * 0.25 * y4);
		glVertex2f(i * 0.25 * x4,i * 0.25 * y4);
		glVertex2f(i * 0.25 * x5,i * 0.25 * y5);
		glVertex2f(i * 0.25 * x5,i * 0.25 * y5);
		glVertex2f(i * 0.25 * x6,i * 0.25 * y6);
		glVertex2f(i * 0.25 * x6,i * 0.25 * y6);
		glVertex2f(i * 0.25 * x7,i * 0.25 * y7);
		glVertex2f(i * 0.25 * x7,i * 0.25 * y7);
		glVertex2f(i * 0.25 * x8,i * 0.25 * y8);
		glVertex2f(i * 0.25 * x8,i * 0.25 * y8);
		glVertex2f(i * 0.25 * x9,i * 0.25 * y9);
		glVertex2f(i * 0.25 * x9,i * 0.25 * y9);
		glVertex2f(i * 0.25 * x10,i * 0.25 * y10);
		glVertex2f(i * 0.25 * x10,i * 0.25 * y10);
		glVertex2f(i * 0.25 * x1,i * 0.25 * y1);
                sleep(1);
		glEnd();
		glFlush();		
	}

	glEnd();
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc,argv);	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Question 1");
	init2D(0.0f, 0.0f, 0.0f);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

