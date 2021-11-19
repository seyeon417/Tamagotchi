#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char name_str[50]; //�̸�
int start_end;
int food_count = 0;
int sleep_count = 0;
int shower_count = 0;
int play_count = 0;
int level = 0;
int happiness = 50;
int money = 0; //������

void print_start();                                 //���� ȭ�� ���
void start_or_end();                                //���� �޴� ���
void name();                                        //�̸� ���ϱ�
void menu();                                        //�޴�
void eat_detail();                                  //�Ա� ����ȭ
void sleep_detail();                                //�ڱ� ����ȭ
void shower_detail();                               //�ı� ����ȭ
void play_detail();                                 //��� ����ȭ
void cham_game();
void stat();                                        //����
void happiness_ending();                            //�ູ���� ���� ���� ����ȭ
void my_money();                                    //������ ���

//���� ȭ�� ���
void print_start() {
	printf("=====================================================\n");
	printf("|                                                   |\n");
	printf("|                                                   |\n");
	printf("|                                                   |\n");
	printf("|                                                   |\n");
	printf("|                                                   |\n");
	printf("|             ������ �ٸ���ġ Ű���                |\n");
	printf("|                                                   |\n");
	printf("|                                                   |\n");
	printf("|                              1. �����ϱ�          |\n");
	printf("|                              2. �����ϱ�          |\n");
	printf("|                                                   |\n");
	printf("=====================================================\n");
}

//���� �޴�
void start_or_end() {
	printf("\n�Է��Ͻʽÿ�>> ");
	scanf_s("%d", &start_end);
	switch (start_end) {
	case 1:
		printf("\n������ �����մϴ�.\n\n");
		printf("."); Sleep(500);
		printf("."); Sleep(500);
		printf("."); Sleep(500);
		system("cls");
		break;
	case 2:
		printf("\n������ �����մϴ�.\n");
		exit(0);
		break;
	default:
		printf("\n�߸� �Է��ϼ̽��ϴ�.\n");
		start_or_end();
		break;
	}
}

//�̸� ���ϱ�
void name() {
	printf("\n\n����� �ٸ���ġ �̸���? ");
	scanf_s("%s", name_str, 50);
	printf("\n\n%s(��)�� ���������ϴ�! %s(��)�� �ູ�մϴ�!\n\n", name_str, name_str); //name_str�� �����
}

//�Ա� ����ȭ
void eat_detail() {
	int select_eat;

	printf("\n\n<�Ա�>�� �����ϼ̽��ϴ�!\n\n");

	printf("������ ���ðڽ��ϱ�? (1: ��, 2: �ƴϿ�): ");
	scanf_s("%d", &select_eat);

	//������ ���� ������ ���� ���� ���
	if ((select_eat == 1) && (money < 300)) {
		printf("���� %s�� �������� �����մϴ�.\n", name_str);
		printf("�ٽ� �������ֽʽÿ�.\n");
		eat_detail();
	}
	//������ ���� ������ ���� �ִ� ���
	else if ((select_eat == 1) && (money >= 300)) {
		printf("\n��! ��Ʈ�� ���ϴ�!\n");
		Sleep(1000);
		printf("\n%s(��)�� �谡 ���� á���ϴ�.\n", name_str);
		printf("\n���� %s(��)�� ����� �ູ�մϴ�.\n", name_str);
		printf("��Ʈ���� 300���� �����߽��ϴ�.\n");
		money -= 300;
		happiness += 30;
	}
	//������ ���� ���� ���� ���
	else if (select_eat == 2) {
		printf("\n������ ���� �Խ��ϴ�.\n");
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
			printf("\n������ ���� �����̾����ϴ�!!!\n");
			printf("\n%s(��)�� ��Ż�� ���� �ʾ����� ����� �����մϴ�...\n", name_str);
			printf("��Ʈ�� ���� �ʰ� ������ �Ծ� ���� �Ʋ����ϴ�.\n");
			money += 100;
			happiness -= 100;
		}
		else if (eat_random == 2) {
			printf("\n%s(��)�� �谡 ������� á���ϴ�.\n", name_str);
			printf("��Ʈ�� ���� �ʰ� ������ �Ծ� ���� �Ʋ����ϴ�.\n");
			money += 100;
			happiness += 10;
		}
		else if (eat_random == 3) {
			printf("\n%s(��)�� �谡 ������� á���ϴ�.\n", name_str);
			printf("��Ʈ�� ���� �ʰ� ������ �Ծ� ���� �Ʋ����ϴ�.\n");
			money += 100;
			happiness += 10;
		}
		else if (eat_random == 4) {
			printf("\n%s(��)�� �谡 ������� á���ϴ�.\n", name_str);
			printf("��Ʈ�� ���� �ʰ� ������ �Ծ� ���� �Ʋ����ϴ�.\n");
			money += 100;
			happiness += 10;
		}
		else if (eat_random == 5) {
			printf("\n%s(��)�� �谡 ������� á���ϴ�.\n", name_str);
			printf("��Ʈ�� ���� �ʰ� ������ �Ծ� ���� �Ʋ����ϴ�.\n");
			money += 100;
			happiness += 10;
		}
	}
	//�߸� �Է��� ���
	else {
		printf("\n�ٽ� �Է����ּ���\n");
		eat_detail();
	}
}

