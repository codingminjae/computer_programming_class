/*세 개의 수를 입력 받고, 그 중에서 가장 큰 값과 가장 작은 값의 차이를 구하여 출력하라*/

#include <stdio.h> // 헤더 파일 추가
float find_max(float a, float b, float c); // 함수 선언 추가
float find_min(float a, float b, float c);
int main() {
	float num1, num2, num3; // 지역변수 선언
	float max, min;
	float difference;
	printf("세 개의 수를 입력하세요.\n\n"); // 데이터 입력
	printf("첫 번째 수: ");
	scanf("%f", &num1);
	printf("두 번째 수: ");
	scanf("%f", &num2);
	printf("세 번째 수: ");
	scanf("%f", &num3);
	max = find_max(num1, num2, num3); //find_max() 호출
	min = find_min(num1, num2, num3);      //find_min() 호출 
	difference = max - min; //차이 구하기 
	printf("\n가장 큰 수와 작은 수의 차이 = %f\n\n", difference); // 결과 출력

	return 0;
}

float find_max(float a, float b, float c) {
	float number[3] = { a, b, c };
	float temp;
	for (int i = 0; i < 2; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (number[i] < number[j]) {
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
		}
	}
	return number[0];
}
float find_min(float a, float b, float c) {
	float number[3] = { a, b, c };
	float temp;
	for (int i = 0; i < 2; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (number[i] < number[j]) {
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
		}
	}
	return number[2];
}
