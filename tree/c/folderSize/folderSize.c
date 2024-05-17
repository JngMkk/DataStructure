#include <stdlib.h>
#include "folderSize.h"

treeNode* makeRootNode(int size, treeNode *leftNode, treeNode *rightNode) {
    treeNode *root = malloc(sizeof(treeNode));
    root->size = size;
    root->left = leftNode;
    root->right = rightNode;

    return root;
}

// 각 폴더의 크기를 계산하기 위한 후위 순회 연산
int postorderFolderSize(treeNode *root) {
    if (root) {
        postorderFolderSize(root->left);
        postorderFolderSize(root->right);
        FOLDER_SIZE += root->size;
    }

    return FOLDER_SIZE;
}

void freeTree(treeNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
