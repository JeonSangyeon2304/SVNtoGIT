#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int main(void) {
	int money = 5000, bat, hours[3], b_hours;
	int buffer[3];
	int i, j;
	int max;

	while (1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("도박은 자신과 가정을 파괴시킵니다.\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		printf("소지금 : %d ", money);
		printf("배팅하시오 : ");
		scanf("%d", &bat);

		money = money - bat;

		srand((unsigned)time(NULL));
		do {
			hours[0] = rand() % 9 + 1;
			hours[1] = rand() % 9 + 1;
			hours[2] = rand() % 9 + 1;
		} while (hours[0] == hours[1] || hours[1] == hours[2] || hours[2] == hours[3]);
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("[1번마], [2번마], [3번마]\n");
		printf("말을 선택하시오 : ");
		scanf("%d", &b_hours);
		system("cls");

		buffer[0] = hours[0];
		buffer[1] = hours[1];
		buffer[2] = hours[2];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		printf("경기중입니다.\n");
		printf("-------------------------------------\n");
		printf("|  [1번마]  |  [2번마]  |  [3번마]  |\n");
		for (i = 0; i < 9; i++) {
			Sleep(50);
			if (buffer[0] != 0 && buffer[1] != 0 && buffer[2] != 0) {
				printf("|     ~     |     ~     |     ~     |\n");
				buffer[0] -= 1;
				buffer[1] -= 1;
				buffer[2] -= 1;
			}
			else if (buffer[0] == 0 && buffer[1] != 0 && buffer[2] != 0) {
				printf("|           |     ~     |     ~     |\n");
				buffer[1] -= 1;
				buffer[2] -= 1;
			}
			else if (buffer[0] != 0 && buffer[1] == 0 && buffer[2] != 0) {
				printf("|     ~     |           |     ~     |\n");
				buffer[0] -= 1;
				buffer[2] -= 1;
			}
			else if (buffer[0] != 0 && buffer[1] != 0 && buffer[2] == 0) {
				printf("|     ~     |     ~     |           |\n");
				buffer[0] -= 1;
				buffer[1] -= 1;
			}
			else if (buffer[0] != 0 && buffer[1] == 0 && buffer[2] == 0) {
				printf("|     ~     |           |           |\n");
				buffer[0] -= 1;
			}
			else if (buffer[0] == 0 && buffer[1] != 0 && buffer[2] == 0) {
				printf("|           |     ~     |           |\n");
				buffer[1] -= 1;
			}
			else if (buffer[0] == 0 && buffer[1] == 0 && buffer[2] != 0) {
				printf("|           |           |     ~     |\n");
				buffer[2] -= 1;
			}
			else
				printf("|           |           |           |\n");

		}
		printf("-------------------------------------\n");
		
		max = hours[0];
		for (i = 0; i < 3; i++) {
			if (max < hours[i])
				max = hours[i];
		}

		if (b_hours == max)	{
			printf("당첨입니다.\n");
			printf("당첨금은 %d원 입니다.\n", bat * 3);
			printf("소지금 : %d\n", money+(bat*3));
			money = money + (bat * 3);
			system("pause");
			system("cls");
		}
		else {
			printf("베팅금액을 잃었습니다.\n");
			printf("소지금 : %d\n", money);
			system("pause");
			system("cls");
		}

		if (money == 0)	{
			printf("소지금을 모두 잃으셧습니다.\n");
			system("cls");
			printf("다시 시작하시겟습니까?\n");
			printf("1.Yes 2.No : ");
			scanf("%d", &j);
			if (j == 1)	{
				system("cls");
				return main();
			}
			else if (j==2)
				exit(0);
		}
	}
}