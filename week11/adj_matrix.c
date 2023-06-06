#include "adj_matrix.h"

void main()
{
	char	c;
	int		i, v;

	front = rear = NULL;
	build_simple_graph();

	printf("********* Command ********\n");
	printf("D: DFS, B: BFS, Q: Quit \n");
	printf("**************************\n");

	while (1) {
		printf("\nCommand> ");
		c = getchar();
		getchar();
		c = toupper(c);
		switch (c) {
		case 'D':
			printf("\n Start vertex: ");
			scanf("%d", &v);
            getchar();
			for (i = 0; i < MAX_VERTICES; i++) visited[i] = false;
			dfs(v);
			printf("\n");
			break;
		case 'B':
			printf("\n Start vertex: ");
			scanf("%d", &v);
            getchar();
			for (i = 0; i < MAX_VERTICES; i++) visited[i] = false;
			bfs(v);
			printf("\n");
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default: break;
		}
	}
}

void build_simple_graph() {
	insert_edge(1, 2);
	insert_edge(1, 3);
	insert_edge(1, 4);
	insert_edge(2, 1);
	insert_edge(2, 5);
	insert_edge(3, 1);
	insert_edge(3, 5);
	insert_edge(4, 1);
	insert_edge(4, 5);
	insert_edge(5, 2);
	insert_edge(5, 3);
	insert_edge(5, 4);

	printf("\n Graph is built. V = 5, E = 6. \n\n");
}
void insert_edge(int sv, int nv) {
	adj[sv][nv] = 1;
}
void dfs(int v) {
	printf(" %d ", v);
	visited[v] = true;

	// v의 모든 인접 vertex에서 dfs를 수행 
	for (int vertex = 0; vertex < MAX_VERTICES; vertex++) {
		if (adj[v][vertex]==1 && !visited[vertex]) dfs(vertex);
	}
}
void bfs(int v) {
	int v_tmp;
	addq(v);
	visited[v] = true;
	printf(" %d ", v);
	while (!is_queue_empty()) {
		v_tmp = deleteq();
		for (int vertex = 0; vertex < MAX_VERTICES; vertex++) {
			if (adj[v_tmp][vertex] == 1 && !visited[vertex]) {
				addq(vertex);
				visited[vertex] = true;
				printf(" %d ", vertex);
			}
		}
	}
}

void addq(Element e) {
	queue_pointer new = (queue_pointer)malloc(sizeof(queue));
	new->item = e;
	new->link = NULL;

	if (is_queue_empty())
		front = rear = new;
	else {
		rear->link = new;
		rear = new;
	}
}
Element deleteq() {
	if (is_queue_empty()) {
		printf("queue is empty \n");
		return 0;
	}
	queue_pointer tmp = front;
	Element item = front->item;
	front = front->link;
	free(tmp);
	return item;
}
boolean is_queue_empty() {
	if (front == NULL) return true;
	else return false;
}
