#include <GL/glut.h>

void myinit()
{
    glClearColor(1, 1, 1, 0);   // clear background to white
    gluOrtho2D(0, 500, 0, 500); // set the coordinate frame
}

void triangle()
{
    glBegin(GL_TRIANGLES);
    glVertex2d(100, 100);
    glVertex2d(200, 100);
    glVertex2d(150, 150);
    glEnd();
}

void translate()
{
    glPushMatrix();
    glTranslated(100, 0, 0);
    triangle();
    glPopMatrix();
}

void rotate()
{
    glPushMatrix();
    glRotated(45, 0, 0, 1);
    triangle();
    glPopMatrix();
}

void rotate_pivot()
{
    glPushMatrix();
    glTranslated(100, 100, 0);
    glRotated(45, 0, 0, 1);
    glTranslated(-100, -100, 0);
    triangle();
    glPopMatrix();
}

void scaling()
{
    glPushMatrix();
    glScaled(2, 2, 1);
    triangle();
    glPopMatrix();
}

void scaling_pivot()
{
    glPushMatrix();
    glTranslated(100, 100, 0);
    glScaled(2, 2, 1);
    glTranslated(-100, -100, 0);
    triangle();
    glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1, 0, 0);
    triangle();
    glFlush();
}

void menu_transformation(int id)
{

    switch (id)
    {
    case 1:
        glColor3d(1, 0, 1);
        translate();
        break;
    case 2:
        glColor3d(1, 0, 0);
        rotate();
        break;
    case 3:
        glColor3d(1, 0, 1);
        rotate_pivot();
        break;
    case 4:
        glColor3d(1, 0, 0);
        scaling();
        break;
    case 5:
        glColor3d(0, 0, 1);
        scaling_pivot();
        break;
    default:
        exit(0);
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("1CR21CS068");
    myinit();
    glutCreateMenu(menu_transformation);
    glutAddMenuEntry("Translate", 1);
    glutAddMenuEntry("Rotate about origin", 2);
    glutAddMenuEntry("Rotate about pivot point", 3);
    glutAddMenuEntry("Scaling", 4);
    glutAddMenuEntry("Scaling about pivot point", 5);
    glutAddMenuEntry("Exit", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}