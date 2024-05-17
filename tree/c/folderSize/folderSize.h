#pragma once

int FOLDER_SIZE;
typedef struct treeNode {
    int size;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

treeNode* makeRootNode(int size, treeNode *leftNode, treeNode *rightNode);
int postorderFolderSize(treeNode *root);
void freeTree(treeNode *root);
