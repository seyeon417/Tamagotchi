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
int money = 0; //소지금

void print_start();                                 //시작 화면 출력
void start_or_end();                                //시작 메뉴 출력
void name();                                        //이름 정하기
void menu();                                        //메뉴
void eat_detail();                                  //먹기 세분화
void sleep_detail();                                //자기 세분화
void shower_detail();                               //씻기 세분화
void play_detail();                                 //놀기 세분화
void cham_game();
void stat();                                        //스텟
void happiness_ending();                            //행복도에 따른 엔딩 세분화
void my_money();                                    //소지금 출력

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

	//상점에 가고 싶으나 돈이 없는 경우
	if ((select_eat == 1) && (money < 300)) {
		printf("현재 %s의 소지금이 부족합니다.\n", name_str);
		printf("다시 선택해주십시오.\n");
		eat_detail();
	}
	//상점에 가고 싶으나 돈이 있는 경우
	else if ((select_eat == 1) && (money >= 300)) {
		printf("\n와! 마트로 갑니다!\n");
		Sleep(1000);
		printf("\n%s(이)의 배가 가득 찼습니다.\n", name_str);
		printf("\n또한 %s(이)의 기분이 행복합니다.\n", name_str);
		printf("마트에서 300원을 지출했습니다.\n");
		money -= 300;
		happiness += 30;
	}
	//상점에 가고 싶지 않은 경우
	else if (select_eat == 2) {
		printf("\n집에서 밥을 먹습니다.\n");
		Sleep(1000);
		srand((unsigned int)time(NULL));
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
			printf("마트에 가지 않고 집에서 먹어 돈을 아꼈습니다.\n");
			money += 100;
			happiness -= 100;
		}
		else if (eat_random == 2) {
			printf("\n%s(이)의 배가 어느정도 찼습니다.\n", name_str);
			printf("마트에 가지 않고 집에서 먹어 돈을 아꼈습니다.\n");
			money += 100;
			happiness += 10;
		}
		else if (eat_random == 3) {
			printf("\n%s(이)의 배가 어느정도 찼습니다.\n", name_str);
			printf("마트에 가지 않고 집에서 먹어 돈을 아꼈습니다.\n");
			money += 100;
			happiness += 10;
		}
		else if (eat_random == 4) {
			printf("\n%s(이)의 배가 어느정도 찼습니다.\n", name_str);
			printf("마트에 가지 않고 집에서 먹어 돈을 아꼈습니다.\n");
			money += 100;
			happiness += 10;
		}
		else if (eat_random == 5) {
			printf("\n%s(이)의 배가 어느정도 찼습니다.\n", name_str);
			printf("마트에 가지 않고 집에서 먹어 돈을 아꼈습니다.\n");
			money += 100;
			happiness += 10;
		}
	}
	//잘못 입력한 경우
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


	//푹신푹신 침대에서 자고 싶으나 돈이 없는 경우
	if ((select_sleep == 1) && (money < 200)) {
		printf("현재 %s의 소지금이 부족합니다.\n", name_str);
		printf("다시 선택해주십시오.\n");
		sleep_detail();
	}
	//푹신푹신 침대에서 자고 싶으나 돈이 있는 경우
	else if ((select_sleep == 1) && (money >= 200)) {
		printf("\n푹신푹신한 침대에서 잡니다...\n");
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("\n개운하게 일어났습니다! %s의 기분이 행복합니다.\n", name_str);
		printf("푹신푹신 침대에서 잤기 때문에 200원을 지출했습니다.\n");
		money -= 200;
		happiness += 50;
	}
	//평범한 침대에서 자고 싶은 경우
	else if (select_sleep == 2) {
		printf("\n평범한 침대에서 잡니다...\n");
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("\n%s는 일어났습니다! %s의 기분이 좋습니다.\n", name_str, name_str);
		printf("평범한 침대로 돈을 아꼈습니다.\n");
		money += 100;
		happiness += 20;
	}
	//잘못 입력한 경우
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

	//최고급 씻기를 하고 싶으나 돈이 없는 경우
	if ((select_shower == 1) && (money < 500)) {
		printf("현재 %s의 소지금이 부족합니다.\n", name_str);
		printf("다시 선택해주십시오.\n");
		shower_detail();
	}
	//최고급 씻기를 하고 싶으나 돈이 있는 경우
	else if ((select_shower == 1) && (money >= 500)) {
		printf("\n최고-급 러쉬 베쓰밤을 사용합니다!\n");
		printf("\n보글보글 거품이 올라와서 %s는 너무 행복해보이네요..!\n", name_str);
		printf("뽀..."); Sleep(1500);
		printf("득..."); Sleep(1500);
		printf("뽀..."); Sleep(1500);
		printf("득..."); Sleep(1500);
		printf("\n개운하게 목욕했습니다! %s의 기분이 행복합니다.\n", name_str);
		printf("최고-급 러쉬 배쓰밤으로 500원을 지출했습니다.\n");
		money -= 500;
		happiness += 50;
	}
	//빠른 샤워를 하고 싶은 경우
	else if (select_shower == 2) {
		printf("\n빠른 샤워를 합니다!\n");
		printf("뽀..."); Sleep(500);
		printf("득..."); Sleep(500);
		printf("뽀..."); Sleep(500);
		printf("득..."); Sleep(500);
		printf("\n광이 나게 씻었습니다! %s는 뿌듯합니다.\n", name_str);
		printf("빠른 샤워를 한 관계로 100원을 아꼈습니다.\n");
		money += 100;
		happiness += 20;
	}
	//잘못 입력한 경우
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
		cham_game();
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
		srand((unsigned int)time(NULL));
		int book_random = 0;
		book_random = rand() % 2 + 1; //1, 2
		if (book_random == 1) {
			Sleep(2000);
			printf("!!!");
			Sleep(500);
			printf("\n%s(은)는 책 한 권을 벌써 다 읽었습니다!\n대단한 %s!\n", name_str, name_str);
			printf("독서로 마음의 양식 100원을 쌓았습니다.\n");
			money += 100;
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

//참참참 게임
void cham_game() {
	printf("\n참참참 게임을 시작합니다!\n");
	char cham_answer[50] = { 0, }; //나의 답

	printf("어느 쪽을 고르시겠습니까? (left, center, right) >> ");
	scanf_s("%s", cham_answer, 50); //left, right, center
	if (strcmp(cham_answer, "left") == 0) {
		printf("\n왼쪽 선택!\n");
	}
	else if (strcmp(cham_answer, "center") == 0) {
		printf("\n가운데 선택!\n");
	}
	else if (strcmp(cham_answer, "right") == 0) {
		printf("\n오른쪽 선택!\n");
	}
	else {
		printf("\n잘못 입력하셨습니다.\n");
		cham_game();
	}
	Sleep(1000);
	printf("다"); Sleep(500);
	printf("마"); Sleep(500);
	printf("고"); Sleep(500);
	printf("치"); Sleep(500);
	printf("가"); Sleep(500);
	printf(" "); Sleep(500);
	printf("고"); Sleep(500);
	printf("르"); Sleep(500);
	printf("는"); Sleep(500);
	printf("중"); Sleep(500);
	printf("입"); Sleep(500);
	printf("니"); Sleep(500);
	printf("다"); Sleep(500);

	srand((unsigned int)time(NULL));
	int cham_random = 0; //다마고치의 답
	cham_random = rand() % 3 + 1; //1, 2, 3

	if (cham_random == 1) {
		printf("\n다마고치는 왼쪽을 골랐습니다.\n");
		if (strcmp(cham_answer, "left") == 0) {
			printf("\n맞혔습니다!\n");
			printf("\n이겼으니 상금을 드리겠습니다!\n");
			printf("\n다음에도 %s와 재밌게 놀아주세요!\n", name_str);
			money += 500;
			happiness += 20;
		}
		else if (strcmp(cham_answer, "left") != 0) {
			printf("\n아! 아쉽게도 맞추지 못했습니다!\n");
			printf("\n소정의 상금을 드리겠습니다!\n");
			printf("\n하지만 %s는 이겨서 기분이 좋은 것 같군요!\n", name_str);
			money += 100;
			happiness += 50;
		}
	}
	else if (cham_random == 2) {
		printf("\n다마고치는 가운데를 골랐습니다.\n");
		if (strcmp(cham_answer, "center") == 0) {
			printf("\n맞혔습니다!\n");
			printf("\n이겼으니 상금을 드리겠습니다!\n");
			printf("\n다음에도 %s와 재밌게 놀아주세요!\n", name_str);
			money += 500;
			happiness += 20;
		}
		else if (strcmp(cham_answer, "center") != 0) {
			printf("\n아! 아쉽게도 맞추지 못했습니다!\n");
			printf("\n소정의 상금을 드리겠습니다!\n");
			printf("\n하지만 %s는 이겨서 기분이 좋은 것 같군요!\n", name_str);
			money += 100;
			happiness += 50;
		}
	}
	else if (cham_random == 3) {
		printf("\n다마고치는 오른쪽을 골랐습니다.\n");
		if (strcmp(cham_answer, "right") == 0) {
			printf("\n맞혔습니다!\n");
			printf("\n이겼으니 상금을 드리겠습니다!\n");
			printf("\n다음에도 %s와 재밌게 놀아주세요!\n", name_str);
			money += 500;
			happiness += 20;
		}
		else if (strcmp(cham_answer, "right") != 0) {
			printf("\n아! 아쉽게도 맞추지 못했습니다!\n");
			printf("\n소정의 상금을 드리겠습니다!\n");
			printf("\n하지만 %s는 이겨서 기분이 좋은 것 같군요!\n", name_str);
			money += 100;
			happiness += 50;
		}
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
	printf("|   6. 소지금 확인                                  |\n");
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
	else if (select_menu == 6) {
		my_money();
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

void my_money() {
	printf("================================================\n");
	printf("|                                              |\n");
	printf("|    소지금: %d                                |\n", money);
	printf("|                                              |\n");
	printf("================================================\n");
}

//행복도에 따른 엔딩 세분화
void happiness_ending() {
	//0이하
	if (happiness < 0) {
		printf("\n\n%s에게 무슨 짓을 저지른건가요?\n", name_str); Sleep(1000);
		printf("%s(을)를 울리다니 참 잘 하셨습니다!\n", name_str); Sleep(1000);
		printf("당신의 다마고치 %s(은)는 당신 곁을 떠나갑니다...\n", name_str); Sleep(1000);
		printf("뭐... 게임을 플레이해주셔서 무척 감사드립니다!\n");
	}
	//0~20
	else if ((0 <= happiness) && (happiness < 20)) {
		printf("\n\n%s에게 무슨 일이 일어난건가요?\n", name_str); Sleep(1000);
		printf("%s가 슬프게 울고있습니다!\n", name_str); Sleep(1000);
		printf("당신의 다마고치 %s(은)는 슬피 울며 가출했습니다...\n", name_str); Sleep(1000);
		printf("뭐... 게임을 플레이해주셔서 무척 감사드립니다!\n");
	}
	//20~40
	else if ((20 <= happiness) && (happiness < 40)) {
		printf("\n\n%s(은)는 심술이 난 걸까요?\n", name_str); Sleep(1000);
		printf("%s의 기분이 좋아지기엔 아직 한참 먼 것 같네요!\n", name_str); Sleep(1000);
		printf("다음번엔 분발하셔야겠습니다!\n"); Sleep(1000);
		printf("게임을 플레이해주셔서 무척 감사드립니다!\n");
	}
	//40~60
	else if ((40 <= happiness) && (happiness < 60)) {
		printf("\n\n%s의 기분은 그럭저럭입니다.\n", name_str); Sleep(1000);
		printf("%s의 기분이 좋아지기엔 조금 부족한 것 같네요!\n", name_str); Sleep(1000);
		printf("다음번엔 분발하시리라 믿습니다!\n"); Sleep(1000);
		printf("게임을 플레이해주셔서 무척 감사드립니다!\n");
	}
	//60~80
	else if ((60 <= happiness) && (happiness < 80)) {
		printf("\n\n%s의 기분은 좋습니다!\n", name_str); Sleep(1000);
		printf("약간은 아쉽지만 지금 상황에 만족해보이는 것 같네요!\n"); Sleep(1000);
		printf("게임을 플레이해주셔서 무척 감사드립니다!\n");
	}
	//80~100
	else if ((80 <= happiness) && (happiness < 100)) {
		printf("\n\n%s의 기분은 최고입니다!\n", name_str); Sleep(1000);
		printf("당신은 다마고치 키우기의 고수군요!\n"); Sleep(1000);
		printf("%s의 행복도 100을 넘기면 좋은 일이 생길수도...?\n", name_str); Sleep(1000);
		printf("아무튼 게임을 플레이해주셔서 무척 감사드립니다!\n");
	}
	//100이상
	else if (happiness >= 100) {
		printf("\n\n%s의 기분은 당장이라도 날아갈 듯 합니다!\n", name_str); Sleep(1000);
		printf("당신은 다마고치 키우기의 신이군요!\n"); Sleep(1000);
		printf("행복도 100을 넘기기란 쉽지 않은데 넘기시다니...\n"); Sleep(1000);
		printf("특별한 선물을 드리도록 하겠습니다...!\n"); Sleep(1000);
		Sleep(2000);
		printf("당신은 \'다마고치의 보은\'을 얻었습니다!\n"); Sleep(1000);
		printf("이제부터 당신의 모든 코드는 \"완벽한 성공률\"을 보입니다!\n"); Sleep(1000);
		printf("게임을 플레이해주셔서 무척 감사드립니다!\n");
	}
}

int main(void)
{
	print_start();
	start_or_end();
	name();
	menu();
	stat();
	happiness_ending();
	return 0;
}