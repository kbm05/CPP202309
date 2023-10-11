#include <iostream>
using namespace std;

int main() {
	const int numCell = 3;  // �������� ����, ���� ĭ ��
	char board[numCell][numCell]{};  // �迭�� ��� ĭ�� 0�̳� null�� �ʱ�ȭ
	int x, y;  // ����ڿ��� �Է¹޴� (x,y) ��ǥ�� ������ ����

	// �������� ��ĭ���� �ʱ�ȭ
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}

	// ���� �ڵ�
	int k = 0;  // ������ �������� üũ�ϱ� ���� ����
	char currentUser = 'X';  // ���� ������ ���� �����ϱ� ���� ���� ����
	while (true) {
		// 1. ������ �������� ���
		switch (k % 2) {
		case 0:
			cout << k % 2 + 1 << "�� ����(X)�� �����Դϴ� -> ";
			currentUser = 'X';
			break;
		case 1:
			cout << k % 2 + 1 << "�� ����(O)�� �����Դϴ� -> ";
			currentUser = 'O';
			break;
		}

		// 2. (x, y) ��ǥ�� �Է¹���
		cout << "(x, y) ��ǥ�� �Է��ϼ���: ";
		cin >> x >> y;


		// 3. �Է¹��� ��ǥ�� ��ȿ�� üũ
		if (x >= numCell || y >= numCell) {
			cout << x << ", " << y << ": ";
			cout << "x�� y �� �� �ϳ��� ĭ�� ����ϴ�." << endl;
			cout << endl;
			continue;
		}
		if (board[x][y] != ' ') {
			cout << x << ", " << y << ": �̹� ���� ���ֽ��ϴ�." << endl;
			cout << endl;
			continue;
		}

		// 4. �Է¹��� ��ǥ�� ���� ������ �� ����
		board[x][y] = currentUser;

		// 5. ���� ���� �� ���
		for (int i = 0; i < numCell; i++) {
			cout << "---|---|---" << endl;
			for (int j = 0; j < numCell; j++) {
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  |";
			}
			cout << endl;
		}
		cout << "---|---|---" << endl;
		cout << endl;

		// 6. ���� �� ���� ��� �� ����
		for (int i = 0; i < numCell; i++) {
			// (1) ���ο� ��� ���� ���� ����
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
				cout << "���ο� ��� ���� ���� �������ϴ�!: ";
				cout << k % 2 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
				cout << "������ �����մϴ�\n";
				break;
			}

			// (2) ���ο� ��� ���� ���� ����
			if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
				cout << "���ο� ��� ���� ���� �������ϴ�!: ";
				cout << k % 2 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
				cout << "������ �����մϴ�\n";
				break;
			}
		}

		// (3) ���� ������ ������ �Ʒ� �밢������ ��� ���� ���� ����
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
			cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� ���� �������ϴ�!: ";
			cout << k % 2 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
			cout << "������ �����մϴ�\n";
			break;
		}

		// (4) ������ ������ ���� �Ʒ� �밢������ ��� ���� ���� ����
		if (board[2][0] == currentUser && board[1][1] == currentUser && board[0][2] == currentUser) {
			cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� ���� �������ϴ�!: ";
			cout << k % 2 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
			cout << "������ �����մϴ�\n";
			break;
		}

		// 7. ��� ĭ�� �� á���� ���� ����
		int blank = 0;  // �����ǿ��� ��ĭ�� ���� ��Ÿ���� ����
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					blank++;
				}
			}
		}
		if (blank == 0) {  // ��ĭ�� ���� �� ���� ����
			cout << "��� ĭ�� �� á���ϴ�. ������ �����մϴ�\n";
			break;
		}

		k++;  // ���� �������� ���ʸ� �ѱ�
	}
	return 0;
}