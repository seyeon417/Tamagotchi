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
int level = 1;
int happiness = 0;
int money = 0; //������

void opening();                                     //������
void print_start();                                 //���� ȭ�� ���
void start_or_end();                                //���� �޴� ���
void name();                                        //�̸� ���ϱ�
void menu();                                        //�޴�
void eat_detail();                                  //�Ա� ����ȭ
void sleep_detail();                                //�ڱ� ����ȭ
void shower_detail();                               //�ı� ����ȭ
void play_detail();                                 //��� ����ȭ
void cham_game();                                   //������ ����
void stat();                                        //����
void level_status();                                //���� �޼� ����
void happiness_ending();                            //�ູ���� ���� ���� ����ȭ
void my_money();                                    //������ ���
void lv1_to_lv2();                                  //���� 1���� ���� 2��
void lv2_to_lv3();                                  //���� 2���� ���� 3��
void lv3_to_lv4();                                  //���� 3���� ���� 4��
void lv4_to_lv5();                                  //���� 4���� ���� 5��
void ending();                                      //����

//���� �� ���
void opening() {
	Sleep(500);
	printf("�ȳ��ϼ���!\n"); Sleep(500);
	printf("\"������ �ٸ���ġ\" ���ӿ� ���� ������ ȯ���մϴ�\n"); Sleep(2000);
	printf("�������� ���ݺ��� ����� �ٸ���ġ�� �Բ� ��Ȱ�ϰ� �˴ϴ�\n"); Sleep(2000);
	printf("�ٸ���ġ�� ���� 1���� �����ϸ� ���� 5���� �����Ű�� ���� ���� ��ǥ�Դϴ�\n"); Sleep(2000);
	printf("�� ������ �����Ϸ���...\n"); Sleep(1500);
	printf("������ ���� n�� ��ɵ��� n�� �̻� �����ؾ� �������� �� �ֽ��ϴ�\n"); Sleep(2000);
	printf("������ �ʹ� �����Ű���?\n"); Sleep(1500);
	printf("�鹮�� �ҿ��ϰ�!\n"); Sleep(1500);
	printf("�׷� ����� ���ؼ� ���� �޼� ���� �޴��� �־����ϴ�!\n"); Sleep(2000);
	printf("�׷� �������� ����� �ٸ���ġ�� ������ ���������?\n"); Sleep(2000);
	printf("�ٸ���ġ�� �׻� �ູ�ϱ�..! ����� ���ϴ�..!\n\n"); Sleep(2000);
}

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
	while (getchar() != '\n');
	switch (start_end) {
	case 1:
		printf("\n������ �����մϴ�\n\n");
		printf("."); Sleep(500);
		printf("."); Sleep(500);
		printf("."); Sleep(500);
		system("cls");
		break;
	case 2:
		printf("\n������ �����մϴ�\n");
		exit(0);
		break;
	default:
		printf("\n�߸� �Է��ϼ̽��ϴ�\n");
		printf("�ٽ� �Է����ּ���\n");
		start_or_end();
		break;
	}
}

//�̸� ���ϱ�
void name() {
	printf("����� �ٸ���ġ �̸���? ");
	scanf_s("%s", name_str, 50);
	while (getchar() != '\n');
	printf("\n\n%s(��)�� ���������ϴ�!\n", name_str); Sleep(800);
	printf("%s(��)�� �ູ�մϴ�!\n\n", name_str); Sleep(800);
}

