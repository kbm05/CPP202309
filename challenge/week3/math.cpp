#include <iostream>
#include <time.h>
using namespace std;

int main() {
	int i = 0;  //i는 정답 횟수
	int ans;
	cout << "산수 문제를 자동으로 출제합니다." << endl;

	while (true) {
		int firstNum = rand() % 100;
		int secondNum = rand() % 100;

		cout << firstNum << " + " << secondNum << " = ";

		cin >> ans;  //답 입력 받기

		if (ans == (firstNum + secondNum)) {
			i++;  //정답일때 i(정답 횟수)의 값 증가
			cout << "맞았습니다." << endl;
		}
		else {
			cout << "틀렸습니다." << endl;
		}

		if (i == 5)
			break;  //5번 정답일때 종료
	}
	return 0;
}