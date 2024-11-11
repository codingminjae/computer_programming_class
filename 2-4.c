/*철수는 자료구조 과제를 위해 9시 30분부터 컴퓨터를 사용하여 22시 50분에 작업을 끝냈다. 영희는 13시 정각에 시작하여 다음날 1시에 작업을 끝냈다. 철수가 컴퓨터를 사용한 시간은 13시간 20분이고, 영희는 12시간 동안 컴퓨터를 사용하였다. 컴퓨터를 사용한 시작 시간과 종료 시간이 주어질 때, 컴퓨터 사용 시간을 구하는 프로그램을 작성하시오. 단 컴퓨터 사용 시간은 0보다 크고 24보다 작다. 

입력
첫 줄에는 시작 시간을 나타내는 두 개의 정수 A와 B가 주어지고, 둘째 줄에는 종료 시간을 나타내는 두 개의 정수 C와 D가 주어진다. 여기서 시작 시간은 A시 B분이고, 종료 시간은 C시 D분이다. A와 C는 0부터 23까지의 정수이고, B와 D는 0부터 59까지의 정수이다. 시작 시간과 종료 시간이 같은 경우는 없다. 종료 시간이 시작 시간보다 작으면 다음 날이라고 생각할 것. 
출력
컴퓨터 사용 시간인 T시간 M분을 나타내는 두 개의 정수 T와 M을 한 개의 빈칸을 사이에 두고 출력한다. */

#include <stdio.h>

int main() {
	int start_h, start_m, end_h, end_m;
	int hour, minute;
	scanf("%d%d", &start_h, &start_m);
	scanf("%d%d", &end_h, &end_m);
	if (start_m <= end_m) {
		hour = end_h - start_h;
		minute = end_m - start_m;
	}
	else {
		hour = end_h - start_h - 1;
		minute = end_m - start_m + 60;
	}

	if (hour < 0) {
		hour += 24;
	}

	printf("%d %d", hour, minute);

	return 0;
}
