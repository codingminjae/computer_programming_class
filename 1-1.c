/*1. 월을 입력하면 봄, 여름, 가을, 겨울로 구분하는 프로그램을 switch문을 이용하여 작성해 보세요 (봄 : 3~5월, 여름: 6~8월, 가을 : 9~11월, 겨울 : 12~2월)*/

#include <stdio.h>

int main() {
	int month;
	scanf("%d", &month);
	switch (month) {
	case 3:
		printf("봄 입니다.");
		break;
	case 4:
		printf("봄 입니다.");
		break;
	case 5:
		printf("봄 입니다.");
		break;
	case 6:
		printf("여름 입니다.");
		break;
	case 7:
		printf("여름 입니다.");
		break;
	case 8:
		printf("여름 입니다.");
		break;
	case 9:
		printf("가을 입니다.");
		break;
	case 10:
		printf("가을 입니다.");
		break;
	case 11:
		printf("가을 입니다.");
		break;
	case 12:
		printf("겨울 입니다.");
		break;
	case 1:
		printf("겨울 입니다.");
		break;
	case 2:
		printf("겨울 입니다.");
		break;
	}

	return 0;
}
