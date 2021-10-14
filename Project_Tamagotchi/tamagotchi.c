#include <stdio.h>
#include <Windows.h>

char name_str[50]; //이름
int food_count = 0;
int sleep_count = 0;
int shower_count = 0;
int game_count = 0;
int level = 0;
int happiness = 50;

void print_start();
void name();
void menu();
void store();
void stat();

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
	printf("|                                                   |\n");
	printf("|                                                   |\n");
	printf("|                                                   |\n");
	printf("=====================================================\n");
}
//이름 정하기
void name() {
	printf("\n\n당신의 다마고치 이름은? ");
	scanf_s("%s", name_str, 50);
	printf("%s로 정해졌습니다! %s는 행복합니다!\n\n", name_str, name_str); //name_str에 저장됨
}
//마트 가기
void store() {
	int select_yn;
	printf("상점에 가시겠습니까? (1: Yes, 2: No): ");
	scanf_s("%d", &select_yn);
	if (select_yn == 1) {
		printf("와! 마트!\n");
		Sleep(500);
		printf("%s(이)의 배가 가득 찼습니다.\n", name_str);
		printf("또한 %s(이)의 기분이 행복합니다.\n", name_str);
	}
	else if (select_yn == 2) {
		printf("집에서 밥을 먹습니다.\n");
		Sleep(500);
		printf("%s(이)의 배가 어느정도 찼습니다.\n", name_str);
	}
}
//메뉴 정하기
void menu() {
	int select;

	printf("무엇을 하시겠습니까?\n");
	printf("1. 먹기\n");
	printf("2. 자기\n");
	printf("3. 씻기\n");
	printf("4. 놀기\n");
	scanf_s("%d", &select);

	if (select == 1) {
		food_count++;
		printf("\n\nfood_count: %d\n\n", food_count);
		store();
		printf("%s(이)는 뇸뇸 먹습니다.\n\n", name_str);
	}
	else if (select == 2) {
		sleep_count++;
		printf("\n\nsleep_count: %d\n\n", sleep_count);
		printf("%s(이)는 쿨쿨 잡니다.\n\n", name_str);
	}
	else if (select == 3) {
		shower_count++;
		printf("\n\nshower_count: %d\n\n", shower_count);
		printf("%s(이)는 빡빡 씻습니다.\n\n", name_str);
	}
	else if (select == 4) {
		game_count++;
		printf("\n\ngame_count: %d\n\n", game_count);
		printf("%s(이)는 게임을 하며 놉니다.\n\n", name_str);
	}
	else {
		printf("\n%s(이)가 슬퍼합니다. 다시 골라주십시오\n", name_str);
	}
}
//스텟 출력
void stat() {
	printf("현재 %s의 스텟은?\n", name_str);
	printf("================================================\n");
	printf("|                                              |\n");
	printf("| 레벨: %d                                      |\n", level);
	printf("| 행복도: %d                                   |\n", happiness);
	printf("|                                              |\n");
	printf("================================================\n");

}
int main(void)
{
	print_start();
	name();
	menu();
	stat();
	return 0;
}