#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

// typedef struct 
// {
//     char name[10];
//     int std_num;
//     char grade;
// }Student;

int main(){
    // Student student[30];
    int count = 0;
    FILE *ifp, *ofp;

    ifp = fopen("grade.txt", "r"); 
    ofp = fopen("out.txt", "w+");

    if (ifp==NULL){
        printf("ERROR : no such file or directory");
    }
    else{
        fputs("Hello", ofp);
    }

    fclose(ifp);
    fclose(ofp);
}
