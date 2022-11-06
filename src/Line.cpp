#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
using namespace std;

class Point
{

private:

    GLfloat x1; GLfloat y1; GLfloat x2; GLfloat y2;

    void get() {
        cout << "Enter Endpoints for Line {x1,y1,x2,y2} : ";
        cin >> x1 >> y1 >> x2 >> y2;
    }

public:
    Point()
    {
        cout << "Enter Endpoints for Line {x1,y1,x2,y2} : ";
        cin >> x1 >> y1 >> x2 >> y2;
    }

    ~Point()
    {

    }

    void drawLine_DDA() 
    {
        glBegin(GL_POINTS);

        GLfloat dx = abs(x2 - x1);
        GLfloat dy = abs(y2 - y1);
        GLfloat k;

        if (dx >= dy)
            k = dx;
        else
            k = dy;

        GLfloat X = dx / 1000*k;
        GLfloat Y = dy / 1000*k;

        for (int i = 0; i <= 1000*k; i ++)
        {
            glVertex2f(x1, y1);
            x1 += X;
            y1 += Y;
            //cout << x1 << "," << y1 << endl;
            
        }

        glEnd();
    }

    void drawLine_Bresenham()
    {
        glBegin(GL_POINTS);
        
        glEnd();
    }

};