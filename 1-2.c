/*2. 0 에서 100 사이의 정수를 여러 개 입력 받아 합, 평균, 개수를 출력 해보세요. 
단, 0보다 작으면 반복을 종료하고, 100보다 큰 수는 개수, 합, 평균에서 제외하며 계속 다음 데이터를 입력 받을 수 있도록 합니다.*/

#include <stdio.h>

int main() {
	int n;
	int sum = 0;
	int cnt = 0;
	double ave = 0;
	while (1) {
		scanf("%d", &n);
		if (n <= 100 && n >= 0) {
			sum += n;
			cnt++;
			ave += n;
		}
		else if (n > 100)
			continue;
		else if (n < 0)
			break;
	}
	ave /= cnt;
	printf("합 : %d, 평균 : %lf, 개수 : %d", sum, ave, cnt);

	return 0;
}
