#ifndef LABIRINTO_H_INCLUDED
#define LABIRINTO_H_INCLUDED

#include "pilha.h"
#include "interface.h"

typedef struct line{
    char vet[100];
} TLinha;

typedef struct celLab{
    struct celLab *prox;
    TLinha linha;
} TCelLab;

typedef struct lab{
    TCelLab *base;
    TCelLab *topo;
} MazeRows;

void FazMRVazia(MazeRows *p1);
int VaziaMR(MazeRows p1);
void EmpilharMR(MazeRows *p1, TLinha a);
void DesempilharMR(MazeRows *p1, TLinha *a);
void LabDimensoes(int *lin, int *col);
void ConstruirLabirinto(MazeRows *p1, char matriz[100][100]);
void Percorrer(MazeStacks *p1, char matriz[100][100]);

#endif // LABIRINTO_H_INCLUDED
