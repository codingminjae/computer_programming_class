/*양의 정수를 입력받고 이수의 모든 약수를 구하여 출력하는 프로그램을 작성해 보세요. 
만약 입력 값이 1보다 작은 정수이면 프로그램을 종료 합니다.*/

#include <stdio.h>
void print_divisor(int value); // 약수 구하는 함수 
int main(void) {
	int number;
	while (1) // 무한 반복
	{
		printf("약수를 구할 정수 입력(1 이하 종료) : ");
		scanf("%d", &number); // 데이터 입력
		if (number >= 2) { // 약수를 구할 수 있다면
			print_divisor(number);
		}
		else { // 약수를 구할 수 없다면
			printf("%d에 대한 약수를 구할 수 없습니다.\n", number);
			printf("프로그램을 종료합니다.\n");
			break;
		}
		printf("\n");
	}
	return 0;
}

void print_divisor(int value) {
	printf("2의 약수 : ");
	for (int i = 2; i <= value; i++) {
		if (value % i == 0) {
			printf("%d ", i);
		}
	}
}
