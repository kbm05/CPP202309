#include <iostream>
using namespace std;

const int numCell = 3; // �������� ���� ���� ����
char board[numCell][numCell]{}; // �������� ��Ÿ���� 2���� �迭

bool isValid(int x, int y) {
	bool valid = true;
	if (x >= numCell || y >= numCell) {// ��ǥ ������ �����
		cout << x << "," << y << ": x�� y���� �ϳ��� ĭ�� ����ϴ�. " << endl;
		valid = false;
	}
	else
		if (board[x][y] != ' ') {// ��ǥ������ �Է°��� �ߺ��ɶ�
			cout << x << "," << y << ": �̹� ���� ���ֽ��ϴ�. " << endl;
			valid = false;
		}
	return valid;
}

bool checkWin(char currentUser) {

	bool isWin = false;

	// 6.1. ����/���� �� üũ�ϱ�
	for (int i = 0; i < numCell; i++) {
		if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
			cout << "���ο� ��� ���� �������ϴ�!!";
			isWin = true;
			break;
		}
		if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
			cout << "���ο� ��� ���� �������ϴ�!!";
			isWin = true;
			break;
		}
	}


	// 6.2. �밢���� üũ�ϱ�
	// TODO 1.3: numCell�� ���� �밢�� ���� üũ �ڵ�� Ȯ��
	// HINT: for ��
	int rightDown = 0, leftDown = 0;
	for (int i = 0; i < numCell; i++) {
		if (board[i][i] == currentUser)
			rightDown++;

		if (rightDown == numCell) {
			cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
			isWin = true;
		}

		if (board[i][numCell - 1 - i] == currentUser)
			leftDown++;

		if (leftDown == numCell) {
			cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
			isWin = true;
		}
	}
	return isWin;
}

int main() {
	// ������ �����ϴ� �� �ʿ��� ���� ����

	int k = 0; // ���� �������� üũ�ϱ� ���� ����
	char currentUser = 'X'; // ���� ������ ���� �����ϱ� ���� ����
	int x, y = 0; // ����ڿ��� xy��ǥ���� �Է¹ޱ� ���� ����

	// ������ �ʱ�ȭ
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	int userNum = 3;  // ������ ��
	// ������ ���� �ݺ�
	while (true) {
		// 1. ���� �������� ���
		// TODO 1.1: 3�ο� �������� ����
		switch (k % 3) {
		case 0:
			currentUser = 'X';
			break;
		case 1:
			currentUser = 'O';
			break;
		case 2:
			currentUser = 'H';
			break;
		}
		cout << k % userNum + 1 << "�� ����(" << currentUser << ")�� �����Դϴ�. -> ";

		// 2. ��ǥ �Է� �ޱ�
		cout << "(x, y) ��ǥ�� �Է��ϼ���: ";
		int x, y;
		cin >> x >> y;

		// 3. �Է¹��� ��ǥ�� ��ȿ�� üũ
		// TODO FUNC 1: isValid �Լ� ���� �� ȣ��
		bool valid = isValid(x, y);
		if (valid == false)
			continue;


		// 4. �Է¹��� ��ǥ�� ���� ������ �� ����
		board[x][y] = currentUser;

		// 5. ���� ���� �� ���
		// TODO 1.2: numCell ���ڿ� ���� ������ ���
		for (int i = 0; i < numCell; i++) {
			for (int k = 0; k < numCell - 1; k++) {
				cout << "---|";
			}
			cout << "---" << endl;
			for (int j = 0; j < numCell; j++) {
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  |";
			}
			cout << endl;
		}
		for (int k = 0; k < numCell - 1; k++) {
			cout << "---|";
		}
		cout << "---" << endl;
		cout << endl;


		// TODO FUNC2: 6.1���� 6.2���� checkWin �Լ� ���� �� ȣ��
		bool isWin = checkWin(currentUser); // �¸� ����

		// �¸��ڰ� �����Ǿ����� �ش� �÷��̾ ����ϰ� ������ �����Ѵ�.
		if (isWin == true) {
			cout << k % userNum + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
			break;
		}

		// 7. ��� ĭ �� á���� üũ�ϱ�
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "��� ĭ�� �� á���ϴ�.  �����մϴ�. " << endl;
			break;
		}

		k++;
	}

	return 0;
}