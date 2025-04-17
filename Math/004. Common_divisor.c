/*
문제 번호 : 5618
문제 링크 : https://www.acmicpc.net/problem/5618
컴파일러 버전 : gcc 11.3.1
*/
#include <stdio.h>

#define MAX_SIZE 100

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    int N;
    int Num[MAX_SIZE] = {};

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &Num[i]);
    }

    int g = Num[0];
    for (int i = 1; i < N; i++) {
        g = gcd(g, Num[i]);
    }

    for (int i = 1; i <= g; i++) {
        if (g % i == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}
