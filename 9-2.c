/*다음은 버블정렬 알고리즘을 사용하여 난수로 생성된 정수 배열을 정렬하여 출력하는 프로그램입니다. 사용자로부터 정렬방법(오름차순, 내림차순)을 선택 할 수 있도록 합니다. 
난수 생성범위는 1~100 정수입니다. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void f_data(int*, int);
void print(int*, int);
void bubble_sort(int*, int, int);
void swap(int*, int*);
int main() {
    int size, choice;
    int* array;
    printf("데이터 입력 수 : ");
    scanf("%d", &size);
    array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("메모리 할당 실패\n");
        return 1; // 메모리 할당 실패 시 프로그램 종료
    }
    f_data(array, size);
    printf("데이터 생성\n");
    print(array, size);
    printf("정렬 기준 선택 (1: 오름차순, 2: 내림차순): ");
    scanf("%d", &choice);
    bubble_sort(array, size, choice);
    printf("정렬된 데이터\n");
    print(array, size);
    free(array); // 동적 할당한 메모리 해제
    return 0;
}
void f_data(int* a, int size) {
    srand((unsigned int)time(NULL));
    // 1부터 100 사이의 난수 생성
    for (int i = 0; i < size; i++) {
        while (1) {
            int check = 0;
            a[i] = rand() % 100 + 1;
            for (int j = 0; j < i; j++) {
                if (a[j] == a[i])
                    check = 1;
            }
            //반복문 탈출 조건(중복 없을 경우)
            if (check == 0)
                break;
        }
    }
}
void bubble_sort(int* a, int size, int choice) {
    // 버블정렬, choice = 1 오름차순, choice = 2 내림차순
    if (choice == 1) { //오름차순
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (a[i] > a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
    else if (choice == 2) { //내림차순
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (a[i] < a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
}
void swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
void print(int* a, int size) {
    // 배열 출력
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
