#include <iostream>
#include <string>
using namespace std;

int main() {
	const int maxPeople = 3;  //maxPeople ������ ����� �����Ͽ� 3���� �ʱ�ȭ
	
	//cout << "�� ���� ���� �Է��϶�: ";
	//cin >> maxPeople;
	
	string names[maxPeople];  //ũ�Ⱑ 3�� ���ڿ� �迭 ����
	int ages[maxPeople];

	for (int i = 0; i < maxPeople; i++) {  //for �ݺ����� �̿��� �� �迭 ���ҿ� ����
		cout << "��� " << i + 1 << "�� �̸�: ";
		cin >> names[i];  //names �迭�� �� ���ҿ� �̸� �Է�
		cout << "��� " << i + 1 << "�� ����: ";
		cin >> ages[i];  //ages �迭�� �� ���ҿ� ���� �Է�
	}

	int ageThreshold;
	cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���: ";
	cin >> ageThreshold;

	cout << ageThreshold << "�� �̻��� ����:\n";
	int count = 0;  //Ư�� ���� �̻��� ���� ���� ������ ���� count
	for (int i = 0; i < maxPeople; i++) {
		if (ages[i] >= ageThreshold) {
			cout << names[i] << "(" << ages[i] << ") ";
			count++;  //Ư�� ���� �̻��� �� count ������ �� 1 ����
		}
	}

	if (count == 0)  //Ư�� ���� �̻��� ���� ���� �� count ���� 0, ���� ���� ���� ����
		cout << ageThreshold << "�� �̻��� ���̸� ���� ���� �����ϴ�";

	return 0;
}