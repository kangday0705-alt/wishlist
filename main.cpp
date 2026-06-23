#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include "Wishfunc.h"
using namespace std;


void Wish::addchecklist(string cont) {
	Checklist temp;
	temp.setcheck(cont);
	checklist.push_back(temp);
}

void Wish::completecheck(int idx) {
	if (idx < checklist.size()) {
		checklist[idx].checkCheck();
	}
	WishUnlock();
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

vector<Wish> Wishlist::getlockedwish() const {
	vector<Wish> locked;
	for (Wish att : wlist) {
		if (!att.getIsUnlocked()) {
			locked.push_back(att);
		}
	}
	return locked;
}

vector<Wish> Wishlist::getunlockedwish() const {
	vector<Wish> unlocked;
	for (Wish att : wlist) {
		if (att.getIsUnlocked()) {
			unlocked.push_back(att);
		}
	}
	return unlocked;
}

void Wishlist::showwishlist() const {
	for (int i = 0; i < wlist.size(); ++i) {
		cout << i << ". " << wlist[i].name
			<< " " << (wlist[i].getIsUnlocked() ? "해금" : "잠금") << endl;

	}
}



int main() {
	Wishlist manager;

	cout << " 테스트" << endl;

	Wish wish1("스위치", 2);
	wish1.setBalance(1000000); 

	Wish wish2("플스", 0); 
	wish2.setBalance(600000);

	manager.addwish(wish1);
	manager.addwish(wish2);

	manager.showwishlist();
	cout << endl;

	// 0번 원본 꺼내기
	Wish& myPad = manager.getwish(0);
	myPad.setcurrBalance(1000000);
	cout << " 스위치저축완료" << endl;

	myPad.addchecklist("체크");
	myPad.completecheck(0);
	cout << " 스위치체크리스트완료" << endl;
	cout << endl;

	manager.showwishlist();
	cout << "\n";

	
	vector<Wish> lockedList = manager.getlockedwish();
	vector<Wish> unlockedList = manager.getunlockedwish();

	cout << "잠긴 위시: " << lockedList.size()<< endl;
	cout << "해금 위시: " << unlockedList.size() << endl;
	cout << "\n";


	cout << "플스 삭제" << endl;
	manager.deletewish(1);
	manager.showwishlist();
	cout << "\n\n";

	return 0;
}