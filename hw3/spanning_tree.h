#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 8

// 그래프 구조체 정의
typedef struct Graph {
    int num_vertices;
    int adj_matrix[MAX_VERTEX][MAX_VERTEX];
} Graph;
