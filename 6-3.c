/*두 개의 무한 수열을 사용하여 원주율의 값을 구하고 실제 원주율 값과 오차를 출력하는 프로그램을 작성해보세요. (항의 수가 많아질수록 원주율의 값에 가까운 근사치를 구할 수 있습니다.) 





원주율을 10,000 항까지 계산하고, 1,000 항마다 결과를 출력합니다.
원주율을 소수점 8째 자리까지 출력합니다.*/

#include <stdio.h>
#include <math.h>
void main() {
    int n, sign;
    double PI, pi1, pi2, pi2sqr;
    PI = 4.0 * atan(1.0);			// 원주율 계산 
    printf("원주율 = %10.8lf\n", PI);	// 원주율 출력
    printf("===================================================================\n");
    printf("항의 수\t공식1\t\t오차\t\t공식2\t\t오차\n");   // 제목 줄 출력
    printf("===================================================================\n");
    pi1 = 0.0;		// 첫 번째 공식
    pi2sqr = 0.0;	// 두 번째 공식
    sign = -1;		// 부호 초기화
    for (n = 1; n <= 10000; n++) {
        sign *= -1;	// 부호
        pi1 += (double)sign * 4.0 / (2.0 * (double)n - 1.);   // 첫 번째 공식
        pi2sqr += 6.0 / ((double)n * (double)n);	// 두 번째 공식
        pi2 = sqrt(pi2sqr);
        if ((n % 1000) == 0)	// 1,000 항마다
            printf("%6d\t%10.8lf\t%10.8lf\t%10.8lf\t%10.8lf\n", n, pi1, fabs(PI - pi1), pi2, fabs(PI - pi2)); // 결과 출력
    }
}