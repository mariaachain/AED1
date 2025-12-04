#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void bfs(Node* root) {
    if (root == NULL) return;

    Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int first = 1;
    while (front < rear) {
        Node* current = queue[front++];

        if (!first) printf(" ");
        printf("%d", current->val);
        first = 0;

        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
    printf("\n");
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int C;
    if (scanf("%d", &C) != 1) return 0;

    for (int i = 1; i <= C; i++) {
        int N;
        scanf("%d", &N);

        Node* root = NULL;
        for (int j = 0; j < N; j++) {
            int val;
            scanf("%d", &val);
            root = insert(root, val);
        }

        printf("Case %d:\n", i);
        bfs(root);
        printf("\n");

        freeTree(root);
    }

    return 0;
}
