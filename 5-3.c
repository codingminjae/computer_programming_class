/*컴퓨터와 숫자 야구게임을 하는 프로그램을 만들어 보세요. 
숫자를 랜덤하게 4개 생성(중복되지 않도록)하고, 
사용자 입력에 따라 아래와 설명과 같이 동작하는 프로그램을 완성해 보세요.
입력한 숫자가 생성된 숫자에 포함되어 있고 자리도 맞으면 스트라이크, 
숫자가 포함되어 있지만 자리는 다르면 볼, 숫자가 포함되어 있지 않으면 아웃 출력.
모든 숫자가 스트라이크이면 정답이라고 출력합니다. 정답을 맞힐 때까지 반복 합니다.  
숫자 범위는 1 ~ 9 입니다.  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void user(int*); //사용자 입력
void computer(int*); //컴퓨터 숫자 생성
int mapping(int*, int*); //매핑


int main(void) {
    int arr_com[4] = { 0 };
    int arr_user[4] = { 0 };
    srand((unsigned)time(NULL));

    computer(arr_com); //컴퓨터 숫자 랜덤 생성

    while (1) {
        user(arr_user); //사용자 입력 

        if (mapping(arr_com, arr_user))
            break;
    }
    return 0;
}

void computer(int* arr_c) {
    for (int i = 0; i < 4; i++) {
        while (1) {
            int num = rand() % 9 + 1;
            int j;
            for (j = 0; j < i; j++) {
                if (arr_c[j] == num) {
                    break;
                }
            }
            if (j == i) {
                arr_c[i] = num;
                break;
            }
        }
    }
}

void user(int* arr_u) {
    for (int i = 0; i < 4; i++) {
        scanf("%d", &arr_u[i]);
    }
}
int mapping(int* c, int* u) {

        int cnt = 0;
        int p = 0;
        int strike = 0;
        int ball = 0;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (c[i] == u[j]) {
                    if (i == j) {
                        strike++;
                    }
                    else {
                        ball++;
                    }

                }
            }
        }
        if (strike == 0 && ball == 0) {
            printf("아웃입니다.\n");
            return 0;
        }
        else if(strike != 4){
            printf("%d 볼, %d 스트라이크입니다.\n", ball, strike);
            return 0;
        }

        //종료조건
        else if (strike == 4) {
            printf("4 스트라이크입니다.");
            return 1;
        }
}
