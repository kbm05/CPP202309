#include "user.h"

User::User(int hp = 20) {
	this->hp = hp;
}
void User::SetUser_X(int x) {
	user_x = x;
}
void User::SetUSer_Y(int y) {
	user_y = y;
}
int User::GetUser_X() {
	return user_x;
}
int User::GetUser_Y() {
	return user_y;
}
void User::DecreaseHP(int dec_hp) {
	hp -= dec_hp;
}
void User::IncreaseHP(int inc_hp) {
	hp += inc_hp;
}
int User::GetHP() {
	return hp;
}
void User::doAttack() {
	cout << "공격합니다";
}