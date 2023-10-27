#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;
int hp = 20;  // hp 값 저장

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y);

//맵을 벗어날 때 출력할 함수
void printFalse() {
	cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
}

//맵을 벗어나지 않고 원하는 방향으로 이동 가능할 때 줄력할 함수
void printTrue(string move) {
	cout << move << "쪽으로 한 칸 이동합니다." << endl;
	hp -= 1;  // 이동할 때 체력 1 감소
}

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		cout << endl;

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << "현재 HP: " << hp;
		cout << "   명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;

		if (user_input == "상") {
			// 위로 한 칸 올라가기
			user_y -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				printFalse();  // 맵을 벗어날 때 출력할 함수 호출
				user_y += 1;
				continue;
			}
			else {
				string move = "위";
				printTrue(move);  // 맵을 벗어나지 않을 때 출력할 함수 호출
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "하") {
			// 아래로 한 칸 내려가기
			user_y += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				printFalse();  // 맵을 벗어날 때 출력할 함수 호출
				user_y -= 1;
				continue;
			}
			else {
				string move = "아래";
				printTrue(move);  // 맵을 벗어나지 않을 때 출력할 함수 호출
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "좌") {
			// 왼쪽으로 이동하기
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				printFalse();  // 맵을 벗어날 때 출력할 함수 호출
				user_x += 1;
				continue;
			}
			else {
				string move = "왼";
				printTrue(move);  // 맵을 벗어나지 않을 때 출력할 함수 호출
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "우") {
			// 오른쪽으로 이동하기
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				printFalse();  // 맵을 벗어날 때 출력할 함수 호출
				user_x -= 1;
				continue;
			}
			else {
				string move = "오른";
				printTrue(move);  // 맵을 벗어나지 않을 때 출력할 함수 호출
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "지도") {
			// 지도 보여주기 함수 호출
			displayMap(map, user_x, user_y);
			continue;
		}
		else if (user_input == "종료") {
			cout << "종료합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 아이템, 포션, 적을 만났을 때 그에 대한 메시지 출력 & HP 감소/증가
		checkState(map, user_x, user_y);

		// HP가 0 이하가 되면 게임 종료
		if (hp <= 0) {
			cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		cout << " ---------------------------------- " << endl;
		cout << "|";
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
	}
	cout << " ---------------------------------- " << endl;
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// 아이템, 포션, 적을 만났을 때 그에 대한 메시지 출력 & HP 감소/증가 함수
void checkState(int map[][mapX], int user_x, int user_y) {
	// 적을 만났을 때 HP 2 감소, 포션을 만났을 때 HP 2 증가
	switch (map[user_y][user_x]) {
	case 1:
		cout << "아이템이 있습니다." << endl;
		break;
	case 2:
		hp -= 2;
		cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
		break;
	case 3:
		hp += 2;
		cout << "포션이 있습니다. HP가 2 늘어납니다." << endl;
		break;
	}
}