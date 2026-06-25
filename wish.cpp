#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include "Wishfunc.h"
using namespace std;


void Wish::completeCheck(int idx, bool achieve, int currBalance) {
	if (0 <=idx && idx < checklist.size()) {
		checklist[idx].setisCheckAchieved(achieve);
		tryUnlock(currBalance);
	}
}

void Wish::tryUnlock(int currBalance) {

	//저축액
	if (Balance == 0 && checklist.empty() && date.year == 0000) {
		isUnlocked = false;
		return;
	}
	if (currBalance < Balance) {
		isUnlocked = false; return;
	}

	//체크리스트
	if (!checklist.empty()) {
		for (int i = 0; i < checklist.size(); i++) {
			if (!checklist[i].getisCheckAchieved()) {
				isUnlocked = false; return;
			}
		}
	}

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