//�Ա� ����ȭ
void eat_detail() {
	int select_eat;
	Sleep(500);
	printf("\n<�Ա�>�� �����ϼ̽��ϴ�!\n\n"); Sleep(1000);

	printf("������ ���ðڽ��ϱ�? (1: ��, 2: �ƴϿ�): ");
	scanf_s("%d", &select_eat);
	while (getchar() != '\n');

	//������ ���� ������ ���� ���� ���
	if ((select_eat == 1) && (money < 300)) {
		printf("\n���� %s�� �������� �����մϴ�\n", name_str); Sleep(1000);
		printf("�ٽ� �Է����ּ���\n");
		eat_detail();
	}
	//������ ���� ������ ���� �ִ� ���
	else if ((select_eat == 1) && (money >= 300)) {
		printf("\n��! ��Ʈ�� ���ϴ�!\n");
		Sleep(1000);
		printf("��\n"); Sleep(1000);
		printf("��\n"); Sleep(1000);
		printf("%s(��)�� �谡 ���� á���ϴ�\n", name_str); Sleep(800);
		printf("���� %s(��)�� ����� �ູ�մϴ�\n", name_str); Sleep(800);
		printf("��Ʈ���� 300���� �����߽��ϴ�\n\n"); Sleep(1500);
		money -= 300;
		happiness += 10;
	}
	//������ ���� ���� ���� ���
	else if (select_eat == 2) {
		printf("\n������ ���� �Խ��ϴ�\n"); Sleep(1000);
		srand((unsigned int)time(NULL));
		int eat_random;
		eat_random = rand() % 5 + 1; //1, 2, 3, 4, 5
		if (eat_random == 1) {
			printf("."); Sleep(1000);
			printf("."); Sleep(1000);
			printf("."); Sleep(1000);
			printf("?!?!"); Sleep(1500);
			printf("\n");
			printf("������ ���� �����̾����ϴ�!!!\n"); Sleep(800);
			printf("%s(��)�� ��Ż�� ���� �ʾ����� ����� �����մϴ�...\n", name_str); Sleep(1000);
			printf("��Ʈ�� ���� �ʰ� ������ �Ծ� 100���� ������ϴ�\n\n"); Sleep(1500);
			money += 100;
			happiness -= 100;
		}
		else if (eat_random == 2) {
			printf("%s(��)�� �谡 ������� á���ϴ�\n", name_str); Sleep(800);
			printf("��Ʈ�� ���� �ʰ� ������ �Ծ� 100���� ������ϴ�\n\n"); Sleep(1500);
			money += 100;
		}
		else if (eat_random == 3) {
			printf("%s(��)�� �谡 ������� á���ϴ�\n", name_str); Sleep(800);
			printf("��Ʈ�� ���� �ʰ� ������ �Ծ� 100���� ������ϴ�\n\n"); Sleep(1500);
			money += 100;
		}
		else if (eat_random == 4) {
			printf("%s(��)�� �谡 ������� á���ϴ�.\n", name_str); Sleep(800);
			printf("��Ʈ�� ���� �ʰ� ������ �Ծ� 100���� ������ϴ�\n\n"); Sleep(1500);
			money += 100;
		}
		else if (eat_random == 5) {
			printf("%s(��)�� �谡 ������� á���ϴ�.\n", name_str); Sleep(800);
			printf("��Ʈ�� ���� �ʰ� ������ �Ծ� 100���� ������ϴ�\n\n"); Sleep(1500);
			money += 100;
		}
	}
	//�߸� �Է��� ���
	else {
		printf("\n�߸� �Է��ϼ̽��ϴ�\n"); Sleep(1000);
		printf("�ٽ� �Է����ּ���\n");
		eat_detail();
	}
}

