/*그리스 수학자 에라토스테네스가 고안한 방법을 사용하여 양의 정수 n에 대하여 n과 같거나 작은 소수를 모두 출력하는 프로그램을 작성해 보세요.
  에라토스테네스의 체 
 1. 1은 소수에 해당하지 않으므로, 종이에 2부터 n까지 정수를 모두 적는다. 
 2. 처음에 인수를 2로 정하고 2의 배수에 해당하는 수를 모두 지운다.
 3. 다음에 인수를 3으로 정하고 3의 배수에 해당하는 배열의 원소를 모두 지운다. 
 4. 이와 같은 방법으로 인수를 하나씩 증가시켜가면서 계속 인수의 배수를 모두 지운다.
 5. 마지막까지 남아 있는 숫자는 소수이다. */

#include<stdio.h>
#include<stdlib.h> //calloc(), free() 함수 선언
#include<math.h> //sqrt() 

void eratos(int number, char array[]) { //에라토스테네스의 체 알고리즘 사용하여 소수 구하기
	int n, m, to, last, index;
	to = (int)sqrt((double)number); // 마지막 나눌 값
	for (n = 2; n <= to; n++) { // 바깥쪽 루프
		last = number / n; // 마지막 조사 값
		for (m = 2; m <= last; m++) { // 안쪽 루프
			index = n * m; // 배열의 인덱스
			array[index] = 1; // 소수가 아님을 표시한다.
		}
	} // 이중 반복문이 끝났을 때까지 값이 0인 원소의 인덱스가 소수이다.
}
void print_primes(int value, char* array) {    //출력하기 
	int n;
	int count = 0;
	printf("%d의 소수 : \n", value);
	for (n = 2; n <= value; n++) {
		if (array[n] == 0) { // 소수인 것만
			printf("%9d", n); // 소수를 9 칸의 공간에 출력한다.
			count += 1; // 한 줄에 출력한 소수의 수
			if ((count % 8) == 0) // 한 줄에 8 개를 출력하였다면,
				printf("\n"); // 다음 줄로 이동한다. }
		}
	}
	printf("\n");
}

int main() {
	int number;
	char* array; // 문자형 포인터
	printf("정수를 입력하세요: "); // 정수 입력
	scanf("%d", &number);
	if (number > 2) {
		array = (char*)calloc(number, sizeof(char)); // 배열 동적 할당
		if (array != NULL) {
			eratos(number, array); //eratos() 함수 호출 
			print_primes(number, array); //print_primes()함수 호출 
			free(array); //동적할당 해제 
		}

	}

	return 0;
}
