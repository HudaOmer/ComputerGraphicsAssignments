#include "../imports.h"

void init(void){
    glClearColor(0.25, 0.25, 0.25, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-4.0, 4.0, -4.0, 4.0);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    // Hexagon vertices with gradient colors
    glColor3f(1.0, 0.0, 0.0);  // Red
    glVertex2f(3.0 * cos(0), 3.0 * sin(0));
    
    glColor3f(1.0, 0.5, 0.0);  // Orange
    glVertex2f(3.0 * cos(M_PI/3), 3.0 * sin(M_PI/3));
    
    glColor3f(0.0, 1.0, 0.0);  // Green
    glVertex2f(3.0 * cos(2*M_PI/3), 3.0 * sin(2*M_PI/3));
    
    glColor3f(0.0, 0.0, 1.0);  // Blue
    glVertex2f(3.0 * cos(M_PI), 3.0 * sin(M_PI));
    
    glColor3f(0.5, 0.0, 0.5);  // Purple
    glVertex2f(3.0 * cos(4*M_PI/3), 3.0 * sin(4*M_PI/3));
    
    glColor3f(1.0, 1.0, 0.0);  // Yellow
    glVertex2f(3.0 * cos(5*M_PI/3), 3.0 * sin(5*M_PI/3));
glEnd();
    glFlush();
}

int main(int argc, char **argv){
    // Display window management using glut
    // Initialise GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow(task2_1);
    
    glutDisplayFunc(display);
    init();
    
    glutMainLoop();
    return 0;
}