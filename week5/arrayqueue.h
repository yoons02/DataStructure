#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define boolean int
#define true 1
#define false 0
typedef char Element;
// Global queue
Element queue[MAX_SIZE];
int front = 0;
int rear = 0;
boolean is_empty = false;
void addq(Element e);
Element deleteq();
void queue_show();