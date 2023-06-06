#include "spanning_tree.h"

// 그래프 초기화
void initGraph(Graph* graph, int num_vertices) {
    graph->num_vertices = num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
}

// 간선 추가
void addEdge(Graph* graph, int src, int dest) {
    graph->adj_matrix[src - 1][dest - 1] = 1;
    graph->adj_matrix[dest - 1][src - 1] = 1;
}

// 너비우선 탐색(BFS)
void BFS(Graph* graph, int start_vertex, int* visited, FILE* file) {
    visited[start_vertex - 1] = 1;

    // 큐 초기화
    int queue[MAX_VERTEX];
    int front = -1;
    int rear = -1;
    queue[++rear] = start_vertex;

    while (front != rear) {
        int current_vertex = queue[++front];
        for (int i = 0; i < graph->num_vertices; i++) {
            if (graph->adj_matrix[current_vertex - 1][i] && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i + 1;
                fprintf(file, "%d %d\n", current_vertex, i + 1);
            }
        }
    }
}

int main() {
    FILE* input_file = fopen("edges.txt", "r");
    FILE* output_file = fopen("tree.txt", "w");
    Graph graph;
    initGraph(&graph, MAX_VERTEX);
    int src, dest;

    // edges.txt로부터 그래프 읽어들이기
    while (fscanf(input_file, "%d %d", &src, &dest) == 2) {
        addEdge(&graph, src, dest);
    }

    // 너비우선 탐색(BFS) 수행하여 spanning tree 생성 및 기록
    int visited[MAX_VERTEX] = {0};
    BFS(&graph, 1, visited, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}
