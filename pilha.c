#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilha.h"

//Cria uma Pilha do Tipo MazeStacks vazia
void FazMSVazia(MazeStacks *p1){
    p1->topo = (TCelCoord*) malloc(sizeof(TCelCoord));
    p1->base = p1->topo;
    p1->topo->prox = NULL;
}

//Verifica se a pilha MS(MazeStacks) é vazia
int VaziaMS(MazeStacks p1){
    //retorna 1 para vazia, outro valor para não vazia
    return(p1.base == p1.topo);
}

//Empilha um tipo TCoord na pilha MS
void EmpilharMS(MazeStacks *p1, TCoord x){
    TCelCoord *aux;
    aux = (TCelCoord*) malloc(sizeof(TCelCoord));
    p1->topo->coord = x;
    aux->prox = p1->topo;
    p1->topo = aux;
}

//Desempilha um tipo TCoord da pilha MS
void DesempilharMS(MazeStacks *p1, TCoord *x){
    TCelCoord *aux;
    aux = p1->topo;
    p1->topo = aux->prox;
    *x = aux->prox->coord;
    free(aux);
}
