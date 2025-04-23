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
    float a = 1.0;  // First parameter
    float b = 3.0;  // Second parameter controlling Limacon shape
    for (t = 0; t <= 2*M_PI; t += 0.01) {
        // Limacon equation variations:
        // 1. Classic Limacon: r = a + b * cos(t)
        // 2. Convex Limacon: r = a + b * cos(t), where b > a
        // 3. Dimpled Limacon: r = a + b * cos(t), where 0 < b < a
        // 4. Cardioid (special case): r = a * (1 + cos(t))
        r = a + b * cos(t);
        x = r * cos(t);
        y = r * sin(t);
        glVertex2f(x - 2.0, y);
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
    glutCreateWindow(task2_1_a);
    
    
    glutDisplayFunc(display);
    init();
    
    glutMainLoop();
    return 0;
}