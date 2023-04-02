#include "arraystack.h" 
int main() {
    char c, e;
    printf("******************** Command *******************\n"); 
    printf("+<c>: push c, - : pop, \n");
    printf("S: Show, Q: Quit \n"); 
    printf("************************************************\n"); 
    while (1) {
        printf("\nCommand> "); 
        c = getchar();
        getchar();
        c = toupper(c);
        printf("\n");
        switch (c) {
            case '+': 
                printf("char : ");
                e = getchar(); 
                getchar();
                push(e);
                break; 
            case '-':
                e = pop();
                if (e != '\0')
                    printf("\n %c \n", e);
                break;
            case 'S':
                stack_show();
                break; 
            case 'Q': 
                printf("\n");
                exit(1); 
            default: 
                break;
        } 
    }
}

void push(int e){
    if (top >= MAX_SIZE-1) { 
        printf("Stack is Full\n");
    }
    else{
        stack[++top] = e;
    }
}

Element pop(){
    if (top == -1) { 
        printf("Stack is Empty\n"); 
    }
    else{
        return stack[top--];
    }
}

void stack_show(){
    for (int i = 0; i < top+1; i++){
        printf("%c ", stack[i]);
    }
}