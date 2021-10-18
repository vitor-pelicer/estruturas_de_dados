#include<iostream>
#include<cstdlib>

using namespace std;

struct node{
    int n;
    node *next;
    node *prev;
};

//protótipos das funções
int insert(node **head, node **tail);
int remove_first(node **head, node **tail);
int busca(node *head);


int main(){
    node *head = NULL, *tail = NULL;
    srand(time(0));
    int op;

    //cria a lista com 5 nós
    for(int i=1; i<=5; i++){
        insert(&head, &tail);
    }

    //menu
    do{
        cout<<"[1] pop\n[2] buscar o primeiro elemento\n\n[0] sair\n\n--> ";
        cin>>op;

        switch(op){
            case 1:
                remove_first(&head, &tail);
                break;
            case 2:
                busca(head);
                break;
        }
        
        cout << "\n";
    }while(op != 0);
    

    return 0;
}

//função que insere novo nó
int insert(node **head, node **tail){
    node *nn = new node();
    nn->n = rand()%100;
    node *ptr, *prev;
    
    if(*head == NULL){
        *head = nn;
        *tail = nn;
        nn->next = NULL;
        nn->prev = NULL;
    }
    else{
        nn->prev = NULL;
        nn->next = *head;
        (*head)->prev = nn;
        *head = nn;
    }
    return 0;
}

//função que remove o primeiro elemento
int remove_first(node **head, node **tail){
    if(*head == NULL){
        cout<<"\n----------Lista vazia----------\n";
    }
    else if(*head == *tail){
        delete *head;
        *head = NULL;
        *tail = NULL;
        cout << "POP\n";
        cout<<"\n----------Lista limpa----------\n";
    }
    else{
        *head = (*head)->next;
        delete (*head)->prev;
        (*head)->prev = NULL;
        cout << "POP\n";
    }
    return 0;
}

//função que busca o primeiro elemento
int busca(node *head){

    if(head==NULL){
        cout<<"\n----------Lista vazia----------\n";
    }
    else{
        cout<<"\nna primeira posicao esta o numero " << head->n<<"\n\n";
    }
    return 0;
}