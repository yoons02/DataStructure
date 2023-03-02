#include <stdio.h>

int main(){
    int score[10] = {65, 76, 67, 84, 34, 56, 80, 74, 38, 91};
    int max = 0;
    int min = 100; 
    int i;

    for (i = 0; i < 10; i++){
        if (score[i] > max){
            max = score[i];
        }
        else if (score[i] < min){
            min = score[i];
        }
    }
    printf("Winner score is %d\n", max);
    printf("Loser score is %d\n", min);
}