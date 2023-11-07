#include <iostream>
#include <string>
using namespace std;

bool checkSame(int number, int& first, int& second, int& third) {
	// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ���� �ۼ�
	first = number / 100;
	second = (number % 100) / 10;
	third = number % 10;

	bool same = true;

	if (first == second || first == third || second == third)
		same = false;

	return same;
}

int main() {
	int randomNum; // ����� �ϴ� 3�ڸ����� ���� ���� ����
	int firstNum; // ������ ù��° �ڸ���
	int secondNum; // ������ �ι�° �ڸ���
	int thirdNum; // ������ ����° �ڸ���

	while (1) {
		randomNum = rand() % 900 + 100; // ������ 3�ڸ��� ����

		bool same = checkSame(randomNum, firstNum, secondNum, thirdNum); // ��� ���� �ٸ� ��� true�� ���� ����

		if (same == true) {
			break;
		}
	}

	int turn = 0;
	while (1) {
		cout << turn + 1 << "��° �õ��Դϴ�. " << endl;

		int userNumber; // ����ڰ� �Է��� ���ڸ��� ���� ����
		int guessFirst; // ������ ������ ù��° �ڸ���
		int guessSecond; // ������ ������ �ι�° �ڸ���
		int guessThird; // ������ ������ ����° �ڸ���


		// ����ڿ��� ���ڸ� ���� �Է¹޴� �ڵ� ����
		while (1) {
			cout << "���ڸ� ���� �Է����ּ���: ";
			cin >> userNumber;

			bool same = checkSame(userNumber, guessFirst, guessSecond, guessThird); // ��� ���� �ٸ� ��� true�� ���� ����

			if (to_string(userNumber).length() != 3) {
				cout << "�Էµ� ���ڰ� 3�ڸ� ���� �ƴմϴ�. �ٽ� �Է��ϼ���." << endl;
				continue;
			}

			if (same == false) {
				cout << "�Է��� ���ڿ� �ߺ��� ���ڰ� �ֽ��ϴ�. �ٽ� �Է��ϼ���." << endl;
				continue;
			}

			if (same == true) {
				break;
			}
		}


		int strike = 0; // ��Ʈ����ũ ������ �����ϴ� ����
		int ball = 0; // �� ������ �����ϴ� ����

		// TODO 2: ����� ������ ������ �ڸ����� ���ڸ� ���ϸ� ��Ʈ�� �ֱ� ���� �ڵ���� �ۼ�
		string random = to_string(randomNum);
		string num = to_string(userNumber);

		for (int i = 0; i < random.length(); i++) {
			if (random[i] == num[i])
				strike++;
			else {
				if (random[i] == num[0]) ball++;
				if (random[i] == num[1]) ball++;
				if (random[i] == num[2]) ball++;
			}
		}

		if (strike == 0 && ball == 0) {
			cout << userNumber << "�� ��� : �ƿ� �Դϴ�." << endl;
		}
		else {
			cout << userNumber << "�� ��� : " << strike << " ��Ʈ����ũ, " << ball << "�� �Դϴ�." << endl;
		}

		if (strike == 3) {
			cout << "������ ������ϴ�. �����մϴ�.";
			break;
		}

		turn += 1;
	}

	return 0;
}