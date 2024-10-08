#include <GL/glut.h>

const int rows = 20;
const int cols = 20;

// Matriz que representa la pokebola en forma pixelada (20x20)
int pokeball[rows][cols] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 3, 3, 1, 1, 1, 1, 1, 3, 3, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 0, 0, 0, 0, 0},
    {0, 0, 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 0, 0, 0, 0},
    {0, 0, 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 0, 0, 0, 0},
    {0, 0, 3, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, 3, 0, 0, 0},
    {0, 0, 3, 1, 1, 1, 1, 3, 2, 2, 2, 3, 1, 1, 1, 1, 3, 0, 0, 0},
    {0, 0, 3, 3, 3, 3, 3, 3, 2, 2, 2, 3, 3, 3, 3, 3, 3, 0, 0, 0},
    {0, 0, 3, 2, 2, 2, 2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 3, 0, 0, 0},
    {0, 0, 0, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0, 0, 0, 0},
    {0, 0, 0, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0, 0, 0, 0},
    {0, 0, 0, 0, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 3, 3, 2, 2, 2, 2, 2, 3, 3, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void drawPixel(int x, int y, float r, float g, float b) {
    glColor3f(r, g, b); // Establecer el color del pixel
    glBegin(GL_QUADS);  // Dibujar un cuadrado por cada pixel
    glVertex2f(x, y);
    glVertex2f(x + 1, y);
    glVertex2f(x + 1, y + 1);
    glVertex2f(x, y + 1);
    glEnd();
}

void drawGrid() {
    glColor4f(1.0f, 1.0f, 1.0f, 0.3f); // Color blanco con transparencia
    // Dibujar líneas verticales
    for (int i = 0; i <= cols; i++) {
        glBegin(GL_LINES);
        glVertex2f(i, 0);
        glVertex2f(i, rows);
        glEnd();
    }

    // Dibujar líneas horizontales
    for (int i = 0; i <= rows; i++) {
        glBegin(GL_LINES);
        glVertex2f(0, i);
        glVertex2f(cols, i);
        glEnd();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Dibuja la Pokébola
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (pokeball[i][j] == 0) {
                drawPixel(j, rows - i - 1, 1.0f, 1.0f, 0.0f);  // Amarillo
            }
            else if (pokeball[i][j] == 1) {
                drawPixel(j, rows - i - 1, 1.0f, 0.0f, 0.0f);  // Rojo
            }
            else if (pokeball[i][j] == 2) {
                drawPixel(j, rows - i - 1, 1.0f, 1.0f, 1.0f);  // Blanco
            }
            else if (pokeball[i][j] == 3) {
                drawPixel(j, rows - i - 1, 0.0f, 0.0f, 0.0f);  // Negro
            }
        }
    }

    drawGrid(); // Dibuja la cuadrícula después de la Pokébola

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Fondo negro
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, cols, 0.0, rows);  // Sistema de coordenadas ortogonales
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Pokedex - Victor Madrid");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
