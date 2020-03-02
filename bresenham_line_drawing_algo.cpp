#include<GL/Glut.h> 
#include<stdlib.h>
#include<math.h>
#include<stdio.h>

void myinit(void)
{

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // multiply the current matrix by identity matrix
    gluOrtho2D(0.0, 250.0, 0.0, 250.0);
}

float xstart, ystart, xend, yend, x, y;

int Round(float a)//any x i.e 1>=a>=0.5 is rounded to 1
{
    if (a - int(a) >= 0.5)
        return int(a) + 1;
    else
        return int(a);
}

void bressen()
{
    float ydiff = yend - ystart;
    float xdiff = xend - xstart;
    if (ydiff < 0) ydiff = -ydiff;
    if (xdiff < 0) xdiff = -xdiff;
    int incx = 1, incy = 1;
    if (xend < xstart)incx = -1;
    if (yend < ystart)incy = -1;

    if (xdiff > ydiff)
    {
        float p0;
        p0 = 2 * (ydiff)-xdiff;

        x = xstart;               //assign xstart to x
        y = ystart;              //assign ystart to y

        while ((x != xend + 1) && (y != yend + 1))
        {
            glBegin(GL_POINTS); // writes pixels on the frame buffer with the current drawing color
            glVertex2i(Round(x), Round(y));//sets vertex
            glEnd();
            if (p0 < 0)
            {
                x = x + incx;
                y = y;
                p0 = p0 + 2 * (ydiff);
            }
            else
            {
                x = x + incx;
                y = y + incy;
                p0 += 2 * (ydiff)-2 * (xdiff);
            }

        }
    }
    else
    {
        float p0;
        p0 = 2 * (xdiff)-ydiff;

        x = xstart;               //assign xstart to x
        y = ystart;              //assign ystart to y

        while ((x != xend + 1) && (y != yend + 1))
        {
            glBegin(GL_POINTS); // writes pixels on the frame buffer with the current drawing color
            glVertex2i(Round(x), Round(y));//sets vertex
            glEnd();
            if (p0 < 0)
            {
                x = x;
                y = y+ incy;
                p0 = p0 + 2 * (xdiff);
            }
            else
            {
                x = x + incx;
                y = y + incy;
                p0 += 2 * (xdiff)-2 * (ydiff);
            }

        }
    }
    glutPostRedisplay();
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT); // clears the frame buffer and set values defined in glClearColor() function call     
    glColor3f(0, 0, 1); // sets the current drawing (foreground) color to blue 
    glPointSize(6); // sets the size of points to be drawn (in pixels)
    bressen();// calls programmer defined function(drawline)
    glFlush(); // flushes the frame buffer to the screen
}

int main(int argc, char** argv)
{
    printf("enter the value of starting and ending coordinates: \n xstart ");
    scanf_s("%f", &xstart);
    printf(" \n ystart: ");
    scanf_s("%f", &ystart);
    printf(" \n xend: ");
    scanf_s("%f", &xend);
    printf(" \n yend: ");
    scanf_s("%f", &yend);

    glutInit(&argc, argv);
    glutInitWindowSize(450, 450);//sets the width and height of the window in pixels
    glutInitWindowPosition(10, 10);//sets the position of the window in pixels from top left corner 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//creates a single frame buffer of RGB color capacity.
    glutCreateWindow("Bressenham Line Drawing");//creates the window as specified by the user as above.
    myinit();
    glutDisplayFunc(display);//links the display event with the display event handler(display)
    glutIdleFunc(bressen);
    glutMainLoop();//loops the current event
}
