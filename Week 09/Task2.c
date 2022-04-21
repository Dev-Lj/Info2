#include <stdlib.h>
#include <stdio.h>

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

int main() {
    TreeNode* root = insert(NULL, 4);
    insert(root, 3);
    insert(root, 2);
    insert(root, 1);

    inorderTreeWalk(root);
}

// To run: gcc Task2.c -o bin/Task2 -g; ./bin/Task2