/*최대 10개의 0보다 크고 100보다 작은 실수를 사용자로부터 입력받고 평균과 표준편차를 구하여 출력하는 프로그램을 작성하라. 단 평균과 표준편차를 소수점 이하 두 자리까지 출력하라. */

#include <stdio.h>
#include <math.h>
#define NUMMAX 10 // 데이터의 최대 수를 정의한다.
void get_data(); // 데이터 입력 
float calc_average(); //평균 계산하여 리턴
float calc_stdev(float mean); // 표준편차 구하여 리턴, mean은 평균 값 
float num[NUMMAX]; // 전역변수 선언
int cnt = 0;

int main() {
	float avg, stdev; // 지역변수 선언
	get_data(); // 데이터를 입력 받고
	avg = calc_average(); // 평균을 구하고
	stdev = calc_stdev(avg); // 표준편차를 구한다.

	printf("\n 평균 = %6.2f\n", avg); // 결과를 출력한다.
	printf("표준편차 = %6.2f\n\n", stdev);

	return 0;
}
void get_data() {
	for (int i = 0; i < NUMMAX; i++) {
		printf("숫자 %d: ", cnt + 1);
		scanf("%f", &num[i]);
		if (num[i] == -1)
			break;
		cnt++;
	}
}
float calc_average() {
	float sum = 0;
	for (int i = 0; i < cnt; i++) {
		sum += num[i];
	}
	sum /= cnt;
	return sum;
}
float calc_stdev(float mean) {
	float ssum = 0;
	float diff = 0;
	for (int i = 0; i < cnt; i++) {
		diff = num[i] - mean;
		ssum += diff * diff;
	}
	ssum /= cnt;
	ssum = sqrt(ssum);

	return ssum;
}
