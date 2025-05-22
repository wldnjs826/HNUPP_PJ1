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
	printf("****야옹이와 수프****\n");
	printf("      /\\_/\\\n /\\  / o o \\\n//\\\\ \\~(*)~/\n`  \\/   ^ / \n   l \\ll ll \n   \\ 'll ll \n    \\)()-())\n");
	printf("야옹이의 이름을 지어주세요:");
	scanf_s("%s", name, sizeof(name));
	printf("야옹이의 이름은 %s입니다.", name);
	Sleep(1000); system("cls");


	//인트로
	int match=2,Move,Soup=0,catback, Choice;
	while (1) {
		printf("==================== 현재 상태 ===================\n");
		printf("현재까지 만든 수프: %d개\n", Soup);
		printf("집사와의 관계(0~4): %d\n", match);
		switch (match) {
		case 4:
			printf("집사 껌딱지입니다.\n");
			break;
		case 3:
			printf("훌륭한 집사로 인정 받고 있습니다.\n");
			break;
		case 2:
			printf("그럭저럭 쓸 만한 집사입니다.\n");
			break;
		case 1:
			printf("간식 자판기 취급입니다.\n");
			break;
		default:
			printf("곁에 오는 것조차 싫어합니다.\n");
			break;
		}
		printf("==================================================\n");
		Sleep(500);

		catback = cat;
		
		//이동
		printf("쫀떡 이동: 집사와 친밀할 수록 냄비쪽으로 갈 학률이 높아집니다.\n");
		Sleep(500);
		printf("주사위 눈이 %d 이상이면 냄비 쪽으로 이동합니다.\n", 6-match);
		Sleep(500);
		printf("주사위를 굴립니다. 또르륵...\n");
		Sleep(500);
		int Dice = rand() % 6 + 1;
		printf("%d이(가) 나왔습니다.!\n", Dice);
		Sleep(500);
		if (Dice >= 6 - match) {
			if (cat == BWL_POS) {
				printf("움직이지 않았습니다.");
			}
			else {
				printf("냄비 쪽으로 움직입니다.\n");
				cat++;
				Sleep(500);
			}
			
		}
		else {
			if (cat == HME_POS) {
				printf("%s은(는) 자신의 집에서 편안함을 느낍니다.\n", name);
				Sleep(500);
			}
			else {
				printf("집 쪽으로 움직입니다.\n");
				Sleep(500);
				cat--;
				if (cat == HME_POS) {
					printf("%s은(는) 자신의 집에서 편안함을 느낍니다.\n", name);
				}
			}

		}
			
		// 수프
		if (cat == BWL_POS) {
			int gacha = rand() % 2;
			switch (gacha) {
				case 2: 
					printf("%s이(가) 감자수프를 만들었습니다!\n", name);
					break;
				case 1:
					printf("%s이(가) 양송이수프를 만들었습니다!\n", name);
					break;
				case 0:
					printf("%s이(가) 브로콜리수프를 만들었습니다!\n", name);
					break;
			}
			Soup++;
			Sleep(500);
			printf("현재까지 만든 스프: %d개\n", Soup);
			Sleep(500);
		}

		// i 세로 / j 가로
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

		//선택
		printf("어떤 상호작용을 하시겠습니까? 0. 아무것도 하지 않음 1. 긁어 주기\n");
		do {
			printf(">> ");
			scanf_s("%d", &Choice);
		} while (Choice != 0 && Choice != 1);

			//아무것도 안하기
			if (Choice == 0) {
				printf("아무것도 하지 않습니다.\n");
				Sleep(500);
				printf("4/6의 확률로 친밀도가 떨어집니다.\n");
				Sleep(500);
				printf("주사위를 굴립니다. 또르륵...\n");
				Sleep(500);
				int Dice = rand() % 6 + 1;
				printf("%d이(가) 나왔습니다.!\n", Dice);
				Sleep(500);
				if (Dice <= 4) {
					if (match > 0) {
						printf("친밀도가 떨어집니다.\n");
						match--;
						Sleep(500);
					}
					else {
						printf("친밀도가 더 이상 내려가지 않습니다.\n");
						Sleep(500);
					}

				}
				else {
					printf("다행히 친밀도가 떨어지지 않았습니다.\n");
					Sleep(500);
				}
				printf("현재 친밀도: %d\n", match);
				Sleep(500);

			} else if (Choice == 1) { //턱 긁어주기

				printf("%s의 턱을 긁어주었습니다.\n", name);
				Sleep(500);
				printf("2/6의 확률로 친밀도가 높아집니다.\n");
				Sleep(500);
				printf("주사위를 굴립니다. 또르륵...\n");
				Sleep(500);
				int Dice = rand() % 6 + 1;
				printf("%d이(가) 나왔습니다.!\n", Dice);
				Sleep(500);
				if (Dice > 4) {
					if (match < 4) {
						printf("친밀도가 높아집니다.\n");
						match++;
						Sleep(500);
					}
					else {
						printf("친밀도는 최대치입니다.\n");
						Sleep(500);
					}
				}
				else {
					printf("친밀도는 그대로입니다.\n");
					Sleep(500);
				}
				printf("현재 친밀도: %d\n", match);
			}

		Sleep(2500);
		system("cls");
	}


}