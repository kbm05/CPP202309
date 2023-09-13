#include <iostream>
using namespace std;

int main() {
	int two = 2;
	int eight = 8;
	int sum1 = 2;
	int sum2 = 2;

	sum1 = sum1 + two;
	//sum1 + two를 한 값 4를 sum1에 다시 대입
	//'+'가 '='보다 먼저 연산
	sum2 += eight;
	//이는 sum2 = sum2 + eight와 같은 의미
	//sum2에 10이 대입됨
	cout << "sum1 = " << sum1 << endl;
	cout << "sum2 = " << sum2 << endl;
}