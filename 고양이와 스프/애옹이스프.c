#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_WIDTH 10
#define HME_POS 1
#define BWL_POS (ROOM_WIDTH - 2)


int cat = 1;

int main(void) {
	srand((unsigned int)time(NULL));
	char name[50];
	printf("****�߿��̿� ����****\n");
	printf("      /\\_/\\\n /\\  / o o \\\n//\\\\ \\~(*)~/\n`  \\/   ^ / \n   l \\ll ll \n   \\ 'll ll \n    \\)()-())\n");
	printf("�߿����� �̸��� �����ּ���:");
	scanf_s("%s", name, sizeof(name));
	printf("�߿����� �̸��� %s�Դϴ�.", name);
	Sleep(1000); system("cls");


	//��Ʈ��
	int match=2,Move,Soup=0,catback, Choice;
	while (1) {
		printf("==================== ���� ���� ===================\n");
		printf("������� ���� ����: %d��\n", Soup);
		printf("������� ����(0~4): %d\n", match);
		switch (match) {
		case 4:
			printf("���� �������Դϴ�.\n");
			break;
		case 3:
			printf("�Ǹ��� ����� ���� �ް� �ֽ��ϴ�.\n");
			break;
		case 2:
			printf("�׷����� �� ���� �����Դϴ�.\n");
			break;
		case 1:
			printf("���� ���Ǳ� ����Դϴ�.\n");
			break;
		default:
			printf("�翡 ���� ������ �Ⱦ��մϴ�.\n");
			break;
		}
		printf("==================================================\n");
		Sleep(500);

		catback = cat;
		
		//�̵�
		printf("�˶� �̵�: ����� ģ���� ���� ���������� �� �з��� �������ϴ�.\n");
		Sleep(500);
		printf("�ֻ��� ���� %d �̻��̸� ���� ������ �̵��մϴ�.\n", 6-match);
		Sleep(500);
		printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
		Sleep(500);
		int Dice = rand() % 6 + 1;
		printf("%d��(��) ���Խ��ϴ�.!\n", Dice);
		Sleep(500);
		if (Dice >= 6 - match) {
			if (cat == BWL_POS) {
				printf("�������� �ʾҽ��ϴ�.");
			}
			else {
				printf("���� ������ �����Դϴ�.\n");
				cat++;
				Sleep(500);
			}
			
		}
		else {
			if (cat == HME_POS) {
				printf("%s��(��) �ڽ��� ������ ������� �����ϴ�.\n", name);
				Sleep(500);
			}
			else {
				printf("�� ������ �����Դϴ�.\n");
				Sleep(500);
				cat--;
				if (cat == HME_POS) {
					printf("%s��(��) �ڽ��� ������ ������� �����ϴ�.\n", name);
				}
			}

		}
			
		// ����
		if (cat == BWL_POS) {
			int gacha = rand() % 2;
			switch (gacha) {
				case 2: 
					printf("%s��(��) ���ڼ����� ��������ϴ�!\n", name);
					break;
				case 1:
					printf("%s��(��) ����̼����� ��������ϴ�!\n", name);
					break;
				case 0:
					printf("%s��(��) ����ݸ������� ��������ϴ�!\n", name);
					break;
			}
			Soup++;
			Sleep(500);
			printf("������� ���� ����: %d��\n", Soup);
			Sleep(500);
		}

		// i ���� / j ����
		printf("\n");
		for (int i = 0; i < 4; i++)		{

			for (int j = 0; j < ROOM_WIDTH; j++) {

				if (j == 0 || j == ROOM_WIDTH - 1||i == 0 || i == 3) {
					printf("#");
				}
				else if (i == 1 && j == BWL_POS) {
					printf("B");
				}
				else if (i == HME_POS && j == 1) {
					printf("H");
				}
				else if (i == 2 && j == catback && catback != cat) {
					printf(".");
				}
				else if (i == 2 && j == cat) {
					printf("C");
				}
				else {
					printf(" ");
				}
			}
			printf("\n");
			
		}

		printf("\n");

		//����
		printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�? 0. �ƹ��͵� ���� ���� 1. �ܾ� �ֱ�\n");
		do {
			printf(">> ");
			scanf_s("%d", &Choice);
		} while (Choice != 0 && Choice != 1);

			//�ƹ��͵� ���ϱ�
			if (Choice == 0) {
				printf("�ƹ��͵� ���� �ʽ��ϴ�.\n");
				Sleep(500);
				printf("4/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
				Sleep(500);
				printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
				Sleep(500);
				int Dice = rand() % 6 + 1;
				printf("%d��(��) ���Խ��ϴ�.!\n", Dice);
				Sleep(500);
				if (Dice <= 4) {
					if (match > 0) {
						printf("ģ�е��� �������ϴ�.\n");
						match--;
						Sleep(500);
					}
					else {
						printf("ģ�е��� �� �̻� �������� �ʽ��ϴ�.\n");
						Sleep(500);
					}

				}
				else {
					printf("������ ģ�е��� �������� �ʾҽ��ϴ�.\n");
					Sleep(500);
				}
				printf("���� ģ�е�: %d\n", match);
				Sleep(500);

			} else if (Choice == 1) { //�� �ܾ��ֱ�

				printf("%s�� ���� �ܾ��־����ϴ�.\n", name);
				Sleep(500);
				printf("2/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
				Sleep(500);
				printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
				Sleep(500);
				int Dice = rand() % 6 + 1;
				printf("%d��(��) ���Խ��ϴ�.!\n", Dice);
				Sleep(500);
				if (Dice > 4) {
					if (match < 4) {
						printf("ģ�е��� �������ϴ�.\n");
						match++;
						Sleep(500);
					}
					else {
						printf("ģ�е��� �ִ�ġ�Դϴ�.\n");
						Sleep(500);
					}
				}
				else {
					printf("ģ�е��� �״���Դϴ�.\n");
					Sleep(500);
				}
				printf("���� ģ�е�: %d\n", match);
			}

		Sleep(2500);
		system("cls");
	}


}