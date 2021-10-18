#include<iostream>

using namespace std;

struct node{
    int n;
    node *next;
    node *prev;
};


int insert(node **head, node **tail);
int remove_last(node **head, node **tail);


int main(){
    node *head = NULL, *tail = NULL, *el;
    int op, position, number;
    do{
        cout << "\nTake one option: \n";
        cout << "1) insert a node \n";
        cout << "2) remove the last node \n";
        cout << "0) exit\n";
        cout << "----> ";
        
        cin >> op;

        switch(op){
            case 1:
                insert(&head, &tail);
                break;
            
            case 2:
                remove_last(&head, &tail);
                break;
            
        }
        el = tail;
        cout << "\n";
        while(el!=NULL){
            cout << el->n << endl;
            el = el->prev;
        }
        cout << "\n";
    }while(op != 0);
    

    return 0;
}

int insert(node **head, node **tail){
    node *nn = new node();
    cout << "insert the new number\n-----> ";
    cin >> nn->n;
    node *ptr, *prev;
    
    if(*head == NULL){
        *head = nn;
        *tail = nn;
        nn->next = NULL;
        nn->prev = NULL;
    }
    else{
        ptr = *head;
        while(ptr != NULL) ptr = ptr->next;
        if(ptr == *head){
            nn->prev = NULL;
            nn->next = *head;
            (*head)->prev = nn;
            *head = nn;
        }
        else{
            (*tail)->next = nn;
            nn->prev = *tail;
            nn->next = NULL;
            *tail = nn;
        }

    }
    return 0;
}


int remove_last(node **head, node **tail){
    if(*head == NULL){
        cout << "The linked list is empty\n";
    }
    else if(*head == *tail){
        delete *head;
        *head = NULL;
        *tail = NULL;
        cout << "POP\n";
        cout << "Now the linked list is empty\n";
    }
    else{
        *tail = (*tail)->prev;
        delete (*tail)->next;
        (*tail)->next = NULL;
        cout << "POP\n";
    }
    return 0;
}

