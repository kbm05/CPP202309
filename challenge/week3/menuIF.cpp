#include <iostream>
using namespace std;

int main() {
	int choice;

	cout << "1. ���� ����" << endl;
	cout << "2. ���� ���� �ݱ�" << endl;
	cout << "3. ����" << endl;
	cin >> choice;  //choice ������ �Է��� �� ����

	if (choice == 1)
		cout << "���� ������ �����߽��ϴ�." << endl; //choice�� ���� 1�� �� ���
	else if (choice == 2)
		cout << "���� �ݱ⸦ �����߽��ϴ�." << endl; //choice�� ���� 2�� �� ���
	else if (choice == 3)
		cout << "���α׷��� �����մϴ�." << endl; //choice�� ���� 3�� �� ���
	else
		cout << "�߸��� �����Դϴ�." << endl; //choice�� ���� 1, 2, 3�� �ƴ� �� ���

	return 0;
}