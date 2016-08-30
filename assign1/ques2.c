#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_STRIP);
    glColor3f(0, 0, 1);
    glVertex3f(-0.5, -0.5, 0);
    glVertex3f(0.5, -0.5, 0);
    glVertex3f(0.5, 0.5, 0);
    glVertex3f(-0.5, 0.5, 0);
    glVertex3f(-0.5, -0.5, 0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex3f(0.5, -0.5, 0);
    glVertex3f(0.9, -0.1, 0);
    glVertex3f(0.9, 0.9, 0);
    glVertex3f(0.5, 0.5, 0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex3f(0.9, 0.9, 0);
    glVertex3f(-0.1, 0.9, 0);
    glVertex3f(-0.5, 0.5, 0);
    glEnd();

    glFlush();
}

void init(float r, float g, float b)
{
    glClearColor(r, g, b, 0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Question 2");
    init(0.75, 0.75, 0.75);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

