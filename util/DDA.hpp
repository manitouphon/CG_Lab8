#include <math.h>
#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif  (__linux__)
#include <GL/glut.h>
#elif  (__APPLE__)
#include <GLUT/glut.h>
#endif

#include "rasteringUtil.hpp"




void DDAMainDriver(float x1, float y1, float x2, float y2, int deviation)
{
   
    glColor3f(1, 0, 0);
    float i, x, y, Xin, Yin;
    float xTemp, yTemp;
    float dx = x2 - x1;
    float dy = y2 - y1;
    float step;

    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
        step = abs(dy);

    Xin = dx / step;
    Yin = dy / step;

    x = x1;
    y = y1;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    for (i = 1; i <= step; i++)
    {
        x = x + Xin  ;
        y = y + Yin ;

        xTemp = roundToNearestX(x,deviation);
        yTemp = roundToNearestX(y,deviation);

        glBegin(GL_POINTS);
        glVertex2i(xTemp, yTemp);
        glEnd();
        if((int)i % deviation)
        drawSinglePixel(xTemp, yTemp,deviation);
    }

    glFlush();

   
   
}