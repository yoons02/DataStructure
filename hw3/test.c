#include <stdio.h>

#define MAX_LINE_LENGTH 100

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_LINE_LENGTH];

    // edges.txt 파일 열기
    inputFile = fopen("edges.txt", "r");
    if (inputFile == NULL) {
        printf("edges.txt 파일을 열 수 없습니다.\n");
        return 1;
    }

    // trees.txt 파일 열기 (쓰기 모드)
    outputFile = fopen("trees.txt", "w");
    if (outputFile == NULL) {
        printf("trees.txt 파일을 열 수 없습니다.\n");
        return 1;
    }

    // edges.txt에서 한 줄씩 읽어 trees.txt에 쓰기
    while (fgets(line, MAX_LINE_LENGTH, inputFile) != NULL) {
        fputs(line, outputFile);
    }

    // 파일 닫기
    fclose(inputFile);
    fclose(outputFile);

    printf("trees.txt 파일이 성공적으로 작성되었습니다.\n");

    return 0;
}
