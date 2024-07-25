#include <GL/glut.h>

float ambient[] = {1, 1, 1, 1};
float light_pos[] = {2, 2, 2, 1};
static float theta[3] = {0, 0, 0};
int axis = 0;
int ch = 1;

void mouse(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        axis = 0;
    if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
        axis = 1;
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
        axis = 2;
}

void idle()
{
    theta[axis] += 2;
    if (theta[axis] > 360)
        theta[axis] = 0;
    glutPostRedisplay();
}

void display()
{
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(theta[0], 1, 0, 0); // conclude by rotation about x
    glRotatef(theta[1], 0, 1, 0); // conclude by rotation about y
    glRotatef(theta[2], 0, 0, 1); // then rotation about z
    if (ch == 1)
        glutSolidCube(1);
    if (ch == 2)
        glutSolidTeapot(0.5);
    glFlush();
    glutSwapBuffers();
}

void choice(int id)
{
    
    switch (id)
    {
    case 1:
        ch = 1;
        break;
    case 2:
        ch = 2;
        break;
    default:
        exit(0);
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("1CR21CS068");
    glutDisplayFunc(display);
    glutCreateMenu(choice);
    glutAddMenuEntry("Solid Cube", 1);
    glutAddMenuEntry("Tea pot", 2);
    glutAddMenuEntry("Exit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glutMouseFunc(mouse);
    glutIdleFunc(idle);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}