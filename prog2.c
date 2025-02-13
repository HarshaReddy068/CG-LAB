#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float p[3][3] = {{0, 200, 100}, {0, 0, 100}, {1, 1, 1}};
float t[3][3] = {{1, 0, 200}, {0, 1, 0}, {0, 0, 1}};
float res[3][3];

void myinit()
{
    glClearColor(1, 1, 1, 10);
    gluOrtho2D(-500, 500, -500, 500);
}

void triangle(float tri[3][3])
{

    glBegin(GL_TRIANGLES);
    glVertex2d(tri[0][0], tri[1][0]);
    glVertex2d(tri[0][1], tri[1][1]);
    glVertex2d(tri[0][2], tri[1][2]);
    glEnd();
}

void matrixmul(float T[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < 3; k++)
                res[i][j] = res[i][j] + T[i][k] * p[k][j];
        }
}

void translate()
{
    printf("Enter the values of Tx and Ty: ");
    scanf("%f %f", &t[0][2], &t[1][2]);
    matrixmul(t);
    glColor3d(0, 1, 0);
    triangle(res);
}

void scaling()
{
    float s[3][3] = {{2, 0, 0}, {0, 2, 0}, {0, 0, 2}};
    printf("Enter the values of Sx and Sy: ");
    scanf("%f %f", &s[0][0], &s[1][1]);
    matrixmul(s);
    glColor3d(0, 0, 1);
    triangle(res);
}

void rotation()
{
    float theta = 0;
    printf("Enter the angle: ");
    scanf("%f", &theta);
    float angle = theta * 3.14 / 180;
    float cosx = cos(angle);
    float sinx = sin(angle);
    float rr[3][3] = {{cosx, -sinx, 0}, {sinx, cosx, 0}, {0, 0, 1}};
    matrixmul(rr);
    glColor3d(0, 0, 1);
    triangle(res);
}

void displayMe()
{
    while (1)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        int ch;
        printf("Enter the choice \n0: For Normal Triangle \n1: For Translation \n2: For Scaling \n3: For Rotation \n4: Exit \n");
        scanf("%d", &ch);
        glColor3d(1, 1, 1); // Color of the Object

        switch (ch)
        {
        case 0:
            triangle(p);
            break;
        case 1:
            translate();
            break;
        case 2:
            scaling();
            break;
        case 3:
            rotation();
            break;
        case 4:
            exit(0);
        default:
            printf("Enter a valid choice: ");
        }
        glColor3d(1, 0, 0);
        triangle(p);
        glFlush();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("1CR21CS068");
    myinit();
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}
