#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

typedef float point[3];
point v[] = {{0.0, 0.0, 1.0},
             {0.0, 1.0, 0.0},
             {-1.0, -1.0, 0.0},
             {1.0, -1.0, 0.0}};

int n;

void triangle(point a, point b, point c)
{
    glBegin(GL_TRIANGLES);
    glVertex3fv(a);
    glVertex3fv(b);
    glVertex3fv(c);
    glEnd();
}

void divide_tri(point a, point b, point c, int m)
{
    if (m == 0)
    {
        triangle(a, b, c);
        return;
    }
    else if (m > 0)
    {
        point v1, v2, v3;
        for (int i = 0; i < 3; i++)
        {
            v1[i] = (a[i] + b[i]) / 2;
        }
        for (int i = 0; i < 3; i++)
        {
            v2[i] = (a[i] + c[i]) / 2;
        }
        for (int i = 0; i < 3; i++)
        {
            v3[i] = (b[i] + c[i]) / 2;
        }
        divide_tri(a, v1, v2, m - 1);
        divide_tri(c, v2, v3, m - 1);
        divide_tri(b, v3, v1, m - 1);
    }
}

void tetrahedron(int m)
{
    glColor3f(1, 0, 0);
    divide_tri(v[0], v[1], v[2], m);
    glColor3f(0, 0, 0);
    divide_tri(v[3], v[2], v[1], m);
    glColor3f(0, 1, 0);
    divide_tri(v[0], v[3], v[1], m);
    glColor3f(0, 0, 1);
    divide_tri(v[0], v[2], v[3], m);
}

void myinit()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
}

void display()
{
    tetrahedron(n);
    glFlush();
}

int main(int argc, char **argv)
{
    printf("Enter the no.of recursive steps: ");
    scanf("%d", &n);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("1CR21CS068");
    myinit();
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}





