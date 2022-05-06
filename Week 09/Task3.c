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

int to_ordered_array(TreeNode* node, int* arr, int pos) {
    if (node != NULL)
    {
        pos = to_ordered_array(node->left, arr, pos);
        arr[pos++] = node->val;
        pos = to_ordered_array(node->right, arr, pos);
    }
    return pos;
}

TreeNode* balance_tree(TreeNode* root, int* arr, int l, int r) {
    if (l < r)
    {
        int m = (l+r)/2;
        root = insert(root, arr[m]);
        balance_tree(root, arr, l, m);
        balance_tree(root, arr, m+1, r);
    }
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
    TreeNode* root = insert(NULL, 40);
    insert(root, 20);
    insert(root, 50);
    insert(root,11);
    insert(root, 22);
    insert(root, 26);
    insert(root, 23);

    int arr[7];
    to_ordered_array(root, arr, 0);
    // root should be freed
    TreeNode* newroot = balance_tree(NULL, arr, 0, 7);
    printTree(newroot);
    return 0;
}

// To run: gcc Task3.c -o bin/Task3 -g; ./bin/Task3