#include <iostream>
using namespace std;

int main() {
	int number;
	cout << "���ڸ� �Է��Ͻÿ�: ";
	cin >> number;  //number ������ �Է��� �� ����
	
	if (number == 0)
		cout << "zero\n";  //number�� ���� 0�� �� "zero" ���
	else if (number == 1)
		cout << "one\n";  //number�� ���� 1�� �� "one" ���
	else
		cout << "many\n";  //number�� ���� 0�� 1�� �ƴ� �� "many" ���

	return 0;
}