#include <iostream>
using namespace std;

int main() {
	int a, b, c, largest;

	cout << "3���� ������ �Է��Ͻÿ�: ";
	cin >> a >> b >> c;  //���� a, b, c�� ���ʷ� ������ �Է¹���

	if (a >= b && a >= c)
		largest = a;
	//a >= b�� a >= c�� ��� ������ ��(a�� ���� ���� Ŭ ��), largest ������ a�� ����
	else if (b >= a && b >= c)
		largest = b;
	//b >= a�� b >= c�� ��� ������ ��(b�� ���� ���� Ŭ ��), largest ������ b�� ����
	else
		largest = c;
	//���� ������ ��� �� �������� ���� ��, �� c�� ���� ���� Ŭ �� largest ������ c�� ����

	//if-else ���� �����ϰ� ����, �Է¹��� ���� �� ���� ū ������ largest ������ ���Ե� 

	cout << "���� ū ������ " << largest << endl;  //3���� ���� �� ���� ū �� ���
	return 0;
}