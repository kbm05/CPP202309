#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1 = "Good";
	string s2 = "Morning";
	bool b = (s1 == s2);  
	//'==(��ȣ 2��)'�� �� ������ ���� �������� ��
	//s1�� s2�� ���� ���� �� true, �ٸ� �� false -> bool Ÿ�� ���� b�� ����
	cout << b << endl;

	s2 = "Good";  //s2�� ���� "Good"���� ����
	b = (s1 == s2); 
	cout << b << endl;
}