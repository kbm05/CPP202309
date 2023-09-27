#include <iostream>
#include <string>
using namespace std;

int main() {
	const int maxPeople = 3;  //maxPeople 변수를 상수로 설정하여 3으로 초기화
	
	//cout << "총 고객의 수를 입력하라: ";
	//cin >> maxPeople;
	
	string names[maxPeople];  //크기가 3인 문자열 배열 생성
	int ages[maxPeople];

	for (int i = 0; i < maxPeople; i++) {  //for 반복문을 이용해 각 배열 원소에 접근
		cout << "사람 " << i + 1 << "의 이름: ";
		cin >> names[i];  //names 배열의 각 원소에 이름 입력
		cout << "사람 " << i + 1 << "의 나이: ";
		cin >> ages[i];  //ages 배열의 각 원소에 나이 입력
	}

	int ageThreshold;
	cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요: ";
	cin >> ageThreshold;

	cout << ageThreshold << "세 이상인 고객들:\n";
	int count = 0;  //특정 나이 이상인 고객의 수를 저장할 변수 count
	for (int i = 0; i < maxPeople; i++) {
		if (ages[i] >= ageThreshold) {
			cout << names[i] << "(" << ages[i] << ") ";
			count++;  //특정 나이 이상일 시 count 변수의 값 1 증가
		}
	}

	if (count == 0)  //특정 나이 이상의 고객이 없을 시 count 값은 0, 따라서 하위 문장 실행
		cout << ageThreshold << "세 이상의 나이를 가진 고객이 없습니다";

	return 0;
}