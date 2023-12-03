#include "user.h"

const int mapX = 5;
const int mapY = 5;

int m_loc[2] = { 0, 0 };  // Magician의 현재 위치를 저장
int w_loc[2] = { 0, 0 };  // Warrior의 현재 위치를 저장

void Move(int userNum, User& user) {
	if (userNum % 2 == 0) {
		m_loc[0] = user.GetUser_X();
		m_loc[1] = user.GetUser_Y();
	}
	else {
		w_loc[0] = user.GetUser_X();
		w_loc[1] = user.GetUser_Y();
	}
}

// 사용자 정의 함수
bool checkXY(int mapX, int mapY, User& user);
void displayMap(int map[][mapX]);
bool checkGoal(int map[][mapX], User& user);
void checkState(int map[][mapX], User& user);
bool CheckUser(User& user);

class Magician :public User {
public:
	Magician(int hp) :User(hp) {}
	void doAttack() {
		cout << "마법 사용!";
	}
};

class Warrior :public User {
public:
	Warrior(int hp) :User(hp) {}
	void doAttack() {
		cout << "베기 사용!";
	}
};

// 메인  함수
int main() {
	Magician m(20);  // user0
	Warrior w(20);  // user1

	int userNum = 0;
	User* p = &m;

	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// 유저의 위치를 저장할 변수
	// int user_x = 0; // 가로 번호
	// int user_y = 0; // 세로 번호

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프
		cout << endl;

		switch (userNum % 2) {
		case 0:
			cout << "Magician의 차례입니다 -> ";
			p = &m;
			break;
		case 1:
			cout << "Warrior의 차례입니다 -> ";
			p = &w;
			break;
		}

		if (userNum == 0 || userNum == 1) {
			p->SetUser_X(0);
			p->SetUSer_Y(0);
		}

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << "현재 HP: " << p->GetHP() << "  명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;

		if (user_input == "상" || user_input == "하" || user_input == "좌" || user_input == "우") {
			if (user_input == "상") {
				// 위로 한 칸 올라가기
				p->SetUSer_Y(p->GetUser_Y() - 1);
				bool inMap = checkXY(mapX, mapY, *p);
				if (inMap == false) {
					cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
					p->SetUSer_Y(p->GetUser_Y() + 1);
					continue;
				}
				else {
					Move(userNum, *p);
					cout << "위로 한 칸 올라갑니다." << endl;
					displayMap(map);
					p->DecreaseHP(1);
				}
			}
			else if (user_input == "하") {
				// TODO: 아래로 한 칸 내려가기
				p->SetUSer_Y(p->GetUser_Y() + 1);
				bool inMap = checkXY(mapX, mapY, *p);
				if (inMap == false) {
					cout << "맵을 벗어났습니다. 다시 돌아갑니다. 다른 좌표를 입력하시오." << endl;
					p->SetUSer_Y(p->GetUser_Y() - 1);
					continue;
				}
				else {
					Move(userNum, *p);
					cout << "아래로 한 칸 내려갑니다." << endl;
					displayMap(map);
					p->DecreaseHP(1);
				}
			}
			else if (user_input == "좌") {
				// TODO: 왼쪽으로 이동하기
				p->SetUser_X(p->GetUser_X() - 1);
				bool inMap = checkXY(mapX, mapY, *p);
				if (inMap == false) {
					cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
					p->SetUser_X(p->GetUser_X() + 1);
					continue;
				}
				else {
					Move(userNum, *p);
					cout << "왼쪽으로 이동합니다." << endl;
					displayMap(map);
					p->DecreaseHP(1);
				}
			}
			else if (user_input == "우") {
				// TODO: 오른쪽으로 이동하기
				p->SetUser_X(p->GetUser_X() + 1);
				bool inMap = checkXY(mapX, mapY, *p);
				if (inMap == false) {
					cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
					p->SetUser_X(p->GetUser_X() - 1);
					continue;
				}
				else {
					Move(userNum, *p);
					cout << "오른쪽으로 이동합니다." << endl;
					displayMap(map);
					p->DecreaseHP(1);
				}
			}
			userNum++;
		}
		else if (user_input == "지도") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map);
			continue;
		}
		else if (user_input == "종료") {
			cout << "종료합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다. 다시 입력하시오." << endl;
			continue;
		}

		// 사용자의 위치 정보 체크
		checkState(map, *p);

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, *p);
		if (finish == true) {
			if (userNum % 2 == 0) {
				cout << "W가 ";
			}
			else {
				cout << "M이 ";
			}
			cout << "목적지에 도착했습니다!" << endl;

			if (userNum % 2 == 0) {
				cout << "Warrior의 ";
			}
			else {
				cout << "Magician의 ";
			}
			cout << "승리입니다. 축하합니다! ";
			cout << "게임을 종료합니다." << endl;
			break;
		}

		// 사용자의 HP 체크
		if (CheckUser(*p) == false) {
			if (userNum % 2 == 0) {
				cout << "W의 ";
			}
			else {
				cout << "M의 ";
			}
			cout << "HP가 0 이하가 되었습니다." << endl;

			if (userNum % 2 == 0) {
				cout << "Warrior의 ";
			}
			else {
				cout << "Magician의 ";
			}
			cout << "패배입니다. ";
			cout << "게임을 종료합니다." << endl;
			break;
		}

	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX]) {
	cout << " -------------------------------- " << endl;
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if ((i == m_loc[1] && j == m_loc[0]) && (i == w_loc[1] && j == w_loc[0])) {
				cout << "  M/W |"; 
			}
			else if (i == m_loc[1] && j == m_loc[0]) {
				cout << "   M  |";
			}
			else if (i == w_loc[1] && j == w_loc[0]) {
				cout << "   W  |";
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
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int mapX, int mapY, User& user) {
	bool checkFlag = false;
	if (user.GetUser_X() >= 0 && user.GetUser_X() < mapX && user.GetUser_Y() >= 0 && user.GetUser_Y() < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], User& user) {
	// 목적지 도착하면
	if (map[user.GetUser_Y()][user.GetUser_X()] == 4) {
		return true;
	}
	return false;
}

// 사용자가 위치한 장소의 상태를 출력하는 함수


// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
void checkState(int map[][mapX], User& user) {
	switch (map[user.GetUser_Y()][user.GetUser_X()]) {
	case 1:
		cout << "아이템이 있습니다" << endl;
		break;
	case 2:
		cout << "적이 있습니다. ";
		user.doAttack();
		cout << endl;
		cout << "그러나 적에게 공격을 받아 HP가 2 줄어듭니다." << endl;
		user.DecreaseHP(2);
		break;
	case 3:
		cout << "포션이 있습니다. HP가 2 늘어납니다." << endl;
		user.IncreaseHP(2);
		break;
	}
}

// hp가 0 이하인지 체크하고, 0 이하라면 false를 반환, 그렇지 않다면 true를 반환
bool CheckUser(User& user) {
	if (user.GetHP() <= 0) return false;
	else return true;
}