#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Warna garis merah

    // Gambar Garis yang Menghubungkan A dan B
    glBegin(GL_LINES);
    glVertex2f(4.0, 1.0); // Titik A
    glVertex2f(8.0, 12.0); // Titik B
    glEnd();

    glFlush(); // Menampilkan hasil gambar ke layar
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // Warna latar belakang putih
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 10.0, 0.0, 15.0); // Koordinat viewport
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Garis 2D");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
