#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>
using namespace std;


int main(void)
{
    //intialize window variables
    GLFWwindow* window;
    int HEIGHT = 600;
    int WIDTH = 600;

    // Initialize the GLFW
    if (!glfwInit())
        return -1;

    //Create a window and its OpenGL context
    window = glfwCreateWindow(WIDTH, HEIGHT, "Probably a mosque", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    //Make the window's context current (bring it to the front)
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {

        glClear(GL_COLOR_BUFFER_BIT);

        //Define rectangle dimensions
        glBegin(GL_LINE_LOOP);
        glColor3f(255, 255, 255);
        glVertex2f(-0.55f, 0.35f);
        glVertex2f(-0.55f, 0.25f);
        glVertex2f(-0.45f, 0.25f);
        glVertex2f(-0.45f, -0.35f);
        glVertex2f(0.45f, -0.35f);
        glVertex2f(0.45f, 0.25f);
        glVertex2f(0.55f, 0.25f);
        glVertex2f(0.55f, 0.35f);

        glEnd();

        //Mosque roof Dimensions
        float RADIUS = 0.1;
        float DEGREE_TO_RAD = 3.14 / 180;
        float CIRCLE_HEIGHT = 0.35;

        glBegin(GL_LINE_LOOP);

        //set roof line color
        glColor3f(255, 255, 255);

        //roof
        int M_IN_DEGREE = 180;
        int N_IN_DEGREE = 0;
        for (int nR = N_IN_DEGREE; nR <= M_IN_DEGREE; nR++)
        {
            float fY = sin((float)nR * DEGREE_TO_RAD) * CIRCLE_HEIGHT + 0.35;
            float fX = cos((float)nR * DEGREE_TO_RAD) * CIRCLE_HEIGHT;

            glVertex2f(fX, fY);
        }

        glEnd();

        //Door Dimensions
        glBegin(GL_LINE_LOOP);
        glColor3f(255, 255, 255);
        glVertex2f(-0.1f, 0.15f);
        glVertex2f(-0.1f, -0.35f);
        glVertex2f(0.1f, -0.35f);
        glVertex2f(0.1f, 0.15f);
        glEnd();

        //Left Window 
        glBegin(GL_LINE_LOOP);
        glColor3f(255, 255, 255);
        glVertex2f(-0.4f, 0.15f);
        glVertex2f(-0.4f, -0.1f);
        glVertex2f(-0.2f, -0.1f);
        glVertex2f(-0.2f, 0.15f);
        glEnd();

        //Right Window 
        glBegin(GL_LINE_LOOP);
        glColor3f(255, 255, 255);
        glVertex2f(0.2f, 0.15);
        glVertex2f(0.2f, -0.1f);
        glVertex2f(0.4f, -0.1f);
        glVertex2f(0.4f, 0.15f);
        glEnd();

        //Left Window Bars 
        //Vertical
        glBegin(GL_LINES);
        glColor3f(255, 255, 255);
        glVertex2f(-0.3f, 0.15f);
        glVertex2f(-0.3f, -0.1f);
        glEnd();
        //Horizontal
        glBegin(GL_LINES);
        glColor3f(255, 255, 255);
        glVertex2f(-0.4f, 0.025f);
        glVertex2f(-0.2f, 0.025f);
        glEnd();

        //Right Window Bars
        //Vertical
        glBegin(GL_LINES);
        glColor3f(255, 255, 255);
        glVertex2f(0.3f, 0.15f);
        glVertex2f(0.3f, -0.1f);
        glEnd();
        //Horizontal
        glBegin(GL_LINES);
        glColor3f(255, 255, 255);
        glVertex2f(0.4f, 0.025f);
        glVertex2f(0.2f, 0.025f);
        glEnd();


        //Door knob
        int i;
        float PI = 3.142;
        GLfloat x = 0.065f;
        GLfloat y = -0.1f;
        GLfloat radius = .015f;
        int triangleAmount = 40;
        GLfloat twicePi = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(61, 143, 174);
        glVertex2f(x, y);
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount)));

        }
        glEnd();

        //Bright Side of the moon

        GLfloat k = 0.55f;
        GLfloat m = 0.75f;
        GLfloat rad = 0.2f;
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(k, m);
        int R = 255;
        int G = 255;
        int B = 255;
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(k + (rad * cos(i * twicePi / triangleAmount)),
                m + (rad * sin(i * twicePi / triangleAmount)));
            R -= 4;
            G -= 4;
            glColor3ub(R, G, B);
        }
        glEnd();

        //Dark side of the moon

        GLfloat l = 0.60f;
        GLfloat n = 0.80f;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0, 0, 0);
        glVertex2f(l, n);
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(l + (rad * cos(i * twicePi / triangleAmount)),
                n + (rad * sin(i * twicePi / triangleAmount)));
        }
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}