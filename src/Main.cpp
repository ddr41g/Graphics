#include <windows.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Line.cpp"

// Driver Code
int main(void) 
{
    GLFWwindow* window;
    int op;

    // Initialize the library
    if (!glfwInit())
        return -1;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(1280, 720, "Graphics Window", NULL, NULL);
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
    //std::cout << glGetString(GL_VERSION) << std::endl;
    //cin.get();

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);
        do {
            system("cls");
            cout << "1 - Line Algorithms \n";
            cout << "0 - EXIT \n";
            cout << "Enter Option: ";
            cin >> op;

            if (op == 1)
            {

                system("cls");
                Point p;
                system("cls");

                cout << "1 - Digital Differential Analyser " << endl;
                cout << "2 - Bresenham's Algorithm " << endl;
                cout << "Enter Option: ";
                cin >> op;

                if (op == 1)
                    p.drawLine_DDA();
                else if (op == 2)
                    p.drawLine_Bresenham();

                break;
            }
            else if (op == 0)
                exit(EXIT_FAILURE);
        } while (op!=0);
        
        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
