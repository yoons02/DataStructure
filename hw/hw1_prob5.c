#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct {
    int element[MAXSIZE];
    int size;
} Bag;

// Function to initialize the Bag
Bag* init_bag() {
    Bag* b = (Bag*) malloc(sizeof(Bag));
    if (b == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    b->size = 0;
    return b;
}

// Function to get the size of the Bag
int size_bag(Bag *b) {
    return b->size;
}

// Function to insert an element into the Bag
void insert_bag(Bag *b, int num) {
    if (b->size < MAXSIZE) {
        b->element[b->size] = num;
        b->size++;
    } else {
        printf("Bag is full!\n");
    }
}

// Function to delete an element from the Bag
void delete_bag(Bag *b, int num) {
    for (int i = 0; i < b->size; i++) {
        if (b->element[i] == num) {
            b->element[i] = b->element[b->size-1];
            b->size--;
            return;
        }
    }
    printf("Element not found in the Bag!\n");
}

// Function to search for an element in the Bag
int search_bag(Bag *b, int num) {
    for (int i = 0; i < b->size; i++) {
        if (b->element[i] == num) {
            return 1;
        }
    }
    return 0;
}

int main(){
    Bag *b;

    // Initialize the Bag
    b = init_bag();

    // Insert some elements into the Bag
    insert_bag(b, 1);
    insert_bag(b, 3);
    insert_bag(b, 3);

    // Delete an element from the Bag
    delete_bag(b, 1);

    // Search for an element in the Bag
    int result = search_bag(b, 3);

    // Get the size of the Bag
    int n = size_bag(b);

    // Print the results
    printf("Size of the Bag: %d\n", n);
    printf("Result of search for element 3: %d\n", result);

    // Free the memory allocated for the Bag
    free(b);

    return 0;
}