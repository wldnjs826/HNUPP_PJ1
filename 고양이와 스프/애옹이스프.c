#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_WIDTH 6
#define HME_POS 1
#define BWL_POS (ROOM_WIDTH - 2)
#define MAX(a, b) ((a) >= (b) ? (a) : (b))

int random(int a, int b) {
	return rand() % a + b;
}

void sp() {
	Sleep(500);
}

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



	int match = 2;
	int Move;
	int Soup = 0;
	int catback;
	int Choice;
	int CP = 0;
	int Feelings = 3;
	int S = random(BWL_POS - 1, HME_POS + 1);
	int T = random(BWL_POS - 1, HME_POS + 1);
	int Tset = 0;
	int Sset = 0;
	int buy;
	int Mset = 0;
	int Lset = 0;
	int price[5] = { 0, 1, 2, 4, 6 };
	int lost = 0;
	int turn = 1;
	
	//��Ʈ��
	while (1) {
		printf("==================== ���� ���� ===================\n");
		printf("������� ���� ����: %d��\n", Soup);
		printf("CP: %d ����Ʈ\n", CP);
		printf("%s ���(0~3): %d\n", name, Feelings);
		switch (Feelings) {
		default:
			printf("����� �ſ� ���޴ϴ�.\n");
			break;
		case 1:
			printf("�ɽ����մϴ�.\n");
			break;
		case 2:
			printf("�Ļ��� �����ϴ�.\n");
			break;
		case 3:
			printf("������ �θ��ϴ�.\n");
			break;
		}
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

		//��� ������
		int Dice2 = random(6, 1);
		printf("6-%d: �ֻ��� ���� %d�����̸� �׳� ����� �������ϴ�. ����̴ϱ�?\n", match, 6 - match);
		printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
		printf("%d��(��) ���Խ��ϴ�.\n", Dice2);
		if (Dice2 <= 6 - match) {
			int feel2 = Feelings;
			if (Feelings <= 0) {
				printf("���̻� ����� �������� �ʽ��ϴ�.: ");
			}
			else {
				Feelings--;
				printf("%s�� ����� �������ϴ�: ", name);
			}
			printf("%d->%d\n", feel2, Feelings);
		}



		//ver1 �̵�
		/*printf("�˶� �̵�: ����� ģ���� ���� ���������� �� �з��� �������ϴ�.\n");
		Sleep(500);
		printf("�ֻ��� ���� %d �̻��̸� ���� ������ �̵��մϴ�.\n", 6-match);
		Sleep(500);
		printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
		Sleep(500);
		int Dice = random(6,1);
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

		}*/

		//ver2 �̵�
		if (Feelings == 0) {
			if (catback == HME_POS) {
				printf("%s��(��) �ڽ��� ������ ������� �����ϴ�.\n", name);
				if (Feelings < 3) {
					Feelings++;
				} //������ ��ġ�� �����غ��� .�� ��ġ
			}
			else {
				printf("����� ���� %s��(��) ������ ���մϴ�.\n", name);
				cat--;
			}
		}
		else if (Feelings == 1) {
			//�ϴ� �������� ��ġ�Ȱ� Ȯ��
			if (Sset != 0 && Tset != 0) {
				int temp;
				if (abs(cat - T) > abs(cat - S)) {
					//T�� cat�ϰ� �� ����ﶧ 
					temp = 1;
				}
				else {
					//S�� �� ����ﶧ
					temp = 0;
				}

				//T�� �� �����
				if (temp == 1 && cat != T) {
					printf("%s��(��) �ɽ��ؼ� ĹŸ�� ������ �̵��մϴ�.\n", name);
					if (cat > T) {
						cat--;
					}
					else if (cat < T) {
						cat++;
					}
				}
				else if (temp == 0 && cat != S) {
					printf("%s��(��) �ɽ��ؼ� ��ũ���� ������ �̵��մϴ�.\n", name);
					if (cat > S) {
						cat--;
					}
					else if (cat < S) {
						cat++;
					}
				}
			}
			//�������� ��ġ���� ���� ���
			else {
				printf("��Ÿ��� ��� ����� �ſ� �������ϴ�.\n");
				if (Feelings > 0) {
					Feelings--;
				}
			}

			//������ ��ġ�Ǿ��� �� ������, Ŭ�� ���� ��ġ Ȯ��.
			//if (cat == T) {
			//	printf("%s��(��) ĹŸ���� �پ�ٴմ�.\n", name);
			//	printf("����� ���� ���������ϴ�.\n");
			//	Feelings + 2;
			//}
			//else if (cat == S) {
			//	printf("%s��(��) ��ũ���ĸ� �ܰ� ��ҽ��ϴ�.\n", name);
			//	printf("����� ���� ���������ϴ�.\n");
			//	Feelings++;
			//}


		}
		else if (Feelings == 2) {
			printf("%s��(��) ������� �Ļ��� ���� �ֽ��ϴ�.\n", name);
		}
		else {
			if (cat >= BWL_POS) {
				printf("�������� �ʾҽ��ϴ�.\n");
			}
			else {
				printf("%s��(��) ������ �θ��� ������ ���鷯 ���ϴ�.\n", name);
				cat++;
			}

		}

		//������ ��ġ�Ǿ��� �� ������, Ŭ�� ���� ��ġ Ȯ��.
		if (cat == T && Tset == 1) {
			printf("%s��(��) ĹŸ���� �پ�ٴմ�.\n", name);
			if (Feelings == 2) {
				printf("����� ���� ���������ϴ�.\n");
				Feelings++;
			}
			else if (Feelings == 3) {
				printf("����� �ְ����Դϴ�.");
			}
			else {
				printf("����� ���� ���������ϴ�.\n");
				Feelings += 2;
			}
		}
		else if (cat == S && Sset == 1) {
			printf("%s��(��) ��ũ���ĸ� �ܰ� ��ҽ��ϴ�.\n", name);
			if (Feelings == 3) {
				printf("����� �ְ����Դϴ�.");
			}
			else {
				printf("����� ���� ���������ϴ�.\n");
				Feelings++;
			}

		}

		// ����
		if (cat == BWL_POS) {
			int gacha = random(2, 0);
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
		for (int i = 0; i < 4; i++) {

			for (int j = 0; j < ROOM_WIDTH; j++) {

				if (j == 0 || j == ROOM_WIDTH - 1 || i == 0 || i == 3) {
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
				else if (Tset == 1 && i == 1 && j == T) {
					printf("T");
				}
				else if (Sset == 1 && i == 1 && j == S) {
					printf("S");
				}
				else {
					printf(" ");
				}
			}
			printf("\n");

		}

		printf("\n");

		//����
		if (Mset == 1 && Lset == 0) {
			printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n0. �ƹ��͵� ���� ����\n1.�ܾ� �ֱ�\n2.�峭�� ��� ����ֱ�\n");
			do {
				printf(">> ");
				scanf_s("%d", &Choice);
			} while (Choice != 0 && Choice != 1 && Choice != 2);
		}
		else if (Lset == 1 && Mset == 0) {
			printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n0. �ƹ��͵� ���� ����\n1.�ܾ� �ֱ�\n2. ������ �����ͷ� ����ֱ�\n");
			do {
				printf(">> ");
				scanf_s("%d", &Choice);
			} while (Choice != 0 && Choice != 1 && Choice != 2);
		}
		else if (Lset == 1 && Mset == 1) {
			printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n0. �ƹ��͵� ���� ����\n1.�ܾ� �ֱ�\n2.�峭�� ��� ����ֱ�\n3.������ �����ͷ� ��� �ֱ�\n");
			do {
				printf(">> ");
				scanf_s("%d", &Choice);
			} while (Choice != 0 && Choice != 1 && Choice != 2 && Choice != 3);
		}
		else {
			printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n0. �ƹ��͵� ���� ����\n1.�ܾ� �ֱ�\n");
			do {
				printf(">> ");
				scanf_s("%d", &Choice);
			} while (Choice != 0 && Choice != 1);
		}

		//�ƹ��͵� ���ϱ�
		if (Choice == 0) {
			printf("�ƹ��͵� ���� �ʽ��ϴ�.\n");
			Sleep(500);
			int feel2 = Feelings;
			if (Feelings == 0) {
				printf("����� �ʹ� ���� �ʽ��ϴ�.\n");
				printf("�̹� ����ġ �Դϴ�.\n");
			}
			else {
				Feelings--;
				printf("%s�� ����� ���������ϴ�:%d -> %d.\n", name, feel2, Feelings);
			}
			Sleep(500);
			printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
			Sleep(500);
			int Dice = random(6, 1);
			printf("%d��(��) ���Խ��ϴ�.!\n", Dice);
			Sleep(500);
			if (Dice <= 5) {
				if (match > 0) {
					printf("������� ���谡 �������ϴ�.\n");
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

		}
		else if (Choice == 1) { //�� �ܾ��ֱ�

			printf("%s�� ���� �ܾ��־����ϴ�.\n", name);
			Sleep(500);
			printf("%s�� ����� �״���Դϴ�: %d\n", name, Feelings);
			Sleep(500);
			printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
			Sleep(500);
			int Dice = random(6, 1);
			printf("%d��(��) ���Խ��ϴ�.!\n", Dice);
			Sleep(500);
			if (Dice >= 5) {
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
		else if (Choice == 2) { //�峭�� ��� ����ֱ�
			if (Feelings == 3) {
				printf("����� �̹� �ְ����Դϴ�.\n");
			}
			else {
				int feel2 = Feelings;
				Feelings++;
				printf("�峭�� ��� %s�� ��� �־����ϴ�. %s�� ����� ���������ϴ�:%d -> %d.\n", name, name, feel2, Feelings);
			}
			Sleep(500);
			printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
			Sleep(500);
			int Dice = random(6, 1);
			printf("%d��(��) ���Խ��ϴ�.!\n", Dice);
			Sleep(500);
			if (Dice >= 4) {
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
		else if (Choice == 3) { //������ ����Ʈ�� ����ֱ�
			if (Feelings == 1) {
				int feel2 = Feelings;
				Feelings += 2;
				printf("������ ����Ʈ�� %s�� �ų��� ��� �־����ϴ�. %s�� ����� �� ���������ϴ�:%d -> %d.\n", name, name, feel2, Feelings);
			}
			else if (Feelings == 2) {
				int feel2 = Feelings;
				Feelings++;
				printf("������ ����Ʈ�� %s�� �ų��� ��� �־����ϴ�. %s�� ����� �� ���������ϴ�:%d -> %d.\n", name, name, feel2, Feelings);
			}
			else {
				printf("����� �̹� �ְ����Դϴ�.\n");
			}
			Sleep(500);
			printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
			Sleep(500);
			int Dice = random(6, 1);
			printf("%d��(��) ���Խ��ϴ�.!\n", Dice);
			Sleep(500);
			if (Dice >= 2) {
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

		//CP ����
		printf("%s ���(0~3): %d\n", name, Feelings);
		printf("������� ģ�е�(0~4): %d\n", match);
		CP += MAX(0, Feelings - 1) + match;
		printf("%s�� ��а� ģ�е��� ���� CP�� %d ����Ʈ ����Ǿ����ϴ�.\n", name, MAX(0, Feelings - 1) + match);
		printf("���� CP: %d ����Ʈ\n", CP);


		// CP����
		printf("\n�������� ������ �� �� �ֽ��ϴ�.\n");
		printf("� ������ �����ұ��?\n");
		printf("0. �ƹ� �͵� ���� �ʴ´�.\n");
		printf("1. �峭�� ��: 1 CP%s\n", Mset ? " (ǰ��)" : "");
		printf("2. ������ ������: 2 CP%s\n", Lset ? " (ǰ��)" : "");
		printf("3. ��ũ��ó: 4 CP%s\n", Sset ? " (ǰ��)" : "");
		printf("4. Ĺ Ÿ��: 6 CP%s\n", Tset ? " (ǰ��)" : "");

		do {
			printf(">> ");
			scanf_s("%d", &buy);
		} while (buy < 0 || buy > 4);

		if (buy == 0) {
			printf("�ƹ��͵� �������� �ʾҽ��ϴ�.");
		}
		else if (buy == 1 && !Mset) {
			if (CP >= 1) {
				CP--;
				Mset = 1;
				printf("�峭�� �㸦 �����߽��ϴ�. ���� CP %d ����Ʈ\n", CP);
			}
			else printf("CP�� �����մϴ�.\n");
		}
		else if (buy == 2 && !Lset) {
			if (CP >= 2) {
				CP -= 2;
				Lset = 1;
				printf("������ �����͸� �����߽��ϴ�. ���� CP %d ����Ʈ\n", CP);
			}
			else printf("CP�� �����մϴ�.\n");
		}
		else if (buy == 3 && !Sset) {
			if (CP >= 4) {
				Sset = 1;
				CP -= 4;
				printf("��ũ��ó�� �����߽��ϴ�. ���� CP %d ����Ʈ\n", CP);
				do {
					S = random(BWL_POS - 1, HME_POS + 1);
				} while (S == T);
			}
			else printf("CP�� �����մϴ�.\n");
		}
		else if (buy == 4 && !Tset) {
			if (CP >= 6) {
				Tset = 1;
				CP -= 6;
				printf("Ĺ Ÿ���� �����߽��ϴ�. ���� CP %d ����Ʈ\n", CP);
				do {
					T = random(BWL_POS - 1, HME_POS + 1);
				} while (S == T);
			}
			else printf("CP�� �����մϴ�.\n");
		}
		else if (Tset == 1 || Sset == 1 || Mset == 1 || Lset == 1) {
			printf("�̹� ������ �����Դϴ�.\n");
		}


		//���� ����Ʈ
		if (turn == 3) {
			system("cls");
			int gacha = random(45, 1);
			int lotto;
			printf("0~45 ���� �� �ϳ��� �Է��ϼ���\n");
			printf(">>");
			scanf_s("%d", &lotto);
			if (lotto == gacha) {
				printf("�¾ҽ��ϴ�!!!");
			}
			else {
				printf("�ƽ��Ե� Ʋ�Ƚ��ϴ� �ФФ�");
			}


		}
		Sleep(2500);
		system("cls");
		turn++;
	}
}