#include<stdio.h>
#define size 20

int Q[size];
int front, rear;

void enqueue(int val);
int Dequeue();


void enqueue(int val){
    if((rear + 1) % size == front){
        printf("queue is full");
        return;
    }

    Q[rear] = val;
    rear = (rear + 1) % size;
}

int Dequeue(){
    if(front == rear){
        printf("queue is empty ");
        return -1;
    }

    int val = Q[front];
    front = (front + 1) % size;
    return val;
}

int main(){
    front = rear = 0;

    enqueue(99);
    enqueue(700);
    enqueue(412);
    enqueue(218);

    printf("%d\n", Dequeue());    
    printf("%d\n", Dequeue());    
    printf("%d\n", Dequeue());    
    printf("%d\n", Dequeue());    
    printf("%d\n", Dequeue());    


    return 0; 
}

