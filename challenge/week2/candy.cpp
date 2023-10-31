#include <iostream>
using namespace std;

int main() {
	int money, candyPrice;  // money는 현대 가지고 있는 돈을 저장할 변수
	                        // candyPrice는 캔디의 가격을 저장할 변수

	cout << "현재 가지고 있는 돈: ";
	cin >> money;  // cin을 통해 money의 값을 입력 받음 

	cout << "캔디의 가격: ";
	cin >> candyPrice;  // candyPrice의 값을 입력 받음

	cout << "최대로 살 수 있는 캔디 = " << money / candyPrice << endl;
	// 최대로 살 수 있는 캔디의 수는 현재 돈에서 캔디의 가격을 나누어준 값

	cout << "캔디 구입 후 남은 돈 = " << money % candyPrice << endl;
	// 캔디 구입 후 남은 돈은 현재 돈에서 캔디의 가격을 나누었을 때 생기는 나머지 값
	return 0;
}