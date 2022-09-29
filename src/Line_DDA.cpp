#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
using namespace std;

int round(float x, float y) { return x + 0.5, y + 0.5; }

void drawLine_DDA(float x1, float y1, float x2, float y2) {
    float dx = abs(x2 - x1);
    float dy = abs(y2 - y1);
    float k;

    if (dx >= dy)
        k = dx;
    else
        k = dy;

    dx = dx / k;
    dy = dy / k;

    for (int i = 1; i <= k; i++)
    {
        glCopyPixels(x1, y1, 800, 600, GL_COLOR);
        x1 += dx;
        y1 += dy;

    }
}

int main()
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(800, 600, "Graphics Window", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    float x1, y1, x2, y2;
    cout << "Enter Endpoints for Line {x1,y1,x2,y2} : ";
    cin >> x1 >> y1 >> x2 >> y2;


    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        return -1;

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_POINTS);
            drawLine_DDA(x1, y1, x2, y2);
        glEnd();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}