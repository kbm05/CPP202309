#include <iostream>
#include <time.h>
using namespace std;

int main() {
	int i = 0;  //i�� ���� Ƚ��
	int ans;
	cout << "��� ������ �ڵ����� �����մϴ�." << endl;

	while (true) {
		int firstNum = rand() % 100;
		int secondNum = rand() % 100;

		cout << firstNum << " + " << secondNum << " = ";

		cin >> ans;  //�� �Է� �ޱ�

		if (ans == (firstNum + secondNum)) {
			i++;  //�����϶� i(���� Ƚ��)�� �� ����
			cout << "�¾ҽ��ϴ�." << endl;
		}
		else {
			cout << "Ʋ�Ƚ��ϴ�." << endl;
		}

		if (i == 5)
			break;  //5�� �����϶� ����
	}
	return 0;
}