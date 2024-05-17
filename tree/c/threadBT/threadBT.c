#include <stdio.h>
#include <stdlib.h>
#include "threadBT.h"

treeThreadNode* makeRootThreadNode(char data, treeThreadNode *left, treeThreadNode *right, int isThreadRight) {
    treeThreadNode *p = (treeThreadNode *)malloc(sizeof(treeThreadNode));
    p->data = data;
    p->left = left;
    p->right = right;
    p->isThreadRight = isThreadRight;
    return p;
}

treeThreadNode* findThreadRight(treeThreadNode *p) {
    treeThreadNode *q = p->right;
    if (q == NULL || p->isThreadRight == 1) {
        return q;
    }
    
    while (q != NULL && q->left != NULL) {
        q = q->left;
    }
    
    return q;
}

void threadInorder(treeThreadNode *root) {
    treeThreadNode *p = root;
    if (p != NULL) {
        while (p->left) p = p->left;
        do {
            printf("%c ", p->data);
            p = findThreadRight(p);
        } while (p);
    }
}

void freeThreadTree(treeThreadNode *root) {
    if (root != NULL) {
        freeThreadTree(root->left);
        if (root->isThreadRight == 0) {
            freeThreadTree(root->right);
        }
        free(root);
    }
}
