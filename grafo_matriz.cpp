#include <iostream>

using namespace std;

struct grafo{
int num_vertices;
int **matriz_adj;
};


grafo* cria_grafo(){
    grafo *gr = new grafo();
    cout<<"quantos vertices existem no grafo?\n\t---> ";
    cin>>gr->num_vertices;
    
    gr->matriz_adj = (int**)malloc(gr->num_vertices*sizeof(int*));
    for(int i=0; i<gr->num_vertices; i++){
        gr->matriz_adj[i] = (int*)malloc(gr->num_vertices*sizeof(int));
    }
}

int add_vertice(grafo *gr){
    int v1, v2;
    do{
        cout<<"Na aresta, qual o primeiro vértice?\n[0] - sair\n\t---> ";
        cin>> v1;
        if(v1==0) return 0;
        if(v1<1 || v1>gr->num_vertices) cout<<"\nEntrada inválida, existem "<<gr->num_vertices<<" no grafo\n\n";
    }while(v1<1 || v1>gr->num_vertices);
    do{
        cout<<"Na aresta, qual o segundo vértice?\n[0] - sair\n\t---> ";
        cin>> v2;
        if(v2 == 0) return 0;
        if(v2<1 || v2>gr->num_vertices) cout<<"\nEntrada inválida, existem "<<gr->num_vertices<<" no grafo\n\n";
        if(v1 == v2) cout<<"\nO vértice 1 e o vértice 2 não podem ser os mesmos";
    }while(v2<1 || v2>gr->num_vertices || v1==v2);
    gr->matriz_adj[v1][v2] = 1;
    gr->matriz_adj[v2][v1] = 1;

    return 0;
}

int main(){
    int n;
    grafo *gr = cria_grafo();
    cout<< "quantas arestas existem no grafo?\n\t---> ";
    cin>>n;
    while(n--){
        
    }

    return 0;
}




