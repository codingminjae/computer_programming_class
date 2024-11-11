/*사용자에게 6개의 로또 번호를 입력하도록 하고, 컴퓨터가 생성한 6개의 로또 번호와 비교하여,
일치하는 번호의 개수를 알려주는 프로그램을 작성해 보세요.
main()함수는 아래와 같이 주어져 있으며, 세가지 서브 함수를 구현해서 프로그램을 완성해 보세요.
컴퓨터가 랜덤하게 생성하는 수는 중복되는 숫자가 생성되지 않도록 해야 합니다.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 45
void user_chek(int* arr_user); //사용자가 입력한 숫자 배열에 저장.
void generate_lotto_number(int* arr_lotto); //컴퓨터 로또번호 생성(랜덤함수 사용)
int mapping_number(int* arr_user, int* arr_lotto);
//사용자 입력 숫자와 컴퓨터가 생성한 로또번호 중 일치하는 번호 수 카운트
void print_arr(int* arr); //숫자 출력 


int main(void) {
    int arr_lotto[6] = { 0 }; //컴퓨터가 임의로 생성하는 번호 6개 저장.
    int arr_user[6] = { 0 }; //사용자가 입력하는 6개 번호 저장.
    int cnt;

    srand((unsigned)time(NULL));
    generate_lotto_number(arr_lotto); //컴퓨터 로또 번호 생성
    user_chek(arr_user); //사용자 숫자 입력 
    printf("사용자 입력 : ");
    print_arr(arr_user);
    printf("\n당첨번호(컴퓨터생성) : ");
    print_arr(arr_lotto);
    cnt = mapping_number(arr_lotto, arr_user);

    printf("\n 당첨 번호는 %d개 입니다.\n", cnt);

    return 0;
}

//사용자가 입력한 숫자를 배열에 저장하는 함수
void user_chek(int* arr_user) {
    printf("1~45사이의 번호를 6개 선택하세요 :");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &arr_user[i]);
    }
}

//컴퓨터 로또 번호 생성하는 함수(랜덤으로)
void generate_lotto_number(int* arr_lotto) {
    int dup = 0;
    int cnt = 0;
    while (cnt < 6) {
        arr_lotto[cnt] = rand() % 45 + 1;
        if (cnt > 0) {
            for (int i = 0; i < cnt; i++) {
                if (arr_lotto[i] == arr_lotto[cnt]) {
                    dup++;
                }
            }
        }

        if (dup == 0) {
            cnt++;
        }
        else {
            dup = 0;
        }
    }
}

//일치하는 번호 매핑하는 함수
int mapping_number(int* arr_user, int* arr_lotto) {
    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (arr_user[i] == arr_lotto[j]) {
                cnt++;
                break;
            }
        }
    }

    return cnt;
}

//숫자 출력하는 함수
void print_arr(int* arr) {
    for (int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
}
