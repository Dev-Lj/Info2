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

void print_arr(char* desc, int* arr, int n) {
    printf("%s: ", desc);
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

// Print all BiQuad subgraphs of G
// From Final Exam 2021
void printBiQuadSubgraphs(int n, int graph[n][n]) {
    int dist[n];
    int pred[n];
    int col[n];
    
    node_t* Q = NULL;
    enqueue(&Q, 0);
    col[0] = 1;
    for (int i = 0; i < n; i++)
    {
        enqueue(&Q, i);
        for (int x = 0; x < n; x++)
        {
            dist[x] = 0;
            pred[x] = -1;
            col[x] = 0;
        }
        col[i] = 1;
        while(!isEmpty(&Q))
        {
            int v = dequeue(&Q);
            for (int j = 0; j < n; j++)
            {
                if (graph[v][j] == 1)
                {
                    if (col[j] == 0)
                    {
                        col[j] = 1;
                        dist[j] = dist[v] + 1;
                        pred[j] = v;
                        enqueue(&Q, j);
                    } else if(col[j] == 1 && dist[j] + dist[v] == 3) {
                        // BiQuad tree
                        // TODO: check for uniqueness
                        int my_pred = pred[v];
                        int nei_pred = pred[j];
                        printf("Biquad Tree: %d, %d, %d, %d\n", v, j, pred[v], pred[j]);
                        
                    }
                }
            }
            col[v] = 2;
        }
    }
}

int main() {
    int n = 5;
    int graph[5][5] ={
        {0,1,1,1,0},
        {1,0,0,0,1},
        {1,0,0,0,1},
        {1,0,0,0,1},
        {0,1,1,1,0}, 
    };
    printBiQuadSubgraphs(n, graph);

    return 0;
}

// To run: gcc Graph.c -o bin/Graph -g; ./bin/Graph