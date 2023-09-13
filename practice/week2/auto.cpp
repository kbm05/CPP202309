#include <iostream>
using namespace std;

auto add(int x, int y) {  //add 함수 선언
	return x + y;
}

int main() {
	auto sum = add(5, 6);  
	//auto를 통해 컴파일러가 자동으로 변수 타입 추론
	cout << sum;
	return 0;
}