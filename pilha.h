#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct coordenadas{
    int x,y;
} TCoord;

typedef struct celCoord{
    struct celCoord *prox;
    TCoord coord;
} TCelCoord;

typedef struct labcoord{
    TCelCoord *base;
    TCelCoord *topo;
} MazeStacks;

void FazMSVazia(MazeStacks *p1);
int VaziaMS(MazeStacks p1);
void EmpilharMS(MazeStacks *p1, TCoord a);
void DesempilharMS(MazeStacks *p1, TCoord *a);

#endif // PILHA_H_INCLUDED
