#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right; 
}TreeNode;

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

TreeNode* find_range(TreeNode* node, int low, int high) {
    
}

int main() {
    TreeNode* root = insert(NULL, 12);
    insert(root, 35);
    insert(root, 45);
    insert(root, 50);
    insert(root, 17);
    insert(root, 9);
    insert(root, 29);
    insert(root, 28);

    printTree(root);
}

// To run: gcc Task4.c -o bin/Task4 -g; ./bin/Task4