//�ڱ� ����ȭ
void sleep_detail() {
	int select_sleep;

	printf("\n\n<�ڱ�>�� �����ϼ̽��ϴ�!\n\n");

	printf("��� �߱��? (1: ǫ��ǫ�� ħ��, 2: ����� ħ��): ");
	scanf_s("%d", &select_sleep);


	//ǫ��ǫ�� ħ�뿡�� �ڰ� ������ ���� ���� ���
	if ((select_sleep == 1) && (money < 200)) {
		printf("���� %s�� �������� �����մϴ�.\n", name_str);
		printf("�ٽ� �������ֽʽÿ�.\n");
		sleep_detail();
	}
	//ǫ��ǫ�� ħ�뿡�� �ڰ� ������ ���� �ִ� ���
	else if ((select_sleep == 1) && (money >= 200)) {
		printf("\nǫ��ǫ���� ħ�뿡�� ��ϴ�...\n");
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("\n�����ϰ� �Ͼ���ϴ�! %s�� ����� �ູ�մϴ�.\n", name_str);
		printf("ǫ��ǫ�� ħ�뿡�� ��� ������ 200���� �����߽��ϴ�.\n");
		money -= 200;
		happiness += 50;
	}
	//����� ħ�뿡�� �ڰ� ���� ���
	else if (select_sleep == 2) {
		printf("\n����� ħ�뿡�� ��ϴ�...\n");
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("\n%s�� �Ͼ���ϴ�! %s�� ����� �����ϴ�.\n", name_str, name_str);
		printf("����� ħ��� ���� �Ʋ����ϴ�.\n");
		money += 100;
		happiness += 20;
	}
	//�߸� �Է��� ���
	else {
		printf("\n�ٽ� �Է����ּ���\n");
		sleep_detail();
	}
}

//�ı� ����ȭ
void shower_detail() {
	int select_shower;

	printf("\n\n<�ı�>�� �����ϼ̽��ϴ�!\n\n");

	printf("�������� �������? (1: �ְ�� ���� �農��, 2: ���� ����): ");
	scanf_s("%d", &select_shower);

	//�ְ�� �ı⸦ �ϰ� ������ ���� ���� ���
	if ((select_shower == 1) && (money < 500)) {
		printf("���� %s�� �������� �����մϴ�.\n", name_str);
		printf("�ٽ� �������ֽʽÿ�.\n");
		shower_detail();
	}
	//�ְ�� �ı⸦ �ϰ� ������ ���� �ִ� ���
	else if ((select_shower == 1) && (money >= 500)) {
		printf("\n�ְ�-�� ���� �������� ����մϴ�!\n");
		printf("\n���ۺ��� ��ǰ�� �ö�ͼ� %s�� �ʹ� �ູ�غ��̳׿�..!\n", name_str);
		printf("��..."); Sleep(1500);
		printf("��..."); Sleep(1500);
		printf("��..."); Sleep(1500);
		printf("��..."); Sleep(1500);
		printf("\n�����ϰ� ����߽��ϴ�! %s�� ����� �ູ�մϴ�.\n", name_str);
		printf("�ְ�-�� ���� �農������ 500���� �����߽��ϴ�.\n");
		money -= 500;
		happiness += 50;
	}
	//���� ������ �ϰ� ���� ���
	else if (select_shower == 2) {
		printf("\n���� ������ �մϴ�!\n");
		printf("��..."); Sleep(500);
		printf("��..."); Sleep(500);
		printf("��..."); Sleep(500);
		printf("��..."); Sleep(500);
		printf("\n���� ���� �ľ����ϴ�! %s�� �ѵ��մϴ�.\n", name_str);
		printf("���� ������ �� ����� 100���� �Ʋ����ϴ�.\n");
		money += 100;
		happiness += 20;
	}
	//�߸� �Է��� ���
	else {
		printf("\n�ٽ� �Է����ּ���\n");
		shower_detail();
	}
}