//�ڱ� ����ȭ
void sleep_detail() {
	int select_sleep;
	Sleep(500);
	printf("\n<�ڱ�>�� �����ϼ̽��ϴ�!\n\n"); Sleep(1000);

	printf("��� �߱��? (1: ǫ��ǫ�� ħ��, 2: ����� ħ��): ");
	scanf_s("%d", &select_sleep);
	while (getchar() != '\n');

	//ǫ��ǫ�� ħ�뿡�� �ڰ� ������ ���� ���� ���
	if ((select_sleep == 1) && (money < 200)) {
		printf("\n���� %s�� �������� �����մϴ�\n", name_str); Sleep(1000);
		printf("�ٽ� �Է����ּ���\n");
		sleep_detail();
	}
	//ǫ��ǫ�� ħ�뿡�� �ڰ� ������ ���� �ִ� ���
	else if ((select_sleep == 1) && (money >= 200)) {
		printf("\nǫ��ǫ���� ħ�뿡�� ��ϴ�...\n\n"); Sleep(500);
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("Z...\n"); Sleep(1500);
		printf("\n�����ϰ� �Ͼ���ϴ�!\n"); Sleep(800);
		printf("%s�� ����� �ູ�մϴ�\n", name_str); Sleep(800);
		printf("ǫ��ǫ�� ħ�뿡�� ��� ������ 200���� �����߽��ϴ�\n\n"); Sleep(1500);
		money -= 200;
		happiness += 10;
	}
	//����� ħ�뿡�� �ڰ� ���� ���
	else if (select_sleep == 2) {
		printf("\n����� ħ�뿡�� ��ϴ�...\n\n"); Sleep(500);
		printf("Z..."); Sleep(1500);
		printf("Z..."); Sleep(1500);
		printf("Z...\n"); Sleep(1500);
		printf("\n%s(��)�� �Ͼ���ϴ�!\n", name_str); Sleep(800);
		printf("%s�� ����� �����ϴ�\n", name_str); Sleep(800);
		printf("����� ħ��� 100���� ������ϴ�\n\n"); Sleep(1500);
		money += 100;
	}
	//�߸� �Է��� ���
	else {
		printf("\n�߸� �Է��ϼ̽��ϴ�\n"); Sleep(1000);
		printf("�ٽ� �Է����ּ���\n");
		sleep_detail();
	}
}

//�ı� ����ȭ
void shower_detail() {
	int select_shower;
	Sleep(500);
	printf("\n<�ı�>�� �����ϼ̽��ϴ�!\n\n"); Sleep(1000);

	printf("�������� �������? (1: �ְ�� ���� �農��, 2: ���� ����): ");
	scanf_s("%d", &select_shower);
	while (getchar() != '\n');

	//�ְ�� �ı⸦ �ϰ� ������ ���� ���� ���
	if ((select_shower == 1) && (money < 500)) {
		printf("\n���� %s�� �������� �����մϴ�\n", name_str); Sleep(1000);
		printf("�ٽ� �Է����ּ���\n");
		shower_detail();
	}
	//�ְ�� �ı⸦ �ϰ� ������ ���� �ִ� ���
	else if ((select_shower == 1) && (money >= 500)) {
		printf("\n�ְ�-�� ���� �������� ����մϴ�!\n"); Sleep(800);
		printf("\n���ۺ��� ��ǰ�� �ö�ͼ� %s(��)�� �ʹ� �ູ�غ��̳׿�..!\n\n", name_str); Sleep(500);
		printf("��..."); Sleep(1500);
		printf("��..."); Sleep(1500);
		printf("��..."); Sleep(1500);
		printf("��...\n"); Sleep(1500);
		printf("\n�����ϰ� ����߽��ϴ�!\n"); Sleep(500);
		printf("%s�� ����� �ູ�մϴ�\n", name_str); Sleep(500);
		printf("�ְ�-�� ���� �農������ 500���� �����߽��ϴ�\n\n"); Sleep(1500);
		money -= 500;
		happiness += 10;
	}
	//���� ������ �ϰ� ���� ���
	else if (select_shower == 2) {
		printf("\n���� ������ �մϴ�!\n\n"); Sleep(500);
		printf("��..."); Sleep(500);
		printf("��..."); Sleep(500);
		printf("��..."); Sleep(500);
		printf("��...\n"); Sleep(500);
		printf("\n���� ���� �ľ����ϴ�!\n"); Sleep(800);
		printf("%s(��)�� �ѵ��մϴ�\n", name_str); Sleep(800);
		printf("���� ������ �� ����� 100���� ������ϴ�\n\n"); Sleep(1500);
		money += 100;
	}
	//�߸� �Է��� ���
	else {
		printf("\n�߸� �Է��ϼ̽��ϴ�\n"); Sleep(1000);
		printf("�ٽ� �Է����ּ���\n");
		shower_detail();
	}
}

