#include <iostream>
#include <string>
using namespace std;

int main() {
	const int STUDENT = 5;
	const int SUBJECT = 3;
	int scores[STUDENT][SUBJECT];  // 5행, 3열의 이차원 배열 scores 선언
	string studentNames[STUDENT] = { "영수", "영희", "철수", "미미", "쥬쥬" };
	string subjectNames[SUBJECT] = { "수학", "영어", "CPP" };

	for (int i = 0; i < STUDENT; i++) {  // 이차원 배열 i번째 행에 접근
		cout << studentNames[i] << "의 성적을 하나씩 입력하세요." << endl;
		for (int j = 0; j < SUBJECT; j++) {  // 이차원 배열 i번째 행의 각 열에 접근
			cout << subjectNames[j] << ": ";
			cin >> scores[i][j];  // 각 원소에 학생들의 성적 입력
		}
	}

	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "의 평균 점수는 ";
		double sum = 0;
		double average = 0;
		for (int j = 0; j < SUBJECT; j++) {  // 각 학생들의 수학, 영어, cpp 성적에 접근하여, 그 합을 구함
			sum += scores[i][j];
		}
		average = sum / SUBJECT;  // 각 학생들의 성적의 합을 과목수로 나누어 평균을 구함
		cout << average << "입니다" << endl;
	}
	return 0;
}  