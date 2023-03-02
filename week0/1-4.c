#include <stdio.h>

int find_max(int *p, int size);
int find_min(int *p, int size);

int main(){
    int score[10] = {65, 76, 67, 84, 34, 56, 80, 74, 38, 91};
    int max = find_max(score, 10);
    int min = find_min(score, 10);

    printf("Max num is %d\nMin num is %d\n", max, min);
}

int find_max(int *p, int size){
    int M = 0;
    for (int i = 0; i < size; i++){
        if (*(p+i) > M){
            M = *(p+i);
        }
    }
    return M;
}

int find_min(int *p, int size){
    int m = 100;
    for (int i = 0; i < size; i++){
        if (*(p+i) < m){
            m = *(p+i);
        }
    }
    return m;
}