/*정수형 배열을 다음과 같이 초기화 하고, 그 중에서 최대값을 찾아 출력하는 프로그램을 작성해보세요.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void){
	int max_idx = 0;
	int arr[10] = { 3,2,9,7,1,4,8,0,6,5 };
	for (int i = 1; i < 10; i++) {
		if (arr[i] > arr[max_idx])
			max_idx = i;
	}
	printf("%d", arr[max_idx]);

	return 0;
}
