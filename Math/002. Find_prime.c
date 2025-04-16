/*
문제 번호 : 1978
문제 링크 : https://www.acmicpc.net/problem/1978
컴파일러 버전 : gcc 11.3.1
*/
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int N, num, count = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        if (is_prime(num)) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
