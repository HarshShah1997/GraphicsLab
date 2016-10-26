#include <GL/glut.h>
#include <iostream>
#include <vector>
#include "../matrix.h"
#include <cmath>
using namespace std;

class vec {
    public:
        float x;
        float y;
        vec(float x1, float y1) {
            x = x1;
            y = y1;
        }
};

vec* sub(vec* v1, vec* v2)
{
    return new vec(v1->x - v2->x, v1->y - v2->y);
}

float cross(vec* v1, vec* v2)
{
    return v1 -> x * v2 -> y - v1 -> y * v2 -> x;
}

vec* intersect(vec* p1, vec* p2, vec* p3, vec* p4)
{
    float deno = (p1->x - p2->x)*(p3->y - p4->y) - (p1->y - p2->y)*(p3->x - p4->x);
    float num_one = (p1->x*p2->y - p1->y*p2->x);
    float num_two = (p3->x*p4->y - p3->y*p4->x);

    float num_x = num_one * (p3->x - p4->x) - num_two * (p1->x - p2->x);
    float num_y = num_one * (p3->y - p4->y) - num_two * (p1->y - p2->y);

    return new vec(num_x / deno, num_y / deno);
}

int main(int argc, char *argv[])
{
    Matrix *p1 = new Matrix(3, 1);
    p1 -> elementAt[0][0] = 14;
    p1 -> elementAt[1][0] = 0;

    Matrix *p2 = new Matrix(3, 1);
    p2 -> elementAt[0][0] = 14;
    p2 -> elementAt[1][0] = 8;

    Matrix *rot = new Matrix(3, 3);

    float angle = 0.1;

    for (int i = 0; i < 5; i++) {
        rot -> elementAt[0][0] = cos(angle);
        rot -> elementAt[0][1] = -sin(angle);
        rot -> elementAt[1][0] = sin(angle);
        rot -> elementAt[1][1] = cos(angle);

        p1 -> elementAt[0][0] -= 11;
        p2 -> elementAt[0][0] -= 11;

        p1 = multiply(rot, p1);
        p2 = multiply(rot, p2);

        p1 -> elementAt[0][0] += 11;
        p2 -> elementAt[0][0] += 11;
        cout << p1 -> elementAt[0][0] << " " << p1 -> elementAt[1][0] << ", ";
        cout << p2 -> elementAt[0][0] << " " << p2 -> elementAt[1][0] << endl;

    }
    return 0;
}
