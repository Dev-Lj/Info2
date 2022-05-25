#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

void enqueue(node_t **head, int val) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    if (!new_node) return;

    new_node->val = val;
    new_node->next = *head;

    *head = new_node;
}


bool isEmpty(node_t **head) {
	return (*head == NULL);
}

int dequeue(node_t **head) {
    node_t *current, *prev = NULL;
    int retval = -1;

    if (*head == NULL) return -1;

    current = *head;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    retval = current->val;
    free(current);
    
    if (prev)
        prev->next = NULL;
    else
        *head = NULL;

    return retval;
}

void dfs_rec(int adj[6][6], int c, int n, bool* visited){
    visited[c] = true;
    for (int i = 0; i < n; i++)
    {
        if (adj[c][i] > 0 && !visited[i])
        {
            dfs_rec(adj, i, n, visited);
        }
    }
}

bool is_root_dfs(int adj[6][6], int start, int n) {
    bool visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    dfs_rec(adj, start, n, visited);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return false;
        }
        
    }
    return true;
}

void dfs(int adj[6][6], int n) {
    printf("DFS roots: ");
    for (int i = 4; i < n; i++)
    {
        bool is_root = is_root_dfs(adj, i, n);
        if (is_root)
        {
            printf("%d, ", i);
        }
    }
    printf("\n");
}

bool is_root_bfs(int adj[6][6], int start, int n) {
    node_t* h = NULL;
    bool visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    
    enqueue(&h, start);
    while (!isEmpty(&h))
    {
        int v = dequeue(&h);
        visited[v] = true;
        for (int i = 0; i < n; i++)
        {
            if (adj[v][i]>0 && !visited[i])
            {
                visited[i] = true;
                enqueue(&h, i);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

// search root vertices and print them using BFS
void bfs(int adj[6][6], int n) {
    printf("BFS roots: ");
    for (int i = 4; i < n; i++)
    {
        bool is_root = is_root_bfs(adj, i, n);
        if (is_root)
        {
            printf("%d, ", i);
        }
    }
    printf("\n");
}

int main() {
	int adj[6][6] = {
		{0,1,0,0,0,0},	
		{0,0,1,0,0,0},
		{0,0,0,1,0,0},
		{1,0,0,0,0,0},
		{0,0,0,1,0,1},
		{1,0,0,0,0,0}
	};
    int n = 6;
    bfs(adj, n);
    dfs(adj, n);
}

// To run: gcc Task3.c -o bin/Task3 -g; ./bin/Task3
