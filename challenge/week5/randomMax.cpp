#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	const int numCell = 10;  // 배열의 크기로 사용하기 위해서는 상수로 선언이 필요
	int numList[numCell][numCell];  // 10행, 10열의 이차원 배열 numList 선언

	for (int i = 0; i < numCell; i++) {  // 이차원 배열의 행에 접근
		for (int j = 0; j < numCell; j++) {  // 이차원 배열의 열에 접근
			int num = rand() % 1000;  // 0~999 사이의 수를 랜덤하게 가짐
			numList[i][j] = num;  // 랜덤한 수를 이차원 배열의 각 원소에 저장
			cout << i << ", " << j << " : " << num << endl;
		}
	}
	cout << endl;

	int max;  // 가장 큰 값을 저장하기 위한 변수
	int maxI;  // 큰 값이 있는 i를 저장하기 위한 변수
	int maxJ;  // 큰 값이 있는 j를 저장하기 위한 변수

	max = numList[0][0];  // max에 numList의 첫 행의 첫번째 원소 대입, 후에 다른 원소들과 비교해 더 큰 값으로 바뀔 예정
	for (int i = 0; i < numCell; i++) {  // numList 배열의 i번째 행에 접근
		int j = 0;  // max 값의 열(j) 위치를 찾기위한 변수
		for (int var : numList[i]) {  // numList i번째 행의 각 원소를 var변수에 대입
			if (var > max) {  // var > max 일 때, max에 var 대입 
				max = var;
				maxI = i;  // max 값의 행(i) 위치
				maxJ = j;  // max 값의 열(j) 위치
			}
			j++; // 열(j)의 위치 증가 (max의 열 위치 찾기 위함)
		}
		
	}

	cout << "가장 큰 값은 " << max << "이고, ";
	cout << "i와 j는 각각 " << maxI << ", " << maxJ << "입니다." << endl;
	cout << "검증 결과: " << numList[maxI][maxJ] << endl;

	return 0;
}