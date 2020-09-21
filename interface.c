#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "interface.h"

void DesenharPercurso(void){
    int i, j;
    for( i=0; i<linhas+2; i++){
        for( j=0; j<colunas+2; j++){
            if(Bancomatriz[h][i][j] == '1'){
                glBegin(GL_QUADS);
                glColor3f(1.0f, 1.0f, 1.0f);
                glVertex2i(x*j,height-(y*i));
                glVertex2i(x*j,height-(y*(i+1)));
                glVertex2i(x*(j+1),height-(y*(i+1)));
                glVertex2i(x*(j+1),height-(y*i));
                glEnd();
            }
            if(Bancomatriz[h][i][j] == '0' || Bancomatriz[h][i][j] == '.'){
                glBegin(GL_QUADS);
                glColor3f(0.0f, 0.0f, 0.0f);
                glVertex2i(x*j,height-(y*i));
                glVertex2i(x*j,height-(y*(i+1)));
                glVertex2i(x*(j+1),height-(y*(i+1)));
                glVertex2i(x*(j+1),height-(y*i));
                glEnd();
            }
            if(Bancomatriz[h][i][j] == 'm' || Bancomatriz[h][i][j] == 'M'){
                glBegin(GL_QUADS);
                glColor3f(1.0f, 0.0f, 1.0f);
                glVertex2i(x*j,height-(y*i));
                glVertex2i(x*j,height-(y*(i+1)));
                glVertex2i(x*(j+1),height-(y*(i+1)));
                glVertex2i(x*(j+1),height-(y*i));
                glEnd();
            }
            if(Bancomatriz[h][i][j] == 'e' || Bancomatriz[h][i][j] == 'E'){
                glBegin(GL_QUADS);
                glColor3f(0.0f, 1.0f, 0.0f);
                glVertex2i(x*j,height-(y*i));
                glVertex2i(x*j,height-(y*(i+1)));
                glVertex2i(x*(j+1),height-(y*(i+1)));
                glVertex2i(x*(j+1),height-(y*i));
                glEnd();
            }
        }
    }
}

void DesenharMenu(void){
    //VC TEM QUE DESENHAR AQ, QUE É A PRIMEIRA TELA Q CHAMA, COLOQUEI UM TRIANGULO SO P TESTAR
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0, 0);
    glVertex2f(widht, 0);
    glVertex2f(widht/2, height);
    glEnd();
}

//Um callback para atribuir valor a minha variável h e realizar a impressão de movimento amovimento do rato
void Timer(int value){
    h += value;
    if(h<z)
    {
        glutPostRedisplay();
        glutTimerFunc(500, Timer, 1);
    }
}

//Função que desenha o conteúdo selecionado no menu
void Desenhar(void){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    switch(primitiva){

    case 1:
        DesenharMenu();
        break;

    case 2:
        DesenharPercurso();
        break;
    }
    glColor3f(1.0f,1.0f,1.0f);

    glutSwapBuffers();
}

//Função que é passada como argumento de glutReshapeFun, serve para o redimensionamento da minha janela
void AlteraTamanhoJanela(GLsizei w, GLsizei h){
    // Evita a divisao por zero
    if(h == 0) h = 1;

    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Estabelece a janela de seleção (left, right, bottom, top)
    if (w <= h)
        gluOrtho2D (0.0f, w, 0.0f, h);
    else
        gluOrtho2D (0.0f, w, 0.0f, h);

}

void Inicializar (void){
    primitiva = 1;
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

}

//O controle do menu principal do programa
void MenuPrincipal(int op){
    switch(op){
    case 0:
        exit(0);
        break;
    case 1:
        primitiva = 1;
        break;
    case 2:
        primitiva = 2;
        glutTimerFunc(500, Timer, 1);
        break;
    }
    glutPostRedisplay();
}

//Função utilizada criar o menu do programa
void CriaMenu(){
    int menu;

    menu = glutCreateMenu(MenuPrincipal);
    glutAddMenuEntry("SAIR",0);
    glutAddMenuEntry("MENU",1);
    glutAddMenuEntry("INICIAR",2);
    glutAttachMenu(GLUT_LEFT_BUTTON);
}

void GerenciaMouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON)
        if(state == GLUT_DOWN)
            CriaMenu();
    state == GLUT_UP;
    glutPostRedisplay();

}
