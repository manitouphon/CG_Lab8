#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif  (__linux__)
#include <GL/glut.h>
#elif  (__APPLE__)
#include <GLUT/glut.h>
#endif

//On MacOS's GCC, the GLUT library folder is "GLUT" instead of "GL", on Windows
#include <iostream>
#include "util/color.hpp"
#include "util/glBitmapStringGenerator.hpp"

extern Color primaryColor;
extern Color secondaryColor;

extern float boundaryWidth;
extern float boundaryHeight;

extern float target1[2];
extern float target2[2];
extern float targetWidth;

extern int mainWindow;
extern int rWindow;

extern bool doDDA;
extern bool doMidpoint;

void drawTargetLine()
{

    glColor3f(secondaryColor.getR(), secondaryColor.getG(), secondaryColor.getB());

    glLineWidth(targetWidth);
    glBegin(GL_LINES);

    glVertex2f(target1[0], target1[1]);
    glVertex2f(target2[0], target2[1]);

    glEnd();
    glFlush();
}

void drawDDA()
{
    doDDA = true;
    doMidpoint = false;
}

void drawMidPoint()
{
    doDDA = false;
    doMidpoint = true;
}

void showMsg()
{
    glColor3f(1.0, 0.0, 0.0);
    generateBitmapString("Check Your Command Line for inputs", 110, 110);
}

void drawCoordinate()
{
    glColor3f(primaryColor.getR(), primaryColor.getG(), primaryColor.getB());

    glClear(GL_COLOR_BUFFER_BIT);

    //Draw X line

    glBegin(GL_LINE_STRIP);

    glVertex2f(-100.0, 0.0);
    glVertex2f(100.0, 0.0);

    glEnd();
    glFlush();

    //Draw X arrow
    glBegin(GL_LINE_LOOP);

    glVertex2f(95.0, 5.0);
    glVertex2f(100.0, 0.0);
    glVertex2f(95.0, -5.0);
    glVertex2f(110.0, 0.0);

    glEnd();
    glFlush();

    //Draw Y line
    glBegin(GL_LINE_STRIP);

    glVertex2f(0.0, -100.0);
    glVertex2f(0.0, 100.0);

    glEnd();
    glFlush();

    //Draw Y arrow

    glBegin(GL_LINE_LOOP);

    glVertex2f(5.0, 95.0);
    glVertex2f(0.0, 100.0);
    glVertex2f(-5.0, 95.0);
    glVertex2f(0.0, 110.0);

    glEnd();
    glFlush();

    //Draw 0 unit label:
    generateBitmapString("0", 3, 2);

    float x = -100.0;
    float y = 0;
    float lineOffset = 2.5;
    //X unit div
    for (x = -100.0; x < 100.0; x = x + 10.0)
    {

        glBegin(GL_LINE_STRIP);

        y = 0;
        y = y + lineOffset;
        glVertex2f(x, y);
        y = 0;
        y = y - lineOffset;
        glVertex2f(x, y);

        glEnd();
        glFlush();
        if (x == 0)
            continue;
        //Generate the unit dividers labels
        generateBitmapString(to_string((int)x), x + 2, y + (lineOffset * 2.5));
    }

    //Y unit div

    x = 0;
    y = -100.0;
    for (y = -100.0; y < 100.0; y = y + 10.0)
    {

        glBegin(GL_LINE_STRIP);

        x = 0;
        x = x + lineOffset;
        glVertex2f(x, y);
        x = 0;
        x = x - lineOffset;
        glVertex2f(x, y);

        glEnd();
        glFlush();
        //Generate the unit dividers labels
        if (y == 0)
            continue;
        generateBitmapString(to_string((int)y), x + (lineOffset * 4), y - 1);
    }

    //Fill in bitmap chars

    glBegin(GL_BITMAP);

    glRasterPos2f(10.0, 100.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'y');

    glRasterPos2f(100.0, 10.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'x');

    glEnd();
    glFlush();
}

//
//
//Div
//
//

void postRedisplayAll()
{
    glutSetWindow(mainWindow);
    glutPostRedisplay();
    glutSetWindow(rWindow);
    glutPostRedisplay();
}

