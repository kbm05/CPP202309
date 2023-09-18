#include <iostream>
using namespace std;

int main() {
	int a, b, c, largest;

	cout << "3개의 정수를 입력하시오: ";
	cin >> a >> b >> c;  //변수 a, b, c에 차례로 정수를 입력받음

	if (a >= b && a >= c)
		largest = a;
	//a >= b와 a >= c를 모두 만족할 때(a의 값이 가장 클 때), largest 변수에 a값 대입
	else if (b >= a && b >= c)
		largest = b;
	//b >= a와 b >= c를 모두 만족할 때(b의 값이 가장 클 때), largest 변수에 b값 대입
	else
		largest = c;
	//위의 조건을 모두 다 만족하지 않을 시, 즉 c의 값이 가장 클 때 largest 변수에 c값 대입

	//if-else 문을 실행하고 나면, 입력받은 정수 중 가장 큰 정수가 largest 변수에 대입됨 

	cout << "가장 큰 정수는 " << largest << endl;  //3개의 정수 중 가장 큰 값 출력
	return 0;
}