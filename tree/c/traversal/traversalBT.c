#include <stdio.h>
#include <stdlib.h>
#include "traversalBT.h"

treeNode* makeRootNode(element data, treeNode *left, treeNode *right) {
    treeNode *root = malloc(sizeof(treeNode));
    root->data = data;
    root->left = left;
    root->right = right;
    return root;
}

// 전위 연산
void preorder(treeNode *root) {
    if (root) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// 중위 연산
void inorder(treeNode *root) {
    if (root) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

// 후위 연산
void postorder(treeNode *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

void freeTree(treeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
