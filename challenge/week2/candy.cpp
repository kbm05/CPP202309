#include <iostream>
using namespace std;

int main() {
	int money, candyPrice;  // money�� ���� ������ �ִ� ���� ������ ����
	                        // candyPrice�� ĵ���� ������ ������ ����

	cout << "���� ������ �ִ� ��: ";
	cin >> money;  // cin�� ���� money�� ���� �Է� ���� 

	cout << "ĵ���� ����: ";
	cin >> candyPrice;  // candyPrice�� ���� �Է� ����

	cout << "�ִ�� �� �� �ִ� ĵ�� = " << money / candyPrice << endl;
	// �ִ�� �� �� �ִ� ĵ���� ���� ���� ������ ĵ���� ������ �������� ��

	cout << "ĵ�� ���� �� ���� �� = " << money % candyPrice << endl;
	// ĵ�� ���� �� ���� ���� ���� ������ ĵ���� ������ �������� �� ����� ������ ��
	return 0;
}