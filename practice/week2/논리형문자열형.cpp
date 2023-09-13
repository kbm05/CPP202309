#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1 = "Good";
	string s2 = "Morning";
	bool b = (s1 == s2);  
	//'==(등호 2개)'는 두 변수의 값이 같은지를 비교
	//s1와 s2의 값이 같을 시 true, 다를 시 false -> bool 타입 변수 b에 대입
	cout << b << endl;

	s2 = "Good";  //s2의 값을 "Good"으로 변경
	b = (s1 == s2); 
	cout << b << endl;
}