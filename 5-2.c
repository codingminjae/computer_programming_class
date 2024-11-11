/*충북대학교 은송이교수님은 응용컴퓨터프로그래밍 수업을 담당한다. 수강생은 30명이다.
각 학생별로 1번부터 30번까지 출석번호가 붙어 있다.

교수님이 내준 특별과제를 28명이 제출했는데, 그 중에서 제출 안 한 학생 2명의 출석번호를 구하는 프로그램을 작성해보세요.*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	int student[31] = { 0, };
	int ans[31];
	int idx = 0;
	for (int i = 0; i < 30; i++) {
		ans[i] = i + 1;
	}
	for (int i = 0; i < 28; i++) {
		scanf("%d", &student[i]);
	}

	qsort(student, 28, sizeof(int), compare);

	for (int i = 0; i < 30; i++) {
		if (student[idx] == ans[i]) {
			idx++;
		}
		else {
			printf("%d\n", ans[i]);
		}
	}

	return 0;
}
