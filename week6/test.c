#include <stdio.h>
#include <stdlib.h>
double random()
{
	return rand()/(double)RAND_MAX;
}

int main(){
    for (int i = 0; i < 5; i++){
        printf("%.10f\n", random());
    }
}
