/*는 다음과 같은 무한급수로 정의 됩니다. 

이 급수를 일정한 항수까지 계산하면 근사값을 얻을 수 있습니다. 

위 수식을 코드로 구현하여 값을 구하고, c언어 라이브러리 함수 exp()의 값을 이용하여 두 값의 오차를 출력해 보세요. */

#include <stdio.h>
#include <math.h>	// exp(), fabs() 함수 선언
void main() {
    int n;
    double nexp, newexp, oldexp, fact;
    nexp = exp(1.0);		// 자연대수 e (라이브러리 함수 사용)
    printf(" n  자연대수              계산                 오차\n");
    printf("================================================================\n");
    n = 1;			// 변수 초기화
    newexp = 0;			// 새로 계산할 자연대수
    oldexp = -1.0;	  // 이전 자연대수. 초기에 oldexp와 newexp를 다르게 설정한다.
    fact = 1.0;	// 팩토리얼
    while (oldexp != newexp) {  // 이전 값과 새로운 값이 다르면 계속 반복
        oldexp = newexp;		// 이전 값으로 저장한다.
        newexp = newexp + 1.0 / fact;	// 새로 계산한다.
        printf("%2d  %20.18lf  %20.18lf  %20.18lf\n", n, nexp, newexp, fabs(nexp-newexp)); // 출력
        fact = fact * (double)n;		// 다음을 위하여 팩토리얼을 미리 계산한다.
        n = n + 1;			// n을 증가시킨다.
    }
}
