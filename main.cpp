#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <ctime>
#include "Wishfunc.h"

using namespace std;

void Wish::setrequiredCount(int c) {
	requiredCount = c;
}

void Wish::setBalance(int bal) {
	Balance = bal;
}

void Wish::setcurrBalance(int bal) {
	currBalance = bal;
}

void Wish::setDate(Date dt) {
	date = dt;
}

void Wish::addchecklist(string cont) {
	Checklist temp;
	temp.setcheck(cont);
	checklist.push_back(temp);
}

void Wish::completecheck(int idx) {
	if (idx < checklist.size()) {
		checklist[idx].checkCheck();
	}
}

void Wish::WishUnlock() {

	int count = 0; //만족하는조건갯수

	//저축액
	if (Balance > 0 && currBalance >= Balance) {
		count++;
	}

	//체크리스트
	bool allcom = true;
	for (int i = 0; i < checklist.size(); i++) {
		if (!checklist[i].getisCheckAchieved()) {
			allcom = false;
			break;
		}
	}
	if (!checklist.empty() && allcom == true)count++;

	//날짜
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);
	int todayYear = t->tm_year + 1900;
	int todayMonth = t->tm_mon + 1;    
	int todayDay = t->tm_mday;

	if (todayYear > date.year) {
		count++;
	}
	else if (todayYear == date.year) {
		if (todayMonth > date.month) {
			count++;
		}
		else if (todayMonth==date.month) {
			if(todayDay>=date.day){
				count++;
			}
		}
	}

	if (count >= requiredCount) {
		isUnlocked = true;
	}
	else isUnlocked = false;
}

int main() {


	Wish myWish("아이패드", 1);


	myWish.setBalance(1000000);

	myWish.setcurrBalance(0);
	myWish.WishUnlock();

	cout << "저축액설정 " << myWish.getIsUnlocked() << endl;

	myWish.setcurrBalance(1500000);
	myWish.WishUnlock(); 

	cout << "저축액달성 " << myWish.getIsUnlocked() << endl;

	myWish.addchecklist("1");

	myWish.setrequiredCount(2);

	myWish.WishUnlock();
	cout << "쳌리설정" << myWish.getIsUnlocked() << endl;

	myWish.completecheck(0);
	myWish.WishUnlock();
	cout << "쳌리체크" << myWish.getIsUnlocked() << endl;

	myWish.setrequiredCount(3);
	Date dt = { 2026,6,25 };
	myWish.setDate(dt);

	myWish.WishUnlock();
	cout << "날짜미래" << myWish.getIsUnlocked() << endl;

	dt = { 2026,6,23 };
	myWish.setDate(dt);

	myWish.WishUnlock();
	cout << "날짜오늘" << myWish.getIsUnlocked() << endl;

	return 0;

}