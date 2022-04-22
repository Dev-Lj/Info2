#include <stdlib.h>
#include <stdio.h>

#define RED 1
#define BLACK 0

typedef struct RBTNode
{
    struct RBTNode* parent;
    int val;
    struct RBTNode* left;
    struct RBTNode* right;
    int col;
}RBTNode;

void rotateRight(RBTNode* node) {
    RBTNode* t = node->left;
    node->left = t->right;
    t->parent = node->parent;
    if (t->right != NULL)
    {
        // TF is dis doin?
        t->right->parent = node;
    }
    // ToDo: Catch if parent of node is NULL -> root = s
    if (node->parent != NULL)
    {
        // check if node is right child
        if (node==node->parent->right)
        {
            // node is right child of parent
            node->parent->right = t;
        } else
        {
            // node is left child of parent
            node->parent->left = t;
        }
    }
    t->right = node;
    node->parent = t;
}

void rotateLeft(RBTNode* node) {
    RBTNode* t = node->right;
    node->right = t->left;
    t->parent = node->parent;
    if (t->left != NULL)
    {
        t->left->parent = node;
    }
    // ToDo: Catch if parent of node is NULL -> root = s
    if (node->parent != NULL)
    {
        // check if node is right child
        if (node==node->parent->right)
        {
            // node is right child of parent
            node->parent->right = t;
        } else
        {
            // node is left child of parent
            node->parent->left = t;
        }
    }
    t->left = node;
    node->parent = t;
}

void fixRBTInsert(RBTNode* root, RBTNode* node) {
    // Case 0: Color of parent is Black
    // Case 1: Color of uncle is red
    // Case 2: uncle is black, node is a right child
    // Case 3: uncle is black, node is a left child
    while (node->parent != NULL && node->parent->col == RED)
    {
        // check if parent is left or right child of grandparent
        if (node->parent == node->parent->parent->left) 
        {
            // parent is left child
            RBTNode* uncle = node->parent->parent->right;
            if (uncle != NULL && uncle->col == RED)
            {
                // case 1
                node->parent->col = BLACK;
                uncle->col = BLACK;
                node->parent->parent->col = RED;
                node = node->parent->parent;
                // Ensure case 3 does not execute after case 1
                continue;
            } else if (node->parent->right == node)
            {
                // case 2
                node = node->parent;
                rotateLeft(node);
            }
            // case 3
            node->parent->col = BLACK;
            node->parent->parent->col = RED;
            rotateRight(node->parent->parent);
        } else
        {
            // parent is right child
            RBTNode* uncle = node->parent->parent->left;
            if (uncle != NULL && uncle->col == RED)
            {
                // case 1
                node->parent->col = BLACK;
                uncle->col = BLACK;
                node->parent->parent->col = RED;
                node = node->parent->parent;
                // Ensure case 3 does not execute after case 1
                continue;
            } else if (node->parent->left == node)
            {
                // case 2
                node = node->parent;
                rotateRight(node);
            }
            // case 3
            node->parent->col = BLACK;
            node->parent->parent->col = RED;
            rotateLeft(node->parent->parent);
        }
    }
    // case 0
    root->col = BLACK;
}

RBTNode* RBTInsert(RBTNode* root, int val){
    RBTNode* prev =NULL;
    RBTNode* node = malloc(sizeof(RBTNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->col = RED;

    RBTNode* current = root;
    while (current!=NULL)
    {
        prev = current;
        if (node->val < current->val)
        {
            current = current->left;
        } else
        {
            current = current->right;
        }
    }
    node->parent = prev;

    if (prev == NULL)
    {
        root = node;
    } else
    {
        if (node->val < prev->val)
        {
            prev->left = node;
        } else
        {
            prev->right = node;
        }
    }
    fixRBTInsert(root, node);
    
    
    return root;
}

void printTree(RBTNode* root) {
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        printf("%d--%d\n", root->val, root->left->val);
    }
    if (root->right != NULL)
    {
        printf("%d--%d\n", root->val, root->right->val);
    }
    printTree(root->left);
    printTree(root->right);
}

int main() {
    RBTNode* root = RBTInsert(NULL, 40);
    RBTInsert(root, 50);
    RBTInsert(root, 20);
    RBTInsert(root, 11);
    RBTInsert(root, 22);
    RBTInsert(root, 26);
    RBTInsert(root, 23);

    printTree(root);
    return 0;
}

// To run: gcc RedBlackTree.c -o bin/RedBlackTree -g; ./bin/RedBlackTree