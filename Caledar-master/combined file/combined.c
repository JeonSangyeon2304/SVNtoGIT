#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* variable*/
int log = 0; //Variable to use check log in
int Y, M, D, h; //��, ��, ��, ��, ��, ��/* �޷� ���� */
int L; //�Ϸ絿�� ���� ��/* �޷� ���� */
int T; //1970�� 1�� 1�� ������ ��/* �޷� ���� */
int i, a, b;/* �޷� ���� */
int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //1���� �ϼ� (1��~12��)/* �޷� ���� */
int p, j, d;/* �޷� ���� */
int totalday = 0;/* �޷� ���� */
int k;/* �޷� ���� */
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
	printf("\t�ޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡ�\n");
	printf("\t��                                                            ��\n");
	printf("\t��  ���  ���  ��    ��                                      ��\n");
	printf("\t��  ��  ��  ��   ��  ��                                       ��\n");
	printf("\t��  ��      ��     ��                                         ��\n");
	printf("\t��  ��      ��     ��                                         ��\n");
	printf("\t��                                                            ��\n");
	printf("\t��                      ����   ���  ����  ���� ��  ��  ��\n");
	printf("\t��                      ��   �� ��  ��   ��    ��  ��  ���   ��\n");
	printf("\t��                      ��   �� ����   ��    ���     ��    ��\n");
	printf("\t��                      ����  ��  �� ����  ��  ��   ��    ��\n");
	printf("\t��                                                            ��\n");
	printf("\t�ޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡ�\n");
	printf("\t  ��������������������������������\n");
	printf("\t  �� 1�� New       ��\n");
	printf("\t  ��������������������������������\n");
	printf("\t  �� 2�� Continue  ��\n");
	printf("\t  ��������������������������������\n");
	printf("\t  �� 3�� exit      ��\n");
	printf("\t  ��������������������������������\n");
	printf("\t  ���� ");
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
	printf("\t������������������������\n");
	printf("\t�� Join  us ��\n");
	printf("\t������������������������\n");
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
	printf("\t����������������������\n");
	printf("\t��  Log in ��\n");
	printf("\t��������������������������������������������������������������������������������������������������\n");
	printf("\t��  PW�� �ؾ�����˴ٸ� �����ڿ��� �����ٶ��ϴ�. ��\n");
	printf("\t��������������������������������������������������������������������������������������������������\n");
	printf("\t  Enter Password (4�ڸ� ���ڷ� �Է��� �ּ���) : ");
	scanf("%s", &pw);
	printf("\n");
	
	printf("\t�α��� ��...");		//������

	FILE *fpw = fopen("List.txt", "rb");
	fscanf(fpw, "%s", re_pw);
	fclose(fpw);
	if (strcmp(pw, re_pw))
		log = 1;
	else
		log = 0;

	switch (log) {
	case 0: printf("\r\t�α��� ����\n");
		calendar();
		break;

	case 1: printf("\t�α��� ����\n");
		printf("\t�ٽ� �α��� �Ͻðڽ��ϱ�?\n");
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
	/*1970�� 1�� 1��(���� ǥ�ؽ� UTC����)������ ��(��ǻ�� �ð�� ����),	+86400*9+60*0 = ���ѹα� ǥ�ؽ�*/

	D = (int)T / 86400 + 1; //��, 1970��1��1��00��00��00�� = 0��, 1970��1��2��00��00��00�� = 1��
	L = (int)T % 86400; //�Ϸ絿�� ���� ��
	h = (int)T % 86400 / 3600; //�ð�

	for (i = 0; 1; i++) {//�⵵ ��� + �ϼ� ���
		Y = 1970 + i;

		if (((Y % 4 == 0) && (Y % 100 != 0)) || (Y % 400 == 0)) { //������
			if (D <= 366) { //�ϼ��� 366���� �� ���(����� ��� ������ �ƴ� ���)
				for (M = 0; 1; M++) { //�� ��� + �ϼ� ���
					if (Y % 4 == 0 && Y % 100 != 0 || Y % 400 == 0) //�����̸�
						month[1] = 29; //2������ 29�ϱ���
					else
						month[1] = 28; //������ �ƴϸ� 2������ 28�ϱ���
					if (D > month[M]) //�ϼ��� ������ ���� Ŭ ���
						D -= month[M]; //�ش� ���� �ϼ��� ��
					else { //�ϼ��� ���������� ���� ���
						M += 1; //�迭 ��ȣ���� ���� ���� ��ȯ
						printf("��������������������������������������������������������������\n");
						printf("�� ����ð� �� %d�� %2d�� %2d�� ��\n", Y, M, D);
						printf("��������������������������������������������������������������\n\n");

						Cal();//�޷��Լ� ȣ��
					}
				}
			}
			else
				D -= 366; //�ϼ����� �ش� �⵵�� �ϼ��� ��
		}
		else{ //������ �ƴҰ��
			if (D <= 365) {//�ϼ��� 365���� �� ���(����� ��� ������ �ƴ� ���)
				for (M = 0; 1; M++) {//�� ��� + �ϼ� ���
					if (Y % 4 == 0 && Y % 100 != 0 || Y % 400 == 0) //�����̸�
						month[1] = 29; //2������ 29�ϱ���
					else
						month[1] = 28; //������ �ƴϸ� 2������ 28�ϱ���
					if (D > month[M]) //�ϼ��� ������ ���� Ŭ ���
						D -= month[M]; //�ش� ���� �ϼ��� ��
					else {//�ϼ��� ���������� ���� ���
						M += 1; //�迭 ��ȣ���� ���� ���� ��ȯ
						printf("��������������������������������������������������������������\n");
						printf("�� ����ð� �� %d�� %2d�� %2d�� ��\n", Y, M, D);
						printf("��������������������������������������������������������������\n\n");
						printf("\t              %d�� %d�� %d��\n", Y, M, D);
						
						Cal();//�޷��Լ� ȣ��
					}
				}
			}
			else
				D -= 365; //�ϼ����� �ش� �⵵�� �ϼ��� ��
		}
	}
}


