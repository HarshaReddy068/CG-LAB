#include <GL/glut.h>

void myinit()
{
    glClearColor(1, 1, 1, 0);   // clear background to white
    gluOrtho2D(0, 500, 0, 500); // set the coordinate frame
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // clears the color buffer
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
    glutMainLoop();
    return 0;
}