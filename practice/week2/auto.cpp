#include <iostream>
using namespace std;

auto add(int x, int y) {  //add �Լ� ����
	return x + y;
}

int main() {
	auto sum = add(5, 6);  
	//auto�� ���� �����Ϸ��� �ڵ����� ���� Ÿ�� �߷�
	cout << sum;
	return 0;
}