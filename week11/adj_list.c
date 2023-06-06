#include "adj_list.h"

void main()
{
	char	c;
	int	i, v;

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
// sv : start vertex , nv : next vertex
void insert_edge(int sv, int nv) {
	node_pointer new = (node_pointer)malloc(sizeof(node));
	new->vertex = nv;
	new->link = adj[sv];
	adj[sv] = new;
}

void dfs(int v) {
	node_pointer tmp;

	printf(" %d", v);
	visited[v] = true;

	// v의 모든 인접 vertex에서 dfs를 수행 
	for (tmp = adj[v]; tmp; tmp = tmp->link) {
		if (!visited[tmp->vertex]) dfs(tmp->vertex);
	}
}

// queue 이용
void bfs(int v) {
	node_pointer tmp;
	int v_tmp;
	addq(v);
	visited[v] = true;
	printf(" %d", v);
	while (!is_queue_empty()) {
		v_tmp = deleteq();
		for (tmp = adj[v_tmp]; tmp; tmp = tmp->link) {
			if (!visited[tmp->vertex]) {
				addq(tmp->vertex);
				visited[tmp->vertex] = true;
				printf(" %d", tmp->vertex);
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
