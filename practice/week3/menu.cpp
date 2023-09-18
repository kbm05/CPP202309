#include <iostream>
using namespace std;

int main() {
	int choice;

	cout << "1. 파일 저장" << endl;
	cout << "2. 저장 없이 닫기" << endl;
	cout << "3. 종료" << endl;
	cin >> choice;  //choice 변수에 입력한 값 대입

	switch (choice) {
		case 1:
			cout << "파일 저장을 선택했습니다." << endl; //choice의 값이 1일 때 출력
			break;
		case 2:
			cout << "파일 닫기를 선택했습니다." << endl; //choice의 값이 2일 때 출력
			break;
		case 3:
			cout << "프로그램을 종료합니다." << endl; //choice의 값이 3일 때 출력
			break;
		default:
			cout << "잘못된 선택입니다." << endl; //choice의 값이 1, 2, 3이 아닐 때 출력
			break;
	}

	return 0;
}