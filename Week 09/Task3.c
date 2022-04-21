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
    return newNode;
}

TreeNode* insert_node(TreeNode* node, TreeNode* insertNode) {
    if (insertNode->val < node->val)
    {
        node->left = insertNode;
    } else
    {
        node->right = insertNode;
    }
    return node;
}

void rt_right(TreeNode* node) {
    
}

void rt_left(TreeNode* node) {

}

int inorderTreeWalk(TreeNode* node, int height) {
    if (node == NULL)
    {
        return 0;
    }
    int left = inorderTreeWalk(node->left, height);
    int right = inorderTreeWalk(node->right, height);
    printf("%d, balance: %d\n", node->val, left - right);
    return height + 1;
}

void balanceTree(TreeNode* node, int balance) {
    if (node != NULL)
    {
        balanceTree(node->left, balance-1);
        if (balance == 2)
        {
            rt_left(node);
            balance = 0;
        } else if(balance == -2) {
            rt_right(node);
            balance = 0;
        }
        balanceTree(node->right, balance+1);
    }
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
    TreeNode* root = insert(NULL, 20);
    insert(root, 11);
    insert(root, 22);
    TreeNode* current = insert(root, 23);
    insert_node(current, insert(NULL, 14));
    root = insert_node(insert(NULL, 40), root);
    insert(root, 50);
    insert(root, 45);
    insert(root, 51);

    inorderTreeWalk(root, 0);
}

// To run: gcc Task3.c -o bin/Task3 -g; ./bin/Task3