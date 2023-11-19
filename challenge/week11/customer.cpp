#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Customer {
private:
	string name;
	int age;
public:
	Customer(string n = " ", int a = 0) {
		name = n; age = a;
	}
	string Getname() {
		return name;
	}
	int GetAge() {
		return age;
	}
	void Print() {
		cout << name << " (" << age << "세)\n";
	}
};

int main() {
	int maxPeople;
	cout << "총 고객의 수를 입력하라: ";
	cin >> maxPeople;

	vector<Customer> c;

	for (int i = 0; i < maxPeople; i++) { //for 반복문을 이용해 각 배열 원소에 접근
		string n; int a;
		cout << "사람 " << i + 1 << "의 이름: ";
		cin >> n; //names 배열의 각 원소에 이름 입력
		cout << "사람 " << i + 1 << "의 나이: ";
		cin >> a; //ages 배열의 각 원소에 나이 입력

		c.push_back(Customer(n, a));
	}

	int ageThreshold;
	cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요: ";
	cin >> ageThreshold;

	cout << ageThreshold << "세 이상인 고객들:\n";
	int count = 0; //특정 나이 이상인 고객의 수를 저장할 변수
	for (auto& e : c) {
		if (e.GetAge() >= ageThreshold) {
			e.Print();
			count++;
		}
	}

	if (count == 0) //특정 나이 이상의 고객이 없을 시 count 값은 0, 따라서 하위 문장 실행
		cout << ageThreshold << "세 이상의 나이를 가진 고객이 없습니다";

	return 0;
}