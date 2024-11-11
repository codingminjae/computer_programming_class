/*다음은 선택 정렬 알고리즘을 사용하여 난수로 생성된 정수 배열을 정렬하고, 
정렬된 배열의 중앙값을 출력하는 프로그램입니다. 코드를 완성해 보세요. 
난수로 생성된 정수의 범위는 100보다 작은 3의 배수입니다. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void f_data(int*, int);
void print(int*, int);
void select_sort(int*, int);
int main() {
    int size;
    int* array;
    int mid;
    printf("데이터 입력 수 : ");
    scanf("%d", &size);
    array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("메모리 할당 실패\n");
        return 1; // 메모리 할당 실패 시 프로그램 종료
    }
    f_data(array, size);
    printf("데이터 생성\n");
    print(array, size); //생성된 데이터 출력 
    select_sort(array, size); //정렬
    printf("정렬\n");
    print(array, size); //정렬된 데이터 출력 
    mid = size / 2;
    // 중앙값 출력
    printf("데이터 중앙값 = %d", array[mid]);
    free(array); // 동적 할당한 메모리 해제
    return 0;
}
void f_data(int* a, int size) {
    // 현재시간을 시드로 사용하여 난수 생성기 초기화
    srand((unsigned int)time(NULL));
    // 난수 생성 범위 : 100보다 작은 3의 배수 (중복 제거하기)
    for (int i = 0; i < size; i++) {
        while (1) {
            int check = 0;
            a[i] = (rand() % 34) * 3;
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

void select_sort(int* a, int size) {
    // 선택 정렬 구현
    int min;
    for (int i = 0; i < size - 1; i++) {
        min = i;
        for (int j = i + 1; j < size; j++) {
            if (a[min] > a[j])
                min = j;
        }
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}
void print(int* a, int size) {
    // 배열 출력
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
