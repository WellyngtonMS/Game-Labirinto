#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include "interface.h"
#include "labirinto.h"

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "Portuguese");

    MazeRows p1;
    FazMRVazia(&p1);
    MazeStacks p2;
    FazMSVazia(&p2);
    char matriz[100][100];
    LabDimensoes(&linhas, &colunas);
    ConstruirLabirinto(&p1, matriz);
    Percorrer(&p2, matriz);

    glutInit(&argc, argv);

    //Tipo de exebição
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    //Tamanho da janela
    glutInitWindowSize(800,640);

    //Posição da janela na tela
    glutInitWindowPosition(20,20);
    widht = 800;
    height = 640;
    x = widht/(colunas+2);
    y = height/(linhas+2);

    //Criação da janela
    glutCreateWindow("Game Labirinto");

    //Chamada da função que irá desenhar o conteúdo na janela
    glutDisplayFunc(Desenhar);

    //Chamada da função que irá redimensionar o conteúdo da janela
    glutReshapeFunc(AlteraTamanhoJanela);

    //Chamada da função que irá gerenciar os eventos de clique do mouse
    glutMouseFunc(GerenciaMouse);

    //Chamada da função que incializa o background da janela e pode incializar outras coisas
    Inicializar();

    //Chamada da função que coloca todas as funções em loop
    glutMainLoop();

    return EXIT_SUCCESS;
}



