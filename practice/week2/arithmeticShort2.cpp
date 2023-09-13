#include <iostream>
using namespace std;

int main() {
	int two = 2;
	int eight = 8;
	int sum1 = 2;
	int sum2 = 8;

	sum1 *= two;
	//sum1 = sum1 * two; 따라서 sum1의 값은 4
	sum2 /= eight;
	//sum2 = sum2 / eight; 따라서 sum2의 값은 1

	cout << "sum1 = " << sum1 << endl;
	cout << "sum2 = " << sum2 << endl;

	return 0;
}