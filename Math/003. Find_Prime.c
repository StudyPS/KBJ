/*
문제 번호 : 2745
문제 링크 : https://www.acmicpc.net/problem/2745
컴파일러 버전 : gcc 11.3.1
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char N[36];
    int B, result = 0, power = 1;

    scanf("%s %d", N, &B);
    int len = strlen(N);

    // 오른쪽부터 왼쪽으로 자릿수 처리
    for (int i = len - 1; i >= 0; i--) {
        int digit;
        if (N[i] >= '0' && N[i] <= '9') {
            digit = N[i] - '0';
        } else {
            digit = N[i] - 'A' + 10;
        }

        result += digit * power;
        power *= B;
    }

    printf("%d\n", result);
    return 0;
}
