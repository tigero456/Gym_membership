#include <windows.h>
#include <conio.h>
#include <stdio.h>
#define MAX_MEMBER 100

typedef struct user {
	char name[10];
	char age[3];
	char number[10];
	char item[10];
	char gender[1];
	char membership[1];
	char adress[30];
}User;

User member[MAX_MEMBER] = { 0, };

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void MenuUi() {
	int  i, j, x = 1, y = 1;

	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 30; i++) {
		printf("��");
	}
	printf("��");

	for (i = 0; i < 17; i++) {
		y++;
		gotoxy(x, y);
		printf("��");

		if (i == 3) {
			gotoxy(3, i);
			printf("C��� ����������� �����");
			gotoxy(8, i + 1);
			printf("�ｺ�� ȸ������ ���α׷�");
			gotoxy(3, 6);
			for (j = 0; j < 30; j++) {
				printf("��");
			}
		}

		if (i == 8) {
			gotoxy(5, i);
			printf("1) ȸ�����");
			gotoxy(5, i + 2);
			printf("2) ȸ������ ����");
			gotoxy(5, i + 4);
			printf("3) ȸ������ �˻�");
			gotoxy(5, i + 6);
			printf("4) ȸ�� Ż��(ȯ��)");
			gotoxy(5, i + 8);
			printf("5) ����");
		}

		x += 31;
		gotoxy(x, y);
		printf("��");
		x = 1;
	}
	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 30; i++) {
		printf("��");
	}
	printf("��\n\n");

}

int Mnumber() {
	int number;

	printf("�޴� ��ȣ�� �Է����ּ���... ");
	scanf("%d", &number);

	return number;
}

void Userinput() {
	char name[10];
	char age[3];
	char number[10];
	int item;
	char gender[1];
	char membership[1];
	char adress[30];
	char date[8];
	system("cls");
	int i, j, x = 1, y = 1;

	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 50; i++) {
		printf("��");
	}
	printf("��");

	for (i = 0; i < 24; i++) {
		y++;
		gotoxy(x, y);
		printf("��");

		if (i == 3) {
			gotoxy(19, i);
			printf("��ȸ������ ��ϡ�");
			gotoxy(3, 5);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
		}

		if (i == 7) {
			gotoxy(5, i);
			printf("����");
			gotoxy(20, i);
			scanf("%s", &name);
			gotoxy(31, i);
			printf("����");
			gotoxy(45, i);
			scanf("%s", &age);
			gotoxy(3, i+2);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
			gotoxy(5, i + 4);
			printf("����ó");
			gotoxy(5, i + 5);
			printf("('-' ���� �Է�)");
			gotoxy(15, i + 4);
			scanf("%s", &number);
			gotoxy(31, i + 4);
			printf("ȸ����");
			gotoxy(31, i + 5);
			printf("(��ȣ�� �Է�)");
			gotoxy(54, i + 1);
			for (j = 0; j < 17; j++) {
				printf("��");
			}
			printf("��");
			gotoxy(54, i + 2);
			printf("1) 1����   3���� ��");
			gotoxy(54, i + 3);
			printf("                 ��");
			gotoxy(54, i + 4); 
			printf("2) 3����   8���� ��");
			gotoxy(54, i + 5);
			printf("                 ��");
			gotoxy(54, i + 6);
			printf("3) 6����  15���� ��");
			gotoxy(54, i + 7);
			printf("                 ��");
			gotoxy(54, i + 8);
			printf("4) 12���� 25���� ��");
			gotoxy(54, i + 9);
			for (j = 0; j < 17; j++) {
				printf("��");
			}
			gotoxy(45, i + 4);
			scanf("%s", &membership);
			gotoxy(3, i+6);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
			gotoxy(5, i + 8);
			printf("����(��/��)");
			gotoxy(20, i + 8);
			scanf("%s", &gender);
			gotoxy(3, i+10);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
			gotoxy(5, i + 12);
			printf("�ּ�");
			gotoxy(15, i + 12);
			scanf("%s", &adress);
			gotoxy(3, i+14);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
			gotoxy(5, i + 16);
			printf("�����");
			gotoxy(5, i + 17);
			printf("��/��/�� ex) 20220104");
			gotoxy(15, i + 16);
			scanf("%s", &date);
			
		}

		x += 51;
		gotoxy(x, y);
		printf("��");
		x = 1;
	}
	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 50; i++) {
		printf("��");
	}
	printf("��\n\n");
	_getch();
}

void Usercorr() {
	printf("cc");
	_getch();
}

