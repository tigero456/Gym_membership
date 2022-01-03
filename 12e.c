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
	printf("┌");
	for (i = 0; i < 30; i++) {
		printf("─");
	}
	printf("┐");

	for (i = 0; i < 17; i++) {
		y++;
		gotoxy(x, y);
		printf("│");

		if (i == 3) {
			gotoxy(3, i);
			printf("C언어 파일입출력을 사용한");
			gotoxy(8, i + 1);
			printf("헬스장 회원관리 프로그램");
			gotoxy(3, 6);
			for (j = 0; j < 30; j++) {
				printf("─");
			}
		}

		if (i == 8) {
			gotoxy(5, i);
			printf("1) 회원등록");
			gotoxy(5, i + 2);
			printf("2) 회원정보 수정");
			gotoxy(5, i + 4);
			printf("3) 회원정보 검색");
			gotoxy(5, i + 6);
			printf("4) 회원 탈퇴(환불)");
			gotoxy(5, i + 8);
			printf("5) 종료");
		}

		x += 31;
		gotoxy(x, y);
		printf("│");
		x = 1;
	}
	gotoxy(x, y);
	printf("└");
	for (i = 0; i < 30; i++) {
		printf("─");
	}
	printf("┘\n\n");

}

int Mnumber() {
	int number;

	printf("메뉴 번호를 입력해주세요... ");
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
	printf("┌");
	for (i = 0; i < 50; i++) {
		printf("─");
	}
	printf("┐");

	for (i = 0; i < 17; i++) {
		y++;
		gotoxy(x, y);
		printf("│");

		if (i == 3) {
			gotoxy(19, i);
			printf("※회원정보 등록※");
			gotoxy(3, 5);
			for (j = 0; j < 49; j++) {
				printf("─");
			}
		}

		if (i == 8) {
			gotoxy(5, i);
			printf("성명");
			gotoxy(15, i);
			scanf("%s", &name);
			gotoxy(31, i);
			printf("나이");
			gotoxy(45, i);
			scanf("%s", &age);
			gotoxy(3, i+1);
			for (j = 0; j < 49; j++) {
				printf("─");
			}
			gotoxy(5, i + 3);
			printf("연락처");
			gotoxy(15, i + 3);
			scanf("%s", &number);
			gotoxy(31, i + 3);
			printf("신청종목");
			gotoxy(45, i + 3);
			scanf("%s", &item);
			gotoxy(3, i+4);
			for (j = 0; j < 49; j++) {
				printf("─");
			}
			gotoxy(5, i + 6);
			printf("성별");
			gotoxy(15, i + 6);
			scanf("%s", &sex);
			gotoxy(31, i + 6);
			printf("회원권");
			gotoxy(45, i + 6);
			scanf("%s", &membership);
			gotoxy(3, i+7);
			for (j = 0; j < 49; j++) {
				printf("─");
			}
			gotoxy(5, i + 9);
			printf("주소");
			gotoxy(15, i + 9);
			scanf("%s", &adress);
		}

		x += 51;
		gotoxy(x, y);
		printf("│");
		x = 1;
	}
	gotoxy(x, y);
	printf("└");
	for (i = 0; i < 50; i++) {
		printf("─");
	}
	printf("┘\n\n");
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
