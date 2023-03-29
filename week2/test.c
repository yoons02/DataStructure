#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 128

typedef struct
{
    char name[10];
    int std_num;
    char grade;
}Student;

void print_record();
void S();
void C();
void W();

int main(void){
    int i = 0;
    char cmd;
    // char buffer[MAX_LENGTH];
    // FILE *ifp, *ofp;
    // ifp = fopen("grade.txt", "r"); 
    // ofp = fopen("out.txt", "w+");

    printf("------------Command zip------------\n");
    printf("P : Print all Records\n");
    printf("S : Search Record\n");
    printf("C : Change Record\n");
    printf("W : Write Record\n");
    printf("S : Save and quit\n");
    printf("-----------------------------------\n\n");

    printf("Command : ");
    scanf("%c", cmd);
    cmd = toupper(cmd);

    // fclose(ofp);
    switch (cmd)
    {
    case 'P':
        print_record();
        break;
    
    default:
        break;
    }
}

void print_record(){
    int i = 0;
    char buffer[MAX_LENGTH];
    FILE *ifp;
    ifp = fopen("grade.txt", "r"); 

    Student* a = (Student*)malloc(sizeof(Student));
    while (fgets(buffer, MAX_LENGTH, ifp)){
        fscanf(ifp, "%s %d %c", &(a+i)->name, &(a+i)->std_num, &(a+i)->grade);
        printf("%10s %10d %3c\n", (a+i)->name, (a+i)->std_num, (a+i)->grade);
        i++;
    }

    fclose(ifp);
}