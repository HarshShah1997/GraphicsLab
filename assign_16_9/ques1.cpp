#include <GL/glut.h>
#include <cmath>
#include <unistd.h>

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
            glVertex2f(-0.7, 0.3);
            glVertex2f(0.3, -0.7);
            glEnd();
            glutSwapBuffers();
        }
};

void display(void) 
{
    glClear(GL_COLOR_BUFFER_BIT);

    float x = -0.7;
    float y = 0.7;

    for (int i = 0; i < 10; i++) {
        float rand1 = 65.0 / 255;
        float rand2 = 105.0 / 255;
        float rand3 = 225.0 / 255;
        glColor3f(rand1, rand2, rand3);
        Point *center = new Point(x, y, 0);
        Circle *circle = new Circle(center, 0.3);
        circle -> drawCircle();
        x += 0.1;
        y -= 0.1;
        sleep(1);
    }

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Question 1");
    glClearColor(0.75, 0.75, 0.75, 1);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}



