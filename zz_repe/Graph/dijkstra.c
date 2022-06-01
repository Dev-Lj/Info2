#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INT_MAX 1000000

typedef struct vertice {
    int dist;
    int key;
    vertice* pred;
}vertice;

struct MinPQ {
    int n;
    int pos;
    vertice* heap;
};

void exchange(vertice *A, int idx_1, int idx_2) {
    vertice t = A[idx_1];
    A[idx_1] = A[idx_2];
    A[idx_2] = t;
}

void heapify(vertice *A, int i, int length) {
    int current = i;

    int left_child_idx = 2*i + 1;
    int right_child_idx = 2*i + 2;
    if (left_child_idx <= length && A[left_child_idx].dist < A[current].dist) {
        current = left_child_idx;
    }
    if (right_child_idx <= length && A[right_child_idx].dist < A[current].dist) {
        current = right_child_idx;
    }
    if (i != current) {
        // exchange A[i] and A[current]
        exchange(A, i, current);
        heapify(A, current, length);
    }
}

void buildHeap(vertice *A, int length) {
    for (int i = length/2; i >= 0; i--)
    {
        heapify(A, i, length);
    }
}

struct MinPQ initMinPQ(vertice v[], int n) {
    struct MinPQ pq;
    buildHeap(v, n);
    pq.heap = v;
    pq.n = n;
    return pq;
}

bool isPQEmpty(struct MinPQ pq) {
    return pq.n == pq.pos;
}

vertice extractMin(struct MinPQ* pq) {
    vertice min;
    if (!isPQEmpty(*pq))
    {
        min = pq->heap[pq->pos];
        pq->pos++;
    }
    return min;
}

void dijkstra(int n, int graph[n][n], int start) {
    vertice vertices[n];
    for (int i = 0; i < n; i++)
    {
        vertices[i].dist = INT_MAX;
        vertices[i].pred = NULL;
        vertices[i].key = i;
    }
    vertices[start].dist = 0;
    struct MinPQ pq = initMinPQ(vertices, n);
    while (!isPQEmpty(pq))
    {
        vertice v = extractMin(&pq);
        // get adjacent nodes
        // foreach adj node:
        // relax
        // decreaseKey
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