#include <iostream>
using namespace std;

int main() {
	int choice;

	cout << "1. ���� ����" << endl;
	cout << "2. ���� ���� �ݱ�" << endl;
	cout << "3. ����" << endl;
	cin >> choice;  //choice ������ �Է��� �� ����

	switch (choice) {
		case 1:
			cout << "���� ������ �����߽��ϴ�." << endl; //choice�� ���� 1�� �� ���
			break;
		case 2:
			cout << "���� �ݱ⸦ �����߽��ϴ�." << endl; //choice�� ���� 2�� �� ���
			break;
		case 3:
			cout << "���α׷��� �����մϴ�." << endl; //choice�� ���� 3�� �� ���
			break;
		default:
			cout << "�߸��� �����Դϴ�." << endl; //choice�� ���� 1, 2, 3�� �ƴ� �� ���
			break;
	}

	return 0;
}