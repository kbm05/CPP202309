#include <iostream>
#define PI 3.14159265359 
//define을 통한 상수 선언
//상수로 선언한 변수의 값은 변경할 수 없음
//상수는 대문자로 적음
using namespace std;

int main() {
	int income = 1000;
	const double TAX_RATE = 0.25;  // const 키워드로 상수 선언
	income = income - TAX_RATE * income;

	double x = 100;
	x = x * PI;

	cout << x << endl;
	return 0;
}