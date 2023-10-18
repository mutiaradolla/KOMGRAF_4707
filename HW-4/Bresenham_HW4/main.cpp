#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <GL/glut.h>

float xAwal, yAwal, xEnd, yEnd;

void tampilan(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 15, 0.0, 15);
}

void aturPixel(GLint xCoordinate, GLint yCoordinate) {
    glBegin(GL_POINTS);
    glVertex2i(xCoordinate, yCoordinate);
    glEnd();
    glFlush();
}

void garisBresenham(GLint x0, GLint y0, GLint xEnd, GLint yEnd) {
    GLint dx = abs(xEnd - x0);
    GLint dy = abs(yEnd - y0);
    GLint p = 2 * dy - dx;
    GLint twoDy = 2 * dy;
    GLint twoDyMinusDx = 2 * (dy - dx);
    GLint x, y;

    if (x0 > xEnd) {
        x = xEnd;
        y = yEnd;
        xEnd = x0;
    } else {
        x = x0;
        y = y0;
    }

    aturPixel(x, y);

    while (x < xEnd) {
        x++;
        if (p < 0)
            p += twoDy;
        else {
            y++;
            p += twoDyMinusDx;
        }

        aturPixel(x, y);
    }
}

void gambarGaris(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glPointSize(2.0);

    garisBresenham((GLint)xAwal, (GLint)yAwal, (GLint)xEnd, (GLint)yEnd);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Garis Bresenham");
    tampilan();

    printf("Masukkan koordinat titik awal (x0 y0): ");
    scanf("%d %d", &xAwal, &yAwal);
    printf("Masukkan koordinat titik akhir (xEnd yEnd): ");
    scanf("%d %d", &xEnd, &yEnd);

    glutDisplayFunc(gambarGaris);
    glutMainLoop();
    return 0;
}
