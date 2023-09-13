#include <iostream>
#include <string>
using namespace std;

int main() {
	string name;
	cout << "이름을 입력하시오: ";
	cin >> name;  // name에 들어갈 문자를 입력받음
	cout << name << "을(를) 환영합니다" << endl;
	//출력 시 '<<'는 연결하여 출력한다는 의미
	return 0;
}