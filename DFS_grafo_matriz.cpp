#include <iostream>

using namespace std;

int add_aresta(int **m_grafo, int inicio, int fim);
int DFS(int **m_grafo, int *valor, int base, int buscado);

int main(){
    int i, j, opcao=1, inicio, fim, buscado, resultado;
    int **m_grafo;
    m_grafo = (int **)malloc(5*sizeof(int*));
    for(int k=0; k<5; k++) m_grafo[k] = (int *)malloc(5*sizeof(int*));
    int valor[4];

    //neste código o grafo é representado por uma matriz e os seu valor é representado pelo vetor
    //de maneira a simplificar e agilizar, valor é o mesmo número do indice que o vertice representa na matriz
    //apartir disso, poderia se dispensar o uso do vetor valor, mas será mantido por fim de ilustrar a ideia
    //o vertice que será utilizado como raiz por padrão é o vertice 0
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            m_grafo[i][j]=(i==j ? 0 : -1);
        }
        valor[i]=i;
    }
    do{
        cout<<"\tOs valores dos vertices sao 0, 1, 2, 3, 4\n\tNa busca o vertice utilizado como raiz é por padrao o 0\n\n";
        cout<<"\t[1] inserir aresta\n\t[2] busca por profundidade\n\t[0] sair\n\t---> ";
        cin>>opcao;
        switch(opcao){
            case 1:
                cout<<"\tdigite o numero do vertice inicial: ";
                cin>>inicio;
                cout<<"\tdigite o numero do vertice final: ";
                cin>>fim;
                add_aresta(m_grafo, inicio, fim);
                break;
            case 2:
                cout<<"\tdigite o numero do vertice a ser buscado: ";
                cin>>buscado;
                if(resultado) cout<<"\n\tEncontrado!\n\n";
                else cout<<"\n\tNão foi encontrado!\n\n";
                break;
        }
    }while(opcao!=0);

    return 0;
}

int add_aresta(int **m_grafo, int inicio, int fim){
    if(inicio==fim){
        cout<<"\tNão é permitido criar aresta para o proprio grafo\n";
        return 0;
    }
    else if(inicio>=5 || inicio<0){
        cout<<"\tValores de vertices invalidos\n";
        return 0;
    }
    else if(fim>=5 || fim<0){
        cout<<"\tValores de vertices invalidos\n";
        return 0;
    }
    m_grafo[inicio][fim]=1;
    return 0;
}

int DFS(int **m_grafo, int *valor, int base, int buscado){
    int resultado=0;
    if(valor[base]==buscado) return 1;
    else{
        for(int i=0; i<5; i++){
            if(m_grafo[base][i]==1){
                resultado = DFS(m_grafo, valor, i, buscado);
                if(resultado==1) return 1;
            }
                
        }
    }
    return 0;
}