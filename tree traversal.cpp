#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Tree Traversals:\n");
    printf("1. Inorder\n");
    printf("2. Preorder\n");
    printf("3. Postorder\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    printf("Traversal Result: ");
    switch (choice) {
        case 1:
            inorderTraversal(root);
            break;
        case 2:
            preorderTraversal(root);
            break;
        case 3:
            postorderTraversal(root);
            break;
        default:
            printf("Invalid choice.\n");
    }
    printf("\n");

    return 0;
}

