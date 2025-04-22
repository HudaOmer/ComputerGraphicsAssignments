#include "../imports.h"

void init(void){
    glClearColor(0.25, 0.25, 0.25, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 7.0, -2.0, 7.0);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 1.0);
    // 
    glBegin(GL_LINE_STRIP);
        glVertex2i(6, 3);
        glVertex2i(1, 0);
        glVertex2i(3, 5);
        glVertex2i(5, 0);
        glVertex2i(0, 3);
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
    glutCreateWindow(task1_1_b);
    
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}