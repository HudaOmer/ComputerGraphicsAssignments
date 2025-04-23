#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <string>
#include <sstream>


// Assignment 1
const char* task1_1_a = "OpenGL Line 1.1 (a) GL_LINES";
const char* task1_1_b = "OpenGL Line 1.1 (b) GL_LINE_STRIP";
const char* task1_1_c = "OpenGL Line 1.1 (c) GL_LINE_LOOP";

const char* task1_2_a = "OpenGL Arc 1.2 (a) GL_LINE_STRIP (03 lines)";
const char* task1_2_b = "OpenGL Arc 1.2 (b) GL_LINE_STRIP (06 lines)";
const char* task1_2_c = "OpenGL Arc 1.2 (c) GL_LINE_STRIP (12 lines)";

// Assignment 2
const char* task2_1 = "OpenGL Filled Hexagon 2.1 GL_POLYGON";
const char* task2_1_a = "OpenGL Limacon Curve 2.2 (a) GL_LINE_STRIP";
const char* task2_1_b = "OpenGL Cardioid Curve 2.2 (b) GL_LINE_STRIP";
const char* task2_1_c = "OpenGL 3-Leaf Rose Curve 2.2 (c) GL_LINE_STRIP";
const char* task2_1_d = "OpenGL 4-Leaf Rose Curve 2.2 (d) GL_LINE_STRIP";
const char* task2_1_e = "OpenGL Spiral of Archimedes Curve 2.2 (e) GL_LINE_STRIP";

// Assignment 3
const char* task3_1 = "OpenGL Translate Rectangle to point LL(-150, 50) 3.1 GL_POLYGON";
const char* task3_2 = "OpenGL Rotate Rectangle by 90 degrees CCW 3.2 GL_POLYGON";
const char* task3_3 = "OpenGL Mirror and Scale Rectangle to half its original width 3.3 GL_POLYGON";

void drawRectangle(){
    glBegin(GL_POLYGON);
        glVertex2f(50, 100);
        glVertex2f(200, 100);
        glVertex2f(200, 150);
        glVertex2f(50, 150);
    glEnd();
}

// Define the center and radius of the arc
float centerX = 0.0f;
float centerY = 0.0f;
float radius = 0.5f;
float startAngle = 0.0f;  // Starting angle of arc (in degrees)
float endAngle = 270.0f;   // Ending angle of arc (in degrees)