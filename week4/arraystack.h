#include <stdio.h> 
// #include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 10
#define boolean unsigned char 
#define true 1
#define false 0

typedef char Element;
// Global stack
Element stack[MAX_SIZE]; 
int top = -1;

void push(int e);

Element pop();

void stack_show();