#include "max_heap.h"
void main() {
    char c, data;
    int key;
    Element item;

    printf("************* Command ************ \n");
    printf("I: Insert data, D: Delete max data \n");
    printf("P: Print heap, Q: Quit \n");
    printf("********************************** \n");

    while (1) {
        printf("\nCommand> ");
        c = getchar();
        getchar();
        c = toupper(c);
        switch (c) {
            case 'I':
                printf("\n key and data: ");
                scanf("%d %c", &key, &data);
                getchar();
                getchar();
                item.key = key;
                item.data = data;
                insert_max_heap(item);
                break;
            case 'D':
                if (is_heap_empty())
                printf("\nHeap is empty\n");
                else {
                item = delete_max_heap();
                printf("\n Max: key %d, data %c \n", item.key,
                item.data);
                }
                break;
            case 'P':
                printf("\n");
                max_heap_show();
                break;
            case 'Q':
                printf("\n");
                exit(1);
            default: break;
        }
    }
}

// 히프에 item(key, data) 삽입
void insert_max_heap(Element item) {
	int i = heap_size;
	while (i != 0 && (item.key > heap[(i+1)/ 2-1].key)) {
		heap[i] = heap[(i + 1) / 2 - 1];
		i = (i + 1) / 2 - 1;
	}
	heap[i] = item;
	heap_size++;
}


// 히프에서 max item (루트) 삭제 및 반환
Element delete_max_heap() {
	Element output = heap[0];
	int parent = 0;
	int child = (parent + 1) * 2 - 1;
	Element tmp = heap[--heap_size];

	while (child<=heap_size) {
		
		if((child<heap_size)&&(heap[child].key<heap[child+1].key)) child++;
		if (tmp.key >= heap[child].key) break;
		heap[parent] = heap[child];
		parent = child;
		child = (parent + 1) * 2 - 1;
	}
	heap[parent] = tmp;
	return output;

}
// 히프의 자료들을 차례로 출력 
void max_heap_show() {
	for(int i=0; i<heap_size; i++)
		printf("%3d%3c\n", heap[i].key, heap[i].data);
}
boolean is_heap_empty() {
	if (heap_size == 0) return true;
	else return false;
}
