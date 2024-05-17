#include <stdio.h>
#include "threadBT.h"

int main() {
    treeThreadNode *n7 = makeRootThreadNode('D', NULL, NULL, 0);
    treeThreadNode *n6 = makeRootThreadNode('C', NULL, NULL, 1);
    treeThreadNode *n5 = makeRootThreadNode('B', NULL, NULL, 1);
    treeThreadNode *n4 = makeRootThreadNode('A', NULL, NULL, 1);
    treeThreadNode *n3 = makeRootThreadNode('/', n6, n7, 0);
    treeThreadNode *n2 = makeRootThreadNode('*', n4, n5, 0);
    treeThreadNode *n1 = makeRootThreadNode('-', n2, n3, 0);

    n4->right = n2;
    n5->right = n1;
    n6->right = n3;
    
    threadInorder(n1);
    freeThreadTree(n1);
    return 0;
}