void Cal() {//�޷�
	printf("\t������������������������������������������������������������������������\n");
	printf("\t�� Sun�� Mon�� Tue�� Wed�� Thu�� Fri�� Sat��\n");
	printf("\t������������������������������������������������������������������������\n");
	printf("\t��������������������������������������������\n");
	printf("\t��������������������������������������������\n");
	printf("\t");
	//���ޱ����� �ϼ� ����Լ� ȣ��
	totalday = (Y - 1) * 365 + (Y - 1) / 4 - (Y - 1) / 100 + (Y - 1) / 400; //���⵵������ �ϼ�

	for (k = 1; k <= M - 1; k++)
		totalday = totalday + month[k - 1]; //���ޱ����� �ϼ�

	//�޷�����Լ� ȣ��
	int H = 1;
	for (p = 1; p <= 6; p++) {//����(�ִ� 6��)
		for (j = 1; j <= 7; j++, H++) {//����(��~��)
			if (H <= month[M - 1] + 1 + totalday % 7) {//�ش� ���� �ʰ��ϼ����� ����ؾ��� �ϼ��� ���� ���
				d = H - totalday % 7; //�ڸ�(1~42�ڸ�����-�޷����δ� 36����)
				if (d - 1 <= 0)  //1�� �ȉư��
					printf("      "); //��������� ��
				else
					printf("  %3d ", d - 1); //�� ǥ��(�ڸ��� ����)
			}
		}
		printf("\n\t"); //�� �ٲ�
	}
	diary_main();
}


void diary_main() {
	int select = 0;
	printf("��������������������������������������������\n");
	printf("\t  1.���� �� ��\n");
	printf("\t  2.�ٸ��� �� �� ����\n");
	printf("\t  3.������\n");
	printf("\t  ����");
	scanf("%d", &select);
	printf("\n");

	switch (select) {
	case 1: diary();
		break;
	case 2: system("cls");
		printf("\n");
		printf("\t������������������������\n");
		printf("\t��  �ٸ���  ��\n");
		printf("\t������������������������\n\t ");
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
	strcat(today, "��-");
	strcat(today, mounth);
	strcat(today, "��-");
	strcat(today, day);
	strcat(today, "��");
	
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
				printf("\n\t�ʦ�������������������������������������\n");
				printf("\t�� %d�� %2d�� %2d�� ��\n", Y, M, D);
				printf("\t�ɦ�������������������������������������\n");
				printf("\t�̹� ������ �ֽ��ϴ�.\n");
				fseek(rfp, len, SEEK_CUR);
				fgets(buffer, 1000, rfp);
				printf("%s", buffer);
				fclose(rfp);
				do {
					printf("\n1. ���ư���\n");
					printf("\t����");
					scanf("%d", &select);
					if (select == 1)
						return calendar();
				} while (select == 1);


			}
			else {
				system("cls");
				printf("\n\t�ʦ�������������������������������������\n");
				printf("\t�� %d�� %2d�� %2d�� ��\n", Y, M, D);
				printf("\t�ɦ�������������������������������������\n");
				printf("\t20���ܷ� ������\n");
				printf("��������������������������������������������������������������\n");
				scanf("%s", di);
				printf("��������������������������������������������������������������\n\t");
				printf("1.����\n");
				printf("\t2.���\n");
				printf("\t����");
				scanf("%d", &select);
				fclose(rfp);
				switch (select) {
				case 1:
					save();
					printf("������....\n");
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
	fprintf(fp, "%d��-%d��-%d��\n%s\n", Y, M, D, di);
	fclose(fp);
}