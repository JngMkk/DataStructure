#pragma oncde

typedef char element;

typedef struct treeNode {
    element data;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

treeNode* makeRootNode(element data, treeNode *left, treeNode *right);
void preorder(treeNode *root);
void inorder(treeNode *root);
void postorder(treeNode *root);
void freeTree(treeNode *root);
