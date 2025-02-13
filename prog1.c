#include <GL/glut.h>
#include <math.h>
int x, y;
int dx, dy, p, k;
int incx = 1, incy = 1;

void myinit()
{
    glClearColor(1, 1, 1, 0);   // clear background to white
    gluOrtho2D(0, 500, 0, 500); // set the coordinate frame
}

void plotpoints(int x, int y)
{
    glColor3d(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();
}

void bresenhams(int x1, int y11, int x2, int y2)
{
    if (x2 < x1)
        incx = -1;
    if (y2 < y11)
        incy = -1;

    x = x1;
    y = y11;
    plotpoints(x, y);
    dx = abs(x2 - x1);
    dy = abs(y2 - y11);
    p = 2 * dy - dx;

    // positive and Negative slop
    if (dx > dy) // m<1
    {
        for (k = 0; k < dx; k++)
        {
            if (p < 0)
            {
                x = x + incx;
                y = y;
                p = p + 2 * dy;
            }
            else
            {
                x = x + incx;
                y = y + incy;
                p = p + 2 * dy - 2 * dx;
            }
            plotpoints(x, y);
        }
    }

    // m>1
    else
    {
        for (k = 0; k < dy; k++)
        {
            if (p < 0)
            {
                y = y + incy;
                x = x;
                p = p + 2 * dx;
            }
            else
            {
                x = x + incx;
                y = y + incy;
                p = p + 2 * dx - 2 * dy;
            }
            plotpoints(x, y);
        }
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // clears the color

    bresenhams(100, 100, 300, 150); // m<1 for +ve slope
    bresenhams(100, 100, 150, 300); // m>1
    bresenhams(100, 100, 300, 300); // m=1

    bresenhams(300, 50, 20, 20);  // m<1 for -ve slope
    bresenhams(50, 300, 20, 20);  // m>1
    bresenhams(400, 400, 50, 50); // m=1

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Line Drawing Program");
    myinit();
    glutDisplayFunc(display);
    glutMainLo op();
    return 0;
}