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

int count = 0;

void push(Element e){
    if(count < 9){
        stack[count] = e;
        count++;
        printf("%c", count);
    }
    else{
        printf("Stack is Full\n");
    }
}

Element pop(){
    if(count > 0){
        printf("%c", stack[count-1]);
        stack[count-1] = '\0';
        count--;
    }
    else{
        printf("Stack is Empty\n");
    }
}

void stack_show(){
    if (count >= 0){
        for (int i = 0; i < count; i++){
            printf("%c ", stack[i]);
        }
    }
    else{
        printf("Stack is Empty\n");
    }
}