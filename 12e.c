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

USER Userinput() {
	system("cls");
	
	USER m;
	FILE* fp;
	fp=fopen("data.txt", "a+");
	
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
  			//fflush(stdin);
			gotoxy(31, i);
			printf("����");
			gotoxy(45, i);
			scanf("%s", m.age);
  			//fflush(stdin);
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
  			//fflush(stdin);
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
  			//fflush(stdin);
			gotoxy(3, i+6);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
			gotoxy(5, i + 8);
			printf("����(��/��)");
			gotoxy(20, i + 8);
			scanf("%s", m.gender);
  			//fflush(stdin);
			gotoxy(3, i+10);
			for (j = 0; j < 49; j++) {
				printf("��");
			}
			gotoxy(5, i + 12);
			printf("�ּ�");
			gotoxy(15, i + 12);
			scanf("%s", m.adress);
  			//fflush(stdin);
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
  			//fflush(stdin);
			
    		fprintf(fp,"%10s %3s %15s %d %5s %30s %8s\n", m.name, m.age, m.number, m.membership, m.gender, m.adress, m.date);
			fclose(fp);
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
        printf("file open ����\n");
        return;
    }
	while (!feof(fp)){
		fscanf(fp, "%s %s %s %d %s %s %s", member[COUNT].name, member[COUNT].age, member[COUNT].number, &member[COUNT].membership, member[COUNT].gender, member[COUNT].adress, member[COUNT].date);
		COUNT++;
	}
	
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
					if (strcmp(searchnumber, member[k].number) == 0) {
						gotoxy(5, i+7);
						printf("����");
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
						printf("����");
						gotoxy(45, i+7);
						scanf("%s", member[k].age);
						gotoxy(3, i+8);
						for (j = 0; j < 49; j++) {
							printf("��");
						}
						gotoxy(5, i + 10);
						printf("����ó");
						gotoxy(15, i + 10);
						scanf("%s", member[k].number);
						gotoxy(31, i + 10);
						printf("ȸ����");
						gotoxy(45, i + 10);
						scanf("%d", &member[k].membership);
						gotoxy(3, i+11);
						for (j = 0; j < 49; j++) {
							printf("��");
						}
						gotoxy(5, i + 13);
						printf("����");
						gotoxy(20, i + 13);
						scanf("%s", member[k].gender);
						gotoxy(3, i+14);
						for (j = 0; j < 49; j++) {
							printf("��");
						}
						gotoxy(5, i + 16);
						printf("�ּ�");
						gotoxy(15, i + 16);
						scanf("%s", member[k].adress);
						gotoxy(3, i+17);
						for (j = 0; j < 49; j++) {
							printf("��");
						}
						gotoxy(5, i + 19);
						printf("�����");
						gotoxy(15, i + 19);
						scanf("%s", member[k].date);
						
			    		fclose(fp);
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
    FILE* fp;
    fp = fopen("data.txt", "r");

    if (!fp) {
        printf("file open ����\n");
        return;
    }
	while (!feof(fp)){
		fscanf(fp, "%s %s %s %d %s %s %s", member[COUNT].name, member[COUNT].age, member[COUNT].number, &member[COUNT].membership, member[COUNT].gender, member[COUNT].adress, member[COUNT].date);
		COUNT++;
	}

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
				if (strcmp(searchname, member[k].name) == 0) {
					if (strcmp(searchnumber, member[k].number) == 0) {
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
        printf("file open ����\n");
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
		    for (k = 0; k < COUNT; k++){
				if (strcmp(searchname, member[k].name) == 0) {
					if (strcmp(searchnumber, member[k].number) == 0) {
						gotoxy(5, i + 7);
						printf("Ż����");
						gotoxy(15, i + 7);
						scanf("%s", deletedate);
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
						if(answer == "Y"){
							gotoxy(4, i+16);
							printf("13�� 4167�� = %d���� - (833�� + 1�� 5000��)", money);
							gotoxy(4, i+17);
							printf("833�� = (1�� / 180��) * %d����", money);
							gotoxy(4, i+18);
							printf("13�� 4167�� ȯ�� �Ǿ����ϴ�.");
							gotoxy(4, i+19);
							printf("��â�� ȸ������ ������ �����Ǿ����ϴ�");
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
