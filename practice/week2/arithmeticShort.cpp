#include <iostream>
using namespace std;

int main() {
	int two = 2;
	int eight = 8;
	int sum1 = 2;
	int sum2 = 2;

	sum1 = sum1 + two;
	//sum1 + two�� �� �� 4�� sum1�� �ٽ� ����
	//'+'�� '='���� ���� ����
	sum2 += eight;
	//�̴� sum2 = sum2 + eight�� ���� �ǹ�
	//sum2�� 10�� ���Ե�
	cout << "sum1 = " << sum1 << endl;
	cout << "sum2 = " << sum2 << endl;
}