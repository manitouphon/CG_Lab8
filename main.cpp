#include <stdio.h>

#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif  (__linux__)
#include <GL/glut.h>
#elif  (__APPLE__)
#include <GLUT/glut.h>
#endif




#include "display.hpp"
#include "rasterView.hpp"

Color background;
Color primaryColor;
Color secondaryColor;

float boundaryWidth;
float boundaryHeight;
float delta;


float target1[2] = {12.5, 12.5};
float target2[2] = {22.5, 97.5};
float targetWidth = 1;

int mainWindow;
int rWindow;

bool doDDA = false;
bool doMidpoint = false;

void init(void)
{

    glClearColor(background.getR(), background.getG(), background.getB(), 0.0);
    //change projection mode
    glMatrixMode(GL_PROJECTION);
    glShadeModel(GL_SMOOTH);
    // set current matrix to identiy matrix

    glLoadIdentity();
    gluOrtho2D(-5, 120.0, -5, 120.0);
}

int main(int argc, char **argv)
{
    primaryColor.setColor(0.0, 0.5, 1.0);
    secondaryColor.setColor(1.0, 0.0, 0.0);
    background.setColor(1.0, 1.0, 1.0);
    boundaryWidth = 100;
    boundaryHeight = 100;
    delta = 5;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    //Init main window
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    mainWindow = glutCreateWindow("Lab 7 (Main)");
    init();
    glutDisplayFunc(display);
    createMenu();

    //Init Raster view mode window
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(600, 00);
    rWindow = glutCreateWindow("Ratering View Mode");
    init();
    glClearColor(0.2, 0.2, 0.2, 0.0);
    glutDisplayFunc(rDisplay);

    glutMainLoop();

    return 0;
}
