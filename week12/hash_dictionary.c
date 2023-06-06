#include "hash_dictionary.h"

void main()
{
	char	c, fname[20];
	char	key[100], * data;

	printf("************* Command ************\n");
	printf("R: Read data, S: Search data    \n");
	printf("P: Print hash table, Q: Quit    \n");
	printf("**********************************\n"); 


	while (1) {
		printf("\nCommand> ");
		c = getchar();
		getchar();
		c = toupper(c);
		switch (c) {
		case 'R':
			printf("\n Dictionary file name: ");
			scanf("%s", fname);
            getchar();
			wcount = 0;
			build_dictionary(fname);
			printf(" Total number of words: %d \n", wcount);
			break;
		case 'S':
			printf("\n Word: ");
			scanf("%s", key);
            getchar();
			num_comparison = 1;
			data = hash_search(key);
			if (data) printf(" Meaning: %s \n", data);
			else printf(" No such word ! \n");
			printf(" Tatal number of comparison = %d \n", num_comparison);
			break;
		case 'P':
			printf("\n");
			hash_show();
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default: break;
		}
	}
}


void build_dictionary(char* fname)
{
	char	key[100], data[200];
	FILE* ifp;

	if ((ifp = fopen(fname, "r")) == '\0') {
		printf("No such file ! \n");
		exit(1);
	}

	while (fscanf(ifp, "%s %s", key, data) == 2) {	   // (key data)를 읽어 해시테이블에 삽입
		hash_insert(key, data);
	}
	fclose(ifp);
}



// 해시테이블에 (key, data) 자료 삽입
void hash_insert(char* key, char* data) {
	int hash_value = hash(key);
	num_comparison = 1;
	while (strcmp(hash_table[hash_value].key,"")!=0) {
		if (strcmp(hash_table[hash_value].key, key) == 0) {
			printf(" there is already same key-data\n");
			return;
		}
		if (num_comparison == TABLE_SIZE) {
			printf(" hash table is full \n");
			return;
		}
		num_comparison++;
		hash_value = (hash_value + 1) % TABLE_SIZE;
	}
	strcpy(hash_table[hash_value].key, key);
	strcpy(hash_table[hash_value].data, data);
	wcount++;
}
// 해시테이블에서 키값이 key인 자료를 검색, data를 반환
char* hash_search(char* key) {
	int hash_value = hash(key);
	printf(" start_hash_value = %d\n", hash_value);
	while (strcmp(hash_table[hash_value].key,"")!=0) {
		if (strcmp(hash_table[hash_value].key, key) == 0) 
			return hash_table[hash_value].data;
		if (num_comparison == TABLE_SIZE) 
			return NULL;
		num_comparison++;
		hash_value = (hash_value+1)%TABLE_SIZE;
	}
	return NULL;
	
}
// 해시테이블의 key들을 차례로 출력 
void hash_show() {
	for (int i = 0; i < TABLE_SIZE; i++) 
		printf("hash_table[%d] = <%s , %s>\n", i, hash_table[i].key, hash_table[i].data);
}
// 해시 함수 (folding + division (TABLE_SIZE로 나눈 나머지))
int hash(char* key) {
	return transform(key) % TABLE_SIZE;
}
// folding (key의 각 character 값을 더함)
int transform(char* key) {
	int folding = 0;
	for (int i = 0; key[i] != '\0'; i++) {
		folding += key[i];
	}
	return folding;
}
