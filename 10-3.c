/*실습#2에서 파일에 저장한 데이터(sorted.txt)를 읽어 배열에 저장하고, 사용자로부터 정수를 입력 받아서, 그 수가 존재하는지 탐색하는 프로그램을 작성해보세요. (선형 탐색)*/

#include <stdio.h>  
#include <stdlib.h> 
void print_array(char* str, int* array, int size); // 배열 출력 함수
int read_data(int** parray); // 파일에서 데이터 읽기 함수
int linear_search(int* array, int size, int key); // 선형 탐색 함수
void main() {
    int* data = NULL;  // 데이터 저장을 위한 포인터
    int size = 0;      // 배열 크기
    int index, key = 1; // 검색할 키와 인덱스 변수 초기화
    // sorted.txt 파일에서 크기 및 데이터를 읽어옴
    size = read_data(&data);
    print_array("원본:", data, size); // 읽어온 배열 출력

    while (key > 0) { // key 값이 양수일 동안 반복
        printf("검색할 수를 입력하세요 : "); // 사용자에게 검색할 수 입력 요청
        scanf("%d", &key); // 입력값을 key에 저장
        if (key > 0) { // 입력된 값이 양수인 경우
            index = linear_search(data, size, key); // 선형 탐색 수행
            if (index != -1) // 탐색 성공 시
                printf("데이터가 %d번째 위치에 있습니다.\n", index + 1); // 위치 출력
            else
                printf("데이터가 파일에 존재하지 않습니다.\n"); // 탐색 실패 시 메시지 출력
        }
    }
    // 동적 메모리 해제
    if (data != NULL)
        free(data); // 동적으로 할당한 메모리 해제
}




int read_data(int** parray) {
    char tmp[20]; // 파일에서 읽어올 문자열 저장
    int* array = NULL; // 동적 배열 포인터 초기화
    int size = 0, n; // 배열 크기 및 반복 변수
    FILE* fp = fopen("C:\\Users\\user\\Desktop\\sorted.txt", "r"); // sorted.txt 파일 열기

    if (fp != NULL) { // 파일이 정상적으로 열렸을 경우
        fscanf(fp, "%d", &size); // 파일 첫 줄에서 정렬 정보와 배열 크기 읽기
        if (size != 0) { // 배열 크기가 0이 아닐 경우
            // 읽어온 크기만큼 동적 메모리 할당
            array = (int*)malloc(sizeof(int) * size);
            for (n = 0; n < size; n++) { // 배열에 데이터 읽기
                fscanf(fp, "%d", &array[n]); // 정수 값을 배열에 저장
            }
        }
        fclose(fp); // 파일 닫기
    }
    else {
        printf("파일이 존재하지 않습니다.\n"); // 파일이 열리지 않을 경우 메시지 출력
    }
    *parray = array; // 읽어온 배열을 호출자에게 전달
    return size; // 배열 크기 반환
}
void print_array(char* str, int* array, int size) {
    int n;
    printf("%s %d\n", str, size); // 배열 이름과 크기 출력
    for (n = 0; n < size; n++) { // 배열의 각 요소 출력
        printf("%5d", array[n]); // 배열의 각 요소를 정렬된 형태로 출력
        if ((n + 1) % 10 == 0) // 10개마다 줄 바꿈
            printf("\n");
    }
    printf("\n"); // 출력 마무리
}


int linear_search(int* array, int size, int key) {
    int n;
    for (n = 0; n < size; n++) { // 배열을 순회하며 탐색
        if (array[n] == key) // 키 값과 현재 요소가 같으면
            return n; // 인덱스 반환
        if (array[n] < key) // 키 값이 현재 요소보다 작으면 탐색 중단
            break;
    }
    return -1; // 탐색 실패 시 -1 반환
}
