/*
문제 번호 : 22864
문제 링크 : https://www.acmicpc.net/problem/22864
컴파일러 버전 : gcc 11.3.1
*/
#include <stdio.h>

#define Day 24

int main() {
    int up_fatigue, work, down_fatigue, max_fatigue;
    scanf("%d", &up_fatigue);
    scanf("%d", &work);
    scanf("%d", &down_fatigue);
    scanf("%d", &max_fatigue);

    int now_fatigue = 0;
    int work_done = 0;

    for (int hour = 0; hour < Day; hour++) {
        if (now_fatigue + up_fatigue <= max_fatigue) {
            now_fatigue += up_fatigue;
            work_done += work;
        } else {
            now_fatigue -= down_fatigue;
            if (now_fatigue < 0) {
                now_fatigue = 0;
            }
        }
    }

    printf("%d\n", work_done);
    return 0;
}