//��� ����ȭ
void play_detail() {
	int select_play;
	Sleep(500);
	printf("\n<���>�� �����ϼ̽��ϴ�!\n"); Sleep(800);
	printf("��°� ���� ����!\n\n"); Sleep(500);

	printf("������ �ϸ� ����? (1: �ֽ� ���� ���� ������, 2: ��Ʃ�� ��û, 3: ����): ");
	scanf_s("%d", &select_play);
	while (getchar() != '\n');

	if (select_play == 1) {
		//������ ����
		cham_game();
	}
	else if (select_play == 2) {
		printf("\n��Ʃ�긦 ��û�մϴ�!\n"); Sleep(800);
		printf("��Ʃ��� �� ����ֱ���!\n\n");
		Sleep(2000);
		printf("!"); Sleep(500);
		printf("!"); Sleep(500);
		printf("!\n"); Sleep(500);
		printf("\n��, ���� �ð��� �̷��Գ�!!!\n"); Sleep(800);
		printf("������ �� ��վ����ϴ�\n\n"); Sleep(1500);
	}
	else if (select_play == 3) {
		printf("\n������ �մϴ�!\n"); Sleep(800);
		printf("������ �� ���� ��̱���!\n\n"); Sleep(500);
		srand((unsigned int)time(NULL));
		int book_random = 0;
		book_random = rand() % 2 + 1; //1, 2
		if (book_random == 1) {
			Sleep(2000);
			printf("!"); Sleep(500);
			printf("!"); Sleep(500);
			printf("!\n"); Sleep(500);
			printf("\n%s(��)�� å �� ���� ���� �� �о����ϴ�!\n", name_str); Sleep(1000);
			printf("����� %s!!!\n", name_str); Sleep(500);
			printf("������ ������ ��� 100���� �׾ҽ��ϴ�\n\n"); Sleep(1500);
			money += 100;
			happiness += 10;
		}
		else if (book_random == 2) {
			Sleep(2000);
			printf("?"); Sleep(500);
			printf("?"); Sleep(500);
			printf("?\n"); Sleep(500);
			printf("\n%s(��)�� å�� �д� �������ϴ�!\n", name_str); Sleep(1000);
			printf("��°������ �ູ�غ��Դϴ�\n\n"); Sleep(1500);
		}
	}
	else {
		printf("\n�߸� �Է��ϼ̽��ϴ�\n"); Sleep(1000);
		printf("�ٽ� �Է����ּ���\n");
		play_detail();
	}
}

