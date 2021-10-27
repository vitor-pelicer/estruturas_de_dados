#include <iostream>
#define TAM 9

using namespace std;

struct hashNode{
    hashNode *prox;
    int valor;
};

int fhash(int n){
    int pos;
    if(n>=0) pos = n%TAM;
    else pos = -(n%TAM);
    return pos;
}


int inserirHash(int add, hashNode **hash);
int buscaHash(int busca, hashNode **hash);
int removeHash(int busca, hashNode **hash);

int main(){
    hashNode *hash[TAM];
    int op, num;
    for(int i=0; i<TAM; i++) hash[i] = NULL;
    cout<<"Digite a opção desejada\n";
    cout<<"considerando que a O(B) é a complexidade de busca na lista de colisões\n";
    cout<<"A complexidade pode ser considerada O(1), dependendo dos fatores\n";
    cout<<"uma aproximação de B é n/m\n";
    cout<<"Considerando n o número de elementos a serem inseridos\n";
    cout<<"E M o número de posições da tabela Hash\n";
    cout<<"fonte GeeksforGeeks Hashing | Set 2 (Separate Chaining)\n\n";
    //https://www.geeksforgeeks.org/hashing-set-2-separate-chaining/
    do{
        
        cout<<"[0] Sair\n";
        cout<<"[1] Inserir ( Complexidade O(1) )\n";
        cout<<"[2] Busca ( Complexidade O(1 + B) )\n";
        cout<<"[3] remover ( Complexidade O(1 + B) )\n";
        cout<<"--> ";
        cin>>op;
        switch(op){
            case 1:{
                cout<<"Digite o número a ser inserido:\n";
                cout<<"---> ";
                cin>>num;
                inserirHash(num, &(hash[fhash(num)]));
                break;
            }
            case 2:{
                cout<<"Digite o número a ser buscado:\n";
                cout<<"---> ";
                cin>>num;
                if(buscaHash(num, &(hash[fhash(num)]))) cout<<"Elemento encontrado\n\n";
                else cout<<"Elemento não encontrado\n\n";
                break;
            }
            case 3:{
                cout<<"Digite o número a ser removido:\n";
                cout<<"---> ";
                cin>>num;
                removeHash(num, &(hash[fhash(num)]));
                break;
            }
        }
    }while(op!=0);

    
    return 0;
}

int inserirHash(int add, hashNode **hash){
    hashNode *no = new hashNode(), *iter = *hash;
    int op;
    no->valor = add;
    no->prox = NULL;
    if(*hash==NULL){
        *hash = no;
    }
    else{
        while(true){
            cout<<"posição ocupada, deseja realizar o tratamento por encadeamento?\n";
            cout<<"[1] SIM\n";
            cout<<"[2] NÃO\n";
            cin>>op;
            if(op==1||op==2) break;
            else cout<<"opção inválida\n\n";
        }

        if(op==1){
            no->prox = *hash;
            *hash = no;
        }
        else{
            cout<<"cancelando...\n";
        }
    }
    return 0;
}

int buscaHash(int busca, hashNode **hash){
    hashNode *iter = *hash;
    while(iter != NULL){
        if(iter->valor == busca) return 1;
        else iter = iter->prox;
    }
    return 0;
}

int removeHash(int busca, hashNode **hash){
    hashNode *iter = *hash, *ant=NULL;
    while(iter != NULL){
        if(iter->valor == busca) break;
        else{
            ant=iter;
            iter = iter->prox;
        }
    }
    if(iter==NULL){
        cout<<"Não existe o elemento buscado na lista\n\n";
        return 0;
    } 
    else{
        if(ant==NULL){
            *hash = (*hash)->prox;
            delete iter;
        }
        else{
            ant->prox = iter->prox;
            delete iter;
        }
    }
    return 0;
}