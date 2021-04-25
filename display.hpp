#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif (__linux__)
#include <GL/glut.h>
#elif (__APPLE__)
#include <GLUT/glut.h>
#endif

//On MacOS's GCC, the GLUT library folder is "GLUT" instead of "GL", on Windows
#include <iostream>
#include "util/color.hpp"
#include "util/glBitmapStringGenerator.hpp"
#include "util/drawCircle.hpp"

extern Color primaryColor;
extern Color secondaryColor;

extern float boundaryWidth;
extern float boundaryHeight;

extern float target1[2];
extern float target2[2];
extern float circle[3];
extern int itemWidth;

extern int mainWindow;
extern int rWindow;

extern bool doDDA;
extern bool doMidpoint;
extern bool doCircleMidPoint;
extern bool isDrawingGrid;


void drawItem()
{
    if (doCircleMidPoint)
    {
        drawCircle(circle[0], circle[1], circle[2], secondaryColor.getR(), secondaryColor.getG(), secondaryColor.getB());
    }
    else if (doDDA || doMidpoint)
    {

        glColor3f(secondaryColor.getR(), secondaryColor.getG(), secondaryColor.getB());

        glBegin(GL_LINES);

        glVertex2f(target1[0], target1[1]);
        glVertex2f(target2[0], target2[1]);

        glEnd();
        glFlush();
    }
}

void drawDDA()
{
    doDDA = true;
    doMidpoint = false;
    doCircleMidPoint = false;
}

void drawMidPoint()
{
    doDDA = false;
    doMidpoint = true;
    doCircleMidPoint = false;
}
void drawCircleMidPoint()
{
    doDDA = false;
    doMidpoint = false;
    doCircleMidPoint = true;
    
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
////
////
////
////
////
////
////
////
////
////
//
//
//
//
//
//
//

//

////
////
////
////
////
////
////
////
////
////
//
//
//
//
//
//
//

//
//////
////
////
////
////
////
////
////
////
////
//
//
//
//
//
//
//

//
//
//

void postRedisplayAll()
{
    glutSetWindow(mainWindow);
    glutPostRedisplay();
    glutSetWindow(rWindow);
    glutPostRedisplay();
}

void addLineCoordinates()
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

    if (target1[0] > boundaryWidth ||
        target1[1] > boundaryHeight ||
        target2[0] > boundaryWidth ||
        target2[1] > boundaryHeight)
    {
        cout << " WARNING !!! \nTHE LINE THAT GOES OUT OF THE BOUNDARY WILL NOT BE GENERATED WHEN USING MIDPOINT ALGORITHM ! ";
    }

    cout << "\n";
    postRedisplayAll();
}
void addCircleCoordinates()
{
    cout << "\n -Circle Center X: ";
    cin >> circle[0];

    cout << "\n -Circle Center Y: ";
    cin >> circle[1];

    cout << "\n -Circle Raduis (r): ";
    cin >> circle[2];

    cout << "\n New Circle Parameters: X=" << circle[0];
    cout << "; Y= " << circle[0];
    cout << "; Raduis=" << circle[0];

    cout << "\n";
    postRedisplayAll();
}

void setCustomitemWidthCLI()
{
    showMsg();
    cout << "New Line Width: ";
    cin >> itemWidth;
    cout << " Line Width = " << itemWidth << "\n\n";
}

//Menu Actions:

void mainmenuAction(int ID)
{
}

void drawingAction(int ID)
{
    showMsg();

    switch (ID)
    {
    case 1:
        addLineCoordinates();
        drawDDA();
        break;
    case 2:
        addLineCoordinates();
        drawMidPoint();
        break;
    case 3:
        cout << "function isn't implemented yet.";
        break;
    case 4:
        addCircleCoordinates();

        drawCircleMidPoint();
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
        itemWidth = 1;
        break;
    case 2:
        itemWidth = 5;
        break;
    case 3:
        itemWidth = 7;
        break;
    case 4:
        itemWidth = 10;
        break;
    case 5:

        setCustomitemWidthCLI();
        break;

    default:
        break;
    }
    postRedisplayAll();
}
void drawGridAction(int ID)
{
    switch (ID)
    {
    case 1:
        isDrawingGrid = false;
        break;
    case 2:
        isDrawingGrid = true;
        break;

    default:
        break;
    }
    postRedisplayAll();
    postRedisplayAll();
}
//Menus
void createMenu()
{
    int drawing;
    int color;
    int lineWidth;
    int drawGrid;

    int mainmenu;

    glutAddMenuEntry("Add Coordinates via Command Line", 1);

    drawing = glutCreateMenu(drawingAction);
    glutAddMenuEntry("DDA Line", 1);
    glutAddMenuEntry("MidPoint Line", 2);
    glutAddMenuEntry("Trigonometry Circle", 3);
    glutAddMenuEntry("MidPoint Circle", 4);

    color = glutCreateMenu(colorAction);
    glutAddMenuEntry("Red (default)", 1);
    glutAddMenuEntry("Black", 2);
    glutAddMenuEntry("Green", 3);

    lineWidth = glutCreateMenu(lineWidthAction);
    glutAddMenuEntry("1 ", 1);
    glutAddMenuEntry("5(default)", 2);
    glutAddMenuEntry("7", 3);
    glutAddMenuEntry("10", 4);
    glutAddMenuEntry("Custom", 5);

    drawGrid = glutCreateMenu(drawGridAction);
    glutAddMenuEntry("OFF", 1);
    glutAddMenuEntry("ON", 2);

        mainmenu = glutCreateMenu(mainmenuAction);
    glutAddSubMenu("Draw", drawing);
    glutAddSubMenu("Item Color", color);
    glutAddSubMenu("Item Width (Pixel Size)", lineWidth);
    glutAddSubMenu("Toggle Grid", drawGrid);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

//Main display driver ------------------------------------------------------------------------------------------------

void display(void)
{
    glColor3f(primaryColor.getR(), primaryColor.getG(), primaryColor.getB());
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(1);
    drawCoordinate();
    drawItem();
}
