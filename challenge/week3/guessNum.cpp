#include <iostream>
#include <time.h>  //rand() �Լ��� ȣ���ϱ� ���� ��� ����
using namespace std;

int main() {
	srand(time(NULL));  //random �Լ� ���� ����

	int answer = rand() % 100;  //0���� 99�� ���� �� �������� ������ ����
	int tries = 0;  //�õ� Ƚ���� �����ϱ� ���� ����

	int guess;  //����� �Է��� �����ϱ� ���� ����

	do {
		cout << "������ �����Ͽ� ���ÿ�: ";
		cin >> guess;
		++tries;  //�ݺ����� �������� tries�� ���� 1����

		if (guess > answer)
			cout << "������ ������ �����ϴ�." << endl;
		else if (guess < answer)
			cout << "������ ������ �����ϴ�." << endl;
		else
			break;  //guess == answer�� �� ���� -> while���� ����� ���� break ���

	} while (true);

	cout << "�����մϴ�. �õ� Ƚ�� = " << tries << endl;

	return 0;
}