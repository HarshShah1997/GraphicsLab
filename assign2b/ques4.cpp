#include <GL/glut.h>
#include <cmath>
#include <unistd.h>
#include <time.h>
#include "../matrix.h"

class Point {
    public:
        float x, y, z;

        Point(float a, float b, float c) {
            x = a;
            y = b;
            z = c;
        }
};

class Circle {
    public:
        Point *center;
        float radius;

        Circle(Point *p, float r) {
            center = p;
            radius = r;
        }

        void drawCircle(Point* color) {
            //glClear(GL_COLOR_BUFFER_BIT);
            glBegin(GL_TRIANGLES);
            for (float angle = 0; angle < 2 * M_PI; angle = angle + 0.01) {
                glColor3f(color -> x, color -> y, color -> z);
                glVertex2f(center -> x, center -> y);
                glVertex2f(radius * cos(angle) + center -> x, radius * sin(angle) + center -> y);
                glVertex2f(radius * cos(angle + 0.01) + center -> x, radius * sin(angle + 0.01) + center -> y);
            }
            glEnd();
        }

        void drawLine(float angle) {
            Matrix *q = new Matrix(3, 1);
            q -> elementAt[0][0] = center -> x + radius / sqrt(2);
            q -> elementAt[1][0] = center -> y + radius / sqrt(2);
            
            Matrix* rotate = new Matrix(3, 3);
            rotate -> elementAt[0][0] = cos(angle);
            rotate -> elementAt[0][1] = -sin(angle);
            rotate -> elementAt[1][0] = cos(angle);
            rotate -> elementAt[1][1] = sin(angle);

            Matrix* translate = new Matrix(3, 1);
            translate -> elementAt[0][0] = - (center -> x);
            translate -> elementAt[1][0] = - (center -> y);

            Matrix *org = new Matrix(3, 1);
            org -> elementAt[0][0] = center -> x;
            org -> elementAt[1][0] = center -> y;

            Matrix *p = add(org, multiply(rotate, add(translate, q)));

            glBegin(GL_LINES);
            glVertex2f(p -> elementAt[0][0], p -> elementAt[1][0]);
            glVertex2f(center -> x, center -> y);
            glEnd();
            glFlush();
        }
};

void display(void) 
{
    glClear(GL_COLOR_BUFFER_BIT);

    float x = -0.7;
    float y = 0;
    float angle = 0;

    struct timespec tim1, tim2;
    tim1.tv_sec = 0;
    tim1.tv_nsec = 10000000L;

    float dir[4][2] = {{0.01, -0.01}, {0.01, 0.01}, {-0.01, 0.01}, {-0.01, -0.01}};
    int j = 0;
    while(1) {
        float rand1 = (rand() % 255) / 255.0;
        float rand2 = (rand() % 255) / 255.0;
        float rand3 = (rand() % 255) / 255.0;
        for (int i = 0; i < 70; i++) {
            glClear(GL_COLOR_BUFFER_BIT);
            for (float radius = 0.3; radius >= 0; radius -= 0.005) {
                Point *center = new Point(x, y, 0);
                Circle *circle = new Circle(center, radius);
                circle -> drawCircle(new Point(rand1+(0.3 - radius), rand2 + (0.3 - radius), rand3 + (0.3 - radius)));
            }
            glFlush();
            x += dir[j][0];
            y -= dir[j][1];

            nanosleep(&tim1, &tim2);
        }
        j = (j + 1) % 4;
    }

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Question 2");
    glClearColor(0.01, 0.01, 0.01, 1);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}



