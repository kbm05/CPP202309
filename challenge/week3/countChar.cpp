#include <iostream>
using namespace std;

int main() {
	int vowel = 0;;
	int consonant = 0;
	cout << "영문자를 입력하고 ctrl+z를 치세요" << endl;

	char ch;  //입력받을 값을 저장하기 위한 변수

	while (cin >> ch) {
		switch (ch) {  //case로 a, e, i, o, u 일 때를 이용하여 vowel(모음)의 개수 증가
		case 'a': 
			vowel++;
			break;
		case 'e':
			vowel++;
			break;
		case 'i':
			vowel++;
			break;
		case 'o':
			vowel++;
			break;
		case 'u':
			vowel++;
			break;
		default:  //모음이 아닐 때, 즉 입력한 문자가 자음일 때 consonant 값 증가
			consonant++;
		}
	}

	cout << "모음: " << vowel << endl;
	cout << "자음: " << consonant << endl;

	return 0;
}