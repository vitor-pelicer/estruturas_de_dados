#include <iostream>
#define TAM 8

struct no{
    int num;
    no *prox;
    void *grPtr;
};

struct grafo{
    int num;
    no *inicio;
    no *fim;
    grafo *prox;
    int adj;
};

struct fila{
    grafo *gr;
    fila *prox;
};


int CriaGrafo(grafo **inicio, grafo **fim, int num);
int CriaAresta(grafo *inicio, int origem, int destino);
int BFS(grafo *gr, int busca, int visitados[], int tam);

int main(){
    grafo *inicio=NULL;
    grafo *fim=NULL;
    grafo *aux;
    no *aux2;
    int tam = TAM;

    //cria vetor para os visitados
    int *visitados = (int*) malloc(TAM*sizeof(int));

    //criado 8 nós no grafo
    for(int i=1; i<=TAM; i++) CriaGrafo(&inicio, &fim, i);

    //criado as conexões no grafo
    CriaAresta(inicio, 1, 2);
    CriaAresta(inicio, 1, 3);
    CriaAresta(inicio, 2, 4);
    CriaAresta(inicio, 2, 5);
    CriaAresta(inicio, 3, 6);
    CriaAresta(inicio, 3, 7);
    CriaAresta(inicio, 7, 8);

    int op=0;
    int num;
    while(true){
        printf("qual a sua opção?\n[1] Buscar número no grafo\n[2] Sair\n---> ");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Digite o número do grafo a ser buscado: ");
                scanf("%d", &num);
                for(int i=0;i<tam;i++) visitados[i]=0;
                BFS(inicio, num, visitados, tam);
                break;
            case 2:
                return 0;
        }
    }
    //apaga todos os vertices e memória alocada dinamicamente no programa
    while(inicio!=NULL){
        aux=inicio;
        inicio=inicio->prox;
        while(aux->inicio != NULL){
            aux2 = aux->inicio;
            aux->inicio = aux->inicio->prox;
            delete aux2;
        }
        delete aux;
    }
    delete visitados;
    return 0;
}
//função para criar um vertice no grafo
int CriaGrafo(grafo **inicio, grafo **fim, int num){
    grafo *novo = new grafo();
    novo->num = num;
    novo->prox = NULL;
    novo->inicio = NULL;
    novo->fim = NULL;
    novo->adj = 0;
    if(*inicio == NULL){
        *inicio = novo;
        *fim = novo;
    }
    else{
        (*fim)->prox = novo;
        *fim = novo;
    }
    return 0;
}

//função para criar uma aresta
int CriaAresta(grafo *inicio, int origem, int destino){
    no *nvOrigem = new no();
    no *nvDestino = new no();
    nvOrigem->num = destino;
    nvDestino->num = origem;
    grafo *g = inicio;
    grafo *d = inicio;
    while(g!=NULL){
        if(g->num == origem) break;
        g = g->prox;
    }
    while(d!=NULL){
        if(d->num == destino) break;
        d = d->prox;
    }
    if(g==NULL){
        printf("vertice de origem não existe\n");
        delete nvDestino;
        delete nvOrigem;
        return -1;
    }
    if(d==NULL){
        printf("vertice destino não existe\n");
        delete nvDestino;
        delete nvOrigem;
        return -1;
    }
    nvDestino->grPtr = (void*)g;
    nvOrigem->grPtr = (void*)d;

    if(g->inicio == NULL){
        nvOrigem->prox = NULL;
        g->fim = nvOrigem;
        g->inicio = nvOrigem;
    }
    else{
        g->fim->prox = nvOrigem;
        g->fim = nvOrigem;
    }
    
    if(d->inicio == NULL){
        nvDestino->prox = NULL;
        d->fim = nvDestino;
        d->inicio = nvDestino;
    }
    else{
        d->fim->prox = nvDestino;
        d->fim = nvDestino;
    }
    g->adj++;
    d->adj++;
    return 0;

}

//função para busca em largura
int BFS(grafo *gr, int busca, int visitados[], int tam){
    fila *inicio = new fila();
    fila *fim = inicio;
    fila *aux;
    grafo *roda;
    no *adj;
    int cont=0;
    inicio->gr = gr;
    inicio->prox = NULL;
    visitados[gr->num] = 1;

    while(inicio != NULL && cont<tam){
        roda = inicio->gr;
        aux = inicio;
        if(inicio==fim){
            fim = NULL;
            inicio = NULL;
        }else inicio = inicio->prox;
        
        adj = roda->inicio;
        delete aux;

        printf("\nVisitando os vertices adjacentes do no n%d\n", roda->num);
        
        while(adj!=NULL){
            if(visitados[adj->num]==0){
                
                if(adj->num == busca){
                    printf("\n\tEncontrou!!!\n\n");
                    while(inicio!=NULL){
                       aux = inicio;
                       inicio = inicio->prox;
                       delete aux;
                    }
                    return 1;
                }
                else{
                    printf("\tvisitando o n%d\n", adj->num);
                    cont++;
                    visitados[adj->num] = 1;
                    fila *novo = new fila();
                    novo->prox = NULL;
                    novo->gr = (grafo*)adj->grPtr;
                    if(inicio==NULL){
                        inicio = novo;
                        fim = novo;
                    }
                    else{
                        fim->prox = novo;
                        fim = novo;
                    }

                }
            }
            adj = adj->prox;
        }


    }

    return -1;
}
