#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {
private:
	int hp;
	int user_x;  // 가로 번호
	int user_y;  // 세로 번호
public:
	User(int hp);
	void SetUser_X(int x);
	void SetUSer_Y(int y);
	int GetUser_X();
	int GetUser_Y();
	void DecreaseHP(int dec_hp);
	void IncreaseHP(int inc_hp);
	int GetHP();
	virtual void doAttack();
};