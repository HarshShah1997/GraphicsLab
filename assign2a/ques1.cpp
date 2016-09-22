#include "../matrix.h"
#include <GL/glut.h>
#include <math.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    Matrix* triangle[3];

    triangle[0] = new Matrix(3, 1);
    triangle[0] -> elementAt[0][0] = -0.5;
    triangle[0] -> elementAt[1][0] = -0.5;

    triangle[1] = new Matrix(3, 1);
    triangle[1] -> elementAt[0][0] = 0.5;
    triangle[1] -> elementAt[1][0] = -0.5;
    
    triangle[2] = new Matrix(3, 1);
    triangle[2] -> elementAt[0][0] = 0;
    triangle[2] -> elementAt[1][0] = 0.5;

    double factor = 0.5;
    Matrix* scaling  = new Matrix(3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                scaling -> elementAt[i][j] = factor;
            } else {
                scaling -> elementAt[i][j] = 0;
            }
        }
    }
    Matrix* rotate = new Matrix(3, 3);
    rotate -> elementAt[0][1] = -1;
    rotate -> elementAt[1][0] = 1;

    Matrix* translate = new Matrix(3, 1);
    translate -> elementAt[0][0] = 0;
    translate -> elementAt[1][0] = 0.5;
    

    Matrix* transformed[3];
    for (int i = 0; i < 3; i++) {
        transformed[i] = add(translate, multiply(rotate, multiply(scaling, triangle[i])));
    }

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++) {
        glVertex2f(transformed[i] -> elementAt[0][0], transformed[i] -> elementAt[1][0]);
    }
    glEnd();
    glFlush();
}

void init(float r, float g, float b)
{
    glClearColor(r, g, b, 1.0);
    glMatrixMode(GL_PROJECTION);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Question 1");
    init(0.75, 0.75, 0.75);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
