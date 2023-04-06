#include "arrayqueue.h"
int main() {
    char c, e;
    printf("****************command*******************\n");
    printf("+<c> : AddQ c , - : DeleteQ, \n S : show , Q : Quit\n");
    printf("******************************************\n");
    while (1) {
        printf("\nCommand> ");
        c = getchar();
        getchar();
        c = toupper(c);
        switch (c) {
            case '+':
                e = getchar();
                getchar();
                addq(e);
                break;
            case '-':
                e = deleteq();
                if (is_empty != true)
                printf("\n %c ", e);
                is_empty = false;
                break;
            case 'S':
                queue_show();
                break;
            case 'Q': printf("\n");
                exit(1);
            default: break;
        }
    }
}

// void addq(Element e){
//     if (front == (rear+1)%MAX_SIZE) { 
//         printf("Queue is Full\n");
//         return; 
//     }
//     else{
//         rear = (rear+1) % MAX_SIZE; 
//         queue[rear] = e;
//     }
// }

void addq(Element e)
{
   if (front == (rear + 1) % MAX_SIZE) {
      printf("queue is full!!");
      return;
   }
   rear = (rear + 1) % MAX_SIZE;
   queue[rear%MAX_SIZE] = e;
}

// Element deleteq(){
//     if (front == rear) { 
//         printf("Queue is Empty\n");
//     }
//     else{
//         front = (front+1) % MAX_SIZE; 
//         return queue[front];
//     }

// }

void queue_show(){
    if(rear > front){
        int count = rear - front;
        for (int i = 0; i < count; i++){
            if (count == MAX_SIZE+1){
                break;
            }
            printf("%c ", queue[(front+i+1)%MAX_SIZE]);
        }
    }
    else{
        int count = MAX_SIZE - (rear + front);
        for (int i = 0; i < count; i++){
            if (count == MAX_SIZE+1){
                break;
            }
            printf("%c ", queue[(front+i+1)%MAX_SIZE]);
        }
    }
}

Element deleteq()
{
   if (front == rear) {
      printf("queue is empty!!!");
   }
   front = (front + 1)%MAX_SIZE;
   return queue[front];

}
// void queue_show()
// {
//    printf("\n");
//    for (int i=0; i<=rear; i++) {
//       printf("%c ", queue[i]);
//    }
// }