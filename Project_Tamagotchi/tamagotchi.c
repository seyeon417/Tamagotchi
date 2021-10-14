#include <stdio.h>
#include <Windows.h>

char name_str[50]; //�̸�
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
	printf("|                                                   |\n");
	printf("|                                                   |\n");
	printf("|                                                   |\n");
	printf("=====================================================\n");
}
//�̸� ���ϱ�
void name() {
	printf("\n\n����� �ٸ���ġ �̸���? ");
	scanf_s("%s", name_str, 50);
	printf("%s�� ���������ϴ�! %s�� �ູ�մϴ�!\n\n", name_str, name_str); //name_str�� �����
}
//��Ʈ ����
void store() {
	int select_yn;
	printf("������ ���ðڽ��ϱ�? (1: Yes, 2: No): ");
	scanf_s("%d", &select_yn);
	if (select_yn == 1) {
		printf("��! ��Ʈ!\n");
		Sleep(500);
		printf("%s(��)�� �谡 ���� á���ϴ�.\n", name_str);
		printf("���� %s(��)�� ����� �ູ�մϴ�.\n", name_str);
	}
	else if (select_yn == 2) {
		printf("������ ���� �Խ��ϴ�.\n");
		Sleep(500);
		printf("%s(��)�� �谡 ������� á���ϴ�.\n", name_str);
	}
}
//�޴� ���ϱ�
void menu() {
	int select;

	printf("������ �Ͻðڽ��ϱ�?\n");
	printf("1. �Ա�\n");
	printf("2. �ڱ�\n");
	printf("3. �ı�\n");
	printf("4. ���\n");
	scanf_s("%d", &select);

	if (select == 1) {
		food_count++;
		printf("\n\nfood_count: %d\n\n", food_count);
		store();
		printf("%s(��)�� ���� �Խ��ϴ�.\n\n", name_str);
	}
	else if (select == 2) {
		sleep_count++;
		printf("\n\nsleep_count: %d\n\n", sleep_count);
		printf("%s(��)�� ���� ��ϴ�.\n\n", name_str);
	}
	else if (select == 3) {
		shower_count++;
		printf("\n\nshower_count: %d\n\n", shower_count);
		printf("%s(��)�� ���� �Ľ��ϴ�.\n\n", name_str);
	}
	else if (select == 4) {
		game_count++;
		printf("\n\ngame_count: %d\n\n", game_count);
		printf("%s(��)�� ������ �ϸ� ��ϴ�.\n\n", name_str);
	}
	else {
		printf("\n%s(��)�� �����մϴ�. �ٽ� ����ֽʽÿ�\n", name_str);
	}
}
//���� ���
void stat() {
	printf("���� %s�� ������?\n", name_str);
	printf("================================================\n");
	printf("|                                              |\n");
	printf("| ����: %d                                      |\n", level);
	printf("| �ູ��: %d                                   |\n", happiness);
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