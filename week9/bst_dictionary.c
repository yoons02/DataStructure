#include "bst_dictionary.h"

void main (){
    char    c, fname[20], w1[100], *w2;
    int     wcount;

    printf("************* Command ************\n");
    printf("R: Read data, S: Search data    \n");
    printf("P: Print inorder, Q: Quit         \n");
    printf("**********************************\n");

    while (1) {
        printf("\nCommand> ");
        c = getchar();
        putchar(c);
        c = toupper(c);

        switch (c) {
            case 'R' : 
                printf("\n Dictionary file name: ");
                scanf("%s", fname);
                getchar();
                wcount = build_dictionary(fname);
                printf(" Total number of words: %d \n", wcount); 
                break;
            case 'S' : 
                printf("\n Word: ");
                scanf("%s", w1);
                getchar();
                w2 = bst_search(w1);
                if (w2) printf (" Meaning: %s \n", w2);
                else printf(" No such word ! \n");
                break;
            case 'P' : 
                printf ("\n");
                bst_show_inorder(root); 
                break;
            case 'Q' : 
                printf("\n");
                exit(1);
            default  : break;
        }
    }
}
// 파일에서 단어들을 읽어 이진탐색트리 구성
int build_dictionary(char *fname)
{
    int     i=0;
    char    w1[100], w2[200];
    FILE    *ifp;

    if((ifp = fopen(fname, "r")) == NULL) {
        printf("No such file ! \n");
        exit(1);
    }

    while(fscanf(ifp, "%s %s", w1, w2) == 2) {
        ++i;
        bst_insert(w1, w2);
    }
    fclose(ifp);
    return(i);
}

// 트리에 (w1, w2) 자료 삽입
void bst_insert(char *w1, char *w2)
{
    tree_pointer p, c, temp;

    p = NULL;
    c = root;

    while (c != NULL) {
        if (strcmp(w1, c->w1) == 0) return;
        p = c;
        if (strcmp(w1, c->w1) < 0) c = c->left;
        else c = c->right;
    }

    temp = (tree_pointer) malloc (sizeof(tree_node));
    strcpy(temp->w1, w1);
    strcpy(temp->w2, w2);
    temp->left = temp->right = NULL;

    if (p != NULL) {
        if (strcmp(w1, p->w1) < 0) p->left = temp;
        else p->right = temp;
    }
    else
        root = temp;
}
// 트리에서 키값이 w1인 자료를 검색, w2를 반환
char * bst_search(char *w1)
{
    tree_pointer ptr = root;

    while(ptr != NULL) {
        if (strcmp(w1, ptr->w1) == 0) return (ptr->w2);   // word is found
        if (strcmp(w1, ptr->w1) < 0) ptr = ptr->left;
        else ptr = ptr->right;
    }
    return NULL;
}

// 트리의 단어들을 inorder로 출력 
void bst_show_inorder(tree_pointer ptr)
{
    if(ptr == NULL) return;

    bst_show_inorder(ptr->left);
    printf(" %s %s \n", ptr->w1, ptr->w2);
    bst_show_inorder(ptr->right);
} 

