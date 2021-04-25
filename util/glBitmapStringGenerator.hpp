#ifdef definded(_WIN32)
#include <GL/glut.h>
#elif  (__linux__)
#include <GL/glut.h>
#elif  (__APPLE__)
#include <GLUT/glut.h>
#endif

#include <iostream>

using namespace std;

void generateBitmapString(string text, float x, float y)
{
    bool switcher = true;
    x = x - (text.size() * 2);
  
    glBegin(GL_BITMAP);
    for (int i = 0; i != text.size(); i++)
    {

        glRasterPos2f(x + (i * 2), y );
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text.at(i));

    }

    glEnd();
    glFlush();
}

