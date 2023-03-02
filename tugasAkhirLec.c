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
// Driver's code
int main()
{
    CreateLinkedList(1);printf("%d %d %d\n", head->x, head->next->x, tail->x);
    insert_tail(2);printf("%d %d %d\n", head->x, head->next->x, tail->x);
    insert_head(3);printf("%d %d %d\n", head->x, head->next->x, tail->x);
    insert_tail(4);printf("%d %d %d %d\n", head->x, head->next->x, head->next->next->x,tail->x);
    insert_head(5);printf("%d %d %d %d\n", head->x, head->next->x, head->next->next->x,head->next->next->next->x,tail->x);
    return 0;
}