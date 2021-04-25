
#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif (__linux__)
#include <GL/glut.h>
#elif (__APPLE__)
#include <GLUT/glut.h>
#endif
#include <math.h>

void drawCircle(float centerX, float centerY, float radius, float r, float g, float b)
{
    float theta;
    glColor3f(r, g, b);
    glBegin(GL_POINTS);

    for (int i = 0; i < 720; i++)
    {
        //Formula: [Offset] +  [radius]* {cos/sin} (theta)  (cos for X , sin for Y)
        theta = i * M_PI / 360;
        glVertex2f(centerX + radius * cosf(theta), centerY + radius * sinf(theta));
    }

    glEnd();
    glFlush();
}
