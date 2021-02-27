#ifndef LAB_3_BINARYTREE_H
#define LAB_3_BINARYTREE_H

typedef struct node_t {
    int key;
    struct node_t *parent;
    struct node_t *left;
    struct node_t *right;
} Node;

typedef struct tree_t {
    struct node_t *root;
} Tree;

void insert(Tree *tree, int key);

// Rename these pointers
void transplant(Tree *tree, Node *u, Node *v);

void delete(Tree *tree, Node *node);

Node *search(Node *root, int key);

Node *max(Node *root);

Node *min(Node *root);

Node *successor(Node *node);

Node *predecessor(Node *node);

int computeDepth(Node *root);

int computeSize(Node *root);

// Helper functions
Tree *createTree();

Node *createNode();

void inOrderTreeWalk(Node *root);

void destroyTree(Node *root);

#endif //LAB_3_BINARYTREE_H
