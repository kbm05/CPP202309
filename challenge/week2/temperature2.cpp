#include <iostream>
using namespace std;

int main() {
	double C; // �����µ��� ������ ����

	cout << "�����µ�: ";
	cin >> C; // �����µ��� �Է��Ͽ� C�� ����

	cout << "ȭ���µ� = " << (9.0 / 5.0) * C + 32 << endl; //ȭ���µ� ���
	// �����µ� = (5.0 / 9.0) * (ȭ���µ� - 32)
	// ȭ���µ� = (9.0 / 5.0) * �����µ� + 32

	return 0;
}