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
	printf("****야옹이와 수프****\n");
	printf("      /\\_/\\\n /\\  / o o \\\n//\\\\ \\~(*)~/\n`  \\/   ^ / \n   l \\ll ll \n   \\ 'll ll \n    \\)()-())\n");
	printf("야옹이의 이름을 지어주세요:");
	scanf_s("%s", name, sizeof(name));
	printf("야옹이의 이름은 %s입니다.", name);
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
	
	//인트로
	while (1) {
		printf("==================== 현재 상태 ===================\n");
		printf("현재까지 만든 수프: %d개\n", Soup);
		printf("CP: %d 포인트\n", CP);
		printf("%s 기분(0~3): %d\n", name, Feelings);
		switch (Feelings) {
		default:
			printf("기분이 매우 나쁩니다.\n");
			break;
		case 1:
			printf("심심해합니다.\n");
			break;
		case 2:
			printf("식빵을 굽습니다.\n");
			break;
		case 3:
			printf("골골송을 부릅니다.\n");
			break;
		}
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

		//기분 나빠짐
		int Dice2 = random(6, 1);
		printf("6-%d: 주사위 눈이 %d이하이면 그냥 기분이 나빠집니다. 고양이니까?\n", match, 6 - match);
		printf("주사위를 굴립니다. 또르륵...\n");
		printf("%d이(가) 나왔습니다.\n", Dice2);
		if (Dice2 <= 6 - match) {
			int feel2 = Feelings;
			if (Feelings <= 0) {
				printf("더이상 기분이 나빠지지 않습니다.: ");
			}
			else {
				Feelings--;
				printf("%s의 기분이 나빠집니다: ", name);
			}
			printf("%d->%d\n", feel2, Feelings);
		}



		//ver1 이동
		/*printf("쫀떡 이동: 집사와 친밀할 수록 냄비쪽으로 갈 학률이 높아집니다.\n");
		Sleep(500);
		printf("주사위 눈이 %d 이상이면 냄비 쪽으로 이동합니다.\n", 6-match);
		Sleep(500);
		printf("주사위를 굴립니다. 또르륵...\n");
		Sleep(500);
		int Dice = random(6,1);
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

		}*/

		//ver2 이동
		if (Feelings == 0) {
			if (catback == HME_POS) {
				printf("%s은(는) 자신의 집에서 편안함을 느낍니다.\n", name);
				if (Feelings < 3) {
					Feelings++;
				} //직전의 위치를 생각해봐라 .의 위치
			}
			else {
				printf("기분이 나쁜 %s은(는) 집으로 향합니다.\n", name);
				cat--;
			}
		}
		else if (Feelings == 1) {
			//일단 아이템이 배치된거 확인
			if (Sset != 0 && Tset != 0) {
				int temp;
				if (abs(cat - T) > abs(cat - S)) {
					//T가 cat하고 더 가까울때 
					temp = 1;
				}
				else {
					//S가 더 가까울때
					temp = 0;
				}

				//T가 더 가까움
				if (temp == 1 && cat != T) {
					printf("%s은(는) 심심해서 캣타워 쪽으로 이동합니다.\n", name);
					if (cat > T) {
						cat--;
					}
					else if (cat < T) {
						cat++;
					}
				}
				else if (temp == 0 && cat != S) {
					printf("%s은(는) 심심해서 스크래쳐 쪽으로 이동합니다.\n", name);
					if (cat > S) {
						cat--;
					}
					else if (cat < S) {
						cat++;
					}
				}
			}
			//아이템이 배치되지 않은 경우
			else {
				printf("놀거리가 없어서 기분이 매우 나빠집니다.\n");
				if (Feelings > 0) {
					Feelings--;
				}
			}

			//아이템 배치되었을 때 작을때, 클때 같은 위치 확인.
			//if (cat == T) {
			//	printf("%s은(는) 캣타워를 뛰어다닙다.\n", name);
			//	printf("기분이 제법 좋아졌습니다.\n");
			//	Feelings + 2;
			//}
			//else if (cat == S) {
			//	printf("%s은(는) 스크래쳐를 긁고 놀았습니다.\n", name);
			//	printf("기분이 조금 좋아졌습니다.\n");
			//	Feelings++;
			//}


		}
		else if (Feelings == 2) {
			printf("%s은(는) 기분좋게 식빵을 굽고 있습니다.\n", name);
		}
		else {
			if (cat >= BWL_POS) {
				printf("움직이지 않았습니다.\n");
			}
			else {
				printf("%s은(는) 골골송을 부르며 수프를 만들러 갑니다.\n", name);
				cat++;
			}

		}

		//아이템 배치되었을 때 작을때, 클때 같은 위치 확인.
		if (cat == T && Tset == 1) {
			printf("%s은(는) 캣타워를 뛰어다닙다.\n", name);
			if (Feelings == 2) {
				printf("기분이 제법 좋아졌습니다.\n");
				Feelings++;
			}
			else if (Feelings == 3) {
				printf("기분이 최고조입니다.");
			}
			else {
				printf("기분이 제법 좋아졌습니다.\n");
				Feelings += 2;
			}
		}
		else if (cat == S && Sset == 1) {
			printf("%s은(는) 스크래쳐를 긁고 놀았습니다.\n", name);
			if (Feelings == 3) {
				printf("기분이 최고조입니다.");
			}
			else {
				printf("기분이 조금 좋아졌습니다.\n");
				Feelings++;
			}

		}

		// 수프
		if (cat == BWL_POS) {
			int gacha = random(2, 0);
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

		//선택
		if (Mset == 1 && Lset == 0) {
			printf("어떤 상호작용을 하시겠습니까?\n0. 아무것도 하지 않음\n1.긁어 주기\n2.장난감 쥐로 놀아주기\n");
			do {
				printf(">> ");
				scanf_s("%d", &Choice);
			} while (Choice != 0 && Choice != 1 && Choice != 2);
		}
		else if (Lset == 1 && Mset == 0) {
			printf("어떤 상호작용을 하시겠습니까?\n0. 아무것도 하지 않음\n1.긁어 주기\n2. 레이저 포인터로 놀아주기\n");
			do {
				printf(">> ");
				scanf_s("%d", &Choice);
			} while (Choice != 0 && Choice != 1 && Choice != 2);
		}
		else if (Lset == 1 && Mset == 1) {
			printf("어떤 상호작용을 하시겠습니까?\n0. 아무것도 하지 않음\n1.긁어 주기\n2.장난감 쥐로 놀아주기\n3.레이저 포인터로 놀아 주기\n");
			do {
				printf(">> ");
				scanf_s("%d", &Choice);
			} while (Choice != 0 && Choice != 1 && Choice != 2 && Choice != 3);
		}
		else {
			printf("어떤 상호작용을 하시겠습니까?\n0. 아무것도 하지 않음\n1.긁어 주기\n");
			do {
				printf(">> ");
				scanf_s("%d", &Choice);
			} while (Choice != 0 && Choice != 1);
		}

		//아무것도 안하기
		if (Choice == 0) {
			printf("아무것도 하지 않습니다.\n");
			Sleep(500);
			int feel2 = Feelings;
			if (Feelings == 0) {
				printf("기분이 너무 좋지 않습니다.\n");
				printf("이미 최하치 입니다.\n");
			}
			else {
				Feelings--;
				printf("%s의 기분이 나빠졌습니다:%d -> %d.\n", name, feel2, Feelings);
			}
			Sleep(500);
			printf("주사위를 굴립니다. 또르륵...\n");
			Sleep(500);
			int Dice = random(6, 1);
			printf("%d이(가) 나왔습니다.!\n", Dice);
			Sleep(500);
			if (Dice <= 5) {
				if (match > 0) {
					printf("집사와의 관계가 나빠집니다.\n");
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

		}
		else if (Choice == 1) { //턱 긁어주기

			printf("%s의 턱을 긁어주었습니다.\n", name);
			Sleep(500);
			printf("%s의 기분은 그대로입니다: %d\n", name, Feelings);
			Sleep(500);
			printf("주사위를 굴립니다. 또르륵...\n");
			Sleep(500);
			int Dice = random(6, 1);
			printf("%d이(가) 나왔습니다.!\n", Dice);
			Sleep(500);
			if (Dice >= 5) {
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
		else if (Choice == 2) { //장난감 쥐로 놀아주기
			if (Feelings == 3) {
				printf("기분이 이미 최고조입니다.\n");
			}
			else {
				int feel2 = Feelings;
				Feelings++;
				printf("장난감 쥐로 %s와 놀아 주었습니다. %s의 기분이 좋아졌습니다:%d -> %d.\n", name, name, feel2, Feelings);
			}
			Sleep(500);
			printf("주사위를 굴립니다. 또르륵...\n");
			Sleep(500);
			int Dice = random(6, 1);
			printf("%d이(가) 나왔습니다.!\n", Dice);
			Sleep(500);
			if (Dice >= 4) {
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
		else if (Choice == 3) { //레이저 포인트로 놀아주기
			if (Feelings == 1) {
				int feel2 = Feelings;
				Feelings += 2;
				printf("레이저 포인트로 %s와 신나게 놀아 주었습니다. %s의 기분이 꽤 좋아졌습니다:%d -> %d.\n", name, name, feel2, Feelings);
			}
			else if (Feelings == 2) {
				int feel2 = Feelings;
				Feelings++;
				printf("레이저 포인트로 %s와 신나게 놀아 주었습니다. %s의 기분이 꽤 좋아졌습니다:%d -> %d.\n", name, name, feel2, Feelings);
			}
			else {
				printf("기분이 이미 최고조입니다.\n");
			}
			Sleep(500);
			printf("주사위를 굴립니다. 또르륵...\n");
			Sleep(500);
			int Dice = random(6, 1);
			printf("%d이(가) 나왔습니다.!\n", Dice);
			Sleep(500);
			if (Dice >= 2) {
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

		//CP 생산
		printf("%s 기분(0~3): %d\n", name, Feelings);
		printf("집사와의 친밀도(0~4): %d\n", match);
		CP += MAX(0, Feelings - 1) + match;
		printf("%s의 기분과 친밀도에 따라서 CP가 %d 포인트 생산되었습니다.\n", name, MAX(0, Feelings - 1) + match);
		printf("보유 CP: %d 포인트\n", CP);


		// CP상점
		printf("\n상점에서 물건을 살 수 있습니다.\n");
		printf("어떤 물건을 구매할까요?\n");
		printf("0. 아무 것도 사지 않는다.\n");
		printf("1. 장난감 쥐: 1 CP%s\n", Mset ? " (품절)" : "");
		printf("2. 레이저 포인터: 2 CP%s\n", Lset ? " (품절)" : "");
		printf("3. 스크래처: 4 CP%s\n", Sset ? " (품절)" : "");
		printf("4. 캣 타워: 6 CP%s\n", Tset ? " (품절)" : "");

		do {
			printf(">> ");
			scanf_s("%d", &buy);
		} while (buy < 0 || buy > 4);

		if (buy == 0) {
			printf("아무것도 구매하지 않았습니다.");
		}
		else if (buy == 1 && !Mset) {
			if (CP >= 1) {
				CP--;
				Mset = 1;
				printf("장난감 쥐를 구매했습니다. 보유 CP %d 포인트\n", CP);
			}
			else printf("CP가 부족합니다.\n");
		}
		else if (buy == 2 && !Lset) {
			if (CP >= 2) {
				CP -= 2;
				Lset = 1;
				printf("레이저 포인터를 구매했습니다. 보유 CP %d 포인트\n", CP);
			}
			else printf("CP가 부족합니다.\n");
		}
		else if (buy == 3 && !Sset) {
			if (CP >= 4) {
				Sset = 1;
				CP -= 4;
				printf("스크래처를 구매했습니다. 보유 CP %d 포인트\n", CP);
				do {
					S = random(BWL_POS - 1, HME_POS + 1);
				} while (S == T);
			}
			else printf("CP가 부족합니다.\n");
		}
		else if (buy == 4 && !Tset) {
			if (CP >= 6) {
				Tset = 1;
				CP -= 6;
				printf("캣 타워를 구매했습니다. 보유 CP %d 포인트\n", CP);
				do {
					T = random(BWL_POS - 1, HME_POS + 1);
				} while (S == T);
			}
			else printf("CP가 부족합니다.\n");
		}
		else if (Tset == 1 || Sset == 1 || Mset == 1 || Lset == 1) {
			printf("이미 구매한 물건입니다.\n");
		}


		//돌발 퀘스트
		if (turn == 3) {
			system("cls");
			int gacha = random(45, 1);
			int lotto;
			printf("0~45 숫자 중 하나를 입력하세요\n");
			printf(">>");
			scanf_s("%d", &lotto);
			if (lotto == gacha) {
				printf("맞았습니다!!!");
			}
			else {
				printf("아쉽게도 틀렸습니다 ㅠㅠㅠ");
			}


		}
		Sleep(2500);
		system("cls");
		turn++;
	}
}