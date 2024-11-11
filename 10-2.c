/*임의로 생성된 숫자를 버블 정렬 알고리즘으로 정렬한 후, sorted.txt에 저장하는 프로그램을 빈칸을 채워 완성해주세요. */

#include <stdio.h>   // 표준 입출력 라이브러리 포함
#include <stdlib.h>  // 동적 메모리 할당 및 기타 유틸리티 함수 포함
#include <time.h>    // 시간 관련 함수 포함
void generate_random(int* array, int size); // 임의의 정수 생성
void print_array(FILE* out, char* str, int* array, int size); // 배열 출력
void bubble_sort(int* array, int size); // 버블 정렬
void swap(int* xp, int* yp); // 두 정수의 값을 교환
void save_data(int* array, int size); // 데이터 저장


int main(void) {
    int* data; // 정수 배열 포인터
    int size;  // 배열의 크기
    srand(time(NULL)); // 현재 시간을 시드로 사용하여 랜덤 수 생성기 초기화
    printf("데이터 입력 사이즈? : "); // 사용자에게 배열 크기 입력 요청
    scanf("%d", &size); // 입력받은 크기를 size에 저장
    data = (int*)malloc(size * sizeof(int)); // size 크기만큼 메모리 동적 할당
    generate_random(data, size); // 임의의 정수 생성
    print_array(stdout, "원본 : ", data, size); // 원본 데이터 출력(표준 출력)
    bubble_sort(data, size); // 배열을 버블 정렬
    print_array(stdout, "정렬 : ", data, size); // 정렬된 데이터 출력(표준 출력)
    save_data(data, size); // 데이터를 파일에 저장
    free(data); // 동적으로 할당된 메모리 해제
}

void generate_random(int* array, int size) {
    int i;
    for (i = 0; i < size; i++) { // 배열 크기만큼 반복
        *(array + i) = rand() % 1000 + 1; // 1~1000 범위의 랜덤한 정수 생성
    }
}

void print_array(FILE* out, char* str, int* array, int size) { // 배열 출력
    int i;
    fprintf(out, "%s %d\n", str, size); // 배열 이름과 크기 출력
    for (i = 0; i < size; i++) {
        fprintf(out, "%5d", array[i]); // 배열 요소를 정렬된 형태로 출력
        if ((i + 1) % 10 == 0) // 10개마다 줄 바꿈
            fprintf(out, "\n");
    }
    fprintf(out, "\n");
}

void bubble_sort(int* array, int size) { // 버블 정렬 구현
    int i, k;
    for (i = 0; i < size - 1; i++) { // 배열의 모든 요소에 대해 반복
        for (k = 0; k < size - i - 1; k++) {
            if (array[k] > array[k + 1]) // 인접한 두 요소 비교
                swap(&array[k], &array[k + 1]); // 교환
        }
    }
}

void swap(int* xp, int* yp) { // 두 정수의 값을 교환
    int tmp;
    tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}

void save_data(int* array, int size) { // 데이터 저장(파일 출력)
    FILE* in; // 파일 포인터
    in = fopen("C:\\Users\\user\\Desktop\\sorted.txt", "w"); // sorted.txt 파일을 쓰기 모드로 열기
    if (in != NULL) { // 파일 열기가 성공했을 경우
        print_array(in, "정렬: ", array, size); // 정렬된 데이터 출력
        fclose(in); // 파일 닫기
    }
}
