/*1000보다 작은 자연수 중 약수의 합이 자기자신과 같아지는 수(완전수)를 모두 찾아서 출력하는 프로그램을 작성해 보세요. */

#include <stdio.h>
int perfect_number(int number); // 완전수 여부 판별 함수 (반환형 void으로 변경가능) 
int main(void) {
	int number = 1000;
	printf("1000 이하의 완전수: \n");
	perfect_number(number);
	// 반복문 수행 및 perfect_number() 호출하여 완전 수 계산 및 출력 
	return 0;
}

int perfect_number(int number) {
	int sum = 0;
	for (int i = 2; i <= number; i++) {
		int sum = 0;
		for (int j = 1; j < i; j++) {
			if (i % j == 0) {
				sum += j;
			}
		}
		if (sum == i) {
			printf("%d\n", i);
		}
	}

	return 0;
}
