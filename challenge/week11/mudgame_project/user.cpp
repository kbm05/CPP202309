#include "user.h"

User::User(int hp = 20) {
	this->hp = hp;
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