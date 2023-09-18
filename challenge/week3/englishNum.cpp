#include <iostream>
using namespace std;

int main() {
	int number;
	cout << "숫자를 입력하시오: ";
	cin >> number;  //number 변수에 입력한 값 대입
	
	if (number == 0)
		cout << "zero\n";  //number의 값이 0일 때 "zero" 출력
	else if (number == 1)
		cout << "one\n";  //number의 값이 1일 때 "one" 출력
	else
		cout << "many\n";  //number의 값이 0과 1이 아닐 때 "many" 출력

	return 0;
}