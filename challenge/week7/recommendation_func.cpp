#include <iostream>
using namespace std;

const int NUM_USERS = 3;  // 사용자의 수
const int NUM_ITEMS = 3;  // 항목 수
int userPreferences[NUM_USERS][NUM_ITEMS];  // 사용자들의 선호도를 저장할 2차원 배열 선언

// 사용자와 항목 간의 선호도를 입력 받아 2차원 배열을 초기화하는 함수 선언
void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS]) {
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요 (";
		cout << NUM_ITEMS << "개의 항목에 대해): ";
		for (int j = 0; j < NUM_ITEMS; ++j) {
			cin >> preferences[i][j];
		}
	}
}

// 각 사용자에 대한 추천 항목을 찾아 출력하기 위한 함수 선언
void findRecommendedItems(int preferences[NUM_USERS][NUM_ITEMS]) {
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0;   // 선호도가 높은 항목(j)을 저장할 변수
		for (int j = 0; j < NUM_ITEMS; ++j) {
			//비교를 통한 선호도가 높은 항목(j) 찾기
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;
			}
		}
		// 사용자에게 추천하는 항목 출력
		cout << "사용자 " << (i + 1) << "에게 추천하는 항목: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}
}

int main() {

	// 함수 호출을 통해 선호도를 초기화하고 사용자에게 추천할 항목 찾기
	initializePreferences(userPreferences);
	findRecommendedItems(userPreferences);

	return 0;
}