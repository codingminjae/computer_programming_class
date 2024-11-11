/*4. [15, 29, 3, 46, 22]로 초기화 된 배열에서 가장 큰 수와 가장 작은 수를 찾아 두 원소의 위치를 바꾸는 프로그램을 작성하려고 한다. 아래의 main() 함수를 보고, exchange() 함수를
구현하여 프로그램을 완성해보세요. 단, main() 함수의 코드는 수정할 수 없습니다.*/

#include<stdio.h>

void exchange(int* a) {
	int max = 0, min = 0;
	for (int i = 0; i < 5; i++) {
		if (a[i] > a[max])
			max = i;
		if (a[i] < a[min])
			min = i;
	}
	int temp =a[max];
	a[max] = a[min];
	a[min] = temp;
}

int main() {
	int arr[] = { 15,29,3,46,22 };
	int i;
	exchange(arr);
	for (i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}

