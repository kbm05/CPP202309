#include <iostream>
using namespace std;

int main() {
	int a, b, c, small;

	cout << "3���� ������ �Է��Ͻÿ�: ";
	cin >> a >> b >> c;  //���� a, b, c�� ���ʷ� ������ �Է¹���

	if (a <= b && a <= c)
		small = a;
	//a <= b�� a <= c�� ��� ������ ��(a�� ���� ���� ���� ��), small ������ a�� ����
	else if (b <= a && b <= c)
		small = b;
	//b <= a�� b <= c�� ��� ������ ��(b�� ���� ���� ���� ��), small ������ b�� ����
	else
		small = c;
	//���� ������ ��� �� �������� ���� ��, �� c�� ���� ���� ���� �� small ������ c�� ����

	//if-else ���� �����ϰ� ����, �Է¹��� ���� �� ���� ���� ������ small ������ ���Ե� 

	cout << "���� ���� ������ " << small << endl;  //3���� ���� �� ���� ���� �� ���
	return 0;
}