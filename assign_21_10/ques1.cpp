#include <GL/glut.h>
#include <iostream>
#include <vector>
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


void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    float vertices[6][2] = {{-0.4, 0.2}, {-0.2, 0.7}, {0.3, 0.6}, {0.5, -0.2}, {0.1, -0.8}, {-0.3, -0.4}};
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);

    float clipvertices[4][2] = {{-0.3, -0.7}, {-0.3, 0.3}, {0.4, 0.3}, {0.4, -0.7}};

    vector<vec*> inputList;

    for (int i = 0; i < 6; i++) {
        inputList.push_back(new vec(vertices[i][0], vertices[i][1]));
    }

    vector<vec*> outputList;

    for (int i = 0; i < 2; i++) {
        vec* v1 = new vec(clipvertices[i][0], clipvertices[i][1]);
        vec* v2 = new vec(clipvertices[(i+1)%4][0], clipvertices[(i+1)%4][1]);
        vec* edge = sub(v2, v1);
        vec* S;
        if (i == 0) {
            S = inputList[inputList.size() - 1];
        } else {
            S = outputList[outputList.size() - 1];
        }
        
        cout << ">S " << S -> x << " " << S -> y << endl;

        for (vector<vec*>::iterator it = inputList.begin(); it != inputList.end(); it++) {
            vec* E = *it;
            cout << ">E " << E -> x << " " << E -> y << endl;

            float resS = cross(edge, sub(S, v1));
            float resE = cross(edge, sub(E, v1));

            cout << "r " << resS << " " << resE << endl;

            if (resE < 0) {
                if (resS >= 0) {
                    outputList.push_back(intersect(v1, v2, S, E));
                }
                outputList.push_back(E);
            } else if (resS < 0) {
                outputList.push_back(intersect(v1, v2, S, E));
            }
            S = E;
        }
    }

    for (int i = 0; i < outputList.size(); i++) {
       cout << outputList[i]->x << " " << outputList[i]->y << endl;
       glVertex2f(outputList[i]->x, outputList[i]->y);
    }
    glEnd();


    //glVertex2f(-0.4, 0.2);
    //glVertex2f(-0.2, 0.7);
    //glVertex2f(0.3, 0.6);
    //glVertex2f(0.5, -0.2);
    //glVertex2f(0.1, -0.8);
    //glVertex2f(-0.3, -0.4);
    //glEnd();

    glutSwapBuffers();
}

void init(float r, float g, float b)
{
    glClearColor(r, g, b, 0);
    //gluOrtho2D(-4, 4, -4, 4);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 300);
    glutCreateWindow("Question 1");
    init(1, 1, 1);
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
