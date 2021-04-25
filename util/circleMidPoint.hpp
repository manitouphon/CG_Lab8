#include <math.h>
#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif (__linux__)
#include <GL/glut.h>
#elif (__APPLE__)
#include <GLUT/glut.h>
#endif



void circleMidPointMainDriver(float x_centre, float y_centre, float r, int deviation)
{
 


    int x = r, y = 0;

    glBegin(GL_POINTS);
    glVertex2f(roundToNearestX(x + x_centre, deviation), roundToNearestX(y + y_centre, deviation));

    glEnd();
    drawSinglePixel(roundToNearestX(x + x_centre, deviation), roundToNearestX(y + y_centre, deviation),deviation);

    if (r > 0)
    {
        glBegin(GL_POINTS);
        glVertex2f(roundToNearestX(x + x_centre, deviation), roundToNearestX(-y + y_centre, deviation));
        glVertex2f(roundToNearestX(y + x_centre, deviation), roundToNearestX(x + y_centre, deviation));
        glVertex2f(roundToNearestX(-y + x_centre, deviation), roundToNearestX(x + y_centre, deviation));
        glEnd();
        // drawSinglePixel(roundToNearestX(x + x_centre, deviation), roundToNearestX(-y + y_centre, deviation),deviation);
        // drawSinglePixel(roundToNearestX(y+ x_centre, deviation), roundToNearestX(x + y_centre, deviation),deviation);
        // drawSinglePixel(roundToNearestX(-y+ x_centre, deviation), roundToNearestX(x + y_centre, deviation),deviation);

    }

    int P = 1 - r;

    while (x > y)
    {
        y++;

        if (P <= 0)
            P = P + 2 * y + 1;

        else
        {
            x--;
            P = P + 2 * y - 2 * x + 1;
        }

        if (x < y)
            break;

        glBegin(GL_POINTS);
        glVertex2f(roundToNearestX(x + x_centre, deviation), roundToNearestX(y + y_centre, deviation));
        glVertex2f(roundToNearestX(-x + x_centre, deviation), roundToNearestX(y + y_centre, deviation));
        glVertex2f(roundToNearestX(x + x_centre, deviation), roundToNearestX(-y + y_centre, deviation));
        glVertex2f(roundToNearestX(-x + x_centre, deviation), roundToNearestX(-y + y_centre, deviation));
        glEnd();

        drawSinglePixel(roundToNearestX(x + x_centre, deviation), roundToNearestX(y + y_centre, deviation),deviation);
        drawSinglePixel(roundToNearestX(-x + x_centre, deviation), roundToNearestX(y + y_centre, deviation),deviation);
        drawSinglePixel(roundToNearestX(x + x_centre, deviation), roundToNearestX(-y + y_centre, deviation),deviation);
        drawSinglePixel(roundToNearestX(-x + x_centre, deviation), roundToNearestX(-y + y_centre, deviation),deviation);

        glBegin(GL_POINTS);
        glVertex2f(roundToNearestX(y + x_centre, deviation), roundToNearestX(x + y_centre, deviation));
        glVertex2f(roundToNearestX(-y + x_centre, deviation), roundToNearestX(x + y_centre, deviation));
        glVertex2f(roundToNearestX(y + x_centre, deviation), roundToNearestX(-x + y_centre, deviation));
        glVertex2f(roundToNearestX(-y + x_centre, deviation), roundToNearestX(-x + y_centre, deviation));
        glEnd();

        drawSinglePixel(roundToNearestX(y + x_centre, deviation), roundToNearestX(x + y_centre, deviation),deviation);
        drawSinglePixel(roundToNearestX(-y + x_centre, deviation), roundToNearestX(x + y_centre, deviation),deviation);
        drawSinglePixel(roundToNearestX(-y + x_centre, deviation), roundToNearestX(-x + y_centre, deviation),deviation);
        drawSinglePixel(roundToNearestX(y + x_centre, deviation), roundToNearestX(-x + y_centre, deviation),deviation);


    }
    glFlush();
}



