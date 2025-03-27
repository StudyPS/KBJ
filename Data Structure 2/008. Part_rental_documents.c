/*
문제 번호 : 21944
문제 링크 : https://www.acmicpc.net/problem/21944
컴파일러 버전 : gcc 11.3.1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 80000
#define NAME_LEN 21
#define PART_LEN 21
#define DATE_LEN 17

typedef struct {
    char member[NAME_LEN];
    int fine;
} FineInfo;

typedef struct {
    char member[NAME_LEN];
    char part[PART_LEN];
    time_t borrow_time;
} BorrowInfo;

BorrowInfo borrowed[MAX_ENTRIES];  // 대여 정보 저장
FineInfo fines[MAX_ENTRIES];       // 벌금 정보 저장
int borrow_count = 0, fine_count = 0;
int F;
time_t loan_period;

// 문자열 날짜를 time_t로 변환
time_t parse_time(const char *date, const char *time) {
    struct tm tm_time = {0};  // 구조체 초기화

    sscanf(date, "%4d-%2d-%2d", &tm_time.tm_year, &tm_time.tm_mon,
           &tm_time.tm_mday);
    sscanf(time, "%2d:%2d", &tm_time.tm_hour, &tm_time.tm_min);

    tm_time.tm_year -= 1900;  // 연도 조정
    tm_time.tm_mon -= 1;      // 월 조정

    return mktime(&tm_time);
}

// 벌금 추가 (이미 있는 회원이면 누적)
void add_fine(char *member, int amount) {
    for (int i = 0; i < fine_count; i++) {
        if (strcmp(fines[i].member, member) == 0) {
            fines[i].fine += amount;
            return;
        }
    }
    strcpy(fines[fine_count].member, member);
    fines[fine_count].fine = amount;
    fine_count++;
}

// 대여 기록 삭제
void remove_borrow(char *member, char *part) {
    for (int i = 0; i < borrow_count; i++) {
        if (strcmp(borrowed[i].member, member) == 0 &&
            strcmp(borrowed[i].part, part) == 0) {
            borrowed[i] = borrowed[--borrow_count];
            return;
        }
    }
}

// 벌금 정보 정렬 함수 (이름 기준)
int compare_fines(const void *a, const void *b) {
    return strcmp(((FineInfo *)a)->member, ((FineInfo *)b)->member);
}

int main() {
    int N, days, hours, minutes;
    char period[10];

    // 입력 받기
    scanf("%d %s %d", &N, period, &F);
    sscanf(period, "%d/%d:%d", &days, &hours, &minutes);
    loan_period = (days * 24 * 60 + hours * 60 + minutes) * 60;  // 초 단위 변환

    for (int i = 0; i < N; i++) {
        char date[DATE_LEN], time[PART_LEN], part[PART_LEN], member[NAME_LEN];
        scanf("%s %s %s %s", date, time, part, member);
        time_t time_stamp = parse_time(date, time);

        // 이미 대여 중인지 확인
        int found = -1;
        for (int j = 0; j < borrow_count; j++) {
            if (strcmp(borrowed[j].member, member) == 0 &&
                strcmp(borrowed[j].part, part) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {  // 반납 처리
            time_t borrow_time = borrowed[found].borrow_time;
            time_t due_time = borrow_time + loan_period;
            double delay = difftime(time_stamp, due_time) / 60;  // 분 단위 변환

            if (delay > 0) {
                add_fine(member, (int)delay * F);
            }
            remove_borrow(member, part);
        } else {  // 대여 처리
            strcpy(borrowed[borrow_count].member, member);
            strcpy(borrowed[borrow_count].part, part);
            borrowed[borrow_count].borrow_time = time_stamp;
            borrow_count++;
        }
    }

    // 벌금 내야 할 사람 정렬 후 출력
    if (fine_count == 0) {
        printf("-1\n");
    } else {
        qsort(fines, fine_count, sizeof(FineInfo), compare_fines);
        for (int i = 0; i < fine_count; i++) {
            printf("%s %d\n", fines[i].member, fines[i].fine);
        }
    }

    return 0;
}
