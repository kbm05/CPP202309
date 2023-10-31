#include <iostream>
using namespace std;

int main() {
	double F; // F는 화씨온도를 저장할 변수

	cout << "화씨온도: ";
	cin >> F; // 화씨온도를 F에 입력 받음

	cout << "섭씨온도 = " << (5.0 / 9.0) * (F - 32) << endl; // 섭씨온도 출력
	// 섭씨온도 = (5.0 / 9.0) * (화씨온도 - 32)

	return 0;
}