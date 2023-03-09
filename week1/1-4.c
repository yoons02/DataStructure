#include <stdio.h>

int find_max(int *p, int size);

int main(){
    int score[10] = {65, 76, 67, 91, 84, 34, 56, 80, 74, 38};
    int max = find_max(score, 10);

    return 0;
}

int find_max(int *p, int size){
    int M = 0;
    int max_len = 0;
    for (int i = 0; i < size; i++){
        if (*(p+i) > M){
            M = *(p+i);
            max_len = i;
        }
    }
    printf("Max %d, location %d\n", M, max_len);
}
