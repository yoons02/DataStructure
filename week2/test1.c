#include "ex2.h"
#define MAX_LENGTH 128

int main(void) {

    char c;
    printf("Reading record from %s\n",ifp); 
    read_record(ifp);
    printf("%d records have read.\n", num_record); 
    printf("********** 명령어 ********** \n"); printf("P: Print all records \n");
    printf("S : Search record \n");
    printf("C : Change record \n");
    printf("W : Write record \n");
    printf("Q : Save and quit \n"); printf("****************************** \n");

    while (1) {
        printf("Command> ");
        c = getchar();
        c = toupper(c); 
        printf("\n");
        switch (c) {
            case 'P':
                print_record();
                break; 
            case 'S':
                search_record();
                break;
            case 'C':
                change_record();
                break;
            case 'W':
                write_record(ifp);
                break;
        }
    }
    return 0; 
}

void read_record(char* ifp) {
    int i = 0; 
    ifp = fopen(ifp, "r");  
    while (fscanf(ifp, "%s %d %s", r[i].name, &r[i].id, r[i].grade) == 3)
        ++i;
    num_record = i;
    fclose(ifp);
}

void print_record(){
    int i = 0;   
    for (i = 0; i < num_record; i++){
        if (r[i].name != NULL){
            printf("%10s %10d %3s\n", (r+i)->name, (r+i)->id, (r+i)->grade);
        }
    }
}

void search_record(){
    char n1[10];
    printf("Input name : ");
    scanf("%s", n1);
    for (int i=0; i<MAX; i++) { 
        if(!strcmp(r[i].name, n1)){
            printf("%10s %10d %3s\n", (r+i)->name, (r+i)->id, (r+i)->grade);
        }
    }
}

void change_record(){
    char n1[10];
    char g1[4];

    printf("Input name : ");
    scanf("%s", n1);
    for (int i=0; i<MAX; i++) { 
        if(!strcmp(r[i].name, n1)){
            printf("%10s %10d %3s\n", (r+i)->name, (r+i)->id, (r+i)->grade);
            printf("Change grade : ");
            scanf("%s", g1);
            strcpy(r[i].grade, g1);
            printf("%10s %10d %3s\n", (r+i)->name, (r+i)->id, (r+i)->grade);
        }
    }
}

void write_record(char* ifp){
    int i;
    char name[10], grade[5]; 
    FILE *ofp;
    ifp = fopen(ifp, "r"); 
    ofp = fopen("out.txt", "w+");
    while(fscanf(ifp, "%10s %10d %3s", r[i].name, &r[i].id, r[i].grade) == 3) 
        fprintf(ofp, "%10s % 10d %3s\n", (r+i)->name, (r+i)->id, (r+i)->grade);
        i++;
    fclose(ifp); 
    fclose(ofp);
}