#include <stdio.h>

int main(){
    int a = 10;
    int b[5] = {10, 20, 30, 40, 50};
    int *p;
    int *p1;

    p = &a;
    p1 = b;

    printf("Integer and Pointer\n");
    printf("a = %d, address of a = %p\n", a, &a);
    printf("*p = %d, p = %p\n",*p, p);

    printf("\nArray and Pointer\n");
    printf("b = %p\n", b);
    printf("b[0] = %d, b[1] = %d, b[2] = %d\n",b[0], b[1], b[2]);
    printf("p1 = %p\n", p1);
    printf("*p1 = %d, *(p1+1) = %d, *(p1+2) = %d\n", *p1, *(p1+1), *(p1+2));
}