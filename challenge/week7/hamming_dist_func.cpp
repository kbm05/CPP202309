#include <iostream>
#include <string>  
using namespace std;

// 문자열의 모든 문자를 소문자로 바꾸는 함수
string toLowerStr(string str) {
	for (char& c : str)  
		c = tolower(c);
	return str;
}

// 문자열의 모든 문자를 대문자로 바꾸는 함수
string toUpperStr(string str) {
	for (char& c : str)
		c = toupper(c);
	return str;
}

// 두 문자열을 받아와 두 문자열의 문자를 모두 소문자로 바꾸고 해밍 거리를 구하는 함수
int calcHammingDist(string s1, string s2) {
	int count = 0;  // 동일한 위치에서 다른 글자의 개수
	
	s1 = toLowerStr(s1);  // 또는 s1 = toUpperStr(s1)
	s2 = toLowerStr(s2);  // 또는 s2 = toUpperStr(s2)

	// 동일한 위치(index)에서 서로 다른 글자를 가질 때, count 값 1 증가
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i])
			count += 1;
	}
	return count;
}

int main() {
	string s1, s2;

	while (true) {
		// 문자열 s1과 s2를 입력받음
		cout << "DNA1: ";
		cin >> s1;
		cout << "DNA2: ";
		cin >> s2;

		if (s1.length() != s2.length()) {
			cout << "두 문자열의 길이가 다릅니다. \n";
			continue;  // while 문의 처음 문장으로 돌아가 s1과 s2를 새롭게 입력 받음
		}
		else
			break;  // 두 문자열의 길이가 같을 때 while문을 벗어남
	}

	// calcHammingDist 함수를 호출하여 대소문자에 상관없는 해밍 거리를 출력
	cout << "해밍 거리는 " << calcHammingDist(s1, s2) << endl;

	return 0;
}