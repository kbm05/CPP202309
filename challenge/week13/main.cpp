#include "user.h"

const int mapX = 5;
const int mapY = 5;

int m_loc[2] = { 0, 0 };  // Magician�� ���� ��ġ�� ����
int w_loc[2] = { 0, 0 };  // Warrior�� ���� ��ġ�� ����

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

// ����� ���� �Լ�
bool checkXY(int mapX, int mapY, User& user);
void displayMap(int map[][mapX]);
bool checkGoal(int map[][mapX], User& user);
void checkState(int map[][mapX], User& user);
bool CheckUser(User& user);

class Magician :public User {
public:
	Magician(int hp) :User(hp) {}
	void doAttack() {
		cout << "���� ���!";
	}
};

class Warrior :public User {
public:
	Warrior(int hp) :User(hp) {}
	void doAttack() {
		cout << "���� ���!";
	}
};

// ����  �Լ�
int main() {
	Magician m(20);  // user0
	Warrior w(20);  // user1

	int userNum = 0;
	User* p = &m;

	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// ������ ��ġ�� ������ ����
	// int user_x = 0; // ���� ��ȣ
	// int user_y = 0; // ���� ��ȣ

	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����
		cout << endl;

		switch (userNum % 2) {
		case 0:
			cout << "Magician�� �����Դϴ� -> ";
			p = &m;
			break;
		case 1:
			cout << "Warrior�� �����Դϴ� -> ";
			p = &w;
			break;
		}

		if (userNum == 0 || userNum == 1) {
			p->SetUser_X(0);
			p->SetUSer_Y(0);
		}

		// ������� �Է��� ������ ����
		string user_input = "";

		cout << "���� HP: " << p->GetHP() << "  ��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
		cin >> user_input;

		if (user_input == "��" || user_input == "��" || user_input == "��" || user_input == "��") {
			if (user_input == "��") {
				// ���� �� ĭ �ö󰡱�
				p->SetUSer_Y(p->GetUser_Y() - 1);
				bool inMap = checkXY(mapX, mapY, *p);
				if (inMap == false) {
					cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
					p->SetUSer_Y(p->GetUser_Y() + 1);
					continue;
				}
				else {
					Move(userNum, *p);
					cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
					displayMap(map);
					p->DecreaseHP(1);
				}
			}
			else if (user_input == "��") {
				// TODO: �Ʒ��� �� ĭ ��������
				p->SetUSer_Y(p->GetUser_Y() + 1);
				bool inMap = checkXY(mapX, mapY, *p);
				if (inMap == false) {
					cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�. �ٸ� ��ǥ�� �Է��Ͻÿ�." << endl;
					p->SetUSer_Y(p->GetUser_Y() - 1);
					continue;
				}
				else {
					Move(userNum, *p);
					cout << "�Ʒ��� �� ĭ �������ϴ�." << endl;
					displayMap(map);
					p->DecreaseHP(1);
				}
			}
			else if (user_input == "��") {
				// TODO: �������� �̵��ϱ�
				p->SetUser_X(p->GetUser_X() - 1);
				bool inMap = checkXY(mapX, mapY, *p);
				if (inMap == false) {
					cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
					p->SetUser_X(p->GetUser_X() + 1);
					continue;
				}
				else {
					Move(userNum, *p);
					cout << "�������� �̵��մϴ�." << endl;
					displayMap(map);
					p->DecreaseHP(1);
				}
			}
			else if (user_input == "��") {
				// TODO: ���������� �̵��ϱ�
				p->SetUser_X(p->GetUser_X() + 1);
				bool inMap = checkXY(mapX, mapY, *p);
				if (inMap == false) {
					cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
					p->SetUser_X(p->GetUser_X() - 1);
					continue;
				}
				else {
					Move(userNum, *p);
					cout << "���������� �̵��մϴ�." << endl;
					displayMap(map);
					p->DecreaseHP(1);
				}
			}
			userNum++;
		}
		else if (user_input == "����") {
			// TODO: ���� �����ֱ� �Լ� ȣ��
			displayMap(map);
			continue;
		}
		else if (user_input == "����") {
			cout << "�����մϴ�.";
			break;
		}
		else {
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��Ͻÿ�." << endl;
			continue;
		}

		// ������� ��ġ ���� üũ
		checkState(map, *p);

		// �������� �����ߴ��� üũ
		bool finish = checkGoal(map, *p);
		if (finish == true) {
			if (userNum % 2 == 0) {
				cout << "W�� ";
			}
			else {
				cout << "M�� ";
			}
			cout << "�������� �����߽��ϴ�!" << endl;

			if (userNum % 2 == 0) {
				cout << "Warrior�� ";
			}
			else {
				cout << "Magician�� ";
			}
			cout << "�¸��Դϴ�. �����մϴ�! ";
			cout << "������ �����մϴ�." << endl;
			break;
		}

		// ������� HP üũ
		if (CheckUser(*p) == false) {
			if (userNum % 2 == 0) {
				cout << "W�� ";
			}
			else {
				cout << "M�� ";
			}
			cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�." << endl;

			if (userNum % 2 == 0) {
				cout << "Warrior�� ";
			}
			else {
				cout << "Magician�� ";
			}
			cout << "�й��Դϴ�. ";
			cout << "������ �����մϴ�." << endl;
			break;
		}

	}
	return 0;
}


// ������ ����� ��ġ ����ϴ� �Լ�
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
					cout << "      |"; // 6ĭ ����
					break;
				case 1:
					cout << "������|";
					break;
				case 2:
					cout << "  ��  |"; // �� �� 2ĭ ����
					break;
				case 3:
					cout << " ���� |"; // �� �� 1ĭ ����
					break;
				case 4:
					cout << "������|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool checkXY(int mapX, int mapY, User& user) {
	bool checkFlag = false;
	if (user.GetUser_X() >= 0 && user.GetUser_X() < mapX && user.GetUser_Y() >= 0 && user.GetUser_Y() < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool checkGoal(int map[][mapX], User& user) {
	// ������ �����ϸ�
	if (map[user.GetUser_Y()][user.GetUser_X()] == 4) {
		return true;
	}
	return false;
}

// ����ڰ� ��ġ�� ����� ���¸� ����ϴ� �Լ�


// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
void checkState(int map[][mapX], User& user) {
	switch (map[user.GetUser_Y()][user.GetUser_X()]) {
	case 1:
		cout << "�������� �ֽ��ϴ�" << endl;
		break;
	case 2:
		cout << "���� �ֽ��ϴ�. ";
		user.doAttack();
		cout << endl;
		cout << "�׷��� ������ ������ �޾� HP�� 2 �پ��ϴ�." << endl;
		user.DecreaseHP(2);
		break;
	case 3:
		cout << "������ �ֽ��ϴ�. HP�� 2 �þ�ϴ�." << endl;
		user.IncreaseHP(2);
		break;
	}
}

// hp�� 0 �������� üũ�ϰ�, 0 ���϶�� false�� ��ȯ, �׷��� �ʴٸ� true�� ��ȯ
bool CheckUser(User& user) {
	if (user.GetHP() <= 0) return false;
	else return true;
}