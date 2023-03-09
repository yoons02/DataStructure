#include <stdio.h>

int main(){
    int score[10] = {65, 76, 67, 84, 34, 91, 56, 80, 74, 38};
    int max = 0;
    int i, len;

    for (i = 0; i < 10; i++){
        if (score[i] > max){
            max = score[i];
            len = i;
        }
        printf("%d번째 점수 = %d\n", i, score[i]);
    }
    printf("Winner is %d, score is %d\n", len, max);
}