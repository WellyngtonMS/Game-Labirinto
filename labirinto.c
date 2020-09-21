#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "labirinto.h"

void FazMRVazia(MazeRows *p1){
    p1->topo = (TCelLab*) malloc(sizeof(TCelLab));
    p1->base = p1->topo;
    p1->topo->prox = NULL;
}

//Verifica se a pilha MR(MazeRows) é vazia
int VaziaMR(MazeRows p1){
    //retorna 1 para vazia, outro valor para não vazia
    return(p1.base == p1.topo);
}

//Empilha um tipo TLinha na pilha MR
void EmpilharMR(MazeRows *p1, TLinha x){
    TCelLab *aux;
    aux = (TCelLab*) malloc(sizeof(TCelLab));
    p1->topo->linha = x;
    aux->prox = p1->topo;
    p1->topo = aux;
}

//Desempilha um tipo TLinha da pilha MR
void DesempilharMR(MazeRows *p1, TLinha *x){
    TCelLab *aux;
    aux = p1->topo;
    p1->topo = aux->prox;
    *x = aux->prox->linha;
    free(aux);
}

//Preenche as dimensões do labirinto
void LabDimensoes(int *linhas, int *colunas){
    printf("PREENCHA OS DADOS TENDO EM MENTE QUE O LABIRINTO SERÁ FECHADO POR PAREDES!\n");
    printf("\nDigite quantas linhas tem o labirinto: ");
    scanf("%d",linhas);
    printf("Digite quantas colunas tem o labirinto: ");
    scanf("%d",colunas);
    system("cls");
}

//Função que faz o processo de Construção e cercamento do Labirinto
void ConstruirLabirinto(MazeRows *p1, char matriz[100][100]){
    MazeRows pil;
    FazMRVazia(&pil);
    TLinha aux;
    char vet[100], vet2[100];
    int i = 0, j = 0;
    int tam = colunas+2;
    int flag=0;

    printf("\nCONSTRUA O LABIRINTO COM: \n'1' PARA PAREDE | '0' PARA UM ESPACO VAZIO | 'E' PARA A SAÍDA DO LABIRINTO | 'M' PARA A POSIÇÃO INICIAL DO RATO.\nAPERTE 'ENTER' PARA CONTINUAR CONSTRUINDO.\n");
    while(i<linhas){
        vet[0] = '1';
        printf("\nPREENCHA A LINHA %d: ", i+1);
        fflush(stdin);
        fgets(vet+1, 99, stdin);
        if(flag == 0){
            for(j=0; j<tam; j++){
                vet2[j] = '1';
                flag = 1;
            }
            vet2[j] = '\0';
            strcpy(aux.vet, vet2);
            EmpilharMR(p1, aux);
        }
        if(flag == 1){
            vet[tam-1] = '1';
            strcpy(aux.vet, vet);
            EmpilharMR(p1, aux);
        }
        i++;
        printf("LINHA: %s", vet);
    }
    strcpy(aux.vet, p1->base->linha.vet);
    EmpilharMR(p1, aux);

    while(!VaziaMR(*p1)){
        DesempilharMR(p1, &aux);
        EmpilharMR(&pil, aux);
    }

    while(!VaziaMR(pil)){
        for(i=0; i<linhas+2; i++){
            DesempilharMR(&pil, &aux);
            for(j=0; j<colunas+2; j++){
                matriz[i][j] = aux.vet[j];
            }
        }
    }

    printf("\n\nLABIRINTO CONSTRUIDO");
    printf("\n");
    for(i=0; i<linhas+2; i++){
        printf("\n");
        for(j=0; j<colunas+2; j++){
            printf("%c", matriz[i][j]);
        }
    }
}

