#include <GL/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_STRIP);
    glColor3f(0, 1, 0);

    glVertex2f(-0.7, -0.7);
    glVertex2f(-0.3, -0.2);
    glVertex2f(-0.1, 0.7);
    glVertex2f(-0.7, -0.7);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.7, -0.7);
    glVertex2f(-0.3, -0.2);
    glVertex2f(0.1, -0.9);
    glVertex2f(-0.7, -0.7);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.1, -0.9);
    glVertex2f(0.2, -0.25);
    glVertex2f(-0.1, 0.7);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.3, -0.2);
    glVertex2f(0.2, -0.25);

    glVertex2f(0.1, -0.9);
    glVertex2f(-0.1, 0.7);
    glEnd();

    glFlush();
}

void init(float r, float g, float b)
{
    glClearColor(r, g, b, 0);
    glMatrixMode(GL_PROJECTION);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Question 1");
    init(0, 0, 0);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
    
