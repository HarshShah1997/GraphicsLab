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

        Circle(Point *p, float r) {
            center = p;
            radius = r;
        }

        void drawCircle() {
            glBegin(GL_LINE_LOOP);
            for (float angle = 0; angle < 2 * M_PI; angle = angle + 0.01) {
                glVertex2f(radius * cos(angle) + center -> x, radius * sin(angle) + center -> y);
            }
            glEnd();
            glFlush();
        }
};

void display(void) 
{
    glClear(GL_COLOR_BUFFER_BIT);

    float x = (0.26);
    float y = sqrt((0.3) * (0.3) - x * x);

    float points[7][2] = {{0, 0}, {0, 0.3}, {0, -0.3}, {x, y}, {-x, -y}, {x, -y}, {-x, y}};
    for (int i = 0; i < 7; i++) {
        float rand1 = 65.0 / 255;
        float rand2 = 105.0 / 255;
        float rand3 = 225.0 / 255;
        glColor3f(rand1, rand2, rand3);
        Point *center = new Point(points[i][0], points[i][1], 0);
        Circle *circle = new Circle(center, 0.3);
        circle -> drawCircle();
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