void Usersearch() {
	char searchname[10];
	char searchnumber[10];
	char name[10];
	char age[3];
	char number[10];
	int item;
	char gender[1];
	char membership[1];
	char adress[30];
	char date[8];
	system("cls");
	int i, j, x = 1, y = 1;

	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 50; i++) {
		printf("��");
	}
	printf("��");

	for (i = 0; i < 26; i++) {
		y++;
		gotoxy(x, y);
		printf("��");

		if (i == 3) {
			gotoxy(19, i);
			printf("��ȸ������ �˻���");
			gotoxy(3, 5);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
		}

		if (i == 7) {
			gotoxy(5, i);
			printf("����");
			gotoxy(30, i);
			scanf("%s", &searchname);
			gotoxy(5, i+1);
			printf("��ȭ��ȣ(�� 4�ڸ�)");
			gotoxy(30, i+1);
			scanf("%s", &searchnumber);
			gotoxy(20, i+3);
			for (j = 0; j < 2; j++) {
				printf("��");
			}
			gotoxy(3, i+5);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
			gotoxy(5, i+7);
			printf("����");
			gotoxy(20, i+7);
			printf("��â��");
			gotoxy(31, i+7);
			printf("����");
			gotoxy(45, i+7);
			printf("25");
			gotoxy(3, i+8);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
			gotoxy(5, i + 10);
			printf("����ó");
			gotoxy(15, i + 10);
			printf("01081201468");
			gotoxy(31, i + 10);
			printf("ȸ����");
			gotoxy(45, i + 10);
			printf("3����");
			gotoxy(3, i+11);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
			gotoxy(5, i + 13);
			printf("����");
			gotoxy(20, i + 13);
			printf("��");
			gotoxy(3, i+14);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
			gotoxy(5, i + 16);
			printf("�ּ�");
			gotoxy(15, i + 16);
			printf("��⵵");
			gotoxy(3, i+17);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
			gotoxy(5, i + 19);
			printf("�����");
			gotoxy(15, i + 19);
			printf("2022�� 01�� 04��");
			
		}

		x += 51;
		gotoxy(x, y);
		printf("��");
		x = 1;
	}
	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 50; i++) {
		printf("��");
	}
	printf("��\n\n");
	_getch();
}

void Userdelete() {
	char searchname[10];
	char searchnumber[10];
	char name[10];
	char age[3];
	char number[10];
	int item;
	char gender[1];
	char membership[1];
	char adress[30];
	char date[8];
	char deletedate[8];
	char answer;
	system("cls");
	int i, j, x = 1, y = 1, n, m;

	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 50; i++) {
		printf("��");
	}
	printf("��");

	for (i = 0; i < 26; i++) {
		y++;
		gotoxy(x, y);
		printf("��");

		if (i == 3) {
			gotoxy(21, i);
			printf("��ȸ�� Ż���");
			gotoxy(3, 5);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
		}

		if (i == 7) {
			gotoxy(5, i);
			printf("����");
			gotoxy(30, i);
			scanf("%s", &searchname);
			gotoxy(5, i+1);
			printf("��ȭ��ȣ(�� 4�ڸ�)");
			gotoxy(30, i+1);
			scanf("%s", &searchnumber);
			gotoxy(20, i+3);
			for (j = 0; j < 2; j++) {
				printf("��");
			}
			gotoxy(3, i+5);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
			gotoxy(5, i + 7);
			printf("Ż����");
			gotoxy(15, i + 7);
			scanf("%s", &deletedate);
			gotoxy(5, i + 8);
			printf("�̿��� : 1��");
			gotoxy(2, i+10);
			printf("��");
			for (j = 0; j < 48; j++) {
				printf("��");
			}
			printf("��");
			
			for (j = 0; j < 3; j++) {
				n=2;
				m=i+11;
				gotoxy(n, m+j);
				printf("��");
				n += 49;
				gotoxy(n, m+j);
				printf("��");
			}
			gotoxy(4, i+11);
			printf("ȯ�ұݾ� = �����ݾ� - (�̿�ݾ� + ����� 10%%)");
			gotoxy(4, i+12);
			printf("�̿�ݾ� = (��ϼ� / �̿�� �Ⱓ) * �����ݾ�");
			gotoxy(2, i+13);
			printf("��");
			for (j = 0; j < 48; j++) {
				printf("��");
			}
			printf("��");
			gotoxy(4, i+14);
			printf("���� Ż���Ͻðڽ��ϱ�? (Y / N)");
			gotoxy(40, i+14);
			scanf("%s", &answer);
			gotoxy(4, i+16);
			printf("13�� 4167�� = 15���� - (833�� + 1�� 5000��)");
			gotoxy(4, i+17);
			printf("833�� = (1�� / 180��) * 15����");
			gotoxy(4, i+18);
			printf("13�� 4167�� ȯ�� �Ǿ����ϴ�.");
			gotoxy(4, i+19);
			printf("��â�� ȸ������ ������ �����Ǿ����ϴ�");
			
		}

		x += 51;
		gotoxy(x, y);
		printf("��");
		x = 1;
	}
	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 50; i++) {
		printf("��");
	}
	printf("��\n\n");
	_getch();
}

int main(){

	while (1) {
		system("cls");
		MenuUi();
		switch (Mnumber()) {
		case 1:
			Userinput();
			break;
		case 2:
			Usercorr();
			break;
		case 3:
			Usersearch();
			break;
		case 4:
			Userdelete();
			break;
		default:
			exit(0);
		}
	}
}
