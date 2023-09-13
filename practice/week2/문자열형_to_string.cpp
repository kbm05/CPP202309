#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1 = "사과";
	string s2;
	//s2 = s1 + " " + 10 + "개";  
	//10이 숫자(int 타입)이어서 에러가 남
	
	s2 = s1 + " " + to_string(10) + "개";  
	//to_string()은 괄호 속의 타입을 문자열로 변경
	cout << s2 << endl;
}