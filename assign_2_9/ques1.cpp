#include <GL/glut.h>

class Point {
    public:
    float x;
    float y;

    Point(float newx, float newy) {
        x = newx;
        y = newy;
    }
};

class Color {
    public:
    float r, g, b;

    Color(float newr, float newg, float newb) {
        r = newr;
        g = newg;
        b = newb;
    }
};

void draw_needle(Point p1, Point p2, Color c)
{
    Point p3 (0, 0);
    if (p1.x == p2.x) {
        p3 = Point(4 * p1.x, 0);
    } else {
        p3 = Point(0, 4 * p1.y);
    }

    glBegin(GL_POLYGON);
    glColor3f(c.r, c.g, c.b);

    glVertex2f(0, 0);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p3.x, p3.y);
    glVertex2f(p2.x, p2.y);
    glVertex2f(0, 0);

    glEnd();
    glFlush();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    float points[4][2] = {{-0.2, 0.2}, {0.2, 0.2}, {0.2, -0.2}, {-0.2, -0.2}};
    float colors[4][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {1, 1, 1}};

    for (int i = 0; i < 4; i++) {
        Point p1 = Point(points[i][0], points[i][1]);
        Point p2 = Point(points[(i+1) % 4][0], points[(i+1)%4][1]);
        Color c = Color(colors[i][0], colors[i][1], colors[i][2]);

        draw_needle(p1, p2, c);
    }
}

void init(Color c)
{
    glClearColor(c.r, c.g, c.b, 0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(300, 300);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Question 1");

    init(Color(0.75, 0.75, 0.75));

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


