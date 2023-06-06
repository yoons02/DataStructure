#include<stdio.h> 
#include "test.h"

void main() {
    int num_keys;
    printf("#keys=");
    scanf("%d", &num_keys);
    for (int i = 0; i < num_keys; i++) {
        element tmp;
        tmp.key = get_random_key(); tmp.value = tmp.key +10000;
        linear_probing_insert(tmp);
    }
    for (int i = 0; i < key_count; i++) {
        int key = keys[i]; 
        linear_probing_search(key);
    }
    printf("[loading density = %f]\n", (float)num_keys/1000);
    printf("successful search의 평균 key 비교 회수 = %f\n", (float)p_comparision /present);
    printf("최악의 경우 key 비교 회수 = %d\n", worst);
    }
    void linear_probing_insert(element item) { int hash_value = hash(item.key); int i = hash_value;
    while (1) {
    } }
    }
    if (ht[i].key==NULL) { ht[i] = item;
    keys[key_count++] = item.key;
    return; }
    i = (i + 1) % TABLE_SIZE; if (i == hash_value) break;
    void linear_probing_search(int key) { int hash_value = hash(key);
    int comparision = 0; int i = hash_value; while(1){
    comparision++;
    if (ht[i].key==NULL) {
    break; }
    if (ht[i].key == key) {
    p_comparision += comparision;
    present++;
    //printf("hash_value : %d\n", ht[i].value); break;
    }
    i = (i +
    if (i == hash_value) break;
    }
    if (worst < comparision) worst = comparision;
    1) % TABLE_SIZE;
    
    int get_random_key() {
    return rand() % 10000;
    }
    int hash(int key) {
    return key % TABLE_SIZE;
}