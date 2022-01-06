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
	int item;
	char gender[1];
	char membership[1];
	char adress[30];
	char date[8];
	system("cls");
	int i, j, x = 1, y = 1;

	gotoxy(x, y);
	printf("┌");
	for (i = 0; i < 50; i++) {
		printf("─");
	}
	printf("┐");

	for (i = 0; i < 24; i++) {
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

		if (i == 7) {
			gotoxy(5, i);
			printf("성명");
			gotoxy(20, i);
			scanf("%s", &name);
			gotoxy(31, i);
			printf("나이");
			gotoxy(45, i);
			scanf("%s", &age);
			gotoxy(3, i+2);
			for (j = 0; j < 49; j++) {
				printf("─");
			}
			gotoxy(5, i + 4);
			printf("연락처");
			gotoxy(5, i + 5);
			printf("('-' 빼고 입력)");
			gotoxy(15, i + 4);
			scanf("%s", &number);
			gotoxy(31, i + 4);
			printf("회원권");
			gotoxy(31, i + 5);
			printf("(번호로 입력)");
			gotoxy(54, i + 1);
			for (j = 0; j < 17; j++) {
				printf("─");
			}
			printf("┐");
			gotoxy(54, i + 2);
			printf("1) 1개월   3만원 │");
			gotoxy(54, i + 3);
			printf("                 │");
			gotoxy(54, i + 4); 
			printf("2) 3개월   8만원 │");
			gotoxy(54, i + 5);
			printf("                 │");
			gotoxy(54, i + 6);
			printf("3) 6개월  15만원 │");
			gotoxy(54, i + 7);
			printf("                 │");
			gotoxy(54, i + 8);
			printf("4) 12개월 25만원 │");
			gotoxy(54, i + 9);
			for (j = 0; j < 17; j++) {
				printf("─");
			}
			gotoxy(45, i + 4);
			scanf("%s", &membership);
			gotoxy(3, i+6);
			for (j = 0; j < 49; j++) {
				printf("─");
			}
			gotoxy(5, i + 8);
			printf("성별(남/여)");
			gotoxy(20, i + 8);
			scanf("%s", &gender);
			gotoxy(3, i+10);
			for (j = 0; j < 49; j++) {
				printf("─");
			}
			gotoxy(5, i + 12);
			printf("주소");
			gotoxy(15, i + 12);
			scanf("%s", &adress);
			gotoxy(3, i+14);
			for (j = 0; j < 49; j++) {
				printf("─");
			}
			gotoxy(5, i + 16);
			printf("등록일");
			gotoxy(5, i + 17);
			printf("년/월/일 ex) 20220104");
			gotoxy(15, i + 16);
			scanf("%s", &date);
			
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
	printf("┌");
	for (i = 0; i < 50; i++) {
		printf("─");
	}
	printf("┐");

	for (i = 0; i < 26; i++) {
		y++;
		gotoxy(x, y);
		printf("│");

		if (i == 3) {
			gotoxy(19, i);
			printf("※회원정보 검색※");
			gotoxy(3, 5);
			for (j = 0; j < 49; j++) {
				printf("─");
			}
		}

		if (i == 7) {
			gotoxy(5, i);
			printf("성명");
			gotoxy(30, i);
			scanf("%s", &searchname);
			gotoxy(5, i+1);
			printf("전화번호(끝 4자리)");
			gotoxy(30, i+1);
			scanf("%s", &searchnumber);
			gotoxy(20, i+3);
			for (j = 0; j < 2; j++) {
				printf("▽");
			}
			gotoxy(3, i+5);
			for (j = 0; j < 49; j++) {
				printf("─");
			}
			gotoxy(5, i+7);
			printf("성명");
			gotoxy(20, i+7);
			printf("김창희");
			gotoxy(31, i+7);
			printf("나이");
			gotoxy(45, i+7);
			printf("25");
			gotoxy(3, i+8);
			for (j = 0; j < 49; j++) {
				printf("─");
			}
			gotoxy(5, i + 10);
			printf("연락처");
			gotoxy(15, i + 10);
			printf("01081201468");
			gotoxy(31, i + 10);
			printf("회원권");
			gotoxy(45, i + 10);
			printf("3개월");
			gotoxy(3, i+11);
			for (j = 0; j < 49; j++) {
				printf("─");
			}
			gotoxy(5, i + 13);
			printf("성별");
			gotoxy(20, i + 13);
			printf("남");
			gotoxy(3, i+14);
			for (j = 0; j < 49; j++) {
				printf("─");
			}
			gotoxy(5, i + 16);
			printf("주소");
			gotoxy(15, i + 16);
			printf("경기도");
			gotoxy(3, i+17);
			for (j = 0; j < 49; j++) {
				printf("─");
			}
			gotoxy(5, i + 19);
			printf("등록일");
			gotoxy(15, i + 19);
			printf("2022년 01월 04일");
			
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
	printf("┌");
	for (i = 0; i < 50; i++) {
		printf("─");
	}
	printf("┐");

	for (i = 0; i < 26; i++) {
		y++;
		gotoxy(x, y);
		printf("│");

		if (i == 3) {
			gotoxy(21, i);
			printf("※회원 탈퇴※");
			gotoxy(3, 5);
			for (j = 0; j < 49; j++) {
				printf("─");
			}
		}

		if (i == 7) {
			gotoxy(5, i);
			printf("성명");
			gotoxy(30, i);
			scanf("%s", &searchname);
			gotoxy(5, i+1);
			printf("전화번호(끝 4자리)");
			gotoxy(30, i+1);
			scanf("%s", &searchnumber);
			gotoxy(20, i+3);
			for (j = 0; j < 2; j++) {
				printf("▽");
			}
			gotoxy(3, i+5);
			for (j = 0; j < 49; j++) {
				printf("─");
			}
			gotoxy(5, i + 7);
			printf("탈퇴일");
			gotoxy(15, i + 7);
			scanf("%s", &deletedate);
			gotoxy(5, i + 8);
			printf("이용일 : 1일");
			gotoxy(2, i+10);
			printf("┌");
			for (j = 0; j < 48; j++) {
				printf("─");
			}
			printf("┐");
			
			for (j = 0; j < 3; j++) {
				n=2;
				m=i+11;
				gotoxy(n, m+j);
				printf("│");
				n += 49;
				gotoxy(n, m+j);
				printf("│");
			}
			gotoxy(4, i+11);
			printf("환불금액 = 결제금액 - (이용금액 + 위약금 10%%)");
			gotoxy(4, i+12);
			printf("이용금액 = (운동일수 / 이용권 기간) * 결제금액");
			gotoxy(2, i+13);
			printf("└");
			for (j = 0; j < 48; j++) {
				printf("─");
			}
			printf("┘");
			gotoxy(4, i+14);
			printf("정말 탈퇴하시겠습니까? (Y / N)");
			gotoxy(40, i+14);
			scanf("%s", &answer);
			gotoxy(4, i+16);
			printf("13만 4167원 = 15만원 - (833원 + 1만 5000원)");
			gotoxy(4, i+17);
			printf("833원 = (1일 / 180일) * 15만원");
			gotoxy(4, i+18);
			printf("13만 4167원 환불 되었습니다.");
			gotoxy(4, i+19);
			printf("김창희 회원님의 정보가 삭제되었습니다");
			
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
