#include<iostream>

using namespace std;

struct node{
    int n;
    node *next;
    node *prev;
};


int insert(node **head, node **tail);
/*int remove_first();
int remove_back();
int remove_at();
int remove_all();
int search();*/

int main(){
    node *head = NULL, *tail = NULL, *el;
    int op;
    do{
        cout << "Take one option: \n";
        cout << "1) insert a node \n";
        cout << "2) remove the first node \n";
        cout << "3) remove the last node \n";
        cout << "4) remove a node at a specific position \n";
        cout << "5) delete all nodes \n";
        cout << "6) search the first occurence of a number in the linked-list \n";
        cout << "0) Exit \n";
        cout << "---->";
        

        insert(&head, &tail);

        el = head;
        while(el!=NULL){
            cout << el->n << endl;
            el = el->next;
        }

    }while(true);
    

    return 0;
}

int insert(node **head, node **tail){
    node *nn = new node();
    cout << "insert the new number";
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
        while(ptr != NULL && nn->n > ptr->n) ptr = ptr->next;
        if(ptr == *head){
            nn->prev = NULL;
            nn->next = *head;
            (*head)->prev = nn;
            *head = nn;
        }
        else if(ptr == NULL){
            (*tail)->next = nn;
            nn->prev = *tail;
            nn->next = NULL;
            *tail = nn;
        }
        else{
            prev = ptr->prev;
            ptr->prev = nn;
            prev->next = nn;
            nn->next = ptr;
            nn->prev = prev;
        }

    }
    return 0;
}