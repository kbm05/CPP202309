#include <iostream>
using namespace std;

int main() {
	int vowel = 0;;
	int consonant = 0;
	cout << "�����ڸ� �Է��ϰ� ctrl+z�� ġ����" << endl;

	char ch;  //�Է¹��� ���� �����ϱ� ���� ����

	while (cin >> ch) {
		switch (ch) {  //case�� a, e, i, o, u �� ���� �̿��Ͽ� vowel(����)�� ���� ����
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
		default:  //������ �ƴ� ��, �� �Է��� ���ڰ� ������ �� consonant �� ����
			consonant++;
		}
	}

	cout << "����: " << vowel << endl;
	cout << "����: " << consonant << endl;

	return 0;
}