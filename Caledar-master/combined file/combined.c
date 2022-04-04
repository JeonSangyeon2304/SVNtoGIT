#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* variable*/
int log = 0; //Variable to use check log in
int Y, M, D, h; //년, 월, 일, 시, 분, 초/* 달력 변수 */
int L; //하루동안 지난 초/* 달력 변수 */
int T; //1970년 1월 1일 이후의 초/* 달력 변수 */
int i, a, b;/* 달력 변수 */
int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //1달의 일수 (1월~12월)/* 달력 변수 */
int p, j, d;/* 달력 변수 */
int totalday = 0;/* 달력 변수 */
int k;/* 달력 변수 */
char di[100];

/* function */
void n_cli();
void cli();
void calendar();		/* Function calendar */
void diary();			/* Function calendar */
void Cal();				/* Function calendar */
void diary_main();		/* Function calendar */
void save();

int main(void) {
	int select;
	printf("\n");
	printf("\t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("\t◇                                                            ◇\n");
	printf("\t◇  ■■  ■■  ■    ■                                      ◇\n");
	printf("\t◇  ■  ■  ■   ■  ■                                       ◇\n");
	printf("\t◇  ■      ■     ■                                         ◇\n");
	printf("\t◇  ■      ■     ■                                         ◇\n");
	printf("\t◇                                                            ◇\n");
	printf("\t◇                      ■■■   ■■  ■■■  ■■■ ■  ■  ◇\n");
	printf("\t◇                      ■   ■ ■  ■   ■    ■  ■  ■■   ◇\n");
	printf("\t◇                      ■   ■ ■■■   ■    ■■     ■    ◇\n");
	printf("\t◇                      ■■■  ■  ■ ■■■  ■  ■   ■    ◇\n");
	printf("\t◇                                                            ◇\n");
	printf("\t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("\t  ┌──┬───────────┐\n");
	printf("\t  │ 1│ New       │\n");
	printf("\t  ├──┼───────────┤\n");
	printf("\t  │ 2│ Continue  │\n");
	printf("\t  ├──┼───────────┤\n");
	printf("\t  │ 3│ exit      │\n");
	printf("\t  └──┴───────────┘\n");
	printf("\t  ▷▷ ");
	scanf("%d", &select);
	printf("\n\t");

	switch (select)	{
	case 1: n_cli();
		break;
	case 2: cli();
		break;
	case 3: exit(0);
	default:
		do {
			if (select = 1)	{
				system("cls");
				return main();
			}
		} while (1);
	}
}


void n_cli() {
	char pw[101];
	system("cls");
	printf("\n\n");
	printf("\t┌──────────┐\n");
	printf("\t│ Join  us │\n");
	printf("\t└──────────┘\n");
	printf("\t  Enter  PassWord : ");
	scanf("%s",&pw);
	fflush(stdin);
	
	FILE *fp = fopen("list.txt", "wb");
	fprintf(fp, pw);
	fclose(fp);
	calendar();
}


void cli() {
	int select;
	char re_pw[101];
	char pw[101];
	system("cls");
	printf("\n\n");
	printf("\t┌─────────┐\n");
	printf("\t│  Log in │\n");
	printf("\t├─────────┴─────────────────────────────────────┐\n");
	printf("\t│  PW를 잊어버리셧다면 개발자에게 연락바랍니다. │\n");
	printf("\t└───────────────────────────────────────────────┘\n");
	printf("\t  Enter Password (4자리 숫자로 입력해 주세요) : ");
	scanf("%s", &pw);
	printf("\n");
	
	printf("\t로그인 중...");		//딜레이

	FILE *fpw = fopen("List.txt", "rb");
	fscanf(fpw, "%s", re_pw);
	fclose(fpw);
	if (strcmp(pw, re_pw))
		log = 1;
	else
		log = 0;

	switch (log) {
	case 0: printf("\r\t로그인 성공\n");
		calendar();
		break;

	case 1: printf("\t로그인 실패\n");
		printf("\t다시 로그인 하시겠습니까?\n");
		printf("\t1.Y 2.N : ");
		scanf("%d", &select);
		switch (select) {
		case 1: system("cls");
			return cli();
		case 2: system("cls");
			return main();
		default:
			do {
				if (select = 1)	{
					system("cls");
					return main();
				}
			} while (1);
		}
		break;
	}
}


void calendar(){ 
	system("cls");
	T = (int)time(NULL) + 3600 * 9 + 60;
	/*1970년 1월 1일(세계 표준시 UTC기준)이후의 초(컴퓨터 시계랑 연동),	+86400*9+60*0 = 대한민국 표준시*/

	D = (int)T / 86400 + 1; //일, 1970년1월1일00시00분00초 = 0일, 1970년1월2일00시00분00초 = 1일
	L = (int)T % 86400; //하루동안 지난 초
	h = (int)T % 86400 / 3600; //시간

	for (i = 0; 1; i++) {//년도 계산 + 일수 계산
		Y = 1970 + i;

		if (((Y % 4 == 0) && (Y % 100 != 0)) || (Y % 400 == 0)) { //윤년계산
			if (D <= 366) { //일수가 366이하 일 경우(년단위 계산 범위가 아닐 경우)
				for (M = 0; 1; M++) { //월 계산 + 일수 계산
					if (Y % 4 == 0 && Y % 100 != 0 || Y % 400 == 0) //윤년이면
						month[1] = 29; //2월달은 29일까지
					else
						month[1] = 28; //윤년이 아니면 2워달은 28일까지
					if (D > month[M]) //일수가 월단위 보다 클 경우
						D -= month[M]; //해당 월의 일수를 뺌
					else { //일수가 월단위보다 작을 경우
						M += 1; //배열 번호에서 실제 월로 변환
						printf("┌──────────┬──────────────────┐\n");
						printf("│ 현재시간 │ %d년 %2d월 %2d일 │\n", Y, M, D);
						printf("└──────────┴──────────────────┘\n\n");

						Cal();//달력함수 호출
					}
				}
			}
			else
				D -= 366; //일수에서 해당 년도의 일수를 뺌
		}
		else{ //윤년이 아닐경우
			if (D <= 365) {//일수가 365이하 일 경우(년단위 계산 범위가 아닐 경우)
				for (M = 0; 1; M++) {//월 계산 + 일수 계산
					if (Y % 4 == 0 && Y % 100 != 0 || Y % 400 == 0) //윤년이면
						month[1] = 29; //2월달은 29일까지
					else
						month[1] = 28; //윤년이 아니면 2워달은 28일까지
					if (D > month[M]) //일수가 월단위 보다 클 경우
						D -= month[M]; //해당 월의 일수를 뺌
					else {//일수가 월단위보다 작을 경우
						M += 1; //배열 번호에서 실제 월로 변환
						printf("┌──────────┬──────────────────┐\n");
						printf("│ 현재시간 │ %d년 %2d월 %2d일 │\n", Y, M, D);
						printf("└──────────┴──────────────────┘\n\n");
						printf("\t              %d년 %d월 %d일\n", Y, M, D);
						
						Cal();//달력함수 호출
					}
				}
			}
			else
				D -= 365; //일수에서 해당 년도의 일수를 뺌
		}
	}
}


void Cal() {//달력
	printf("\t┌────┬────┬────┬────┬────┬────┬────┐\n");
	printf("\t│ Sun│ Mon│ Tue│ Wed│ Thu│ Fri│ Sat│\n");
	printf("\t└────┴────┴────┴────┴────┴────┴────┘\n");
	printf("\t￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣\n");
	printf("\t￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣\n");
	printf("\t");
	//전달까지의 일수 계산함수 호출
	totalday = (Y - 1) * 365 + (Y - 1) / 4 - (Y - 1) / 100 + (Y - 1) / 400; //전년도까지의 일수

	for (k = 1; k <= M - 1; k++)
		totalday = totalday + month[k - 1]; //전달까지의 일수

	//달력출력함수 호출
	int H = 1;
	for (p = 1; p <= 6; p++) {//주차(최대 6주)
		for (j = 1; j <= 7; j++, H++) {//요일(월~일)
			if (H <= month[M - 1] + 1 + totalday % 7) {//해당 월의 초과일수보다 출력해야할 일수가 적을 경우
				d = H - totalday % 7; //자리(1~42자리까지-달력으로는 36까지)
				if (d - 1 <= 0)  //1이 안됄경우
					printf("      "); //빈공간으로 둠
				else
					printf("  %3d ", d - 1); //일 표시(자리수 맞춤)
			}
		}
		printf("\n\t"); //주 바꿈
	}
	diary_main();
}


void diary_main() {
	int select = 0;
	printf("￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣\n");
	printf("\t  1.오늘 할 일\n");
	printf("\t  2.다른날 할 일 수정\n");
	printf("\t  3.나가기\n");
	printf("\t  ▶▶");
	scanf("%d", &select);
	printf("\n");

	switch (select) {
	case 1: diary();
		break;
	case 2: system("cls");
		printf("\n");
		printf("\t┌──────────┐\n");
		printf("\t│  다른날  │\n");
		printf("\t└──────────┘\n\t ");
		printf("\t  Enter YYYY M D : ");
		scanf("%d %d %d", &Y, &M, &D);
		diary();
		break;
	case 3:
		system("cls");
		return main();
	default:
		do {
			if (select = 1)	{
				system("cls");
				return calendar();
			}
		} while (1);
	}
}
void diary() {
	int select;
	char buffer[] = "";
	char today[] = "";
	char year[10];
	char mounth[10];
	char day[10];
	int len;
	sprintf(year, "%d", Y);
	sprintf(mounth, "%d", M);
	sprintf(day, "%d", D);

	strcat(today, year);
	strcat(today, "년-");
	strcat(today, mounth);
	strcat(today, "월-");
	strcat(today, day);
	strcat(today, "일");
	
	system("cls");
	FILE *rfp = NULL;
	rfp = fopen("diary.txt", "r");
	if (!(rfp == NULL)) {
		while (!feof(rfp)) {
			fgets(buffer, 1000, rfp);
			len = strlen(buffer);
			buffer[len+1] = '\n';
			if (strcmp(buffer, today)) {
				system("cls");
				printf("\n\t┟──────────────────┧\n");
				printf("\t│ %d년 %2d월 %2d일 │\n", Y, M, D);
				printf("\t┞──────────────────┦\n");
				printf("\t이미 내용이 있습니다.\n");
				fseek(rfp, len, SEEK_CUR);
				fgets(buffer, 1000, rfp);
				printf("%s", buffer);
				fclose(rfp);
				do {
					printf("\n1. 돌아가기\n");
					printf("\t▶▶");
					scanf("%d", &select);
					if (select == 1)
						return calendar();
				} while (select == 1);


			}
			else {
				system("cls");
				printf("\n\t┟──────────────────┧\n");
				printf("\t│ %d년 %2d월 %2d일 │\n", Y, M, D);
				printf("\t┞──────────────────┦\n");
				printf("\t20내외로 쓰세요\n");
				printf("───────────────────────────────\n");
				scanf("%s", di);
				printf("───────────────────────────────\n\t");
				printf("1.저장\n");
				printf("\t2.취소\n");
				printf("\t▶▶");
				scanf("%d", &select);
				fclose(rfp);
				switch (select) {
				case 1:
					save();
					printf("저장중....\n");
					return calendar();
				case 2: return calendar();
				}
			}
		}
		
	}
}
void save() {
	FILE *fp = NULL;
	fp = fopen("diary.txt", "a");
	fprintf(fp, "%d년-%d월-%d일\n%s\n", Y, M, D, di);
	fclose(fp);
}