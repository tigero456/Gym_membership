#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#define MAX_MEMBER 100

typedef struct user {
	char name[20];
	char age[3];
	char number[15];
	int membership;
	char gender[5];
	char adress[40];
	char date[8];
}USER;

USER member[MAX_MEMBER] = { 0, };
int COUNT=0;

int Count_number(){
	char word[250];
	FILE* fp;
	COUNT=0;
	fp=fopen("data.txt", "r");
	
	while (fgets(word, sizeof(word), fp) != NULL) {
        COUNT++;
    }
	fclose(fp);
    
    return COUNT;
}

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

USER Userinput() {
	system("cls");
	
	USER m;
	FILE* fp;
	fp=fopen("data.txt", "a+");
	
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
			scanf("%s", m.name);
  			//fflush(stdin);
			gotoxy(31, i);
			printf("나이");
			gotoxy(45, i);
			scanf("%s", m.age);
  			//fflush(stdin);
			gotoxy(3, i+2);
			for (j = 0; j < 49; j++) {
				printf("─");
			}
			gotoxy(5, i + 4);
			printf("연락처");
			gotoxy(5, i + 5);
			printf("('-' 빼고 입력)");
			gotoxy(15, i + 4);
			scanf("%s", m.number);
  			//fflush(stdin);
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
			scanf("%d", &m.membership);
  			//fflush(stdin);
			gotoxy(3, i+6);
			for (j = 0; j < 49; j++) {
				printf("─");
			}
			gotoxy(5, i + 8);
			printf("성별(남/여)");
			gotoxy(20, i + 8);
			scanf("%s", m.gender);
  			//fflush(stdin);
			gotoxy(3, i+10);
			for (j = 0; j < 49; j++) {
				printf("─");
			}
			gotoxy(5, i + 12);
			printf("주소");
			gotoxy(15, i + 12);
			scanf("%s", m.adress);
  			//fflush(stdin);
			gotoxy(3, i+14);
			for (j = 0; j < 49; j++) {
				printf("─");
			}
			gotoxy(5, i + 16);
			printf("등록일");
			gotoxy(5, i + 17);
			printf("년/월/일 ex) 20220104");
			gotoxy(15, i + 16);
			scanf("%s", m.date);
  			//fflush(stdin);
			
    		fprintf(fp,"%10s %3s %15s %d %5s %30s %8s\n", m.name, m.age, m.number, m.membership, m.gender, m.adress, m.date);
			fclose(fp);
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
	
	return m;
}

