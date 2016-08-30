#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

typedef struct Point {
    float x;
    float y;
} Point;

int n;

void fillBottom(float startx, float starty, float height, float width, int n)
{
    while (starty - height >= -0.9 + height * n) {
        glBegin(GL_POLYGON);
        glColor3f(0, 1, 0);

        glVertex3f(startx, starty, 0);
        glVertex3f(startx, starty - height, 0);
        glVertex3f(startx - width, starty - height - width, 0);
        glVertex3f(startx - width, starty - width, 0);

        glEnd();
        glFlush();
        starty = starty - height;
    }
}

Point drawStaircase(Point start, float height, float width)
{
    float startx = start.x;
    float starty = start.y;

    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);

    glVertex3f(startx, starty, 0);
    glVertex3f(startx, starty + height, 0);
    glVertex3f(startx - 2 * height, starty + 3 * height, 0);
    glVertex3f(startx - 2 * height, starty + 2 * height, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);

    glVertex3f(startx, starty + height, 0);
    glVertex3f(startx + width, starty + height + width, 0);
    glVertex3f(startx - 2 * height + width, starty + 3 * height + width, 0);
    glVertex3f(startx - 2 * height, starty + 3 * height, 0);
    glEnd();

    glFlush();
    Point end;
    end.x = startx + width;
    end.y = starty + height + width;
    return end;
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    Point start;
    start.x = -0.3;
    start.y = -0.9;

    float height = 0.22;
    float width = 0.19;


    for (int i = 0; i < n; i++) {
        start = drawStaircase(start, height, width);
        fillBottom(start.x, start.y, height, width, i);
    }
}

void init2D(float r, float g, float b)
{
    glClearColor(r, g, b, 0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
    n = atoi(argv[1]);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Question 3");
    init2D(0.75, 0.75, 0.75);

    glutDisplayFunc(display);
    glutMainLoop();
}

