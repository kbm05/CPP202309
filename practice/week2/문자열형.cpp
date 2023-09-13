#include <iostream>
#include <string>  //string 타입을 사용하기 위함
using namespace std;

int main() {
	string s1 = "Good";
	string s2 = "Morning";
	string s3 = s1 + " " + s2 + "!";  //'+'는 문자열을 연결
	cout << s3 << endl;  //endl은 'enter(\n)'와 같은 의미 
	return 0;
}