#include <GL/glut.h>
#include <math.h>

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
        bool isDashed;

        Circle(Point *p, float r, bool dash) {
            center = p;
            radius = r;
            isDashed = dash;
        }

        void drawCircle() {
            float start = 0.01;
            float end = M_PI / 8;
            while (start <= 2 * M_PI) {
                glBegin(GL_LINE_STRIP);
                for (float angle = start; angle <= end; angle = angle + 0.001) {
                    glVertex2f(radius * cos(angle) + center -> x, radius * sin(angle) + center -> y);
                    //glVertex2f(radius * cos(angle + 0.005) + center -> x, radius * sin(angle + 0.005) + center -> y);
                }
                glEnd();
                if (isDashed) {
                    start += 3 * M_PI / 16;
                    end += 3 * M_PI / 16;
                } else {
                    start += M_PI / 8;
                    end += M_PI / 8;
                }
                glFlush();
            }
        }
};

void display(void) 
{
    glClear(GL_COLOR_BUFFER_BIT);

    float radius = 0.1;
    bool dashed = true;

    for (int i = 0; i < 8; i++) {
        float rand1 = 0;
        float rand2 = 0;
        float rand3 = 0;
        glColor3f(rand1, rand2, rand3);
        Point *center = new Point(0, 0, 0);
        Circle *circle = new Circle(center, radius, dashed);
        circle -> drawCircle();
        radius += 0.1;
        dashed = !dashed;
    }

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Question 2");
    glClearColor(0.75, 0.75, 0.75, 1);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}



