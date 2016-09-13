#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

class Leg {
    public:
        float startx;
        float starty;
        
        Leg(float sx, float sy) {
            startx = sx;
            starty = sy;
        }

        void draw() {
            glBegin(GL_LINE_LOOP);
            glVertex2f(startx, starty);
            glVertex2f(startx, starty - 60);
            glVertex2f(startx + 10, starty - 60);
            glVertex2f(startx + 10, starty);
            glEnd();

            glBegin(GL_LINE_STRIP);
            glVertex2f(startx, starty);
            glVertex2f(startx - 2, starty + 5);
            glVertex2f(startx - 2, starty + 5 - 60);
            glVertex2f(startx, starty - 60);
            glEnd();

            glBegin(GL_LINE_STRIP);
            glVertex2f(startx - 2, starty + 5);
            glVertex2f(startx + 10 - 2, starty + 5);
            glVertex2f(startx + 10, starty);
            glEnd();

            glFlush();
        }
};

class Plane {
    public:
        float startx;
        float starty;
        Plane(float sx, float sy) {
            startx = sx;
            starty = sy;
        }
        void draw() {
            glBegin(GL_LINE_LOOP);
            glVertex2f(startx, starty);
            glVertex2f(startx + 130, starty + 20);
            glVertex2f(startx + 110, starty + 70);
            glVertex2f(startx - 20, starty + 50);
            glEnd();
            glFlush();
        }

        void fill() {
            glBegin(GL_POLYGON);
            glVertex2f(startx, starty);
            glVertex2f(startx + 130, starty + 20);
            glVertex2f(startx + 110, starty + 70);
            glVertex2f(startx - 20, starty + 50);
            glEnd();
            glFlush();
        }

};

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    Plane *p1 = new Plane(40, 100);
    Plane *p2 = new Plane(37, 97);

    Leg *l1 = new Leg(40, 100);
    Leg *l2 = new Leg(170 - 10, 120);
    Leg *l3 = new Leg(150 - 10, 170 - 10);
    Leg *l4 = new Leg(20, 150 - 10);

    glColor3f(1, 0, 0);
    l1 -> draw();
    l2 -> draw();
    l3 -> draw();
    l4 -> draw();
    
    glColor3f(0.75, 0.75, 0.75);
    p2 -> fill();
    glColor3f(1, 0, 0);
    p2 -> draw();
    glColor3f(0.75, 0.75, 0.75);
    p1 -> fill();
    glColor3f(1, 0, 0);
    p1 -> draw();

}

void init(float r, float g, float b)
{
    glClearColor(r, g, b, 1);
    gluOrtho2D(0, 200, 0, 200);
    glMatrixMode(GL_PROJECTION);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Question 3");
    init(0.75, 0.75, 0.75);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


