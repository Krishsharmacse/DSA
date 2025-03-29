#include<stdio.h>
#include<stdlib.h>

void push(int val);
int pop();
int peek();

typedef struct Node{
    int data;
    struct  Node *next;
} node;

static node *head = NULL; 
void push(int val){
    node *temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = head;
    head = temp;
}

int pop(){
    if(head == NULL){
        printf("empty stack\n");
        return -1; 
    }
    node *temp = head;
    int val = head->data;
    head = head->next;
    free(temp);
    return val;
}

int peek(){
    if(head == NULL){
        printf("empty stack\n");
        return -1;
    }
    return head->data;
}

int isEmpty() {
    return head == NULL;
}

int main(){
    push(52);
    push(19);
    push(85);
    push(92);

    printf("peek: %d\n", peek());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
        printf("%d\n", pop());


    return 0;
}


