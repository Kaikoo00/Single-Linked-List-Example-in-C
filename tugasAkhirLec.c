#include <stdio.h>
#include <stdlib.h>
  
typedef struct Node {
    int x;
    struct Node* next;
}node;

node *head, *tail,*newnode;

void CreateLinkedList(int value){
	newnode=malloc(sizeof(node));
	newnode->x=value;
	newnode->next=NULL;
	head=newnode;
    tail=head;
    head->next=tail;
}

void insert_head(int value){
    newnode=malloc(sizeof(node));;
    newnode->x=value;
    newnode->next=head;
    head = newnode;
}

void insert_tail(int value){
    newnode=malloc(sizeof(node));
    newnode->x=value;
    newnode->next=NULL;
    tail->next=newnode;
    tail = tail->next;
}

void delete_head(){
    head = head->next;
}

void delete_element(int pos){
    if(pos>=data_count){
        return;
    }

    if(pos==0){
        delete_head();
        return;
    }

    else{
        node *curr = head;
        node *prev;
        for(int i=0; i<pos;i++){
            prev = curr;
            curr = curr->next;
            if(curr==tail){
                free(curr);
                tail = prev;
                return;
            }
        }
        prev->next = curr->next;
    }
    return;
}
// Driver's code
int main()
{
    CreateLinkedList(1);data_count++;
    insert_tail(2);data_count++;
    insert_head(3);data_count++;
    insert_tail(4);data_count++;
    insert_head(5);data_count++;
    printf("%d %d %d %d %d\n", head->x, head->next->x, head->next->next->x,head->next->next->next->x,tail->x);
    delete_element(4);
    printf("%d %d %d %d\n", head->x, head->next->x, head->next->next->x,tail->x);
    return 0;
}
