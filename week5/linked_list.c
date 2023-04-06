#include "linked_list.h"
void main()
{
    char c, e;
    list_pointer head, p;
    // dummy head 노드
    head = (list_pointer)malloc(sizeof(list_node));
    head->data = '\0';
    head->link = '\0';
    printf("******************command*******************\n");
    printf("+<c> : Insert c , -<c> : Delete c, \n ?<c> : Search c, S : show , Q : Quit\n");
    printf("********************************************\n");
    while (1) {
        printf("\nCommand> ");
        c = getchar();
        getchar();
        c = toupper(c);
        switch (c) {
            case '+':
                e = getchar();
                getchar();
                list_insert(head, e);
                break;
            case '-':
                e = getchar();
                getchar();
                list_delete(head, e);
                break;
            case '?':
                e = getchar();
                getchar();
                p = list_search(head, e);
                if (p) {
                    printf(" Node address = %p, data = %c, link = %p \n",
                    p, p->data, p->link);
                }
                else printf("\n %c is not in the list \n", e);
                break;
            case 'S':
                list_show(head); break;
            case 'Q':
                printf("\n");
                exit(1);
            default: break;
        }
    }
}

void list_insert(list_pointer head, Element e){
    list_pointer next;
    next = (list_pointer)malloc(sizeof(list_node)); 

    next -> data = e;
    next -> link = head -> link;
    head -> link = next;
}

void list_delete(list_pointer head, Element e){
    list_pointer p = head;
    while(p){
        if (p -> data == e){
            p -> data = p -> link -> link;
        }
        p = p -> link;
    }
}

list_pointer list_search(list_pointer head, Element e){
    list_pointer p = head;
    while(p){
        if (p -> data == e){
            return p;
        }
        p = p -> link;
    }
    return NULL;
}

bool list_empty(list_pointer head){
    if (head == '\0'){
        return true;
    }
    else{
        return false;
    }
}

void list_show(list_pointer head){
    list_pointer p = head;
    while(p != '\0'){
        printf("%c", p->data);
        p = p -> link;
    }
}