//Função que percorre o labirinto construído afim de chegar à saída
void Percorrer(MazeStacks *p1, char matriz[100][100]){
    printf("\n\n\n>>>>>>>>>>>PERCORRENDO<<<<<<<<<<<");
    MazeStacks aux;
    FazMSVazia(&aux);
    TCoord currentcell, entrycell, exitcell, candidatacell;
    int i, j, flag=0,cont=0;
    z=0;
    for(i=0; i<linhas+2; i++){
        for(j=0; j<colunas+2; j++){
            if(matriz[i][j] == 'm' || matriz[i][j] == 'M'){
                entrycell.x = i;
                entrycell.y = j;
            }
            if(matriz[i][j] == 'e' || matriz[i][j] == 'E'){
                exitcell.x = i;
                exitcell.y = j;
            }
        }
    }
    currentcell.x = entrycell.x;
    currentcell.y = entrycell.y;

    while(flag == 0){
        printf("\n\n---------------------------------");
        printf("\nMOVIMENTO %d", z+1);
        printf("\n");
        for(i=0; i<linhas+2; i++){
            printf("\n");
            for(j=0; j<colunas+2; j++){
                printf("%c", matriz[i][j]);
                Bancomatriz[z][i][j] = matriz[i][j];
                if(matriz[i][j] == '0'){
                    cont++;
                }
            }
        }
        if(cont == 0){
            flag = 1;
        }
        else{
            //SUPERIOR
            if(matriz[currentcell.x-1][currentcell.y] == '0' || matriz[currentcell.x-1][currentcell.y] == 'e' || matriz[currentcell.x-1][currentcell.y] == 'E'){
                if(matriz[currentcell.x-1][currentcell.y] == 'e' || matriz[currentcell.x-1][currentcell.y] == 'E'){
                    flag=1;
                }
                else{
                    candidatacell.x = currentcell.x-1;
                    candidatacell.y = currentcell.y;
                    EmpilharMS(p1, candidatacell);
                }
            }
            //INFERIOR
            if(matriz[currentcell.x+1][currentcell.y] == '0' || matriz[currentcell.x+1][currentcell.y] == 'e' || matriz[currentcell.x+1][currentcell.y] == 'E'){
                if(matriz[currentcell.x+1][currentcell.y] == 'e' || matriz[currentcell.x+1][currentcell.y] == 'E'){
                    flag=1;
                }
                else{
                    candidatacell.x = currentcell.x+1;
                    candidatacell.y = currentcell.y;
                    EmpilharMS(p1, candidatacell);
                }
            }
            //DIREITA
            if(matriz[currentcell.x][currentcell.y+1] == '0' || matriz[currentcell.x][currentcell.y+1] == 'e' || matriz[currentcell.x][currentcell.y+1] == 'E'){
                if(matriz[currentcell.x][currentcell.y+1] == 'e' || matriz[currentcell.x][currentcell.y+1] == 'E'){
                    flag=1;
                }
                else{
                    candidatacell.x = currentcell.x;
                    candidatacell.y = currentcell.y+1;
                    EmpilharMS(p1, candidatacell);
                }

            }
            //ESQUERDA
            if(matriz[currentcell.x][currentcell.y-1] == '0' || matriz[currentcell.x][currentcell.y-1] == 'e' || matriz[currentcell.x][currentcell.y-1] == 'E'){
                if(matriz[currentcell.x][currentcell.y-1] == 'e' || matriz[currentcell.x][currentcell.y-1] == 'E'){
                    flag=1;
                }
                else{
                    candidatacell.x = currentcell.x;
                    candidatacell.y = currentcell.y-1;
                    EmpilharMS(p1, candidatacell);
                }
            }
            matriz[currentcell.x][currentcell.y] = '.';
            printf("\n\nCURRENT CELL: (%d,%d)", currentcell.x, currentcell.y);
            printf("\nMazeStacks");
            while(!VaziaMS(*p1)){
                DesempilharMS(p1, &currentcell);
                printf("\n(%d,%d)", currentcell.x, currentcell.y);
                EmpilharMS(&aux, currentcell);
            }
            while(!VaziaMS(aux)){
                DesempilharMS(&aux, &currentcell);
                EmpilharMS(p1, currentcell);
            }

            if(flag == 0){
                DesempilharMS(p1, &currentcell);
                matriz[currentcell.x][currentcell.y] = 'm';
            }
            printf("\n---------------------------------");
            z++;
            cont=0;
        }
    }
}
