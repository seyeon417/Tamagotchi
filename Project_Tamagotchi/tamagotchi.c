#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char name_str[50]; //이름
int start_end;
int food_count = 0;
int sleep_count = 0;
int shower_count = 0;
int play_count = 0;
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
void happiness_ending();                            //행복도에 따른 엔딩 세분화

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
		happiness += 30;
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
			happiness -= 100;
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
		happiness += 50;
	}
	else if (select_sleep == 2) {
		printf("\n평범한 침대에서 잡니다...\n");
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("\n%s는 일어났습니다! %s의 기분이 좋습니다.\n", name_str, name_str);
		happiness += 20;
	}
	else {
		printf("\n다시 입력해주세요\n");
		sleep_detail();
	}
}

//씻기 세분화
void shower_detail() {
	int select_shower;

	printf("\n\n<씻기>를 선택하셨습니다!\n\n");

	printf("무엇으로 씻을까요? (1: 최고급 러쉬 배쓰밤, 2: 빠른 샤워): ");
	scanf_s("%d", &select_shower);

	if (select_shower == 1) {
		printf("\n최고-급 러쉬 베쓰밤을 사용합니다!\n");
		printf("\n보글보글 거품이 올라와서 %s는 너무 행복해보이네요..!\n", name_str);
		printf("뽀..."); Sleep(1500);
		printf("득..."); Sleep(1500);
		printf("뽀..."); Sleep(1500);
		printf("득..."); Sleep(1500);
		printf("\n개운하게 목욕했습니다! %s의 기분이 행복합니다.\n", name_str);
		happiness += 50;
	}
	else if (select_shower == 2) {
		printf("\n빠른 샤워를 합니다!\n");
		printf("뽀..."); Sleep(500);
		printf("득..."); Sleep(500);
		printf("뽀..."); Sleep(500);
		printf("득..."); Sleep(500);
		printf("\n광이 나게 씻었습니다! %s는 뿌듯합니다.\n", name_str);
		happiness += 20;
	}
	else {
		printf("\n다시 입력해주세요\n");
		shower_detail();
	}
}

//놀기 세분화
void play_detail() {
	int select_play;

	printf("\n\n<놀기>를 선택하셨습니다!\n노는게 제일 좋아!\n\n");

	printf("무엇을 하며 놀까요? (1: 최신 유행 놀이 참참참, 2: 유튜브 시청, 3: 독서): ");
	scanf_s("%d", &select_play);

	if (select_play == 1) {
		//참참참 게임
		printf("\n참참참 게임을 시작합니다!\n");
		char cham_answer[50];

		printf("어느 쪽을 고르시겠습니까? (왼쪽, 오른쪽, 가운데) >> ");
		scanf_s("%s", cham_answer, 50); //왼쪽, 오른쪽, 가운데, left, right, center
		if ((strcmp(cham_answer, "왼쪽") == 0) || strcmp(cham_answer, "left") == 0) {
			printf("왼쪽 선택!\n");
		}
		else if (strcmp(cham_answer, "가운데") == 0 || strcmp(cham_answer, "center") == 0) {
			printf("가운데 선택!\n");
		}
		else if (strcmp(cham_answer, "오른쪽") == 0 || strcmp(cham_answer, "right") == 0) {
			printf("오른쪽 선택!\n");
		}
		else {
			printf("잘못 입력하셨습니다.");
			//다시 돌아가기
		}
		Sleep(1000);

		srand((unsigned int)time(NULL));
		int cham_random = 0;
		cham_random = rand() % 3 + 1; //1, 2, 3
		//int* left, center, right;
		if (cham_random == 1) {
			//left = &cham_random;
			printf("\n%s는 왼쪽을 골랐습니다.\n", name_str);
		}
		else if (cham_random == 2) {
			//center = &cham_random;
			printf("\n%s는 가운데를 골랐습니다.\n", name_str);
		}
		else if (cham_random == 3) {
			//right = &cham_random;
			printf("\n%s는 오른쪽을 골랐습니다.\n", name_str);
		}
		//내가 먼저 선택 후 다마고치가 무엇을 선택했는지 출력
		//나의 답과 다마고치 답과 비교하여 정답인지 아닌지 출력
		//포인터 사용 or 입력을 정수값으로 받기
		//이기면 행복도 +50, 돈 +100
	}
	else if (select_play == 2) {
		printf("\n유튜브를 시청합니다! 유튜브는 참 재미있군요!\n");
		Sleep(2000);
		printf("!!!");
		Sleep(500);
		printf("\n앗, 벌써 시간이 이렇게나!!!\n하지만 참 재밌었습니다\n");
		happiness += 30;
	}
	else if (select_play == 3) {
		printf("\n독서를 합니다! 독서는 참 좋은 취미군요!\n");
		srand(time(NULL));
		int book_random = 0;
		book_random = rand() % 2 + 1; //1, 2
		if (book_random == 1) {
			Sleep(2000);
			printf("!!!");
			Sleep(500);
			printf("\n%s(은)는 책 한 권을 벌써 다 읽었습니다!\n대단한 %s!\n", name_str, name_str);
			happiness += 30;
		}
		else if (book_random == 2) {
			Sleep(2000);
			printf("???");
			Sleep(500);
			printf("\n%s(은)는 책을 읽다 잠들었습니다!\n어째서인지 행복해보입니다\n", name_str);
			happiness += 30;
		}
	}
	else {
		printf("\n다시 입력해주세요\n");
		play_detail();
	}
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
	printf("|                                                   |\n");
	printf("=====================================================\n");
	scanf_s("%d", &select_menu);

	if (select_menu == 1) {
		food_count++;
		printf("\n\nfood_count: %d\n\n", food_count);
		//레벨 1 푸드 카운트가 찼다고 알려주기
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
		play_count++;
		printf("\n\nplay_count: %d\n\n", play_count);
		play_detail();
	}
	else if (select_menu == 5) {
		stat();
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

//행복도에 따른 엔딩 세분화
void happiness_ending() {

}

int main(void)
{
	print_start();
	start_or_end();
	name();
	menu();
	//stat();
	happiness_ending();
	return 0;
}