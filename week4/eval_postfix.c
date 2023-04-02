#include "eval_postfix.h"
int main(){
    char exp[100];
    int result;

    while (1) {
        printf("\n Input postfix expression: "); 
        scanf("%s", exp);
        getchar();
        result = eval_postfix(exp); 
        if (err_check == false)
            printf(" Result = %d \n\n", result);
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

int pop(){
    if (top == -1) { 
        printf("Stack is Empty\n"); 
    }
    else{
        return stack[top--];
    }
}

int eval_postfix(char* exp){
    i = 0;
    token = exp[0];
    while (token != '\0') {
        // 피연산자가 나오면 스택에 push
        if (is_number(token)) {
            op = token-'0';
            push(op);
        }
        // 연산자가 나오면 두 피연산자를 pop, 연산을 수행, 결과를 push
        else {
            op2 = pop(); op1 = pop();
            switch(token) {
                case '+': push(op1+op2); break;
                case '-': push(op1-op2); break;
                case '*': push(op1*op2); break;
                case '/': 
                    if(op2 == '\0'){ 
                        printf("ERROR : Devided by 0\n");
                        err_check = true;
                        break;
                    }
                    else if (op1 == '\0')
                    {
                        push(0); 
                    }
                    else{
                        push((int)(op1/op2)); 
                        break;
                    }
            }
        }
        token = exp[i++];
    }
    // 결과를 반환
    return pop();
}

boolean is_number(char c){
    if (('0' > c) && (c <= '9')){
        return false;
    }
    else
        return true;
}

boolean is_op(char c){
    if ((c == '+')||(c == '-')||(c == '*')||(c == '/')){
        return true;
    }
    else
        return false;
}