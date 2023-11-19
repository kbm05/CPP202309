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
		cout << name << " (" << age << "��)\n";
	}
};

int main() {
	int maxPeople;
	cout << "�� ���� ���� �Է��϶�: ";
	cin >> maxPeople;

	vector<Customer> c;

	for (int i = 0; i < maxPeople; i++) { //for �ݺ����� �̿��� �� �迭 ���ҿ� ����
		string n; int a;
		cout << "��� " << i + 1 << "�� �̸�: ";
		cin >> n; //names �迭�� �� ���ҿ� �̸� �Է�
		cout << "��� " << i + 1 << "�� ����: ";
		cin >> a; //ages �迭�� �� ���ҿ� ���� �Է�

		c.push_back(Customer(n, a));
	}

	int ageThreshold;
	cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���: ";
	cin >> ageThreshold;

	cout << ageThreshold << "�� �̻��� ����:\n";
	int count = 0; //Ư�� ���� �̻��� ���� ���� ������ ����
	for (auto& e : c) {
		if (e.GetAge() >= ageThreshold) {
			e.Print();
			count++;
		}
	}

	if (count == 0) //Ư�� ���� �̻��� ���� ���� �� count ���� 0, ���� ���� ���� ����
		cout << ageThreshold << "�� �̻��� ���̸� ���� ���� �����ϴ�";

	return 0;
}