void Usercorr() {
	system("cls");
	int i, k, j, x = 1, y = 1;
	char searchname[20];
	char searchnumber[20];
	char changename[20];
	char changeage[3];
	char changenumber[15];
	int changemembership;
	char changegender[5];
	char changeadress[40];
	char changedate[8];
	char *p;
	char temp[256];
	int find_pos;
    FILE* fp;
    fp = fopen("data.txt", "r+");

    if (!fp) {
        printf("file open 에러\n");
        return;
    }
	while (!feof(fp)){
		fscanf(fp, "%s %s %s %d %s %s %s", member[COUNT].name, member[COUNT].age, member[COUNT].number, &member[COUNT].membership, member[COUNT].gender, member[COUNT].adress, member[COUNT].date);
		COUNT++;
	}
	
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
			printf("※회원정보 수정※");
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
		    for (k = 0; k < COUNT; k++){
				if (strcmp(searchname, member[k].name) == 0) {
					if (strcmp(searchnumber, member[k].number) == 0) {
						gotoxy(5, i+7);
						printf("성명");
						gotoxy(20, i+7);
						scanf("%s", changename);
						while (fgets(temp, 256, fp) != NULL) {
					        p = strstr(temp, name);
					        if (p != NULL) {
					            find_pos = strlen(temp) - (p - temp) + 1;
					            fseek(fp, (-1)*find_pos, SEEK_CUR);
					            fwrite(changename, 4, 2, fp);
					            fseek(fp, find_pos - 4, SEEK_CUR);
					        }
					    }
						gotoxy(31, i+7);
						printf("나이");
						gotoxy(45, i+7);
						scanf("%s", member[k].age);
						gotoxy(3, i+8);
						for (j = 0; j < 49; j++) {
							printf("─");
						}
						gotoxy(5, i + 10);
						printf("연락처");
						gotoxy(15, i + 10);
						scanf("%s", member[k].number);
						gotoxy(31, i + 10);
						printf("회원권");
						gotoxy(45, i + 10);
						scanf("%d", &member[k].membership);
						gotoxy(3, i+11);
						for (j = 0; j < 49; j++) {
							printf("─");
						}
						gotoxy(5, i + 13);
						printf("성별");
						gotoxy(20, i + 13);
						scanf("%s", member[k].gender);
						gotoxy(3, i+14);
						for (j = 0; j < 49; j++) {
							printf("─");
						}
						gotoxy(5, i + 16);
						printf("주소");
						gotoxy(15, i + 16);
						scanf("%s", member[k].adress);
						gotoxy(3, i+17);
						for (j = 0; j < 49; j++) {
							printf("─");
						}
						gotoxy(5, i + 19);
						printf("등록일");
						gotoxy(15, i + 19);
						scanf("%s", member[k].date);
						
			    		fclose(fp);
					}	
				}
		    }
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

void Usersearch() {
	system("cls");
	int i, k, j, x = 1, y = 1;
	char searchname[20];
	char searchnumber[20];
    FILE* fp;
    fp = fopen("data.txt", "r");

    if (!fp) {
        printf("file open 에러\n");
        return;
    }
	while (!feof(fp)){
		fscanf(fp, "%s %s %s %d %s %s %s", member[COUNT].name, member[COUNT].age, member[COUNT].number, &member[COUNT].membership, member[COUNT].gender, member[COUNT].adress, member[COUNT].date);
		COUNT++;
	}

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
		    for (k = 0; k < COUNT; k++){
				if (strcmp(searchname, member[k].name) == 0) {
					if (strcmp(searchnumber, member[k].number) == 0) {
						gotoxy(5, i+7);
						printf("성명");
						gotoxy(20, i+7);
						printf("%s", member[k].name);
						gotoxy(31, i+7);
						printf("나이");
						gotoxy(45, i+7);
						printf("%s", member[k].age);
						gotoxy(3, i+8);
						for (j = 0; j < 49; j++) {
							printf("─");
						}
						gotoxy(5, i + 10);
						printf("연락처");
						gotoxy(15, i + 10);
						printf("%s", member[k].number);
						gotoxy(31, i + 10);
						printf("회원권");
						gotoxy(45, i + 10);
						switch(member[k].membership){
							case 1:
								printf("1개월");
								break;
							case 2:
								printf("3개월");
								break;
							case 3:
								printf("6개월");
								break;
							default:
								printf("12개월");
								break;
						}
						gotoxy(3, i+11);
						for (j = 0; j < 49; j++) {
							printf("─");
						}
						gotoxy(5, i + 13);
						printf("성별");
						gotoxy(20, i + 13);
						printf("%s", member[k].gender);
						gotoxy(3, i+14);
						for (j = 0; j < 49; j++) {
							printf("─");
						}
						gotoxy(5, i + 16);
						printf("주소");
						gotoxy(15, i + 16);
						printf("%s", member[k].adress);
						gotoxy(3, i+17);
						for (j = 0; j < 49; j++) {
							printf("─");
						}
						gotoxy(5, i + 19);
						printf("등록일");
						gotoxy(15, i + 19);
						printf("%s", member[k].date);
						
			        }	
				}
		    }
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
	fclose(fp);
	_getch();
}

void Userdelete() {
	system("cls");
	int i, j, k, x = 1, y = 1, n, m;
	char searchname[20];
	char searchnumber[20];
	int money;
	char deletedate[8];
	char answer[3];
    FILE* fp;
    fp = fopen("data.txt", "r");

    if (!fp) {
        printf("file open 에러\n");
        return;
    }
	while (!feof(fp)){
		fscanf(fp, "%s %s %s %d %s %s %s", member[COUNT].name, member[COUNT].age, member[COUNT].number, &member[COUNT].membership, member[COUNT].gender, member[COUNT].adress, member[COUNT].date);
		COUNT++;
	}
	
	switch(member[k].membership){
		case 1:
			money=3;
		case 2:
			money=8;
		case 3:
			money=15;
		default :
			money=25;
	}
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
		    for (k = 0; k < COUNT; k++){
				if (strcmp(searchname, member[k].name) == 0) {
					if (strcmp(searchnumber, member[k].number) == 0) {
						gotoxy(5, i + 7);
						printf("탈퇴일");
						gotoxy(15, i + 7);
						scanf("%s", deletedate);
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
						if(answer == "Y"){
							gotoxy(4, i+16);
							printf("13만 4167원 = %d만원 - (833원 + 1만 5000원)", money);
							gotoxy(4, i+17);
							printf("833원 = (1일 / 180일) * %d만원", money);
							gotoxy(4, i+18);
							printf("13만 4167원 환불 되었습니다.");
							gotoxy(4, i+19);
							printf("김창희 회원님의 정보가 삭제되었습니다");
						}
					}
				}
			}
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
	fclose(fp);
	_getch();
}

void Userprint(){
	system("cls");
	int i, x=1, y=1;
	
	char buffer[256];
	char *ptr;
	FILE* fp;
	fp=fopen("data.txt", "r");
	int linecount=1;
	
	if(fp!=NULL){
		while(!feof(fp)){
			fgets(buffer, sizeof(buffer), fp);
			printf("%d 라인\n", linecount++);
			
			ptr=strtok(buffer, " ");
			
			while(ptr!=NULL){
				printf("%s\n", ptr);
				ptr=strtok(NULL, " ");
			}
		}
	}
	fclose(fp);
	_getch();
}

int main(){

	while (1) {
		system("cls");
		MenuUi();
		switch (Mnumber()) {
		case 1:
			member[Count_number()+1]=Userinput();
			COUNT++;
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
		case 5:
			Userprint();
			break;
		default:
			exit(0);
		}
	}
}
