#include<iostream>
#include<cstdlib>
#define tamanho 5
using namespace std;

//estrutura para o elemento da lista
struct el{
    int n;
    el *prox;
};

//função para excluir um elemento da lista
int pop(el **head){
    el *aux = *head, *ant;
    //verifica se alista está vazia
    if(*head == NULL){
        cout<<"\n----------Lista vazia----------\n";
    }else{
        //while busca o fim da lista
        while(aux->prox!=NULL){
            ant=aux;
            aux = aux->prox;
        }
        //caso haja apenas um elemento (cabeça da lista)
        if(aux==*head){
            delete aux;
            *head = NULL;
            cout<<"\n----------Lista limpa----------\n";
        }
        //caso haja mais de um elemento na lista
        else{
            ant->prox=NULL;
            delete aux;
        }
    }
    return 0;
}

//função de busca do último elemento da lista
int busca(el *ptr){
    if(ptr!=NULL){
        while(ptr->prox!=NULL){
            ptr = ptr->prox;
        } 
        cout<<"\nna ultima posicao esta o numero " << ptr->n<<"\n\n";
    }else{
        cout<<"\n----------Lista vazia----------\n";
    }
    return 0;
}
//função principal
int main(){
    int count=0, op;
    el *head, *aux;
    srand(time(0));

    //for para a criação da lista com 5 elementos conforme o enunciado
    for(int i=1; i<=tamanho; i++){
        el *novo = new el();
        novo->n = rand()%100;
        novo->prox = NULL;
        if(i==1){
            head = novo;
            aux = novo;
        }else{
            aux->prox = novo;
            aux = novo;
        }
    }//fim do for
//inicio do menu
do{
    cout<<"[1] pop\n[2] buscar último elemento\n\n[0] sair\n\n--> ";
    cin>>op;
    if(op==1){
        //exclui um elemento
        pop(&head);
    }else if(op==2){
        //busca um elemento
        busca(head);
    }
}while(op!=0);//fim do menu
    return 0;
}