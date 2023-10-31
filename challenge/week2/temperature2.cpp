#include <iostream>
using namespace std;

int main() {
	double C; // 섭씨온도를 저장할 변수

	cout << "섭씨온도: ";
	cin >> C; // 섭씨온도를 입력하여 C에 저장

	cout << "화씨온도 = " << (9.0 / 5.0) * C + 32 << endl; //화씨온도 출력
	// 섭씨온도 = (5.0 / 9.0) * (화씨온도 - 32)
	// 화씨온도 = (9.0 / 5.0) * 섭씨온도 + 32

	return 0;
}