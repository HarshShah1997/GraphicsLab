#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    //For square
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(50, 10);
    glVertex2i(150, 10);
    glVertex2i(150, 10);
    glVertex2i(150, 100);
    glVertex2i(50, 100);
    glVertex2i(50, 10);

    //Trianlge
    glColor3f(0, 0, 1);
    glVertex2i(150, 100);
    glVertex2i(100, 150);
    glVertex2i(100, 150);
    glVertex2i(50, 100); //Here
    glVertex2i(50, 100);
    glVertex2i(150, 100);

    glEnd();
    glFlush();
}

void init2D(float r, float g, float b)
{
    glClearColor(r, g, b, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 200, 0, 200);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Question 1");
    init2D(0.75, 0.75, 0.75);
    glutDisplayFunc(display);
    glutMainLoop();
}


