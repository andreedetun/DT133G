#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

Node *createNode() {
    Node *tmp = (Node *) malloc(sizeof(Node));
    tmp->key = 0;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

Tree *createTree() {
    Tree *tmp = (Tree *) malloc(sizeof(Tree));
    tmp->root = NULL;

    return tmp;
}

void insert(Tree *tree, int key) {
    Node *newNode = createNode();
    newNode->key = key;
    Node *tmp = NULL;
    Node *root = tree->root;

    while (root != NULL) {
        tmp = root;
        if (newNode->key < root->key)
            root = root->left;
        else
            root = root->right;

        newNode->parent = tmp;
    }

    if (tmp == NULL)
        tree->root = newNode;
    else if (newNode->key < tmp->key)
        tmp->left = newNode;
    else
        tmp->right = newNode;
}

void transplant(Tree *tree, Node *u, Node *v) {
    if(u->parent == NULL) {
        tree->root = v;
    }
    else if(u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }

    if(v != NULL) {
        v->parent = u->parent;
    }
}

void delete(Tree *tree, Node *node) {
    if (node->left == NULL) {
        transplant(tree, node, node->right);
    } else if (node->right == NULL) {
        transplant(tree, node, node->left);
    } else {
        Node *minimum = min(node->right);
        if (minimum->parent != node) {
            transplant(tree, minimum, minimum->right);
            minimum->right = node->right;
            node->right->parent = minimum;
        }

        transplant(tree, node, minimum);
        minimum->left = node->left;
        minimum->left->parent = minimum;
    }
}

Node *search(Node *root, int key) {
    Node *tmp = root;
    while (tmp != NULL && key != tmp->key) {
        if (key < tmp->key)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    return tmp;
}

Node *max(Node *root) {
    Node *tmp = root;
    while (tmp->right != NULL) {
        tmp = tmp->right;
    }

    return tmp;
}

Node *min(Node *root) {
    Node *tmp = root;
    while (tmp->left != NULL) {
        tmp = tmp->left;
    }

    return tmp;
}

Node *successor(Node *node) {
    Node *tmp = node;

    if (tmp->right != NULL)
        return min(tmp->right);

    Node *parent = tmp->parent;
    while (parent != NULL && tmp == parent->right) {
        tmp = parent;
        parent = parent->parent;
    }

    return parent;
}

Node *predecessor(Node *node) {
    Node *tmp = node;

    if (tmp->left != NULL)
        return max(tmp->left);

    Node *parent = tmp->parent;
    while (parent != NULL && tmp == parent->left) {
        tmp = parent;
        parent = parent->parent;
    }

    return parent;
}

int computeDepth(Node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    } else {
        int left = computeDepth(root->left);
        int right = computeDepth(root->right);

        return (1 + ((left > right) ? left : right));
    }
}

int computeSize(Node *root) {
    Node *tmp = root;
    if (tmp == NULL)
        return 0;

    return 1 + computeSize(tmp->left) + computeSize(tmp->right);
}

void inOrderTreeWalk(Node *root) {
    Node *tmp = root;
    if (tmp != NULL) {
        inOrderTreeWalk(tmp->left);
        printf("%d->", tmp->key);
        inOrderTreeWalk(tmp->right);
    }
}

void destroyTree(Node *root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}