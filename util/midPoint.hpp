#include <math.h>
#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif  (__linux__)
#include <GL/glut.h>
#elif  (__APPLE__)
#include <GLUT/glut.h>
#endif


void midpointDriver(float x1, float y1, float x2, float y2)
{
    //Probably A bit improvised algorithm

    glColor3f(0, 1, 0);
    int dx = x2 - x1;
    int dy = y2 - y1;

    if (dy <= dx)
    {
        int d = dy - (dx / 2);
        int x = x1, y = y1;
        glBegin(GL_POINTS);
        glVertex2f(x, y);

        // iterate through value of X
        while (x < x2)
        {
            x++;

            // E or East is chosen
            if (d < 0)
                d = d + dy;

            // NE or North East is chosen
            else
            {
                d += (dy - dx);
                y++;
            }
            glVertex2f(x, y);
        }
    }

    else if (dx < dy)
    {

        int d = dx - (dy / 2);
        int x = x1, y = y1;
        glBegin(GL_POINTS);
        glVertex2f(x, y);

        // iterate through value of X
        while (y < y2)
        {
            y++;

            // E or East is chosen
            if (d < 0)
                d = d + dx;

            // NE or North East is chosen
            else
            {
                d += (dx - dy);
                x++;
            }

            glVertex2f(x, y);
        }
    }

    //ALGORITH FROM SLIDE:
    // glColor3f(0, 1, 0);

    // float dy = y2 - y1;
    // float dx = x2 - x1;
    // float d = (2 * dy) - dx;
    // float dE = 2 * dy;
    // float dNE = 2 * (dy - dx);
    // float x = x1;
    // float y = y1;

    // //Write first pixel
    // glBegin(GL_POINTS);
    // glVertex2i(x, y);

    // while(x < x2){
    //     if(d<=0){
    //         d += dE;
    //         x += 1;
    //     }
    //     else{
    //         d += dNE;
    //         x += 1;
    //         y += 1;
    //     }
    //     glVertex2f(x,y);
    // }
    // glEnd();
    // glFlush();
}