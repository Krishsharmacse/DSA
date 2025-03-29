#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* parent;
    int rank;
} Node;

Node* makeSet(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->parent = newNode;
    newNode->rank = 0;
    return newNode;
}

Node* find(Node* node) {
    if (node->parent != node) {
        node->parent = find(node->parent);
    }
    return node->parent;
}

void unionSets(Node* node1, Node* node2) {
    Node* root1 = find(node1);
    Node* root2 = find(node2);

    if (root1 != root2) {
        if (root1->rank > root2->rank) {
            root2->parent = root1;
        } else if (root1->rank < root2->rank) {
            root1->parent = root2;
        } else {
            root2->parent = root1;
            root1->rank++;
        }
    }
}

void display(Node* node) {
    printf("Element: %d, Parent: %d, Rank: %d\n", node->data, node->parent->data, node->rank);
}

int main() {
    Node* node1 = makeSet(1);
    Node* node2 = makeSet(2);
    Node* node3 = makeSet(3);
    Node* node4 = makeSet(4);
    Node* node5 = makeSet(5);

    printf("Before union:\n");
    display(node1);
    display(node2);
    display(node3);
    display(node4);
    display(node5);

    unionSets(node1, node2);
    unionSets(node3, node4);
    unionSets(node2, node3);

    printf("\nAfter union:\n");
    display(node1);
    display(node2);
    display(node3);
    display(node4);
    display(node5);

    printf("\nFind operation results:\n");
    printf("Find 1: %d\n", find(node1)->data);
    printf("Find 2: %d\n", find(node2)->data);
    printf("Find 3: %d\n", find(node3)->data);
    printf("Find 4: %d\n", find(node4)->data);
    printf("Find 5: %d\n", find(node5)->data);

    return 0;
}
