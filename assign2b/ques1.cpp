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

        void drawCircle() {
            glClear(GL_COLOR_BUFFER_BIT);
            glBegin(GL_LINE_LOOP);
            for (float angle = 0; angle < 2 * M_PI; angle = angle + 0.01) {
                glVertex2f(radius * cos(angle) + center -> x, radius * sin(angle) + center -> y);
            }
            glEnd();

            glBegin(GL_LINES);
            glVertex2f(-0.7 - 0.3 / sqrt(2), 0.7 - 0.3 / sqrt(2));
            glVertex2f(0.3 - 0.3 / sqrt(2), -0.3 - 0.3 / sqrt(2));
            glEnd();
            glFlush();
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
    float y = 0.7;
    float angle = 0;

    struct timespec tim1, tim2;
    tim1.tv_sec = 0;
    tim1.tv_nsec = 20000000L; //Half second

    for (int i = 0; i < 100; i++) {
        float rand1 = 65.0 / 255;
        float rand2 = 105.0 / 255;
        float rand3 = 225.0 / 255;
        glColor3f(rand1, rand2, rand3);
        Point *center = new Point(x, y, 0);
        Circle *circle = new Circle(center, 0.3);
        circle -> drawCircle();
        circle -> drawLine(angle);
        x += 0.01;
        y -= 0.01;
        angle -= 0.04;
        
        nanosleep(&tim1, &tim2);
    }

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Question 1");
    glClearColor(0.75, 0.75, 0.75, 1);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}



