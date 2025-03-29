#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

int height(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalance(struct Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = (height(y->left) > height(y->right)) ? height(y->left) + 1 : height(y->right) + 1;
    x->height = (height(x->left) > height(x->right)) ? height(x->left) + 1 : height(x->right) + 1;

    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = (height(x->left) > height(x->right)) ? height(x->left) + 1 : height(x->right) + 1;
    y->height = (height(y->left) > height(y->right)) ? height(y->left) + 1 : height(y->right) + 1;

    return y;
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + ((height(node->left) > height(node->right)) ? height(node->left) : height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct Node* delete(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = delete(root->left, key);
    else if (key > root->key)
        root->right = delete(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            struct Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = delete(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + ((height(root->left) > height(root->right)) ? height(root->left) : height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 101);
    root = insert(root, 28);
    root = insert(root, 30);
    root = insert(root, 250);
    root = insert(root, 500);

    printf("Inorder traversal of the AVL tree: ");
    inorder(root);
    printf("\n");

    int key = 101;
    struct Node* result = search(root, key);
    if (result != NULL)
        printf("Node with key %d found in the AVL tree.\n", key);
    else
        printf("Node with key %d not found in the AVL tree.\n", key);

    printf("Deleting key 20 from the AVL tree.\n");
    root = delete(root, 20);

    printf("Inorder traversal of the AVL tree after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
