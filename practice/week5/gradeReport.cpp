#include <iostream>
#include <string>
using namespace std;

int main() {
	const int STUDENT = 5;
	const int SUBJECT = 3;
	int scores[STUDENT][SUBJECT];  // 5��, 3���� ������ �迭 scores ����
	string studentNames[STUDENT] = { "����", "����", "ö��", "�̹�", "����" };
	string subjectNames[SUBJECT] = { "����", "����", "CPP" };

	for (int i = 0; i < STUDENT; i++) {  // ������ �迭 i��° �࿡ ����
		cout << studentNames[i] << "�� ������ �ϳ��� �Է��ϼ���." << endl;
		for (int j = 0; j < SUBJECT; j++) {  // ������ �迭 i��° ���� �� ���� ����
			cout << subjectNames[j] << ": ";
			cin >> scores[i][j];  // �� ���ҿ� �л����� ���� �Է�
		}
	}

	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "�� ��� ������ ";
		double sum = 0;
		double average = 0;
		for (int j = 0; j < SUBJECT; j++) {  // �� �л����� ����, ����, cpp ������ �����Ͽ�, �� ���� ����
			sum += scores[i][j];
		}
		average = sum / SUBJECT;  // �� �л����� ������ ���� ������� ������ ����� ����
		cout << average << "�Դϴ�" << endl;
	}
	return 0;
}  