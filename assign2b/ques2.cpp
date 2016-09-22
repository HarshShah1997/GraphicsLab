#include <GL/glut.h>
#include <bits/stdc++.h>

typedef float Matrix3x3 [3][3];
typedef float Matrix3x4 [3][4];
Matrix3x4 theMatrix;
float refpt[2];
void matrixSetIdentity(Matrix3x3 m)
/// Initialize the matrix as Unit Matrix
{
   int i, j;
   for (i=0; i<3; i++)
        for (j=0; j<3; j++)
            m[i][j] = (i == j);
}
void matrixPreMultiply(Matrix3x3 a , Matrix3x4 b)
/// Multiplies matrix a times b, putting result in theMatrix
{
   int i,j;
   Matrix3x4 tmp;
   for (i = 0; i < 3; i++)
     for (j = 0; j < 4; j++)
        tmp[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j] + a[i][2]*b[2][j];

   for (i = 0; i < 3; i++)
     for (j = 0; j < 4; j++)
       theMatrix[i][j] = tmp[i][j];
}
void Translate(int tx, int ty)
{
   Matrix3x3 m;
   int i,j;
   matrixSetIdentity(m);
   m[0][2] = tx;
   m[1][2] = ty;
   matrixPreMultiply(m, theMatrix);
}

void Scale(float sx , float sy)
{
   Matrix3x3 m;
   matrixSetIdentity(m);
   m[0][0] = sx;
   m[0][2] = (1 - sx)*refpt[0];
   m[1][1] = sy;
   m[1][2] = (1 - sy)*refpt[1];
   matrixPreMultiply(m , theMatrix);
}

void Rotate(float a)
{
   Matrix3x3 m;
   matrixSetIdentity(m);
   a = a*22/1260;
   m[0][0] = cos(a);
   m[0][1] = -sin(a) ;
   m[0][2] = refpt[0]*(1 - cos(a)) + refpt[1]*sin(a);
   m[1][0] = sin(a);
   m[1][1] = cos(a);
   m[1][2] = refpt[1]*(1 - cos(a)) - refpt[0]*sin(a);
   matrixPreMultiply(m , theMatrix);
}

