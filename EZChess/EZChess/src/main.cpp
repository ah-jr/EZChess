#include <GLFW/glfw3.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640

void drawBoard() {
    int square_width = WINDOW_WIDTH / 8;
    int square_height = WINDOW_HEIGHT / 8;
    int x = 0;
    int y = 0;

    for (int i = 0; i < 8; i += 1) {
        x = i * square_width;
        for (int j = 0; j < 8; j += 1) {
            y = j * square_height;
            if ((i + j) % 2 == 1)
                glColor3f(0.66f, 0.50f, 0.2f);
            else
                glColor3f(0.85f, 0.7f, 0.4f);

            glRecti(x, y, x + square_width, y + square_height);
        }
    }
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "EZChess", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Draw Chess Board */
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0f, WINDOW_WIDTH, WINDOW_HEIGHT, 0.0f, 0.0f, 1.0f);
        //glRecti(100,100,200,200);
        drawBoard();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}