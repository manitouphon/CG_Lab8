#include <math.h>
#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif  (__linux__)
#include <GL/glut.h>
#elif  (__APPLE__)
#include <GLUT/glut.h>
#endif





void midpointDriver(float x1, float y1, float x2, float y2, int deviation)
{
    //Probably A bit improvised algorithm
    x1 = roundToNearestX(x1, deviation);
    x2 = roundToNearestX(x2, deviation);
    y1 = roundToNearestX(y1, deviation);
    y2 = roundToNearestX(y2, deviation);

    int dx = x2 - x1;
    int dy = y2 - y1;

    if (dy <= dx)
    {
        int d = dy - (dx / 2);
        int x = x1, y = y1;
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
        drawSinglePixel(x,y,deviation);

        // iterate through value of X
        while (x < x2)
        {
            x = x + deviation;

            // E or East is chosen
            if (d < 0)
                d = d + dy;

            // NE or North East is chosen
            else
            {
                d += (dy - dx);
                y = y + deviation;
            }
            glBegin(GL_POINTS);
            glVertex2f(x, y);
            glEnd();
            drawSinglePixel(x,y,deviation);
        }
    }

    else if (dx < dy)
    {

        int d = dx - (dy / 2);
        int x = x1, y = y1;
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
        drawSinglePixel(x,y,deviation);

        // iterate through value of X
        while (y < y2)
        {
            y = y + deviation;

            // E or East is chosen
            if (d < 0)
                d = d + dx;

            // NE or North East is chosen
            else
            {
                d += (dx - dy);
                x = x + deviation;
            }

            glBegin(GL_POINTS);
            glVertex2f(x, y);
            glEnd();
            drawSinglePixel(x,y,deviation);
        }
    }

    
}