//��� ����ȭ
void play_detail() {
	int select_play;

	printf("\n\n<���>�� �����ϼ̽��ϴ�!\n��°� ���� ����!\n\n");

	printf("������ �ϸ� ����? (1: �ֽ� ���� ���� ������, 2: ��Ʃ�� ��û, 3: ����): ");
	scanf_s("%d", &select_play);

	if (select_play == 1) {
		//������ ����
		cham_game();
	}
	else if (select_play == 2) {
		printf("\n��Ʃ�긦 ��û�մϴ�! ��Ʃ��� �� ����ֱ���!\n");
		Sleep(2000);
		printf("!!!");
		Sleep(500);
		printf("\n��, ���� �ð��� �̷��Գ�!!!\n������ �� ��վ����ϴ�\n");
		happiness += 30;
	}
	else if (select_play == 3) {
		printf("\n������ �մϴ�! ������ �� ���� ��̱���!\n");
		srand((unsigned int)time(NULL));
		int book_random = 0;
		book_random = rand() % 2 + 1; //1, 2
		if (book_random == 1) {
			Sleep(2000);
			printf("!!!");
			Sleep(500);
			printf("\n%s(��)�� å �� ���� ���� �� �о����ϴ�!\n����� %s!\n", name_str, name_str);
			printf("������ ������ ��� 100���� �׾ҽ��ϴ�.\n");
			money += 100;
			happiness += 30;
		}
		else if (book_random == 2) {
			Sleep(2000);
			printf("???");
			Sleep(500);
			printf("\n%s(��)�� å�� �д� �������ϴ�!\n��°������ �ູ�غ��Դϴ�\n", name_str);
			happiness += 30;
		}
	}
	else {
		printf("\n�ٽ� �Է����ּ���\n");
		play_detail();
	}
}

