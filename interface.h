#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include <GL\glut.h>

int linhas, colunas, h, x, y, z;
char Bancomatriz[100][100][100];
GLint widht, height, primitiva;


void DesenharPercurso(void);
void DesenharMenu(void);
void Timer(int value);
void Desenhar(void);
void AlteraTamanhoJanela(GLsizei w, GLsizei h);
void Inicializar(void);
void MenuPrincipal(int op);
void CriaMenu();
void GerenciaMouse(int button, int state, int x, int y);

#endif // INTERFACE_H_INCLUDED
