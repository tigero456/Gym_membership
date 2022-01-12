#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MEMBER 200

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


long Datecal(int y, int m, int d){
    int months[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i;
    long total=0L;
    total=(y-1)*365L+(y-1)/4-(y-1)/100+(y-1)/400;
    if(!(y%4) && y%100 || !(y%400))
        months[1]++;
    for(i=0;i<m-1;i++)
    total += months[i];
    total+=d;
    return total;
}

void Savefile(){
	int i;
	FILE *fp=fopen("data.txt", "w");
	
	for(i=0; i<COUNT; i++){
    	fprintf(fp,"%10s %3s %15s %d %5s %30s %8s\n", member[i].name, member[i].age, member[i].number, member[i].membership, member[i].gender, member[i].adress, member[i].date);
	}
	
	fclose(fp);
}

void Loadfile(){
	int i;
	FILE *fp;
	fp=fopen("data.txt", "r");
	char temp[100];
	
	
	if(fp==NULL){
		return;
	}
	
	while (!feof(fp)){
		fscanf(fp, "%s %s %s %s %s %s %s\n", member[COUNT].name, member[COUNT].age, member[COUNT].number, temp, member[COUNT].gender, member[COUNT].adress, member[COUNT].date);
		member[COUNT].membership=atoi(temp);
		//printf("�̸�: %s ����: %s ��ȣ: %s ȸ���� : %d ����: %s �ּ�: %s ��¥: %s\n", member[COUNT].name, member[COUNT].age, member[COUNT].number, member[COUNT].membership, member[COUNT].gender, member[COUNT].adress, member[COUNT].date);
		COUNT++;
	}
		
	fclose(fp);
}

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
	system("cls");
	
	USER m;
	
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
			scanf("%s", m.name);
			gotoxy(31, i);
			printf("����");
			gotoxy(45, i);
			scanf("%s", m.age);
			gotoxy(3, i+2);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
			gotoxy(5, i + 4);
			printf("����ó");
			gotoxy(5, i + 5);
			printf("('-' ���� �Է�)");
			gotoxy(15, i + 4);
			scanf("%s", m.number);
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
			scanf("%d", &m.membership);
			gotoxy(3, i+6);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
			gotoxy(5, i + 8);
			printf("����(��/��)");
			gotoxy(20, i + 8);
			scanf("%s", m.gender);
			gotoxy(3, i+10);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
			gotoxy(5, i + 12);
			printf("�ּ�");
			gotoxy(15, i + 12);
			scanf("%s", m.adress);
			gotoxy(3, i+14);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
			gotoxy(5, i + 16);
			printf("�����");
			gotoxy(5, i + 17);
			printf("��/��/�� ex) 20220104");
			gotoxy(15, i + 16);
			scanf("%s", m.date);
			member[COUNT-1]=m;
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
	system("cls");
	int i, k, j, x = 1, y = 1;
	char searchname[20];
	char searchnumber[20];
	char changename[20];
	char changeage[3];
	char changenumber[15];
	char changemembership[3];
	char changegender[5];
	char changeadress[40];
	char changedate[8];
	char temp[100];
	char four[100];
	
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
			printf("��ȸ������ ������");
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
		    for (k = 0; k < COUNT; k++){
				if (strcmp(searchname, member[k].name) == 0) {
					strncpy(four, member[k].number+7, 4);
					if (strcmp(searchnumber, four) == 0) {
						gotoxy(5, i+7);
						printf("����");
						gotoxy(20, i+7);
						scanf("%s", changename);
						strcpy(member[k].name, changename);
						gotoxy(31, i+7);
						printf("����");
						gotoxy(45, i+7);
						scanf("%s", changeage);
						strcpy(member[k].age, changeage);
						gotoxy(3, i+8);
						for (j = 0; j < 49; j++) {
							printf("��");
						}
						gotoxy(5, i + 10);
						printf("����ó");
						gotoxy(15, i + 10);
						scanf("%s", changenumber);
						strcpy(member[k].number, changenumber);
						gotoxy(31, i + 10);
						printf("ȸ����");
						gotoxy(45, i + 10);
						scanf("%s", changemembership);
						sprintf(temp, "%d", member[k].membership);
						strcpy(temp, changemembership);
						member[k].membership=atoi(temp);
						gotoxy(3, i+11);
						for (j = 0; j < 49; j++) {
							printf("��");
						}
						gotoxy(5, i + 13);
						printf("����");
						gotoxy(20, i + 13);
						scanf("%s", changegender);
						strcpy(member[k].gender, changegender);
						gotoxy(3, i+14);
						for (j = 0; j < 49; j++) {
							printf("��");
						}
						gotoxy(5, i + 16);
						printf("�ּ�");
						gotoxy(15, i + 16);
						scanf("%s", changeadress);
						strcpy(member[k].adress, changeadress);
						gotoxy(3, i+17);
						for (j = 0; j < 49; j++) {
							printf("��");
						}
						gotoxy(5, i + 19);
						printf("�����");
						gotoxy(15, i + 19);
						scanf("%s", changedate);
						strcpy(member[k].date, changedate);
					}	
				}
		    }
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

void Usersearch() {
	system("cls");
	int i, k, j, x = 1, y = 1;
	char searchname[20];
	char searchnumber[20];
    char temp[100];
   
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
		    for (k = 0; k < COUNT; k++){
				if (!strcmp(searchname, member[k].name)) {
					strncpy(temp, member[k].number+7, 4);
					if (!strcmp(searchnumber, temp)) {
						gotoxy(5, i+7);
						printf("����");
						gotoxy(20, i+7);
						printf("%s", member[k].name);
						gotoxy(31, i+7);
						printf("����");
						gotoxy(45, i+7);
						printf("%s", member[k].age);
						gotoxy(3, i+8);
						for (j = 0; j < 49; j++) {
							printf("��");
						}
						gotoxy(5, i + 10);
						printf("����ó");
						gotoxy(15, i + 10);
						printf("%s", member[k].number);
						gotoxy(31, i + 10);
						printf("ȸ����");
						gotoxy(45, i + 10);
						switch(member[k].membership){
							case 1:
								printf("1����");
								break;
							case 2:
								printf("3����");
								break;
							case 3:
								printf("6����");
								break;
							default:
								printf("12����");
								break;
						}
						gotoxy(3, i+11);
						for (j = 0; j < 49; j++) {
							printf("��");
						}
						gotoxy(5, i + 13);
						printf("����");
						gotoxy(20, i + 13);
						printf("%s", member[k].gender);
						gotoxy(3, i+14);
						for (j = 0; j < 49; j++) {
							printf("��");
						}
						gotoxy(5, i + 16);
						printf("�ּ�");
						gotoxy(15, i + 16);
						printf("%s", member[k].adress);
						gotoxy(3, i+17);
						for (j = 0; j < 49; j++) {
							printf("��");
						}
						gotoxy(5, i + 19);
						printf("�����");
						gotoxy(15, i + 19);
						printf("%s", member[k].date);
						
			        }	
				}
		    }
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
	system("cls");
	int i, j, k, o, x = 1, y = 1, n, m, year, month, day, sy, sm, sd;
	char searchname[20];
	char searchnumber[20];
	int money, moneydate;
	char deletedate[8];
	char answer;
    char temp[100];
    char ttemp[100];
    long dates;
	
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
			fflush(stdin); 
			gotoxy(5, i+1);
			printf("��ȭ��ȣ(�� 4�ڸ�)");
			gotoxy(30, i+1);
			scanf("%s", &searchnumber);
			fflush(stdin); 
			gotoxy(20, i+3);
			for (j = 0; j < 2; j++) {
				printf("��");
			}
			gotoxy(3, i+5);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
		    for (k = 0; k < COUNT; k++){
				switch(member[k].membership){
					case 1:
						money=3;
						moneydate=30;
						break;
					case 2:
						money=8;
						moneydate=90;
						break;
					case 3:
						money=15;
						moneydate=180;
						break;
					default :
						money=25;
						moneydate=360;
						break;
				}
				if (!strcmp(searchname, member[k].name)) {
					strncpy(temp, member[k].number+7, 4);
					strncpy(ttemp, member[k].date+0, 4);
					year=atoi(ttemp);
					strset(ttemp, '\0');
					strncpy(ttemp, member[k].date+4, 2);
					month=atoi(ttemp);
					strset(ttemp, '\0');
					strncpy(ttemp, member[k].date+6, 2);
					day=atoi(ttemp);
					strset(ttemp, '\0');
					if (!strcmp(searchnumber, temp)) {
						gotoxy(5, i + 7);
						printf("Ż����");
						gotoxy(15, i + 7);
						scanf("%s", deletedate);
						fflush(stdin); 
						strncpy(ttemp, deletedate+0, 4);
						sy=atoi(ttemp);
						strset(ttemp, '\0');
						strncpy(ttemp, deletedate+4, 2);
						sm=atoi(ttemp);
						strset(ttemp, '\0');
						strncpy(ttemp, deletedate+6, 2);
						sd=atoi(ttemp);
						
					    dates=Datecal(sy, sm, sd) - Datecal(year, month, day);
					    
						gotoxy(5, i + 8);
						printf("�̿��� : %ld��", dates);
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
						scanf("%c", &answer);
						fflush(stdin); 
						if(answer == 'Y'){
							gotoxy(4, i+16);
							printf("%d�� = %d���� - ( %d�� + %d��)", (money*10000)-(((dates/moneydate)*(money*10000))+((money*10000)/10)), money, (dates/moneydate)*(money*10000), (money*10000)/10);
							gotoxy(4, i+17);
							printf("%d�� = ( %ld�� / %d��) * %d����", (dates/moneydate)*(money*10000), dates, moneydate, money);
							gotoxy(4, i+18);
							printf("%d�� ȯ�� �Ǿ����ϴ�.", (money*10000)-(((dates/moneydate)*(money*10000))+((money*10000)/10)));
							gotoxy(4, i+19);
							printf("%s ȸ������ ������ �����Ǿ����ϴ�", member[k].name);
							for(j=k; j<COUNT-1; j++){
								member[j] = member[j+1];
							}
							COUNT--;
						}
					}
				}
			}
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
	Loadfile();
	
	while (1) {
		system("cls");
		MenuUi();
		switch (Mnumber()) {
		case 1:
			Userinput();
			Savefile();
			COUNT++;
			break;
		case 2:
			Usercorr();
			Savefile();
			break;
		case 3:
			Usersearch();
			break;
		case 4:
			Userdelete();
			Savefile();
			break;
		default:
			exit(0);
		}
	}
}



/*
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
			printf("%d ����\n", linecount++);
			
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
*/
