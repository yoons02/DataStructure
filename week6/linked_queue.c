#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "linked_queue.h"

void main()
{
	char c, e;

	front = rear = NULL;

	printf("\n****************Command********************\n");
	printf("+<c> : AddQ c, -: DeleteQ, \nS:Show, Q : Quit\n");
	printf("*******************************************\n");


	while (1) {
		printf("\nCommand> ");
		c = getchar();
		putchar(c);
		c = toupper(c);
		switch (c) {

		case '+':
			e = getchar(); 
            putchar(e);
			addq(e);
			break;
		case '-':
			if (is_queue_empty()) {
				printf("\n Queue is empty !!! \n");
			}
			else {
				e = deleteq();
				printf("\n %c ", e);
			}
			break;
		case 'S': queue_show(); break;
		case 'Q': printf("\n"); exit(1);
		default: break;
		}
        getchar();
	}
}


void addq(Element e) {
	queue_pointer add = (queue_pointer)malloc(sizeof(queue));
	add->item = e;
	add->link = NULL;

	if (is_queue_empty()) {
		front = rear = add;
	}
	else {
		rear->link = add;
		rear = add;
	}
}

Element deleteq() {
	Element c;
	queue_pointer tmp;

	c = front->item;
	tmp =  front;
	front = front->link;
	free(tmp);
	return c;
	
}

void queue_show() {
	queue_pointer tmp = front;

	printf("\n");
	while (tmp != NULL) {
		printf("%3c", tmp->item);
		tmp = tmp->link;
	}

}

boolean is_queue_empty()
{
	if (front == NULL)
		return true;
	else
		return false;
}
