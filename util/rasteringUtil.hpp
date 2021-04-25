#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif (__linux__)
#include <GL/glut.h>
#elif (__APPLE__)
#include <GLUT/glut.h>
#endif

#include <math.h>


float roundToNearestX(float target, int x){
    int value = round(target);
    return floor(value / x) * x;
}



void drawSinglePixel(float topLeftX, float topLeftY, float size){



    glBegin(GL_POLYGON);

    glVertex2f(topLeftX,topLeftY);
    glVertex2f(topLeftX + size,topLeftY);
    glVertex2f(topLeftX + size,topLeftY - size);
    glVertex2f(topLeftX,topLeftY - size);

    glEnd();
    glFlush();
}