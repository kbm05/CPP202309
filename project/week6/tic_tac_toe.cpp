#include <iostream>
using namespace std;

int main() {
	const int numCell = 3;  // 보드판의 가로, 세로 칸 수
	char board[numCell][numCell]{};  // 배열의 모든 칸을 0이나 null로 초기화
	int x, y;  // 사용자에게 입력받는 (x,y) 좌표를 저장할 변수

	// 보드판을 빈칸으로 초기화
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}

	// 게임 코드
	int k = 0;  // 누구의 차례인지 체크하기 위한 변수
	char currentUser = 'X';  // 현재 유저의 돌을 저장하기 위한 문자 변수
	while (true) {
		// 1. 누구의 차례인지 출력
		switch (k % 2) {
		case 0:
			cout << k % 2 + 1 << "번 유저(X)의 차례입니다 -> ";
			currentUser = 'X';
			break;
		case 1:
			cout << k % 2 + 1 << "번 유저(O)의 차례입니다 -> ";
			currentUser = 'O';
			break;
		}

		// 2. (x, y) 좌표를 입력받음
		cout << "(x, y) 좌표를 입력하세요: ";
		cin >> x >> y;


		// 3. 입력받은 좌표의 유효성 체크
		if (x >= numCell || y >= numCell) {
			cout << x << ", " << y << ": ";
			cout << "x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
			cout << endl;
			continue;
		}
		if (board[x][y] != ' ') {
			cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
			cout << endl;
			continue;
		}

		// 4. 입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = currentUser;

		// 5. 현재 보드 판 출력
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

		// 6. 빙고 시 승자 출력 후 종료
		for (int i = 0; i < numCell; i++) {
			// (1) 가로에 모두 같은 돌이 놓임
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
				cout << "가로에 모두 같은 돌이 놓였습니다!: ";
				cout << k % 2 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
				cout << "게임을 종료합니다\n";
				break;
			}

			// (2) 세로에 모두 같은 돌이 놓임
			if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
				cout << "세로에 모두 같은 돌이 놓였습니다!: ";
				cout << k % 2 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
				cout << "게임을 종료합니다\n";
				break;
			}
		}

		// (3) 왼쪽 위에서 오른쪽 아래 대각선으로 모두 같은 돌이 놓임
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
			cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 같은 돌이 놓였습니다!: ";
			cout << k % 2 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			cout << "게임을 종료합니다\n";
			break;
		}

		// (4) 오른쪽 위에서 왼쪽 아래 대각선으로 모두 같은 돌이 놓임
		if (board[2][0] == currentUser && board[1][1] == currentUser && board[0][2] == currentUser) {
			cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 같은 돌이 놓였습니다!: ";
			cout << k % 2 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			cout << "게임을 종료합니다\n";
			break;
		}

		// 7. 모든 칸이 다 찼으면 게임 종료
		int blank = 0;  // 보드판에서 빈칸의 수를 나타내는 변수
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					blank++;
				}
			}
		}
		if (blank == 0) {  // 빈칸이 없을 때 게임 종료
			cout << "모든 칸이 다 찼습니다. 게임을 종료합니다\n";
			break;
		}

		k++;  // 다음 유저에게 차례를 넘김
	}
	return 0;
}