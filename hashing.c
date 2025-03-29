#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 50

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* hashTableChaining[TABLE_SIZE];

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insertChaining(int key) {
    int index = hashFunction(key);
    Node* newNode = createNode(key);
    newNode->next = hashTableChaining[index];
    hashTableChaining[index] = newNode;
}

int searchChaining(int key) {
    int index = hashFunction(key);
    Node* temp = hashTableChaining[index];
    while (temp != NULL) {
        if (temp->key == key) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void displayChaining() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        Node* temp = hashTableChaining[i];
        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int hashTableLinear[TABLE_SIZE];

int hashFunctionLinear(int key) {
    return key % TABLE_SIZE;
}

void insertLinear(int key) {
    int index = hashFunctionLinear(key);
    while (hashTableLinear[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTableLinear[index] = key;
}

int searchLinear(int key) {
    int index = hashFunctionLinear(key);
    while (hashTableLinear[index] != -1) {
        if (hashTableLinear[index] == key) {
            return 1;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return 0;
}

void displayLinear() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTableLinear[i] != -1) {
            printf("[%d]: %d ", i, hashTableLinear[i]);
        } else {
            printf("[%d]: NULL ", i);
        }
    }
}

int main() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTableChaining[i] = NULL;
        hashTableLinear[i] = -1;
    }

    insertChaining(12);
    insertChaining(22);
    insertChaining(32);
    insertChaining(42);
    insertChaining(52);

    insertLinear(12);
    insertLinear(22);
    insertLinear(32);
    insertLinear(42);
    insertLinear(52);

    printf("Hash Table with Chaining:\n");
    displayChaining();

    printf("\nHash Table with Linear Probing:\n");
    displayLinear();

    printf("\nSearching for 32 in Chaining: %s\n", searchChaining(32) ? "Found" : "Not Found");
    printf("Searching for 99 in Chaining: %s\n", searchChaining(99) ? "Found" : "Not Found");

    printf("\nSearching for 32 in Linear Probing: %s\n", searchLinear(32) ? "Found" : "Not Found");
    printf("Searching for 99 in Linear Probing: %s\n", searchLinear(99) ? "Found" : "Not Found");

    return 0;
}
