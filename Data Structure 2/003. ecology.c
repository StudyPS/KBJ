/*
문제 번호 : 4358
문제 링크 : https://www.acmicpc.net/problem/4358
컴파일러 버전 : gcc 11.3.1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    char name[31];
    int count;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* createNode(char* name) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(node->name, name);
    node->count = 1;
    node->left = node->right = NULL;
    return node;
}

TreeNode* insert(TreeNode* root, char* name) {
    if (root == NULL) return createNode(name);

    int cmp = strcmp(name, root->name);
    if (cmp < 0)
        root->left = insert(root->left, name);
    else if (cmp > 0)
        root->right = insert(root->right, name);
    else
        root->count++;

    return root;
}

void inorder(TreeNode* root, int total) {
    if (root == NULL) return;
    inorder(root->left, total);
    printf("%s %.4f\n", root->name, (root->count * 100.0) / total);
    inorder(root->right, total);
}

int main() {
    TreeNode* root = NULL;
    char name[31];
    int total = 0;

    while (fgets(name, sizeof(name), stdin)) {
        if (name[0] == '\n') break;
        name[strcspn(name, "\n")] = 0;
        root = insert(root, name);
        total++;
    }

    inorder(root, total);
    return 0;
}
