/*3. 제품 매출액 정산
  나부자는 4가지 제품을 판매하는 가게를 운영하고 있다. 4가지 제품별 하루 판매량을 입력하고 

  1) 총 매출액, 순 매출액(총 매출액 - 총 원가액) -> sales()함수 호출 
  2) 제일 많이 판매한 제품 명 –> best_goods() 함수 호출
  3) 제품별 순 매출액이 제일 큰 제품명 출력 –> best_npg() 함수호출 

위의 1), 2) ,3) 값이 출력되도록 프로그램을 작성해 보자. 

3행 4열의 2차원 배열에 1행에는 제품별 판매가, 2행에는 제품별 원가가 아래 표와 같이 초기화 되어 있다. 3행에 제품별 판매수량을 입력 받도록 한다. 제품명은  A, B, C, D 이다. 

             
                    
  - 총 매출액 : (A판매가 * A판매량) + (B판매가 * B판매량) + (C판매가 * C판매량) + (D판매가 * D판매량)
  - 총 원가액: (A원가 * A판매량) +  (B원가 * B판매량) + (C원가 * C판매량) + (D원가 * D판매량)
  - 순 매출액 : 총 매출액 – 총 원가 액 */

#include<stdio.h>
#define ROWS 3 //행
#define COLS 4 //열

void fill_data(int data[][COLS]);
void best_goods(int data[][COLS]);
void best_npg(int data[][COLS]);
void sales(int data[][COLS]);

void main() {
	int data[ROWS][COLS] = {
			{2000,3000,4000,5000},    //판매가
			{1000,1000,2000,2000},    //원가
			{0}                        //판매수량
	};
	fill_data(data);	//제품별 판매 수량 입력
	sales(data);		//총 매출액, 순 매출액 출력
	best_goods(data);	//제일 많이 판매된 제품명 출력
	best_npg(data);	//제품별 순 매출액이 제일 큰 제품명 출력
}

void fill_data(int data[][COLS]) { //제품별 판매 수량 입력
	printf("A 판매량 입력 : ");
	scanf("%d", &data[2][0]);
	printf("B 판매량 입력 : ");
	scanf("%d", &data[2][1]);
	printf("C 판매량 입력 : ");
	scanf("%d", &data[2][2]);
	printf("D 판매량 입력 : ");
	scanf("%d", &data[2][3]);
}

void sales(int data[][COLS]) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		sum += data[0][i] * data[2][i];
	}
	printf("총 매출액 : %d\n", sum);
	int sum2 = 0;
	for (int i = 0; i < 4; i++) {
		sum2 += data[0][i] * data[2][i] - data[1][i] * data[2][i];
	}
	printf("순 매출액 : %d\n", sum2);
}

void best_goods(int data[][COLS]) {
	int max = 0;
	for (int i = 1; i < 4; i++) {
		if (data[2][max] < data[2][i])
			max = i;
	}

	printf("제일 많이 판매된 제품명 : \n");
	for (int i = 0; i < 4; i++) {
		if (data[2][i] == data[2][max]) {
			if (i == 0)
				printf("A\n");
			else if (i == 1)
				printf("B\n");
			else if (i == 2)
				printf("C\n");
			else if (i == 3)
				printf("D\n");

		}
	}

	printf("순 매출액이 제일 큰 제품명 : \n");
	for (int i = 0; i < 4; i++) {
		if (data[2][i] == data[i][max]) {
			if (i == 0)
				printf("A\n");
			else if (i == 1)
				printf("B\n");
			else if (i == 2)
				printf("C\n");
			else if (i == 3)
				printf("D\n");

		}
	}
}
void best_npg(int data[][COLS]) {

	int max = 0;
	for (int i = 0; i < 4; i++) {
		if (data[0][i] * data[2][i] - data[1][i] * data[2][i] > max)
			max = data[0][i] * data[2][i] - data[1][i] * data[2][i];
	}
	for (int i = 0; i < 4; i++) {
		if (data[0][i] * data[2][i] - data[1][i] * data[2][i] == max)
		{
			if (i == 0)
				printf("A\n");
			else if (i == 1)
				printf("B\n");
			else if (i == 2)
				printf("C\n");
			else if (i == 3)
				printf("D\n");
		}
	}
}
