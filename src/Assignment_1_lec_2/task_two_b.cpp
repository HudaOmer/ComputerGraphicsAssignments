#include "../imports.h"

void init(void){
    glClearColor(0.25, 0.25, 0.25, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 1.0);
    // 
    int numberOfLines = 6;
    int numPoints = numberOfLines + 1; 
    // Calculate the angle increment
    float angleStep = (endAngle - startAngle) / (numPoints - 1);
    
    // Start drawing a line strip
    glBegin(GL_LINE_STRIP);
    
    for (int i = 0; i < numPoints; ++i) {
        // Calculate the angle for each point on the arc
        float angle = startAngle + i * angleStep;
        
        // Convert angle to radians
        float rad = angle * (M_PI / 180.0f);
        
        // Calculate the x and y coordinates for the point on the arc
        float x = centerX + radius * cos(rad);
        float y = centerY + radius * sin(rad);
        
        // Draw the point
        glVertex2f(x, y);
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
    glutCreateWindow(task1_2_b);
    
    init();
    glutDisplayFunc(display);
    
    
    glutMainLoop();
    return 0;
}