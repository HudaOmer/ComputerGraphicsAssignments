#include "../imports.h"

void init(void){
    glClearColor(0.25, 0.25, 0.25, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-4.0, 4.0, -4.0, 4.0);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 1.0, 1.0);

    float t, r, x, y;
    for (t = 0.0; t <= 2 * M_PI; t += 0.01) {
        r = 0.5 * t;
        x = r * cos(t);
        y = r * sin(t);
        glVertex2f(x - 0.75, y + 0.5);
    }
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
    glutCreateWindow(task2_1_e);
    
    
    glutDisplayFunc(display);
    init();
    
    glutMainLoop();
    return 0;
}