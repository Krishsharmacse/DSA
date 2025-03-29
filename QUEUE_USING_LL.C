#include<stdio.h>
#include<stdlib.h>
typedef struct Queue {
    int data;
    struct Queue *next;
} Queue;

Queue *rear = NULL;


void enqueue(int val);
int dequeue();



void enqueue(int val){
    Queue *temp = (Queue *)malloc(sizeof(Queue));

    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }


    temp->data = val;
    if(rear == NULL){
        temp->next = temp;
    }else{
        temp->next = rear->next;
        rear->next = temp;
    }
    rear = temp;
}

int dequeue(){
    if (rear == NULL) {
        printf("Queue is empty ");
        return -1;
    }
    Queue *temp = rear->next;
    if(temp == rear){
        rear = NULL;
    }else{
        rear->next = temp->next;
    }
    int val = temp->data;
    free(temp);
    return val;
}


int main(){
    enqueue(12);
    enqueue(85);
    enqueue(721);
    enqueue(101);

    printf("OUTPUT OF QUEUE FOR LL IS %d\n", dequeue());
    printf("OUTPUT OF QUEUE FOR LL IS %d\n", dequeue());
    printf("OUTPUT OF QUEUE FOR LL IS %d\n", dequeue());
    printf("OUTPUT OF QUEUE FOR LL IS %d\n", dequeue());
    printf("OUTPUT OF QUEUE FOR LL IS %d\n", dequeue());
    
    return 0;
}
