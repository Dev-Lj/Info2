#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right; 
}TreeNode;

void rotateRight(TreeNode* root, TreeNode* node) {
    TreeNode* t = node->left;
    node->left = t->right;
    t->right = node;

    // Get parent of node
    TreeNode* current = root;
    TreeNode* last = NULL;
    while (current != node && current != NULL)
    {
        last = current;
        if (current->val < node->val)
        {
            current = current->right;
        } else
        {
            current = current->left;
        }
    }
    if (last != NULL)
    {
        if (node == last->right)
        {
            // node is right child
            last->right = t;
        } else
        {
            // node is left child
            last->left = t;
        }
    } // else node is root -> nothin to do
}

void rotateLeft(TreeNode* root, TreeNode* node) {
    TreeNode* t = node->right;
    node->right = t->left;
    t->left = node;

    // Get parent of node
    TreeNode* current = root;
    TreeNode* last = NULL;
    while (current != node && current != NULL)
    {
        last = current;
        if (current->val < node->val)
        {
            current = current->right;
        } else
        {
            current = current->left;
        }
    }
    if (last != NULL)
    {
        if (node == last->right)
        {
            // node is right child
            last->right = t;
        } else
        {
            // node is left child
            last->left = t;
        }
    } // else node is root -> nothin to do
}

TreeNode* insert(TreeNode* root, int val) {
    TreeNode* newNode = malloc(sizeof(TreeNode));
    newNode->val = val;

    TreeNode* current = root;
    TreeNode* last = NULL;

    while (current != NULL)
    {
        last = current;
        if (current->val < newNode->val)
        {
            current = current->right;
        } else
        {
            current = current->left;
        }
    }
    if (last == NULL)
    {
        root = newNode;
    } else if (last->val < newNode->val)
    {
        last->right = newNode;
    } else
    {
        last->left = newNode;
    }
    return root;
}

TreeNode* search(TreeNode* root, int val) {
    TreeNode* current = root;
    while (current != NULL && current->val != val)
    {
        if (current->val<val)
        {
            current = current->right;
        } else
        {
            current = current->left;
        }
    }
    return current;
}

TreeNode* delete(TreeNode* root, int val) {
    TreeNode* current = root;
    TreeNode* parent = NULL;

    while (current->val != val)
    {
        parent = current;
        if (current->val < val)
        {
            current = current->right;
        } else
        {
            current = current->left;
        }
    }
    // current has less than two children:
    if (current->right == NULL)
    {
        if (parent == NULL)
        {
            root = current->left;
        } else if (parent->left == current)
        {
            parent->left = current->left;
        } else
        {
            parent->right = current->left;
        }
    }else if (current->left == NULL)
    {
        if (parent == NULL)
        {
            root = current->left;
        } else if (parent->left == current)
        {
            parent->left = current->right;
        } else
        {
            parent->right = current->right;
        }
    }
    // current has two children:
    else
    {
        TreeNode* p = current->left;
        TreeNode* q = p;
        while (p->right != NULL)
        {
            q = p;
            p = p->right;
        }
        if (parent == NULL)
        {
            root = current->left;
        } else if (parent->left == current)
        {
            parent->left = p;
        } else
        {
            parent->right = p;
        }
        
        p->right = current->right;
        if (q != p)
        {
            q->right = p->left;
            p->left = current->left;
        } 
    }
    free(current);
    return root;
}

void printTree(TreeNode* root) {
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

// From Midterm 2 of 2021:
int toMaxRankTree(TreeNode* node, int rank) {
    if (node != NULL)
    {
        rank = toMaxRankTree(node->right, rank);
        node->val = rank;
        rank = toMaxRankTree(node->left, rank+1);
    }
    return rank;
}

// From Midterm 2 of 2020:
int smallest(TreeNode* n) {
    if(n->left != NULL) {
        return smallest(n->left);
    } else {
        return n->val;
    }
}

// From Midterm 2 of 2020:
int minAggregate(TreeNode* n, int sum) {
    if (n != NULL)
    {
        sum = minAggregate(n->left, sum);
        sum += n->val;
        n->val = sum;
        sum = minAggregate(n->right, sum);
    }
    return sum;
}

int main() {
    TreeNode* root = insert(NULL, 10);
    insert(root, 3);
    insert(root, 20);
    insert(root, 1);
    insert(root, 7);
    insert(root, 4);
    insert(root, 15);
    insert(root, 21);
    insert(root, 12);
    insert(root, 17);
    printTree(root);
    printf("-----------\n");
    toMaxRankTree(root, 0);
    printTree(root);
}

// To run: gcc BinarySearchTree.c -o bin/BinarySearchTree -g; ./bin/BinarySearchTree