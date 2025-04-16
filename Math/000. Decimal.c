/*
문제 번호 : 2581
문제 링크 : https://www.acmicpc.net/problem/2581
컴파일러 버전 : gcc 11.3.1
*/
#include <stdio.h>

int main() {
    int min_num, max_num;
    scanf("%d", &min_num);
    scanf("%d", &max_num);

    int total = 0;
    int min = -1;

    for (int n = min_num; n <= max_num; n++) {
        int count = 0;

        if (n < 2) continue;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) count++;
        }

        if (count == 2) {
            total += n;
            if (min == -1) {
                min = n;
            }
        }
    }

    if (min == -1) {
        printf("-1\n");
    } else {
        printf("%d\n", total);
        printf("%d\n", min);
    }

    return 0;
}
