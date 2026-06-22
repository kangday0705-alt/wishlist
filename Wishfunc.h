#pragma once
#include <ctime>
#include <vector>
using namespace std;

class Date {
public:
  int year;
  int month;
  int day;
};

class Checklist {
private:

  string check;
  bool isCheckAchieved = false;  // 체크리스트 달성

public:

  bool getisCheckAchieved() {
    return isCheckAchieved;
  }

  void setcheck(string checkk) {
    check = checkk;
  }

  void checkCheck() {
    isCheckAchieved = true;
  }

  void uncheckCheck() {
    isCheckAchieved = false;
  }

};

class Wish {
private:
  string name;          // 위시 이름
  int Balance;          //저축조건액
  int currBalance;

  vector<Checklist> checklist;

  Date date;           // 목표날짜

  int requiredCount;
  bool isUnlocked;           // 해금 여부
  bool isCompleted;          // 완료 여부

public:
  Wish(string namee = " ", int count = 0) {
    
    name = namee;
    requiredCount = count;
    Balance = 0;
    currBalance = 0;
    isUnlocked = false;
    isCompleted = false;
    date = { 9999, 12, 31 };
  }

  void setrequiredCount(int);
  void setBalance(int);
  void setcurrBalance(int);
  void setDate(Date);
  void addchecklist(string);
  void completecheck(int idx);
  bool getIsUnlocked() {
    return isUnlocked; 
  }
  void WishUnlock();
};