void addCoorCLI()
{
    cout << "\n -1st Point X: ";
    cin >> target1[0];

    cout << "\n -1st Point Y: ";
    cin >> target1[1];

    cout << "\n -2nd Point X: ";
    cin >> target2[0];

    cout << "\n -2nd Point Y: ";
    cin >> target2[1];

    cout << "\n New Line @ ( " << target1[0] << " , " << target1[1] << " ) --> "
         << "( " << target2[0] << " , " << target2[1] << " )\n\n\n";


    if(target1[0] > boundaryWidth ||
    target1[1] > boundaryHeight ||
    target2[0] > boundaryWidth ||
    target2[1] > boundaryHeight 
    ){
        cout << " WARNING !!! \nTHE LINE THAT GOES OUT OF THE BOUNDARY WILL NOT BE GENERATED WHEN USING MIDPOINT ALGORITHM ! ";

    }

    cout << "\n";
    postRedisplayAll();
}

void setCustomTargetWidthCLI()
{
    showMsg();
    cout << "New Line Width: ";
    cin >> targetWidth;
    cout << " Line Width = " << targetWidth << "\n\n";
}

//Menu Actions:

void mainmenuAction(int ID)
{
}

void inputCoorAction(int ID)
{
    showMsg();
    switch (ID)
    {
    case 1:
        addCoorCLI();
        break;
    case 2:
        break;

    default:
        break;
    }
}
void drawingAction(int ID)
{
    showMsg();
    if (target1[0] == 0 && target1[1] == 0 && target2[0] == 0 && target2[1] == 0)
    {
        inputCoorAction(1);
    }

    switch (ID)
    {
    case 1:
        drawDDA();
        break;
    case 2:
    
        drawMidPoint();
        break;
    default:
        break;
    }
    postRedisplayAll();
}

void colorAction(int ID)
{
    switch (ID)
    {
    case 1:
        secondaryColor.setColor(1.0, 0, 0);
        break;
    case 2:
        secondaryColor.setColor(0, 0, 0);
        break;
    case 3:
        secondaryColor.setColor(0, 0.69, 0);
        break;

    default:
        break;
    }
    postRedisplayAll();
}

void lineWidthAction(int ID)
{
    switch (ID)
    {
    case 1:
        targetWidth = 1;
        break;
    case 2:
        targetWidth = 5;
        break;
    case 3:
        targetWidth = 10;
        break;
    case 4:
        targetWidth = 20;
        break;
    case 5:
        setCustomTargetWidthCLI();
        break;

    default:
        break;
    }
    postRedisplayAll();
}
//Menus
void createMenu()
{
    int inputCoor;
    int drawing;
    int color;
    int lineWidth;

    int mainmenu;

    inputCoor = glutCreateMenu(inputCoorAction);
    glutAddMenuEntry("Add Coordinates via Command Line", 1);

    drawing = glutCreateMenu(drawingAction);
    glutAddMenuEntry("DDA Line", 1);
    glutAddMenuEntry("MidPoint Line", 2);

    color = glutCreateMenu(colorAction);
    glutAddMenuEntry("Red (default)", 1);
    glutAddMenuEntry("Black", 2);
    glutAddMenuEntry("Green", 3);

    lineWidth = glutCreateMenu(lineWidthAction);
    glutAddMenuEntry("1 (default)", 1);
    glutAddMenuEntry("5", 2);
    glutAddMenuEntry("10", 3);
    glutAddMenuEntry("20", 4);
    glutAddMenuEntry("Custom", 5);

    mainmenu = glutCreateMenu(mainmenuAction);
    glutAddSubMenu("Draw Line", drawing);
    glutAddSubMenu("Line Color", color);
    glutAddSubMenu("Line Width", lineWidth);
    glutAddSubMenu("Input Line Data", inputCoor);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

//Main display driver ------------------------------------------------------------------------------------------------

void display(void)
{
    glColor3f(primaryColor.getR(), primaryColor.getG(), primaryColor.getB());
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(1);
    drawCoordinate();
    drawTargetLine();
}
