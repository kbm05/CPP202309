#include <iostream>
using namespace std;

const int NUM_USERS = 3;  // ������� ��
const int NUM_ITEMS = 3;  // �׸� ��
int userPreferences[NUM_USERS][NUM_ITEMS];  // ����ڵ��� ��ȣ���� ������ 2���� �迭 ����

// ����ڿ� �׸� ���� ��ȣ���� �Է� �޾� 2���� �迭�� �ʱ�ȭ�ϴ� �Լ� ����
void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS]) {
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "����� " << (i + 1) << "�� ��ȣ���� �Է��ϼ��� (";
		cout << NUM_ITEMS << "���� �׸� ����): ";
		for (int j = 0; j < NUM_ITEMS; ++j) {
			cin >> preferences[i][j];
		}
	}
}

// �� ����ڿ� ���� ��õ �׸��� ã�� ����ϱ� ���� �Լ� ����
void findRecommendedItems(int preferences[NUM_USERS][NUM_ITEMS]) {
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0;   // ��ȣ���� ���� �׸�(j)�� ������ ����
		for (int j = 0; j < NUM_ITEMS; ++j) {
			//�񱳸� ���� ��ȣ���� ���� �׸�(j) ã��
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;
			}
		}
		// ����ڿ��� ��õ�ϴ� �׸� ���
		cout << "����� " << (i + 1) << "���� ��õ�ϴ� �׸�: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}
}

int main() {

	// �Լ� ȣ���� ���� ��ȣ���� �ʱ�ȭ�ϰ� ����ڿ��� ��õ�� �׸� ã��
	initializePreferences(userPreferences);
	findRecommendedItems(userPreferences);

	return 0;
}