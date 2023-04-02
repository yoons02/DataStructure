#include <stdio.h>

#define r 3
#define c 5

void row_sum(int test[r][c], int rsum[r]);
void col_sum(int test[r][c], int csum[c]);
void reduce(int test[r][c], int reduced[r*c]);

int main()
{
    int i, j;
    int rsum[r], csum[c], reduced[r*c];
    int test[3][5] = { {1, 2, 3, 4, 5},
                    {6, 7, 8, 9, 10},
                    {11, 12, 13, 14, 15} };

    row_sum(test, rsum);
    col_sum(test, csum);
    reduce(test, reduced);
}

void row_sum(int test[r][c], int rsum[r]){
    int a, b, d, e;
    for (a = 0; a < r; a++){
        rsum[a] = 0;
    }

    for (a = 0; a < r; a++){
        for (b = 0; b < c; b++){
            rsum[a] += test[a][b];
        }
    }
    
    for (e = 0; e < r; e++){
        printf("%d ", rsum[e]);
    }
    printf("\n");
}

void col_sum(int test[r][c], int csum[c]){
    int a, b, d, e;
    for (a = 0; a < c; a++){
        csum[a] = 0;
    }

    for (a = 0; a < c; a++){
        for (b = 0; b < r; b++){
            csum[a] += test[b][a];
        }
    }
    
    for (e = 0; e < c; e++){
        printf("%d ", csum[e]);
    }
    printf("\n");
}

void reduce(int test[r][c], int reduced[r*c]){
    int a, b, d;
    for (a = 0; a < r*c; a++){
        reduced[a] = 0;
    }

    for (a = 0; a < r; a++){
        for (b = 0; b < c; b++){
            reduced[a*c+b] = test[a][b];
        }
    }

    for (a = 0; a < r*c; a++){
        printf("%d ", reduced[a]);
    }
    printf("\n");
}