#include "arrayList.h"

int main(void)
{
    char c;
    printf("******************** Command *******************\n"); 
    printf("+<c>: Insert c, -<c>: Delete c, \n");
    printf("E: ListEmpty, F: ListFull, S: ListShow, Q: Quit \n"); 
    printf("************************************************\n"); 
    while (1) {
        printf("\nCommand> "); 
        c = getchar();
        c = toupper(c); 
        printf("\n");
        switch (c) {
            case '+': 
                c = getchar(); 
                list_insert(c);
                break; 
            case '-':
                c = getchar(); 
                list_delete(c);
                break;
            case 'E': 
                if (list_empty()) printf("\nTRUE \n");
                else printf("\nFALSE \n");
                break;
            case 'F': 
                if (list_full()) printf("\nTRUE \n");
                else printf("\nFALSE \n"); 
                break;
            case 'S': 
                list_show();
                break; 
            case 'Q': 
                printf("\n");
                exit(1);
            default:
                break; 
        }
    } 
}

void list_insert(Element e){
    if (size < MaxSize){
        printf("Enter the char : ");
        scanf("%c", &e);
        getchar();
        List[size] = e;
        size++;
    }
    else {
        printf("ERROR : List is Full.");
    }
}
void list_delete(Element e){
    int ans;

    printf("Enter the char : ");
    scanf("%c", &e);
    getchar();
    
    for (int i = 0; i < size; i++){
        if (List[i] == e){
            ans = 1;
        }
    }

    if (ans == 1){
        for (int i = 0; i < size; i++){
            if (List[i] == e){
                List[i] = '\0';
            }
            List[i] = List[i+1];
        }
        size--;
    }
    else {
            printf("ERROR : Data does not exist.");
    }
}

void list_show(){
    for (int i = 0; i < size; i++){
        printf("%c", List[i]);
    }
}

boolean list_empty()
{
    int count = 0;
    for (int i = 0; i < MaxSize; i++){
        if(List[i] == '\0'){
            count++;
        }
    }
    if (count == MaxSize){
        return true;
    }
    else{
        return false;
    }
}

boolean list_full()
{
    if(size < 4){
        return false;
    }
    else{
        return false;
    }
}

