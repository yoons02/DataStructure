#include "bst.h"
void main()
{
    char c, grade;
    int id;
    printf("************* Command ************\n");
    printf("I: Insert data, S: Search data \n");
    printf("P: Print inorder, Q: Quit \n");
    printf("**********************************\n");
    while (1) {
        printf("\nCommand> ");
        c = getchar();
        getchar();
        c = toupper(c);
        switch (c) {
        case 'I':
            printf("\n id and grade: ");
            scanf("%d %c", &id, &grade);
            getchar();
            bst_insert(id, grade);
            break;
        case 'S':
            printf("\n id: ");
            scanf("%d", &id);
            grade = bst_search(id);
            if (grade) printf(" Grade of %d: %c \n", id, grade);
            else printf(" No such id ! \n");
            break;
        case 'P':
            printf("\n");
            bst_show_inorder(root);
            break;
        case 'Q':
            printf("\n");
            exit(1);
            default: break;
        }
    }
}

void bst_insert(int key, char data)
{
    tree_pointer p, c, temp;

    p = NULL;
    c = root;

    while (c != NULL) {
        if (key == c->key) return;
        p = c;
        if (key < c->key) c = c->left;
        else c = c->right;
    }

    temp = (tree_pointer)malloc(sizeof(tree_node));
    temp->key = key;
    temp->data = data;
    temp->left = temp->right = NULL;

    if (p != NULL) {
        if (key < p->key) p->left = temp;
        else p->right = temp;
    }
    else
        root = temp;
}


// 트리에서 키값이 key인 자료를 검색, data를 반환
char bst_search(int key)
{
    tree_pointer ptr = root;

    while (ptr != NULL) {
        if (key == ptr->key) return (ptr->data);   // key is found
        if (key < ptr->key) ptr = ptr->left;
        else ptr = ptr->right;
    }
    return NULL;
}

// 트리의 자료들을 inorder로 출력 
void bst_show_inorder(tree_pointer ptr)
{
    if (ptr == NULL) return;

    bst_show_inorder(ptr->left);
    printf(" %d %c \n", ptr->key, ptr->data);
    bst_show_inorder(ptr->right);
}
 