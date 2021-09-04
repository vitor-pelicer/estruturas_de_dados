#include<iostream>

using namespace std;

struct node{
    int n;
    node *next;
    node *prev;
};


int insert(node **head, node **tail);
int remove_first(node **head, node **tail);
int remove_last(node **head, node **tail);
int remove_at(node **head, node **tail, int *position);
int remove_all(node **head, node **tail);
int search(node *head, int *wanted);

int main(){
    node *head = NULL, *tail = NULL, *el;
    int op, position, number;
    do{
        cout << "\nTake one option: \n";
        cout << "1) insert a node \n";
        cout << "2) remove the first node \n";
        cout << "3) remove the last node \n";
        cout << "4) remove a node at a specific position \n";
        cout << "5) delete all nodes \n";
        cout << "6) search the first occurence of a number in the linked-list \n";
        cout << "0) Exit \n";
        cout << "----> ";
        
        cin >> op;

        switch(op){
            case 1:
                insert(&head, &tail);
                break;
            case 2:
                remove_first(&head, &tail);
                break;
            case 3:
                remove_last(&head, &tail);
                break;
            case 4:
                cout << "Insert the position to remove\n-----> ";
                cin >> position;
                remove_at(&head, &tail, &position);
                break;
            case 5:
                remove_all(&head, &tail);
                break;
            case 6:
                cout << "Insert the number to be searched\n-----> ";
                cin >> number;
                search(head, &number);
        }
        el = head;
        cout << "\n";
        while(el!=NULL){
            cout << el->n << endl;
            el = el->next;
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

int remove_first(node **head, node **tail){
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
        *head = (*head)->next;
        delete (*head)->prev;
        (*head)->prev = NULL;
        cout << "POP\n";
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

int remove_at(node **head, node **tail, int *position){
    if(position<0){
        cout << "The position does not exist\n";
    }
    else{
        if(*head == NULL){
            cout << "The linked list is empty\n";
        }
        else{
            node *ptr = *head;
            for(int i=0; ptr != NULL && i < *position; i++) ptr = ptr->next;
            if(ptr == NULL){
                cout << "The position does not exist\n";
            }
            else if(ptr == *head){
                if(*head == *tail){
                    *head = NULL;
                    *tail = NULL;
                    delete ptr;
                }else{
                    *head = (*head)->next;
                    (*head)->prev = NULL;
                    delete ptr;
                }
            }else if(ptr == *tail){
                *tail = (*tail)->prev;
                (*tail)->next = NULL;
                delete ptr;
            }else{
                (ptr->prev)->next = ptr->next;
                (ptr->next)->prev = ptr->prev;
                delete ptr;
            }
        }
    }
    return 0;
}

int remove_all(node **head, node **tail){
    node *ptr = *head, *aux;
    while(ptr!=NULL){
        aux = ptr;
        ptr = ptr->next;
        delete aux;
    }
    *head = NULL;
    *tail = NULL;
    return 0;
}

int search(node *head, int *wanted){
    int count = 0;
    if(head == NULL){
        cout << "The linked list is empty\n";
        return -1;
    }
    else{
        node *ptr = head;
        while(ptr != NULL && ptr->n != *wanted){
            ptr = ptr->next;
            count++;
        }
        if(ptr != NULL){
            cout << "\nThe position found is " << count << endl;
            return count;
        }
        else{
            cout << "Number not found\n";
            return -1;
        }
    }
}