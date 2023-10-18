#include <iostream>
#include <string>  
using namespace std;

// ���ڿ��� ��� ���ڸ� �ҹ��ڷ� �ٲٴ� �Լ�
string toLowerStr(string str) {
	for (char& c : str)  
		c = tolower(c);
	return str;
}

// ���ڿ��� ��� ���ڸ� �빮�ڷ� �ٲٴ� �Լ�
string toUpperStr(string str) {
	for (char& c : str)
		c = toupper(c);
	return str;
}

// �� ���ڿ��� �޾ƿ� �� ���ڿ��� ���ڸ� ��� �ҹ��ڷ� �ٲٰ� �ع� �Ÿ��� ���ϴ� �Լ�
int calcHammingDist(string s1, string s2) {
	int count = 0;  // ������ ��ġ���� �ٸ� ������ ����
	
	s1 = toLowerStr(s1);  // �Ǵ� s1 = toUpperStr(s1)
	s2 = toLowerStr(s2);  // �Ǵ� s2 = toUpperStr(s2)

	// ������ ��ġ(index)���� ���� �ٸ� ���ڸ� ���� ��, count �� 1 ����
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i])
			count += 1;
	}
	return count;
}

int main() {
	string s1, s2;

	while (true) {
		// ���ڿ� s1�� s2�� �Է¹���
		cout << "DNA1: ";
		cin >> s1;
		cout << "DNA2: ";
		cin >> s2;

		if (s1.length() != s2.length()) {
			cout << "�� ���ڿ��� ���̰� �ٸ��ϴ�. \n";
			continue;  // while ���� ó�� �������� ���ư� s1�� s2�� ���Ӱ� �Է� ����
		}
		else
			break;  // �� ���ڿ��� ���̰� ���� �� while���� ���
	}

	// calcHammingDist �Լ��� ȣ���Ͽ� ��ҹ��ڿ� ������� �ع� �Ÿ��� ���
	cout << "�ع� �Ÿ��� " << calcHammingDist(s1, s2) << endl;

	return 0;
}