#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define TABLE_SIZE 1001

typedef struct {
   int key;
   int value;
} element;
element  ht[TABLE_SIZE];

int keys[TABLE_SIZE];
int key_count = 0;
int worst = 0;
int per_comparison = 0; // successful search 비교 횟수
int success_insert_count = 0; // 삽입 성공한 key 개수
int num_insert_comparison = 1; // 하나의 item 삽입 시 비교한 횟수
int total_insert_comparison = 0; // 삽입 시 비교한 총 횟수
int num_search_comparison; // 하나의 item 검색 시 비교한 횟수
int total_search_comparison = 0; // 검색 시 비교한 총 횟수

int hash_function(int key);
void linear_probing_insert(element item);
void linear_probing_search(int key );
int get_random_key();
