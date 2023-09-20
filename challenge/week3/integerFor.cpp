#include <iostream>
using namespace std;

int main() {
	int userInput;

	cout << "정수를 10번 입력하세요 (0을 입력하면 종료):";
	
	for (int i = 0; i < 10; i++) {  //i의 값이 0부터 9일때까지, 즉 하위 문장을 10번 실행
		cin >> userInput;
		
		if (userInput == 0) {  //입력한 정수가 0일때 종료
			break;
		}

		cout << "입력값: " << userInput << " 횟수: " << i << endl;
	}

	cout << "종료 되었습니다";

	return 0;
}