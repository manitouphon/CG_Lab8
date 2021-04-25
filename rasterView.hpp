
#include "util/DDA.hpp"
#include "util/midPoint.hpp"
#include "util/circleMidPoint.hpp"




extern float boundaryWidth;
extern float boundaryHeight;


extern Color secondaryColor;

extern float target1[2];
extern float target2[2];
extern float circle[3];
extern int itemWidth;


extern bool doDDA;
extern bool doMidpoint;
extern bool doCircleMidPoint;
extern bool isDrawingGrid;



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

    for (x = 0; x < boundaryWidth; x = x + itemWidth){
        glBegin(GL_LINE_STRIP);

        glVertex2d(x,0);
        glVertex2d(x,y);

        glEnd();
        glFlush();

    }

    //draw horizontal lines
    x = boundaryWidth;
    y = 0;

    for (y = 0; y < boundaryHeight; y = y + itemWidth){
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

    glBegin(GL_POINTS);
    glVertex2d(-100,-100);
    glEnd();
    glFlush();

    if(isDrawingGrid)
    drawBoundary();
 
    
    glColor3f(secondaryColor.getR(), secondaryColor.getG(), secondaryColor.getB());
    // drawTargetLine();
    if(doDDA){
        
        DDAMainDriver(target1[0], target1[1],target2[0], target2[1],itemWidth);
    }
    if(doMidpoint){
        midpointDriver(target1[0], target1[1],target2[0], target2[1],itemWidth);
    }
    if(doCircleMidPoint){
        circleMidPointMainDriver(circle[0], circle[1], circle[2],itemWidth);
        cout << "circle";

    }

}