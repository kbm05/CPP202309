#include <iostream>
#include <string>  
using namespace std;

int main() {
	string s1, s2;
	int count = 0;  // 동일한 위치에서 다른 글자의 개수

	// 문자열 s1과 s2를 입력받음
	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;

	// 문자열 s1과 s2의 길이를 비교
	if (s1.length() != s2.length())
		cout << "오류: 길이 다름" << endl;

	else { 
		// 동일한 위치(index)에서 서로 다른 글자를 가질 때, count 값 1 증가 
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				count += 1;
		}
		cout << "해밍 거리는 " << count << endl;
	}
	return 0;
}