//������ ����
void cham_game() {
	printf("\n������ ������ �����մϴ�!\n");
	char cham_answer[50] = { 0, }; //���� ��

	printf("��� ���� ���ðڽ��ϱ�? (left, center, right) >> ");
	scanf_s("%s", cham_answer, 50); //left, right, center
	if (strcmp(cham_answer, "left") == 0) {
		printf("\n���� ����!\n");
	}
	else if (strcmp(cham_answer, "center") == 0) {
		printf("\n��� ����!\n");
	}
	else if (strcmp(cham_answer, "right") == 0) {
		printf("\n������ ����!\n");
	}
	else {
		printf("\n�߸� �Է��ϼ̽��ϴ�.\n");
		cham_game();
	}
	Sleep(1000);
	printf("��"); Sleep(500);
	printf("��"); Sleep(500);
	printf("��"); Sleep(500);
	printf("ġ"); Sleep(500);
	printf("��"); Sleep(500);
	printf(" "); Sleep(500);
	printf("��"); Sleep(500);
	printf("��"); Sleep(500);
	printf("��"); Sleep(500);
	printf("��"); Sleep(500);
	printf("��"); Sleep(500);
	printf("��"); Sleep(500);
	printf("��"); Sleep(500);

	srand((unsigned int)time(NULL));
	int cham_random = 0; //�ٸ���ġ�� ��
	cham_random = rand() % 3 + 1; //1, 2, 3

	if (cham_random == 1) {
		printf("\n�ٸ���ġ�� ������ ������ϴ�.\n");
		if (strcmp(cham_answer, "left") == 0) {
			printf("\n�������ϴ�!\n");
			printf("\n�̰����� ����� �帮�ڽ��ϴ�!\n");
			printf("\n�������� %s�� ��հ� ����ּ���!\n", name_str);
			money += 500;
			happiness += 20;
		}
		else if (strcmp(cham_answer, "left") != 0) {
			printf("\n��! �ƽ��Ե� ������ ���߽��ϴ�!\n");
			printf("\n������ ����� �帮�ڽ��ϴ�!\n");
			printf("\n������ %s�� �̰ܼ� ����� ���� �� ������!\n", name_str);
			money += 100;
			happiness += 50;
		}
	}
	else if (cham_random == 2) {
		printf("\n�ٸ���ġ�� ����� ������ϴ�.\n");
		if (strcmp(cham_answer, "center") == 0) {
			printf("\n�������ϴ�!\n");
			printf("\n�̰����� ����� �帮�ڽ��ϴ�!\n");
			printf("\n�������� %s�� ��հ� ����ּ���!\n", name_str);
			money += 500;
			happiness += 20;
		}
		else if (strcmp(cham_answer, "center") != 0) {
			printf("\n��! �ƽ��Ե� ������ ���߽��ϴ�!\n");
			printf("\n������ ����� �帮�ڽ��ϴ�!\n");
			printf("\n������ %s�� �̰ܼ� ����� ���� �� ������!\n", name_str);
			money += 100;
			happiness += 50;
		}
	}
	else if (cham_random == 3) {
		printf("\n�ٸ���ġ�� �������� ������ϴ�.\n");
		if (strcmp(cham_answer, "right") == 0) {
			printf("\n�������ϴ�!\n");
			printf("\n�̰����� ����� �帮�ڽ��ϴ�!\n");
			printf("\n�������� %s�� ��հ� ����ּ���!\n", name_str);
			money += 500;
			happiness += 20;
		}
		else if (strcmp(cham_answer, "right") != 0) {
			printf("\n��! �ƽ��Ե� ������ ���߽��ϴ�!\n");
			printf("\n������ ����� �帮�ڽ��ϴ�!\n");
			printf("\n������ %s�� �̰ܼ� ����� ���� �� ������!\n", name_str);
			money += 100;
			happiness += 50;
		}
	}
}

//�޴� ���ϱ�
void menu() {
	int select_menu;
	printf("=====================================================\n");
	printf("|                                                   |\n");
	printf("|                                                   |\n");
	printf("|   ������ �Ͻðڽ��ϱ�?                            |\n");
	printf("|                                                   |\n");
	printf("|   1. �Ա�                                         |\n");
	printf("|   2. �ڱ�                                         |\n");
	printf("|   3. �ı�                                         |\n");
	printf("|   4. ���                                         |\n");
	printf("|   5. ���� Ȯ��                                    |\n");
	printf("|   6. ������ Ȯ��                                  |\n");
	printf("|                                                   |\n");
	printf("|                                                   |\n");
	printf("=====================================================\n");
	scanf_s("%d", &select_menu);

	if (select_menu == 1) {
		food_count++;
		printf("\n\nfood_count: %d\n\n", food_count);
		//���� 1 Ǫ�� ī��Ʈ�� á�ٰ� �˷��ֱ�
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
		printf("\n%s(��)�� �����մϴ�. �ٽ� ����ֽʽÿ�\n", name_str);
		menu();
	}
}

//���� ���
void stat() {
	printf("���� %s�� ������?\n", name_str);
	printf("================================================\n");
	printf("|                                              |\n");
	printf("|    ����: %d                                  |\n", level);
	printf("|    �ູ��: %d                                |\n", happiness);
	printf("|                                              |\n");
	printf("================================================\n");
}

