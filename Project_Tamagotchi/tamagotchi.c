#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

char name_str[50]; //�̸�
int start_end;
int food_count = 0;
int sleep_count = 0;
int shower_count = 0;
int game_count = 0;
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
		happiness += 20;
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
			happiness -= 30;
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
		happiness += 20;
	}
	else if (select_sleep == 2) {
		printf("\n����� ħ�뿡�� ��ϴ�...\n");
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("\n%s�� �Ͼ���ϴ�! %s�� ����� �����ϴ�.\n", name_str, name_str);
		happiness += 10;
	}
	else {
		printf("\n�ٽ� �Է����ּ���\n");
		sleep_detail();
	}
}

//�ı� ����ȭ
void shower_detail() {

}

//��� ����ȭ
void play_detail() {

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

int main(void)
{
	print_start();
	start_or_end();
	name();
	menu();
	//stat();
	return 0;
}