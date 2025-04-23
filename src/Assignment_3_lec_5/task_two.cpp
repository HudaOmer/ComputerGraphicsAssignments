#include "../imports.h"

void renderBitmapString(float x, float y, void* font, const std::string& str) {
    glRasterPos2f(x, y);
    for (char c : str) {
        glutBitmapCharacter(font, c);
    }
}

void drawCoordinateAxes() {
    // X and Y axes
    glColor3f(1.0, 1.0, 1.0);  // White color for axes
    glBegin(GL_LINES);
        // X-axis
        glVertex2f(-200, 0);
        glVertex2f(200, 0);
        
        // Y-axis
        glVertex2f(0, -200);
        glVertex2f(0, 200);
    glEnd();

    // X-axis labels
    renderBitmapString(190, -10, GLUT_BITMAP_HELVETICA_10, "X");
    renderBitmapString(-10, 190, GLUT_BITMAP_HELVETICA_10, "Y");
}

void init(void){
    glClearColor(0.25, 0.25, 0.25, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-280, 280, -280, 280);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw coordinate axes first
    drawCoordinateAxes();
    
    // First rectangle at original position
    glColor3f(1.0, 0.0, 0.0);  // Red
    drawRectangle();
    
    // Annotate rectangle vertices
    glColor3f(1.0, 1.0, 1.0);  // White text
    renderBitmapString(50, 90, GLUT_BITMAP_HELVETICA_12, "(50, 100)");
    renderBitmapString(200, 90, GLUT_BITMAP_HELVETICA_12, "(200, 100)");
    renderBitmapString(200, 160, GLUT_BITMAP_HELVETICA_12, "(200, 150)");
    renderBitmapString(50, 160, GLUT_BITMAP_HELVETICA_12, "(50, 150)");
    
    // Use homogeneous matrix to rotate the second rectangle 90 degrees CCW
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Rotate 90 degrees (π/2 radians) counter-clockwise
    glRotatef(90, 0, 0, 1);  // Rotate around Z-axis
    
    // Second rectangle rotated
    glColor3f(0.0, 1.0, 0.0);  // Green
    drawRectangle();
    
    glFlush();
}

int main(int argc, char **argv){
    // Display window management using glut
    // Initialise GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow(task3_2);
    
    glutDisplayFunc(display);
    init();
    
    glutMainLoop();
    return 0;
}