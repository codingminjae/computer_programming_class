/*3. 다음과 같이 출력 할 문자 A의 개수를 입력받아 문자 A를 출력한 후 B가 출력되도록 
프로그램을 작성하시오.*/

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("A");
	}
	printf("B");

	return 0;
}
