#include <iostream>

using namespace std;

struct node{
    int n;
    node *next;
    node *prev;
};

int insert(node **head, node **tail);
int pop(node **head, node **tail);
int view(node *head, node *tail);

int main(){
    int cont=0, op;
    node *head=NULL, *tail=NULL;
    do{
        cout << "\n\t[1] Inserir\n\t[2] POP\n\t[3] Visualizar pilha\n\t[0] Sair\n----->";
        cin >> op;
        switch(op){
            case 1:
                insert(&head, &tail);
                cont++;
                break;
            case 2:
                if(cont)
                    pop(&head, &tail);
                else cout << "\n\tPilha vazia";
                break;
            case 3:
                view(head, tail);
        }
    }while(op!=0);
    return 0;
}

int insert(node **head, node **tail){
    node *n = new node();
    cout << "\n\tDigite o número do novo elemento da pilha\n----->";
    cin >> n->n;
    if(*head == NULL){
        *head = n;
        *tail = n;
        n->next = NULL;
        n->prev = NULL;
    }
    else{
        (*tail)->next = n;
        n->prev = (*tail);
        n->next = NULL;
        *tail = n;
    }
    return 0;
}

int pop(node **head, node **tail){
    if(*head == NULL)
    cout << "\n\tPilha está vazia";
    else{
        if(*head == *tail){
            delete *head;
            *head = NULL;
            *tail = NULL;
        }
        else{
            *tail = (*tail)->prev;
            delete (*tail)->next;
            (*tail)->next = NULL;
        }

    }
    return 0;
}

int view(node *head, node *tail){
    node *atual = tail;
    while(atual != NULL){
        cout << "\t" << atual->n << "\n";
        atual = atual->prev;
    }
    return 0;
}