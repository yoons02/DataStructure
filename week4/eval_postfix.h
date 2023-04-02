#include <stdio.h>
#pragma warning(disable : 4996)
#define MAX_SIZE 100
#define boolean unsigned char
#define true 1
#define false 0
// Global stack
int stack[MAX_SIZE];
int top = -1;
int i, len;
char token, op, op1, op2;

boolean is_number(char c);
boolean is_op(char c);

boolean err_check = false;
void push(int e);

int pop();

int eval_postfix(char* exp);

boolean is_number(char c);

boolean is_op(char c);