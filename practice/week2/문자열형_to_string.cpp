#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1 = "���";
	string s2;
	//s2 = s1 + " " + 10 + "��";  
	//10�� ����(int Ÿ��)�̾ ������ ��
	
	s2 = s1 + " " + to_string(10) + "��";  
	//to_string()�� ��ȣ ���� Ÿ���� ���ڿ��� ����
	cout << s2 << endl;
}