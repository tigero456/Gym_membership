#include <windows.h>
#include <conio.h>
#include <stdio.h>
#define MAX_MEMBER 100

typedef struct user {
	char name[10];
	char age[3];
	char number[10];
	char item[10];
	char sex[1];
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
	char item[10];
	char sex[1];
	char membership[1];
	char adress[30];
	system("cls");
	int i, j, x = 1, y = 1;

	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 50; i++) {
		printf("��");
	}
	printf("��");

	for (i = 0; i < 17; i++) {
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

		if (i == 8) {
			gotoxy(5, i);
			printf("����");
			gotoxy(15, i);
			scanf("%s", &name);
			gotoxy(31, i);
			printf("����");
			gotoxy(45, i);
			scanf("%s", &age);
			gotoxy(3, i+1);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
			gotoxy(5, i + 3);
			printf("����ó");
			gotoxy(15, i + 3);
			scanf("%s", &number);
			gotoxy(31, i + 3);
			printf("��û����");
			gotoxy(45, i + 3);
			scanf("%s", &item);
			gotoxy(3, i+4);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
			gotoxy(5, i + 6);
			printf("����");
			gotoxy(15, i + 6);
			scanf("%s", &sex);
			gotoxy(31, i + 6);
			printf("ȸ����");
			gotoxy(45, i + 6);
			scanf("%s", &membership);
			gotoxy(3, i+7);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
			gotoxy(5, i + 9);
			printf("�ּ�");
			gotoxy(15, i + 9);
			scanf("%s", &adress);
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
	printf("ss");
	_getch();
}

void Userdelete() {
	printf("bye");
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
