#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	const int numCell = 10;  // �迭�� ũ��� ����ϱ� ���ؼ��� ����� ������ �ʿ�
	int numList[numCell][numCell];  // 10��, 10���� ������ �迭 numList ����

	for (int i = 0; i < numCell; i++) {  // ������ �迭�� �࿡ ����
		for (int j = 0; j < numCell; j++) {  // ������ �迭�� ���� ����
			int num = rand() % 1000;  // 0~999 ������ ���� �����ϰ� ����
			numList[i][j] = num;  // ������ ���� ������ �迭�� �� ���ҿ� ����
			cout << i << ", " << j << " : " << num << endl;
		}
	}
	cout << endl;

	int max;  // ���� ū ���� �����ϱ� ���� ����
	int maxI;  // ū ���� �ִ� i�� �����ϱ� ���� ����
	int maxJ;  // ū ���� �ִ� j�� �����ϱ� ���� ����

	max = numList[0][0];  // max�� numList�� ù ���� ù��° ���� ����, �Ŀ� �ٸ� ���ҵ�� ���� �� ū ������ �ٲ� ����
	for (int i = 0; i < numCell; i++) {  // numList �迭�� i��° �࿡ ����
		int j = 0;  // max ���� ��(j) ��ġ�� ã������ ����
		for (int var : numList[i]) {  // numList i��° ���� �� ���Ҹ� var������ ����
			if (var > max) {  // var > max �� ��, max�� var ���� 
				max = var;
				maxI = i;  // max ���� ��(i) ��ġ
				maxJ = j;  // max ���� ��(j) ��ġ
			}
			j++; // ��(j)�� ��ġ ���� (max�� �� ��ġ ã�� ����)
		}
		
	}

	cout << "���� ū ���� " << max << "�̰�, ";
	cout << "i�� j�� ���� " << maxI << ", " << maxJ << "�Դϴ�." << endl;
	cout << "���� ���: " << numList[maxI][maxJ] << endl;

	return 0;
}