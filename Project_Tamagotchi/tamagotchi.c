#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

char name_str[50]; //이름
int start_end;
int food_count = 0;
int sleep_count = 0;
int shower_count = 0;
int game_count = 0;
int level = 0;
int happiness = 50;

void print_start();                                 //시작 화면 출력
void start_or_end();                                //시작 메뉴 출력
void name();                                        //이름 정하기
void menu();                                        //메뉴
void eat_detail();                                  //먹기 세분화
void sleep_detail();                                //자기 세분화
void shower_detail();                               //씻기 세분화
void play_detail();                                 //놀기 세분화
void stat();                                        //스텟

//시작 화면 출력
void print_start() {
	printf("=====================================================\n");
	printf("|                                                   |\n");
	printf("|                                                   |\n");
	printf("|                                                   |\n");
	printf("|                                                   |\n");
	printf("|                                                   |\n");
	printf("|             나만의 다마고치 키우기                |\n");
	printf("|                                                   |\n");
	printf("|                                                   |\n");
	printf("|                              1. 시작하기          |\n");
	printf("|                              2. 종료하기          |\n");
	printf("|                                                   |\n");
	printf("=====================================================\n");
}

//시작 메뉴
void start_or_end() {
	printf("\n입력하십시오>> ");
	scanf_s("%d", &start_end);
	switch (start_end) {
	case 1:
		printf("\n게임을 시작합니다.\n\n");
		printf("."); Sleep(500);
		printf("."); Sleep(500);
		printf("."); Sleep(500);
		system("cls");
		break;
	case 2:
		printf("\n게임을 종료합니다.\n");
		exit(0);
		break;
	default:
		printf("\n잘못 입력하셨습니다.\n");
		start_or_end();
		break;
	}
}

//이름 정하기
void name() {
	printf("\n\n당신의 다마고치 이름은? ");
	scanf_s("%s", name_str, 50);
	printf("\n\n%s(으)로 정해졌습니다! %s(은)는 행복합니다!\n\n", name_str, name_str); //name_str에 저장됨
}

//먹기 세분화
void eat_detail() {
	int select_eat;

	printf("\n\n<먹기>를 선택하셨습니다!\n\n");

	printf("상점에 가시겠습니까? (1: 네, 2: 아니오): ");
	scanf_s("%d", &select_eat);
	if (select_eat == 1) {
		printf("\n와! 마트로 갑니다!\n");
		Sleep(1000);
		printf("\n%s(이)의 배가 가득 찼습니다.\n", name_str);
		printf("\n또한 %s(이)의 기분이 행복합니다.\n", name_str);
		happiness += 20;
	}
	else if (select_eat == 2) {
		printf("\n집에서 밥을 먹습니다.\n");
		Sleep(1000);
		srand(time(NULL));
		int eat_random;
		eat_random = rand() % 5 + 1; //1, 2, 3, 4, 5
		if (eat_random == 1) {
			printf("."); Sleep(1000);
			printf("."); Sleep(1000);
			printf("."); Sleep(1000);
			printf("?!?!"); Sleep(1500);
			printf("\n");
			printf("\n기한이 지난 음식이었습니다!!!\n");
			printf("\n%s(은)는 배탈이 나진 않았지만 기분은 울적합니다...\n", name_str);
			happiness -= 30;
		}
		else if (eat_random == 2) {
			printf("\n%s(이)의 배가 어느정도 찼습니다.\n", name_str);
			happiness += 10;
		}
		else if (eat_random == 3) {
			printf("\n%s(이)의 배가 어느정도 찼습니다.\n", name_str);
			happiness += 10;
		}
		else if (eat_random == 4) {
			printf("\n%s(이)의 배가 어느정도 찼습니다.\n", name_str);
			happiness += 10;
		}
		else if (eat_random == 5) {
			printf("\n%s(이)의 배가 어느정도 찼습니다.\n", name_str);
			happiness += 10;
		}
	}
	else {
		printf("\n다시 입력해주세요\n");
		eat_detail();
	}
}

//자기 세분화
void sleep_detail() {
	int select_sleep;

	printf("\n\n<자기>를 선택하셨습니다!\n\n");

	printf("어디서 잘까요? (1: 푹신푹신 침대, 2: 평범한 침대): ");
	scanf_s("%d", &select_sleep);

	if (select_sleep == 1) {
		printf("\n푹신푹신한 침대에서 잡니다...\n");
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("\n개운하게 일어났습니다! %s의 기분이 행복합니다.\n", name_str);
		happiness += 20;
	}
	else if (select_sleep == 2) {
		printf("\n평범한 침대에서 잡니다...\n");
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("\n%s는 일어났습니다! %s의 기분이 좋습니다.\n", name_str, name_str);
		happiness += 10;
	}
	else {
		printf("\n다시 입력해주세요\n");
		sleep_detail();
	}
}

//씻기 세분화
void shower_detail() {

}

//놀기 세분화
void play_detail() {

}

//메뉴 정하기
void menu() {
	int select_menu;
	printf("=====================================================\n");
	printf("|                                                   |\n");
	printf("|                                                   |\n");
	printf("|   무엇을 하시겠습니까?                            |\n");
	printf("|                                                   |\n");
	printf("|   1. 먹기                                         |\n");
	printf("|   2. 자기                                         |\n");
	printf("|   3. 씻기                                         |\n");
	printf("|   4. 놀기                                         |\n");
	printf("|   5. 스텟 확인                                    |\n");
	printf("|                                                   |\n");
	printf("=====================================================\n");
	scanf_s("%d", &select_menu);

	if (select_menu == 1) {
		food_count++;
		printf("\n\nfood_count: %d\n\n", food_count);
		eat_detail();
	}
	else if (select_menu == 2) {
		sleep_count++;
		printf("\n\nsleep_count: %d\n\n", sleep_count);
		sleep_detail();
	}
	else if (select_menu == 3) {
		shower_count++;
		printf("\n\nshower_count: %d\n\n", shower_count);
		shower_detail();
	}
	else if (select_menu == 4) {
		game_count++;
		printf("\n\ngame_count: %d\n\n", game_count);
		play_detail();
	}
	else {
		printf("\n%s(이)가 슬퍼합니다. 다시 골라주십시오\n", name_str);
		menu();
	}
}

//스텟 출력
void stat() {
	printf("현재 %s의 스텟은?\n", name_str);
	printf("================================================\n");
	printf("|                                              |\n");
	printf("|    레벨: %d                                  |\n", level);
	printf("|    행복도: %d                                |\n", happiness);
	printf("|                                              |\n");
	printf("================================================\n");
}

int main(void)
{
	print_start();
	start_or_end();
	name();
	menu();
	//stat();
	return 0;
}