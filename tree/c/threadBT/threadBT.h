#pragma once

typedef struct treeThreadNode {
    char data;
    struct treeThreadNode *left;
    struct treeThreadNode *right;
    int isThreadRight;
} treeThreadNode;

treeThreadNode* makeRootThreadNode(char data, treeThreadNode *left, treeThreadNode *right, int isThreadRight);
treeThreadNode* findThreadRight(treeThreadNode *p);
void threadInorder(treeThreadNode *root);
void freeThreadTree(treeThreadNode *root);