void my_money() {
	printf("================================================\n");
	printf("|                                              |\n");
	printf("|    ������: %d                                |\n", money);
	printf("|                                              |\n");
	printf("================================================\n");
}

//�ູ���� ���� ���� ����ȭ
void happiness_ending() {
	//0����
	if (happiness < 0) {
		printf("\n\n%s���� ���� ���� �������ǰ���?\n", name_str); Sleep(1000);
		printf("%s(��)�� �︮�ٴ� �� �� �ϼ̽��ϴ�!\n", name_str); Sleep(1000);
		printf("����� �ٸ���ġ %s(��)�� ��� ���� �������ϴ�...\n", name_str); Sleep(1000);
		printf("��... ������ �÷������ּż� ��ô ����帳�ϴ�!\n");
	}
	//0~20
	else if ((0 <= happiness) && (happiness < 20)) {
		printf("\n\n%s���� ���� ���� �Ͼ�ǰ���?\n", name_str); Sleep(1000);
		printf("%s�� ������ ����ֽ��ϴ�!\n", name_str); Sleep(1000);
		printf("����� �ٸ���ġ %s(��)�� ���� ��� �����߽��ϴ�...\n", name_str); Sleep(1000);
		printf("��... ������ �÷������ּż� ��ô ����帳�ϴ�!\n");
	}
	//20~40
	else if ((20 <= happiness) && (happiness < 40)) {
		printf("\n\n%s(��)�� �ɼ��� �� �ɱ��?\n", name_str); Sleep(1000);
		printf("%s�� ����� �������⿣ ���� ���� �� �� ���׿�!\n", name_str); Sleep(1000);
		printf("�������� �й��ϼž߰ڽ��ϴ�!\n"); Sleep(1000);
		printf("������ �÷������ּż� ��ô ����帳�ϴ�!\n");
	}
	//40~60
	else if ((40 <= happiness) && (happiness < 60)) {
		printf("\n\n%s�� ����� �׷������Դϴ�.\n", name_str); Sleep(1000);
		printf("%s�� ����� �������⿣ ���� ������ �� ���׿�!\n", name_str); Sleep(1000);
		printf("�������� �й��Ͻø��� �Ͻ��ϴ�!\n"); Sleep(1000);
		printf("������ �÷������ּż� ��ô ����帳�ϴ�!\n");
	}
	//60~80
	else if ((60 <= happiness) && (happiness < 80)) {
		printf("\n\n%s�� ����� �����ϴ�!\n", name_str); Sleep(1000);
		printf("�ణ�� �ƽ����� ���� ��Ȳ�� �����غ��̴� �� ���׿�!\n"); Sleep(1000);
		printf("������ �÷������ּż� ��ô ����帳�ϴ�!\n");
	}
	//80~100
	else if ((80 <= happiness) && (happiness < 100)) {
		printf("\n\n%s�� ����� �ְ��Դϴ�!\n", name_str); Sleep(1000);
		printf("����� �ٸ���ġ Ű����� �������!\n"); Sleep(1000);
		printf("%s�� �ູ�� 100�� �ѱ�� ���� ���� �������...?\n", name_str); Sleep(1000);
		printf("�ƹ�ư ������ �÷������ּż� ��ô ����帳�ϴ�!\n");
	}
	//100�̻�
	else if (happiness >= 100) {
		printf("\n\n%s�� ����� �����̶� ���ư� �� �մϴ�!\n", name_str); Sleep(1000);
		printf("����� �ٸ���ġ Ű����� ���̱���!\n"); Sleep(1000);
		printf("�ູ�� 100�� �ѱ��� ���� ������ �ѱ�ôٴ�...\n"); Sleep(1000);
		printf("Ư���� ������ �帮���� �ϰڽ��ϴ�...!\n"); Sleep(1000);
		Sleep(2000);
		printf("����� \'�ٸ���ġ�� ����\'�� ������ϴ�!\n"); Sleep(1000);
		printf("�������� ����� ��� �ڵ�� \"�Ϻ��� ������\"�� ���Դϴ�!\n"); Sleep(1000);
		printf("������ �÷������ּż� ��ô ����帳�ϴ�!\n");
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