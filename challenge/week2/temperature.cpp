#include <iostream>
using namespace std;

int main() {
	double F; // F�� ȭ���µ��� ������ ����

	cout << "ȭ���µ�: ";
	cin >> F; // ȭ���µ��� F�� �Է� ����

	cout << "�����µ� = " << (5.0 / 9.0) * (F - 32) << endl; // �����µ� ���
	// �����µ� = (5.0 / 9.0) * (ȭ���µ� - 32)

	return 0;
}