#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <windows.h>
#include "Line_DDA.cpp"

// Driver Code
int main(void) 
{
    GLFWwindow* window;
    int op;

    // Initialize the library
    if (!glfwInit())
        return -1;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(1200, 900, "Graphics Window", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Runs after window is running
    if (glewInit() != GLEW_OK)
        return -1;

    // Graphics Driver Version
    std::cout << glGetString(GL_VERSION) << std::endl;;

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);
        do {
            system("cls");
            cout << "1 - Line Algorithms \n";
            cout << "Enter Option: ";
            cin >> op;

            if (op==1) {

                system("cls");
                Point p;
                p.drawLine_DDA();
                break;
            }
        } while (op!=0);
        
        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
