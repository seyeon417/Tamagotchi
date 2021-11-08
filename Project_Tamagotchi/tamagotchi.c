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

void print_start();                                 //���� ȭ�� ���
void start_or_end();                                //���� �޴� ���
void name();                                        //�̸� ���ϱ�
void menu();                                        //�޴�
void eat_detail();                                  //�Ա� ����ȭ
void sleep_detail();                                //�ڱ� ����ȭ
void shower_detail();                               //�ı� ����ȭ
void play_detail();                                 //��� ����ȭ
void stat();                                        //����
void happiness_ending();                            //�ູ���� ���� ���� ����ȭ

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
	if (select_eat == 1) {
		printf("\n��! ��Ʈ�� ���ϴ�!\n");
		Sleep(1000);
		printf("\n%s(��)�� �谡 ���� á���ϴ�.\n", name_str);
		printf("\n���� %s(��)�� ����� �ູ�մϴ�.\n", name_str);
		happiness += 30;
	}
	else if (select_eat == 2) {
		printf("\n������ ���� �Խ��ϴ�.\n");
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
			printf("\n������ ���� �����̾����ϴ�!!!\n");
			printf("\n%s(��)�� ��Ż�� ���� �ʾ����� ����� �����մϴ�...\n", name_str);
			happiness -= 100;
		}
		else if (eat_random == 2) {
			printf("\n%s(��)�� �谡 ������� á���ϴ�.\n", name_str);
			happiness += 10;
		}
		else if (eat_random == 3) {
			printf("\n%s(��)�� �谡 ������� á���ϴ�.\n", name_str);
			happiness += 10;
		}
		else if (eat_random == 4) {
			printf("\n%s(��)�� �谡 ������� á���ϴ�.\n", name_str);
			happiness += 10;
		}
		else if (eat_random == 5) {
			printf("\n%s(��)�� �谡 ������� á���ϴ�.\n", name_str);
			happiness += 10;
		}
	}
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

	if (select_sleep == 1) {
		printf("\nǫ��ǫ���� ħ�뿡�� ��ϴ�...\n");
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("\n�����ϰ� �Ͼ���ϴ�! %s�� ����� �ູ�մϴ�.\n", name_str);
		happiness += 50;
	}
	else if (select_sleep == 2) {
		printf("\n����� ħ�뿡�� ��ϴ�...\n");
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("\n%s�� �Ͼ���ϴ�! %s�� ����� �����ϴ�.\n", name_str, name_str);
		happiness += 20;
	}
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

	if (select_shower == 1) {
		printf("\n�ְ�-�� ���� �������� ����մϴ�!\n");
		printf("\n���ۺ��� ��ǰ�� �ö�ͼ� %s�� �ʹ� �ູ�غ��̳׿�..!\n", name_str);
		printf("��..."); Sleep(1500);
		printf("��..."); Sleep(1500);
		printf("��..."); Sleep(1500);
		printf("��..."); Sleep(1500);
		printf("\n�����ϰ� ����߽��ϴ�! %s�� ����� �ູ�մϴ�.\n", name_str);
		happiness += 50;
	}
	else if (select_shower == 2) {
		printf("\n���� ������ �մϴ�!\n");
		printf("��..."); Sleep(500);
		printf("��..."); Sleep(500);
		printf("��..."); Sleep(500);
		printf("��..."); Sleep(500);
		printf("\n���� ���� �ľ����ϴ�! %s�� �ѵ��մϴ�.\n", name_str);
		happiness += 20;
	}
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
		printf("\n������ ������ �����մϴ�!\n");
		char cham_answer[50];

		printf("��� ���� ���ðڽ��ϱ�? (����, ������, ���) >> ");
		scanf_s("%s", cham_answer, 50); //����, ������, ���, left, right, center
		if ((strcmp(cham_answer, "����") == 0) || strcmp(cham_answer, "left") == 0) {
			printf("���� ����!\n");
		}
		else if (strcmp(cham_answer, "���") == 0 || strcmp(cham_answer, "center") == 0) {
			printf("��� ����!\n");
		}
		else if (strcmp(cham_answer, "������") == 0 || strcmp(cham_answer, "right") == 0) {
			printf("������ ����!\n");
		}
		else {
			printf("�߸� �Է��ϼ̽��ϴ�.");
			//�ٽ� ���ư���
		}
		Sleep(1000);

		srand((unsigned int)time(NULL));
		int cham_random = 0;
		cham_random = rand() % 3 + 1; //1, 2, 3
		//int* left, center, right;
		if (cham_random == 1) {
			//left = &cham_random;
			printf("\n%s�� ������ ������ϴ�.\n", name_str);
		}
		else if (cham_random == 2) {
			//center = &cham_random;
			printf("\n%s�� ����� ������ϴ�.\n", name_str);
		}
		else if (cham_random == 3) {
			//right = &cham_random;
			printf("\n%s�� �������� ������ϴ�.\n", name_str);
		}
		//���� ���� ���� �� �ٸ���ġ�� ������ �����ߴ��� ���
		//���� ��� �ٸ���ġ ��� ���Ͽ� �������� �ƴ��� ���
		//������ ��� or �Է��� ���������� �ޱ�
		//�̱�� �ູ�� +50, �� +100
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
		srand(time(NULL));
		int book_random = 0;
		book_random = rand() % 2 + 1; //1, 2
		if (book_random == 1) {
			Sleep(2000);
			printf("!!!");
			Sleep(500);
			printf("\n%s(��)�� å �� ���� ���� �� �о����ϴ�!\n����� %s!\n", name_str, name_str);
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

//�ູ���� ���� ���� ����ȭ
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