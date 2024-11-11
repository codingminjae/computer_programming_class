/*read1.txt 파일을 열어서 파일에 들어있는 문자들을 모두 대문자로 변경하여 read2.txt 파일에 출력하는 프로그램을 작성해 보세요.*/

#include <stdio.h>
#include <ctype.h>

int main() {
    FILE* inputFile = fopen("C:\\Users\\user\\Desktop\\read1.txt", "r");
    FILE* outputFile = fopen("C:\\Users\\user\\Desktop\\read2.txt", "w");

    if (inputFile == NULL) {
        printf("Error\n");
        return 1;
    }

    char ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(toupper(ch), outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