//������ ����
void cham_game() {
	printf("\n������ ������ �����մϴ�!\n\n"); Sleep(500);
	char cham_answer[50] = { 0, }; //���� ��

	printf("��� ���� ���ðڽ��ϱ�? (left, center, right) >> ");
	scanf_s("%s", cham_answer, 50); //left, right, center
	while (getchar() != '\n');
	Sleep(500);
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
		printf("\n�ٽ� �Է����ּ���\n"); Sleep(500);
		fflush(stdin);
		cham_game();
		return;
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
	printf("\n");

	srand((unsigned int)time(NULL));
	int cham_random = 0; //�ٸ���ġ�� ��
	cham_random = rand() % 3 + 1; //1, 2, 3

	if (cham_random == 1) {
		printf("\n%s(��)�� ������ ������ϴ�.\n", name_str); Sleep(1000);
		if (strcmp(cham_answer, "left") == 0) {
			printf("\n�������ϴ�!\n"); Sleep(800);
			printf("�̰����� 500�� ����� ����� �帮�ڽ��ϴ�!\n"); Sleep(1000);
			printf("�������� %s(��)�� ��հ� ����ּ���!\n\n", name_str); Sleep(1500);
			money += 500;
		}
		else if (strcmp(cham_answer, "left") != 0) {
			printf("\n��! �ƽ��Ե� ������ ���߽��ϴ�!\n"); Sleep(800);
			printf("������ ��� 100���� �帮�ڽ��ϴ�!\n"); Sleep(1000);
			printf("������ %s(��)�� �̰ܼ� ����� ���� �� ������!\n\n", name_str); Sleep(1500);
			money += 100;
			happiness += 10;
		}
	}
	else if (cham_random == 2) {
		printf("\n%s(��)�� ����� ������ϴ�.\n", name_str); Sleep(1000);
		if (strcmp(cham_answer, "center") == 0) {
			printf("\n�������ϴ�!\n"); Sleep(800);
			printf("�̰����� 500�� ����� ��� �帮�ڽ��ϴ�!\n"); Sleep(1000);
			printf("�������� %s(��)�� ��հ� ����ּ���!\n\n", name_str); Sleep(1500);
			money += 500;
		}
		else if (strcmp(cham_answer, "center") != 0) {
			printf("\n��! �ƽ��Ե� ������ ���߽��ϴ�!\n"); Sleep(800);
			printf("������ ��� 100���� �帮�ڽ��ϴ�!\n"); Sleep(1000);
			printf("������ %s(��)�� �̰ܼ� ����� ���� �� ������!\n\n", name_str); Sleep(1500);
			money += 100;
			happiness += 10;
		}
	}
	else if (cham_random == 3) {
		printf("\n%s(��)�� �������� ������ϴ�.\n", name_str); Sleep(1000);
		if (strcmp(cham_answer, "right") == 0) {
			printf("\n�������ϴ�!\n"); Sleep(800);
			printf("�̰����� 500�� ����� ����� �帮�ڽ��ϴ�!\n"); Sleep(1000);
			printf("�������� %s(��)�� ��հ� ����ּ���!\n\n", name_str); Sleep(1500);
			money += 500;
		}
		else if (strcmp(cham_answer, "right") != 0) {
			printf("\n��! �ƽ��Ե� ������ ���߽��ϴ�!\n"); Sleep(800);
			printf("������ ��� 100���� �帮�ڽ��ϴ�!\n"); Sleep(1000);
			printf("������ %s(��)�� �̰ܼ� ����� ���� �� ������!\n\n", name_str); Sleep(1500);
			money += 100;
			happiness += 10;
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
	printf("|   6. ���� �޼� ���� Ȯ��                          |\n");
	printf("|   7. ������ Ȯ��                                  |\n");
	printf("|                                                   |\n");
	printf("|                                                   |\n");
	printf("=====================================================\n");
	scanf_s("%d", &select_menu);
	while (getchar() != '\n');

	if (select_menu == 1) {
		food_count++;
		eat_detail();
	}
	else if (select_menu == 2) {
		sleep_count++;
		sleep_detail();
	}
	else if (select_menu == 3) {
		shower_count++;
		shower_detail();
	}
	else if (select_menu == 4) {
		play_count++;
		play_detail();
	}
	else if (select_menu == 5) {
		stat();
	}
	else if (select_menu == 6) {
		level_status();
	}
	else if (select_menu == 7) {
		my_money();
	}
	else {
		printf("\n%s(��)�� �����մϴ�\n", name_str); Sleep(500);
		printf("�ٽ� �Է����ּ���\n\n"); Sleep(1000);
		menu();
	}
}

//���� ���
void stat() {
	printf("���� %s�� ������?\n", name_str);
	printf("================================================\n");
	printf("|                                              |\n");
	printf("|    ����: %5d                               |\n", level);
	printf("|    �ູ��: %4d                              |\n", happiness);
	printf("|                                              |\n");
	printf("================================================\n");
	printf("\n"); Sleep(1500);
}

//���� �޼� ���� Ȯ��
void level_status() {
	printf("\n"); Sleep(1000);
	printf("================================================\n");
	printf("|                                              |\n");
	//�Ա�
	if (level - food_count <= 0) {
		printf("|       ���� %3d �޼�����: �Ա� �Ϸ�           |\n", level + 1);
	}
	else {
		printf("|       ���� %3d �޼�����: �Ա� %d�� ����       |\n", level + 1, level - food_count);
	}
	//�ڱ�
	if (level - sleep_count <= 0) {
		printf("|       ���� %3d �޼�����: �ڱ� �Ϸ�           |\n", level + 1);
	}
	else {
		printf("|       ���� %3d �޼�����: �ڱ� %d�� ����       |\n", level + 1, level - sleep_count);
	}
	//�ı�
	if (level - shower_count <= 0) {
		printf("|       ���� %3d �޼�����: �ı� �Ϸ�           |\n", level + 1);
	}
	else {
		printf("|       ���� %3d �޼�����: �ı� %d�� ����       |\n", level + 1, level - shower_count);
	}
	//���
	if (level - play_count <= 0) {
		printf("|       ���� %3d �޼�����: ��� �Ϸ�           |\n", level + 1);
	}
	else {
		printf("|       ���� %3d �޼�����: ��� %d�� ����       |\n", level + 1, level - play_count);
	}
	printf("|                                              |\n");
	printf("================================================\n\n"); Sleep(1500);
}

//������ Ȯ��
void my_money() {
	printf("================================================\n");
	printf("|                                              |\n");
	printf("|    ������: %5d                             |\n", money);
	printf("|                                              |\n");
	printf("================================================\n\n"); Sleep(1500);
}

//�ູ���� ���� ���� ����ȭ
void happiness_ending() {
	printf("================================================\n");
	printf("|          �ٸ���ġ �ູ�� : %3d               |\n", happiness);
	printf("================================================\n\n"); Sleep(1000);

	//0����
	if (happiness < 0) {
		printf("\n\n%s���� ���� ���� �������ǰ���?\n", name_str); Sleep(1000);
		printf("%s(��)�� �︮�ٴ� �� �� �ϼ̽��ϴ�!\n", name_str); Sleep(1200);
		printf("����� �ٸ���ġ %s(��)�� ��� ���� �������ϴ�...\n", name_str); Sleep(1500);
		printf("��... ������ �÷������ּż� ��ô ����帳�ϴ�!\n\n"); Sleep(1500);
	}
	//0~20
	else if ((0 <= happiness) && (happiness < 20)) {
		printf("\n\n%s���� ���� ���� �Ͼ�ǰ���?\n", name_str); Sleep(1200);
		printf("%s�� ������ ����ֽ��ϴ�!\n", name_str); Sleep(1000);
		printf("����� �ٸ���ġ %s(��)�� ���� ��� �����߽��ϴ�...\n", name_str); Sleep(1500);
		printf("��... ������ �÷������ּż� ��ô ����帳�ϴ�!\n\n"); Sleep(1500);
	}
	//20~40
	else if ((20 <= happiness) && (happiness < 40)) {
		printf("\n\n%s(��)�� �ɼ��� �� �ɱ��?\n", name_str); Sleep(1000);
		printf("%s�� ����� �������⿣ ���� ���� �� �� ���׿�!\n", name_str); Sleep(1500);
		printf("�������� �й��ϼž߰ڽ��ϴ�!\n"); Sleep(1000);
		printf("������ �÷������ּż� ��ô ����帳�ϴ�!\n\n"); Sleep(1500);
	}
	//40~60
	else if ((40 <= happiness) && (happiness < 60)) {
		printf("\n\n%s�� ����� �׷������Դϴ�\n", name_str); Sleep(1000);
		printf("%s�� ����� �������⿣ ���� ������ �� ���׿�!\n", name_str); Sleep(1500);
		printf("�������� �й��Ͻø��� �Ͻ��ϴ�!\n"); Sleep(1000);
		printf("������ �÷������ּż� ��ô ����帳�ϴ�!\n\n"); Sleep(1500);
	}
	//60~80
	else if ((60 <= happiness) && (happiness < 80)) {
		printf("\n\n%s�� ����� �����ϴ�!\n", name_str); Sleep(1000);
		printf("�ణ�� �ƽ����� ���� ��Ȳ�� �����غ��̴� �� ���׿�!\n"); Sleep(1500);
		printf("������ �÷������ּż� ��ô ����帳�ϴ�!\n\n"); Sleep(1500);
	}
	//80~100
	else if ((80 <= happiness) && (happiness < 100)) {
		printf("\n\n%s�� ����� �ְ��Դϴ�!\n", name_str); Sleep(1000);
		printf("����� �ٸ���ġ Ű����� �������!\n"); Sleep(1200);
		printf("%s�� �ູ�� 100�� �ѱ�� ���� ���� �������...?\n", name_str); Sleep(1500);
		printf("�ƹ�ư ������ �÷������ּż� ��ô ����帳�ϴ�!\n\n"); Sleep(1500);
	}
	//100�̻�
	else if (happiness >= 100) {
		printf("\n\n%s�� ����� �����̶� ���ư� �� �մϴ�!\n", name_str); Sleep(1200);
		printf("����� �ٸ���ġ Ű����� ���̱���!\n"); Sleep(1200);
		printf("�ູ�� 100�� �ѱ��� ���� ������ �ѱ�ôٴ�...\n"); Sleep(1200);
		printf("Ư���� ������ �帮���� �ϰڽ��ϴ�...!\n"); Sleep(1200);
		Sleep(2000);
		printf("����� \'�ٸ���ġ�� ����\'�� ������ϴ�!\n"); Sleep(1500);
		printf("�������� ����� ��� �ڵ�� \"�Ϻ��� ������\"�� ���Դϴ�!\n"); Sleep(1500);
		printf("������ �÷������ּż� ��ô ����帳�ϴ�!\n\n"); Sleep(1500);
	}
}

//���� 1���� ���� 2��
void lv1_to_lv2() {
	while (1) {
		menu();
		if ((food_count >= 1) && (sleep_count >= 1) && (shower_count >= 1) && (play_count >= 1)) {
			Sleep(1000);
			printf("���� 2�� ��ȭ!\n\n");
			Sleep(1500);
			level = 2;
			break;
		}
	}
	food_count = 0;
	sleep_count = 0;
	shower_count = 0;
	play_count = 0;
}

//���� 2���� ���� 3��
void lv2_to_lv3() {
	while (1) {
		menu();
		if ((food_count >= 2) && (sleep_count >= 2) && (shower_count >= 2) && (play_count >= 2)) {
			Sleep(1000);
			printf("���� 3���� ��ȭ!\n\n");
			Sleep(1500);
			level = 3;
			break;
		}
	}
	food_count = 0;
	sleep_count = 0;
	shower_count = 0;
	play_count = 0;
}

//���� 3���� ���� 4��
void lv3_to_lv4() {
	while (1) {
		menu();
		if ((food_count >= 3) && (sleep_count >= 3) && (shower_count >= 3) && (play_count >= 3)) {
			Sleep(1000);
			printf("���� 4�� ��ȭ!\n\n");
			Sleep(1500);
			level = 4;
			break;
		}
	}
	food_count = 0;
	sleep_count = 0;
	shower_count = 0;
	play_count = 0;
}

//���� 4���� ���� 5��
void lv4_to_lv5() {
	while (1) {
		menu();
		if ((food_count >= 4) && (sleep_count >= 4) && (shower_count >= 4) && (play_count >= 4)) {
			Sleep(1000);
			printf("���� 5�� ��ȭ!\n\n");
			Sleep(1500);
			level = 5;
			break;
		}
	}
}

//����
void ending() {
	printf("������ �ٸ���ġ Ű���... ������̳���?\n"); Sleep(1500);
	printf("��հ� ����ּ����� ���ڽ��ϴ�!\n"); Sleep(1000);
	printf("���� ������ �ٸ���ġ Ű��� ������ �����ϵ��� �ϰڽ��ϴ�\n"); Sleep(1800);
	printf("�̻����� �ѳ����б� �̵������� 20190876 �ڼ����̾����ϴ�\n"); Sleep(2000);
	printf("�����մϴ�!\n"); Sleep(1000);
}

//�����Լ�
int main(void)
{
	opening();
	print_start();
	start_or_end();
	name();
	lv1_to_lv2();
	lv2_to_lv3();
	lv3_to_lv4();
	lv4_to_lv5();
	happiness_ending();
	ending();
	return 0;
}