#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif  (__linux__)
#include <GL/glut.h>
#elif  (__APPLE__)
#include <GLUT/glut.h>
#endif

#include "util/DDA.hpp"
#include "util/midPoint.hpp"



extern float boundaryWidth;
extern float boundaryHeight;
extern float delta;

extern Color secondaryColor;

extern float target1[2];
extern float target2[2];
extern float targetWidth;


extern bool doDDA;
extern bool doMidpoint;



void drawBoundary(){
    glColor3f(0.5,0.5,0.5);
    glLineWidth(1);

   

    //draw boundary
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_STRIP);

    glVertex2f(0.0, 0.0);
    glVertex2f(boundaryWidth, 0.0);
    glVertex2f(boundaryWidth, boundaryHeight);
    glVertex2f(0, boundaryHeight);
    glVertex2f(0.0, 0.0);


    glEnd();
    glFlush();


    //draw vertical lines
    int x = 0;
    int y = boundaryHeight;

    for (x = 0; x < boundaryWidth; x = x + delta){
        glBegin(GL_LINE_STRIP);

        glVertex2d(x,0);
        glVertex2d(x,y);

        glEnd();
        glFlush();

    }

    //draw horizontal lines
    x = boundaryWidth;
    y = 0;

    for (y = 0; y < boundaryHeight; y = y + delta){
        glBegin(GL_LINE_STRIP);

        glVertex2d(0,y);
        glVertex2d(x,y);

        glEnd();
        glFlush();

    }

}






//Main rDisplay Driver:-----------------------------------------------------------------------------------

void rDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);

    drawBoundary();
    
    // drawTargetLine();
    if(doDDA){
        DDAMainDriver(target1[0], target1[1],target2[0], target2[1]);
    }
    if(doMidpoint){
        midpointDriver(target1[0], target1[1],target2[0], target2[1]);
    }

}