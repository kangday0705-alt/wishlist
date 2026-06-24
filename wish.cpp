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

void Wish::completecheck(int idx, int currBalance) {
	if (0 <=idx && idx < checklist.size()) {
		checklist[idx].checkCheck();
	}
	TryUnlock(currBalance);
}

void Wish::TryUnlock(int currBalance) {

	int count = 0; //만족하는조건갯수

	//저축액
	if (Balance == 0 && checklist.empty() && date.year == 0000) {
		isUnlocked = false;
		return;
	}

	if (currBalance < Balance) {
		isUnlocked = false; return;
	}

	//체크리스트
	//bool allcom = true;
	if (!checklist.empty()) {
		for (int i = 0; i < checklist.size(); i++) {
			if (!checklist[i].getisCheckAchieved()) {
				isUnlocked = false; return;
			}
		}
	}
	//if (!checklist.empty() && allcom == true)count++;

	//날짜
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);
	int todayYear = t->tm_year + 1900;
	int todayMonth = t->tm_mon + 1;
	int todayDay = t->tm_mday;


	if (todayYear < date.year) {
		isUnlocked = false; return;
	}
	else if (todayYear == date.year) {
		if (todayMonth < date.month) {
			isUnlocked = false; return;
		}
		else if (todayMonth == date.month) {
			if (todayDay < date.day) {
				isUnlocked = false; return;
			}
		}
	}

	isUnlocked = true;
	//임시
	if (isUnlocked == true) { cout << name << " 해금!" <<endl; }
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