void init2D(float r, float g, float b)
{
    /// glClearColor sets the colour to clear the buffer to.
    glClearColor(r,g,b,0.0);
    /// used to set up the view volume,GL_MODELVIEW can be used to set up viewing transformation
    glMatrixMode(GL_PROJECTION);
    /// gluOrtho2D specifies the coordinates tobe used with the viewport which defaults to the window size.
    gluOrtho2D(0.0, 200.0, 0.0, 200.0);
}
void display(void)
{
    /// clear the buffers currently enabled for color writing.
   // Matrix3x3 identity,temp;
    glClear(GL_COLOR_BUFFER_BIT);
    ///glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    /// co-ordinates yellow square
    glVertex3f(100.0f, 10.0f, 1.0f);
    glVertex3f(104.0f, 13.999999f, 1.0f);
    glVertex3f(100.0f, 18.0f, 1.0f);
    glVertex3f(96.0f, 13.999999f, 1.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    /// co-ordinates green square
    glVertex3f(93.878679f, 16.121320f, 1.0f);
    glVertex3f(89.878679f, 20.121320f, 1.0f);
    glVertex3f(93.878679f, 24.121320f, 1.0f);
    glVertex3f(97.878679f, 20.121320f, 1.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    /// co-ordinates red square
    glVertex3f(96.0f, 26.2426403f, 1.0f);
    glVertex3f(100.0f, 30.2426403f, 1.0f);
    glVertex3f(104.0f, 26.2426403f, 1.0f);
    glVertex3f(100.0f, 22.2426403f, 1.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    /// co-ordinates blue square
    glVertex3f(106.12132034356f, 24.12132024356f, 1.0f);
    glVertex3f(110.1213203f, 20.121320f, 1.0f);
    glVertex3f(106.12132034356f, 16.12132024356f, 1.0f);
    glVertex3f(102.1213203f, 20.121320f, 1.0f);
    glEnd();
    ///---------------------------------------------------- RED
    theMatrix[0][0] = 96.0f,theMatrix[1][0] = 26.2426403f,theMatrix[2][0] = 1.0;        ///point A
    theMatrix[0][1] = 100.0f,theMatrix[1][1] = 30.2426403f,theMatrix[2][1] = 1.0;       ///point B
    theMatrix[0][2] = 104.0f,theMatrix[1][2] = 26.2426403f,theMatrix[2][2] = 1.0;      ///point C
    theMatrix[0][3] = 100.0f,theMatrix[1][3] = 22.2426403f,theMatrix[2][3]= 1.0f;       ///point D
    ///translation to origin
    Translate(-100.0f,- 34.2426403f);
    ///Rotation
    Rotate(90);
    ///translation to 100,150
    Translate(100.0f,34.2426403f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    /// co-ordinates of all three vertex of the triangle after translation
    glVertex3f(theMatrix[0][0], theMatrix[1][0], theMatrix[2][0]);
    glVertex3f(theMatrix[0][1], theMatrix[1][1], theMatrix[2][1]);
    glVertex3f(theMatrix[0][2], theMatrix[1][2], theMatrix[2][2]);
    glVertex3f(theMatrix[0][3], theMatrix[1][3], theMatrix[2][3]);
    glEnd();
    ///----------------------------------------------------
    theMatrix[0][0] = 96.0f,theMatrix[1][0] = 26.2426403f,theMatrix[2][0] = 1.0;        ///point A
    theMatrix[0][1] = 100.0f,theMatrix[1][1] = 30.2426403f,theMatrix[2][1] = 1.0;       ///point B
    theMatrix[0][2] = 104.0f,theMatrix[1][2] = 26.2426403f,theMatrix[2][2] = 1.0;      ///point C
    theMatrix[0][3] = 100.0f,theMatrix[1][3] = 22.2426403f,theMatrix[2][3]= 1.0f;       ///point D
    ///traslation to origin
    Translate(-100.0f,- 34.2426403f);
    ///Rotation
    Rotate(180);
    ///translation to 100,150
    Translate(100.0f,34.2426403f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    /// co-ordinates of all three vertex of the triangle after translation
    glVertex3f(theMatrix[0][0], theMatrix[1][0], theMatrix[2][0]);
    glVertex3f(theMatrix[0][1], theMatrix[1][1], theMatrix[2][1]);
    glVertex3f(theMatrix[0][2], theMatrix[1][2], theMatrix[2][2]);
    glVertex3f(theMatrix[0][3], theMatrix[1][3], theMatrix[2][3]);
    glEnd();
    ///---------------------------------------------------------
    theMatrix[0][0] = 96.0f,theMatrix[1][0] = 26.2426403f,theMatrix[2][0] = 1.0;        ///point A
    theMatrix[0][1] = 100.0f,theMatrix[1][1] = 30.2426403f,theMatrix[2][1] = 1.0;       ///point B
    theMatrix[0][2] = 104.0f,theMatrix[1][2] = 26.2426403f,theMatrix[2][2] = 1.0;      ///point C
    theMatrix[0][3] = 100.0f,theMatrix[1][3] = 22.2426403f,theMatrix[2][3]= 1.0f;       ///point D
    ///traslation to origin
    Translate(-100.0f,- 34.2426403f);
    ///Rotation
    Rotate(270);
    ///translation to 100,150
    Translate(100.0f,34.2426403f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    /// co-ordinates of all three vertex of the triangle after translation
    glVertex3f(theMatrix[0][0], theMatrix[1][0], theMatrix[2][0]);
    glVertex3f(theMatrix[0][1], theMatrix[1][1], theMatrix[2][1]);
    glVertex3f(theMatrix[0][2], theMatrix[1][2], theMatrix[2][2]);
    glVertex3f(theMatrix[0][3], theMatrix[1][3], theMatrix[2][3]);
    glEnd();


    ///---------------------------------------------------- BLUE
    theMatrix[0][0] = 106.12132034356f,theMatrix[1][0] =24.12132024356f,theMatrix[2][0] = 1.0;        ///point A
    theMatrix[0][1] = 110.1213203f,theMatrix[1][1] = 20.121320f,theMatrix[2][1] = 1.0;       ///point B
    theMatrix[0][2] = 106.12132034356f,theMatrix[1][2] = 16.12132024356f,theMatrix[2][2] = 1.0;      ///point C
    theMatrix[0][3] = 102.1213203f,theMatrix[1][3] = 20.121320f,theMatrix[2][3]= 1.0f;       ///point D
    ///translation to origin
    Translate(-100.0f,- 34.2426403f);
    ///Rotation
    Rotate(90);
    ///translation to 100,150
    Translate(100.0f,34.2426403f);
    glBegin(GL_POLYGON);
   glColor3f(0.0f, 0.0f, 1.0f);
    /// co-ordinates of all three vertex of the triangle after translation
    glVertex3f(theMatrix[0][0], theMatrix[1][0], theMatrix[2][0]);
    glVertex3f(theMatrix[0][1], theMatrix[1][1], theMatrix[2][1]);
    glVertex3f(theMatrix[0][2], theMatrix[1][2], theMatrix[2][2]);
    glVertex3f(theMatrix[0][3], theMatrix[1][3], theMatrix[2][3]);
    glEnd();
    ///----------------------------------------------------
    theMatrix[0][0] = 106.12132034356f,theMatrix[1][0] =24.12132024356f,theMatrix[2][0] = 1.0;        ///point A
    theMatrix[0][1] = 110.1213203f,theMatrix[1][1] = 20.121320f,theMatrix[2][1] = 1.0;       ///point B
    theMatrix[0][2] = 106.12132034356f,theMatrix[1][2] = 16.12132024356f,theMatrix[2][2] = 1.0;      ///point C
    theMatrix[0][3] = 102.1213203f,theMatrix[1][3] = 20.121320f,theMatrix[2][3]= 1.0f;       ///point D
    ///traslation to origin
    Translate(-100.0f,- 34.2426403f);
    ///Rotation
    Rotate(180);
    ///translation to 100,150
    Translate(100.0f,34.2426403f);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    /// co-ordinates of all three vertex of the triangle after translation
    glVertex3f(theMatrix[0][0], theMatrix[1][0], theMatrix[2][0]);
    glVertex3f(theMatrix[0][1], theMatrix[1][1], theMatrix[2][1]);
    glVertex3f(theMatrix[0][2], theMatrix[1][2], theMatrix[2][2]);
    glVertex3f(theMatrix[0][3], theMatrix[1][3], theMatrix[2][3]);
    glEnd();
    ///---------------------------------------------------------
    theMatrix[0][0] = 106.12132034356f,theMatrix[1][0] =24.12132024356f,theMatrix[2][0] = 1.0;        ///point A
    theMatrix[0][1] = 110.1213203f,theMatrix[1][1] = 20.121320f,theMatrix[2][1] = 1.0;       ///point B
    theMatrix[0][2] = 106.12132034356f,theMatrix[1][2] = 16.12132024356f,theMatrix[2][2] = 1.0;      ///point C
    theMatrix[0][3] = 102.1213203f,theMatrix[1][3] = 20.121320f,theMatrix[2][3]= 1.0f;       ///point D
    ///traslation to origin
    Translate(-100.0f,- 34.2426403f);
    ///Rotation
    Rotate(270);
    ///translation to 100,150
    Translate(100.0f,34.2426403f);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    /// co-ordinates of all three vertex of the triangle after translation
    glVertex3f(theMatrix[0][0], theMatrix[1][0], theMatrix[2][0]);
    glVertex3f(theMatrix[0][1], theMatrix[1][1], theMatrix[2][1]);
    glVertex3f(theMatrix[0][2], theMatrix[1][2], theMatrix[2][2]);
    glVertex3f(theMatrix[0][3], theMatrix[1][3], theMatrix[2][3]);
    glEnd();
    ///---------------------------------------------------- YELLOW
    theMatrix[0][0] = 100.0f,theMatrix[1][0] =10.0f,theMatrix[2][0] = 1.0;        ///point A
    theMatrix[0][1] = 104.0,theMatrix[1][1] = 13.999999f,theMatrix[2][1] = 1.0;       ///point B
    theMatrix[0][2] = 100.0f,theMatrix[1][2] = 18.0f,theMatrix[2][2] = 1.0;      ///point C
    theMatrix[0][3] = 96.0f,theMatrix[1][3] = 13.999999f,theMatrix[2][3]= 1.0f;       ///point D
    ///translation to origin
    Translate(-100.0f,- 34.2426403f);
    ///Rotation
    Rotate(90);
    ///translation to 100,150
    Translate(100.0f,34.2426403f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    /// co-ordinates of all three vertex of the triangle after translation
    glVertex3f(theMatrix[0][0], theMatrix[1][0], theMatrix[2][0]);
    glVertex3f(theMatrix[0][1], theMatrix[1][1], theMatrix[2][1]);
    glVertex3f(theMatrix[0][2], theMatrix[1][2], theMatrix[2][2]);
    glVertex3f(theMatrix[0][3], theMatrix[1][3], theMatrix[2][3]);
    glEnd();
    ///----------------------------------------------------
    theMatrix[0][0] = 100.0f,theMatrix[1][0] =10.0f,theMatrix[2][0] = 1.0;        ///point A
    theMatrix[0][1] = 104.0,theMatrix[1][1] = 13.999999f,theMatrix[2][1] = 1.0;       ///point B
    theMatrix[0][2] = 100.0f,theMatrix[1][2] = 18.0f,theMatrix[2][2] = 1.0;      ///point C
    theMatrix[0][3] = 96.0f,theMatrix[1][3] = 13.999999f,theMatrix[2][3]= 1.0f;       ///point D
    ///traslation to origin
    Translate(-100.0f,- 34.2426403f);
    ///Rotation
    Rotate(180);
    ///translation to 100,150
    Translate(100.0f,34.2426403f);
    glBegin(GL_POLYGON);
     glColor3f(1.0f, 1.0f, 0.0f);
    /// co-ordinates of all three vertex of the triangle after translation
    glVertex3f(theMatrix[0][0], theMatrix[1][0], theMatrix[2][0]);
    glVertex3f(theMatrix[0][1], theMatrix[1][1], theMatrix[2][1]);
    glVertex3f(theMatrix[0][2], theMatrix[1][2], theMatrix[2][2]);
    glVertex3f(theMatrix[0][3], theMatrix[1][3], theMatrix[2][3]);
    glEnd();
    ///---------------------------------------------------------
    theMatrix[0][0] = 100.0f,theMatrix[1][0] =10.0f,theMatrix[2][0] = 1.0;        ///point A
    theMatrix[0][1] = 104.0,theMatrix[1][1] = 13.999999f,theMatrix[2][1] = 1.0;       ///point B
    theMatrix[0][2] = 100.0f,theMatrix[1][2] = 18.0f,theMatrix[2][2] = 1.0;      ///point C
    theMatrix[0][3] = 96.0f,theMatrix[1][3] = 13.999999f,theMatrix[2][3]= 1.0f;       ///point D
    ///traslation to origin
    Translate(-100.0f,- 34.2426403f);
    ///Rotation
    Rotate(270);
    ///translation to 100,150
    Translate(100.0f,34.2426403f);
    glBegin(GL_POLYGON);
     glColor3f(1.0f, 1.0f, 0.0f);
    /// co-ordinates of all three vertex of the triangle after translation
    glVertex3f(theMatrix[0][0], theMatrix[1][0], theMatrix[2][0]);
    glVertex3f(theMatrix[0][1], theMatrix[1][1], theMatrix[2][1]);
    glVertex3f(theMatrix[0][2], theMatrix[1][2], theMatrix[2][2]);
    glVertex3f(theMatrix[0][3], theMatrix[1][3], theMatrix[2][3]);
    glEnd();
    ///---------------------------------------------------- GREEN
    theMatrix[0][0] = 93.878679f,theMatrix[1][0] = 16.121320f,theMatrix[2][0] = 1.0;        ///point A
    theMatrix[0][1] = 89.878679f,theMatrix[1][1] = 20.121320f,theMatrix[2][1] = 1.0;       ///point B
    theMatrix[0][2] = 93.878679f,theMatrix[1][2] = 24.121320f,theMatrix[2][2] = 1.0;      ///point C
    theMatrix[0][3] = 97.878679f,theMatrix[1][3] = 20.121320f,theMatrix[2][3]= 1.0f;       ///point D
    ///translation to origin
    Translate(-100.0f,- 34.2426403f);
    ///Rotation
    Rotate(90);
    ///translation to 100,150
    Translate(100.0f,34.2426403f);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    /// co-ordinates of all three vertex of the triangle after translation
    glVertex3f(theMatrix[0][0], theMatrix[1][0], theMatrix[2][0]);
    glVertex3f(theMatrix[0][1], theMatrix[1][1], theMatrix[2][1]);
    glVertex3f(theMatrix[0][2], theMatrix[1][2], theMatrix[2][2]);
    glVertex3f(theMatrix[0][3], theMatrix[1][3], theMatrix[2][3]);
    glEnd();
    ///----------------------------------------------------
    theMatrix[0][0] = 93.878679f,theMatrix[1][0] = 16.121320f,theMatrix[2][0] = 1.0;        ///point A
    theMatrix[0][1] = 89.878679f,theMatrix[1][1] = 20.121320f,theMatrix[2][1] = 1.0;       ///point B
    theMatrix[0][2] = 93.878679f,theMatrix[1][2] = 24.121320f,theMatrix[2][2] = 1.0;      ///point C
    theMatrix[0][3] = 97.878679f,theMatrix[1][3] = 20.121320f,theMatrix[2][3]= 1.0f;       ///point D
    ///traslation to origin
    Translate(-100.0f,- 34.2426403f);
    ///Rotation
    Rotate(180);
    ///translation to 100,150
    Translate(100.0f,34.2426403f);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    /// co-ordinates of all three vertex of the triangle after translation
    glVertex3f(theMatrix[0][0], theMatrix[1][0], theMatrix[2][0]);
    glVertex3f(theMatrix[0][1], theMatrix[1][1], theMatrix[2][1]);
    glVertex3f(theMatrix[0][2], theMatrix[1][2], theMatrix[2][2]);
    glVertex3f(theMatrix[0][3], theMatrix[1][3], theMatrix[2][3]);
    glEnd();
    ///---------------------------------------------------------
    theMatrix[0][0] = 93.878679f,theMatrix[1][0] = 16.121320f,theMatrix[2][0] = 1.0;        ///point A
    theMatrix[0][1] = 89.878679f,theMatrix[1][1] = 20.121320f,theMatrix[2][1] = 1.0;       ///point B
    theMatrix[0][2] = 93.878679f,theMatrix[1][2] = 24.121320f,theMatrix[2][2] = 1.0;      ///point C
    theMatrix[0][3] = 97.878679f,theMatrix[1][3] = 20.121320f,theMatrix[2][3]= 1.0f;       ///point D
    ///traslation to origin
    Translate(-100.0f,- 34.2426403f);
    ///Rotation
    Rotate(270);
    ///translation to 100,150
    Translate(100.0f,34.2426403f);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    /// co-ordinates of all three vertex of the triangle after translation
    glVertex3f(theMatrix[0][0], theMatrix[1][0], theMatrix[2][0]);
    glVertex3f(theMatrix[0][1], theMatrix[1][1], theMatrix[2][1]);
    glVertex3f(theMatrix[0][2], theMatrix[1][2], theMatrix[2][2]);
    glVertex3f(theMatrix[0][3], theMatrix[1][3], theMatrix[2][3]);
    glEnd();

    glFlush();
}
int main(int argc, char *argv[])
{
    /// glutInit will initialize the GLUT library and negotiate a session with the window system.
    glutInit(&argc,argv);
    /// Select a display mode with single buffer because its a simple application and Red, green, blue framebuffer
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Square");
    init2D(0.0, 0.0, 0.0);
    /// calls the function display everytime the display needs to be updated
    glutDisplayFunc(display);
    glutMainLoop();
}
