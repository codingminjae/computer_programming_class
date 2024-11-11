/*3. BINGO 게임 
컴퓨터와 사용자가 5X5 숫자판으로 빙고게임을 하는 프로그램을 작성해보세요.
  게임운영
  화면에 사용자 빙고판만 보인다. 컴퓨터 빙고판은 보이지 않는다. 
사용자가 1~25번 중에서 그 동안 선택하지 않은 번호를 선택한다. 
사용자와 컴퓨터는 해당 번호를 빙고판 에서 지운다. 
컴퓨터가 1~25번 중에서 그 동안 선택하지 않은 번호를 선택한다. 
사용자와 컴퓨터는 해당 번호를 빙고판 에서 지운다. 
빙고를 완성하면, 승자를 표시하고 게임 종료. 
빙고를 완성하지 못하면, 처음부터 반복 

※ 빙고 완성: 수직, 수평, 또는 대각선의 숫자가 모두 지워지면 빙고. */

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define SIZE 5
#define SIZE2 25
void initialize();
void set_rand(int* array);
void swap(int* x, int* y);
void erase_bingo(int arr[][5], int number);
void print_bingo(int arr[][5]);
void print_winner(int winner);
int get_number(int foem); //0: user, 1:computer
int chek_bingo(int arr[][5]);

int checked[25];
int count;
int ubingo[5][5];
int cbingo[5][5];

void main()
{
    int number, uwin, cwin;
    initialize(); //빙고 번호 생성 및 초기화 
    do {
        printf("사용자 \n");
        print_bingo(ubingo); //사용자 빙고판 출력 
        number = get_number(0); //사용자 숫자 입력, 0 :사용자 
        erase_bingo(ubingo, number); //사용자가 입력한 숫자 사용자 빙고판에서 삭제(0 으로 값 변경) 
        erase_bingo(cbingo, number); //사용자가 입력한 숫자 컴퓨터 빙고판에서 삭제(0 으로 값 변경) 
        number = get_number(1); //컴퓨터 숫자 선택 1 :컴퓨터 
        erase_bingo(ubingo, number); //컴퓨터가 선택한 숫자 사용자 빙고판에서 삭제(0 으로 값 변경) 
        erase_bingo(cbingo, number); //컴퓨터가 선택한 숫자 컴퓨터 빙고판에서 삭제(0 으로 값 변경) 
        uwin = chek_bingo(ubingo); //사용자빙고 완성유무 확인 , 가로, 세로, 대각선의 합이 0이면 빙고완성
        cwin = chek_bingo(cbingo); //컴퓨터빙고 완성유무 확인 , 가로, 세로, 대각선의 합이 0이면 빙고완성
    } while ((uwin == 0) && (cwin == 0)); //둘 중 빙고가 완성되어 1이 반환되면 반복 종료

    printf("사용자\n");
    print_bingo(ubingo);
    printf("컴퓨터\n");
    print_bingo(cbingo);
    print_winner(cwin * 2 + uwin);
}

//빙고판 초기화
void initialize() {
    srand((unsigned int)time(NULL));
    set_rand((int*)ubingo); //사용자 빙고판 초기화 
    set_rand((int*)cbingo); //컴퓨터 빙고판 초기화 
}

//랜덤 번호 생성&대입
void set_rand(int* array) {
    int i;
    for (i = 0; i < SIZE2; i++)
    {
        array[i] = i + 1;   //1~25 숫자 순차 생성 및 배열 대입

    }
    for (i = 0; i < SIZE2; i++)
    {
        swap(&array[i], &array[rand() % 25]); //인덱스 값을 랜덤으로 결정하여 숫자의 위치를 변경한다.
    }
}

//값 교환
void swap(int* x, int* y) { //값 교환 
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//빙고판에서 번호 지우기
void erase_bingo(int arr[][5], int number)
{
    int x, y;
    for (y = 0; y < SIZE; y++)
        for (x = 0; x < SIZE; x++)
            if (arr[y][x] == number) // 선택한 숫자와 동일한 값이 있으면 
                arr[y][x] = 0; // 0으로 만든다.
}

//빙고판 출력
void print_bingo(int arr[][5])
{
    int x, y;
    for (y = 0; y < SIZE; y++) {
        for (x = 0; x < SIZE; x++) {
            if (arr[y][x] != 0) //사용자, 컴퓨터가 선택한 숫자에 해당하지 않는 경우 
                printf("%5d", arr[y][x]); //값을 그대로 출력 
            else //사용자, 컴퓨터가 선택한 숫자에 해당하는 경우 (즉 값이 0인 경우)
                printf("   XX"); // 숫자 대신 XX 으로 출력
        }
        printf("\n");
    }
}

//번호 선택
int get_number(int form) {
    int num;
    int retry = 1;
    while (retry == 1) {
        retry = 0;
        if (form == 0) {
            printf("1~25 사이의 숫자를 입력하세요: ");
            scanf("%d", &num);
            if (num < 1 || num > 25)
                retry = 1;
        }
        else
            num = rand() % 25 + 1;
        if (retry == 0) {
            for (int i = 0; i < count; i++) {
                if (checked[i] == num) {
                    retry = 1;
                    break;
                }
            }
        }
    }
    checked[count++] = num;
    if (form == 0)
        printf("사용자가 %d를 선택했습니다.\n", num);
    else
        printf("컴퓨터가 %d를 선택했습니다.\n", number);

    return num;

} //0: user, 1:computer

//빙고 완성 여부 검사
int chek_bingo(int arr[][5]) {
    int x, y, sum;
    for (y = 0; y < SIZE; y++) { // check x-axis  
        sum = 0;
        for (x = 0; x < SIZE; x++) {
            sum += arr[y][x];
        }
        if (sum == 0) return 1;
    }
    for (x = 0; x < SIZE; x++) { // // check y-axis  
        sum = 0;
        for (y = 0; y < SIZE; y++) {
            sum += arr[y][x];
        }
        if (sum == 0) return 1;
    }
    sum = 0;
    for (x = 0; x < SIZE; x++) {
        sum += arr[x][x];
    }
    if (sum == 0) return 1;
    sum = 0;
    for (x = 0; x < SIZE; x++) {
        sum += arr[x][SIZE - x - 1];
    }
    if(sum == 0) return 1;

    return 0;
}

//승자 표시
void print_winner(int winner) {
    switch (winner) {
    case 1:
        printf("사용자가 이겼습니다.\n");
        break;
    case 2:
        printf("컴퓨터가 이겼습니다.\n");
        break;
    case 3:
        printf("비겼습니다.\n");
        break;
    default:
        printf("뭔가 이상합니다.\n");
        break;
    }
}
