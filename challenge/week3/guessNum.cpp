#include <iostream>
#include <time.h>  //rand() 함수를 호출하기 위한 헤더 포함
using namespace std;

int main() {
	srand(time(NULL));  //random 함수 관련 설정

	int answer = rand() % 100;  //0부터 99의 숫자 중 무작위로 선정된 정답
	int tries = 0;  //시도 횟수를 저장하기 위한 변수

	int guess;  //사용자 입력을 저장하기 위한 변수

	do {
		cout << "정답을 추측하여 보시오: ";
		cin >> guess;
		++tries;  //반복문을 돌때마다 tries의 값이 1증가

		if (guess > answer)
			cout << "제시한 정수가 높습니다." << endl;
		else if (guess < answer)
			cout << "제시한 정수가 낮습니다." << endl;
		else
			break;  //guess == answer일 때 정답 -> while문을 벗어나기 위해 break 사용

	} while (true);

	cout << "축하합니다. 시도 횟수 = " << tries << endl;

	return 0;
}