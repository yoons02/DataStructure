#include "hashing.h"

int main(){
    int count;
    printf("Enter the number of insert element : "); // 개수 입력
    scanf("%d", &count);

    srand(time(NULL)); // 진짜 random하게 숫자 뽑기

    for (int i = 0; i < count; i++){ // 입력한 개수만큼 실행, insert
        element item;  // element형 item 선언

        item.key = get_random_key(); // random으로 key값 부여
        item.value = item.key + 10000; // value는 key + 10,000

        linear_probing_insert(item); // item 삽입
        total_insert_comparison += num_insert_comparison; // 하나의 숫자 삽입 당 비교한 횟수를 total_insert_comparison에 더해나감
        printf("Insert key : %d, value : %d, comparison : %d\n", item.key, item.value, num_insert_comparison);
        // 삽입한 key, value, 삽입 시 비교한 횟수 출력
    }
    printf("\n*******************\n");
    printf("Insert complete.\n");
    printf("Total insert comparisons : %d\n", total_insert_comparison); // 삽입 시 총 비교 횟수 출력
    printf("*******************\n\n");

    for (int i = 0; i < count; i++){ // 개수만큼 실행, search
        int key_s = keys[i]; // keys 배열에서 하나 뽑아서 key_s에 부여
        linear_probing_search(key_s); // key_s 를 찾는다.
        total_search_comparison += per_comparison; // 하나의 숫자 검색 시 비교 횟수를 total_search_comparison에 더해나감
        if (worst < per_comparison) worst = per_comparison; // 최악의 경우 비교 수 찾기
    }
    printf("*******************\n");
    printf("Search complete.\n");
    printf("*******************\n\n");
    printf("[loading density : %f]\n", (float)count/1000); // density 출력
    printf("total search : %d, success insert : %d\n", total_search_comparison, success_insert_count); // 총 비교 수와 삽입된 key 수 출력 
    printf("Average successful search key comparison : %f\n", (float)total_search_comparison/success_insert_count); // 평균 search 비교 횟수 출력
    printf("Worst : %d\n", worst); // worst case

    return 0;
}

int hash_function(int key){ // hash function
    return key % TABLE_SIZE;
}

int get_random_key(){ // random key
    return rand() % 10000;
}

void linear_probing_insert(element item){ // item insert to hash table

    int hash_key = hash_function(item.key); // item 키를 hash key로 변환
    int i = hash_key; // i 초기화
    keys[key_count++] = item.key; // 삽입 될 item 키를 keys 배열에 추가한다

    while(ht[i].key != '\0'){ // 뭔가 들어가있으면
        if (ht[i].key == item.key){ // 같은 key가 존재하면
            printf("duplicate\n"); // 중복
            return;
        }
        i = (i+1)%TABLE_SIZE; // 아니면 다음 bucket으로 index를 옮기고
        if (i == hash_key){ // 꽉 참
            printf("Table is Full\n");
            return;
        }
        num_insert_comparison +=1; // 비교 횟수 1 증가
    }

    // 비어있으면
    ht[i] = item; // hash table에 item을 넣는다.
    success_insert_count +=1; // 삽입에 성공했으므로 success_insert_count += 1
    return;
}

void linear_probing_search(int key){ // item search in hash table
    int hash_key = hash_function(key); // item의 키를 hash key로 변환
    int i = hash_key; // i 초기화
    num_search_comparison = 0; // num_search_comparison 초기화

    while (ht[i].key != '\0'){ // 빈 공간이 나올 때까지 loop
        num_search_comparison+=1; // 비교 횟수 1 증가
        if (ht[i].key == key){ // 똑같은 게 있다면
            per_comparison = num_search_comparison; // per_comparison에 num_search_comparison를 부여하고
            printf("Search success. loc = %d, comparison = %d,\n", i, per_comparison); // 결과 출력
            return;
        }
        i = (i+1)%TABLE_SIZE; // 다음 bucket으로 넘어가 탐색한다

        if (i==hash_key){ // 모든 테이블을 모두 돌았다면
            printf("Search Fail\n"); // 검색 실패
            return;
        }
    } 

    // 바로 찾아갔는데 비어있다면 (삽입된 데이터가 아님)
    printf("Search Fail\n");
    return;
}