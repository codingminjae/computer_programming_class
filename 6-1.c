/*입력받은 정수 n에 대한 팩토리얼 값을 계산 하여 출력하는 프로그램을 작성해보세요. 
(순환호출 이용) 
*/

#include <stdio.h>
double factorial(int n) {
    if (n == 1)
        return 1.0;
    else
        return factorial(n - 1) * n; // 재귀 호출
}
int main() {
    int number;
    double result;
    printf("정수를 입력하세요: ");
    scanf("%d", &number);
    result = factorial(number);
    printf("%d! = %.0f\n", number, result);
    return 0;
}
