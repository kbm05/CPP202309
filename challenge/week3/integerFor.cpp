#include <iostream>
using namespace std;

int main() {
	int userInput;

	cout << "������ 10�� �Է��ϼ��� (0�� �Է��ϸ� ����):";
	
	for (int i = 0; i < 10; i++) {  //i�� ���� 0���� 9�϶�����, �� ���� ������ 10�� ����
		cin >> userInput;
		
		if (userInput == 0) {  //�Է��� ������ 0�϶� ����
			break;
		}

		cout << "�Է°�: " << userInput << " Ƚ��: " << i << endl;
	}

	cout << "���� �Ǿ����ϴ�";

	return 0;
}