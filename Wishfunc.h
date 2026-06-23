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

  vector<Checklist> checklist; // 체크리스트 목록
  Date date;                   // 목표날짜
  int requiredCount;
  bool isUnlocked;           // 해금 여부
  bool isCompleted;          // 완료 여부

public:
  Wish(string namee = " ", int count = 0)
    : name(namee),
    requiredCount(count),
    Balance(0),
    currBalance(0),
    isUnlocked(false),
    isCompleted(false),
    date{ 9999, 12, 31 } {

  }
  void setBalance(int bal) {
    Balance = bal;
  }
  void setcurrBalance(int bal) {
    currBalance = bal;
  }
  void setDate(Date dt) {
    date = dt;
  }
  void setrequiredCount(int c) {
    requiredCount = c;
  }
  bool getIsUnlocked() {
    return isUnlocked; 
  }
  bool getIsCompleted() {
    return isCompleted;
  }

  void addchecklist(string);
  void completecheck(int idx);
  void WishUnlock();
};

class Wishlist {
private:
  vector<Wish> wlist;

public:
  Wishlist() {}

  void addwish(const Wish& newWish) {
    wlist.push_back(newWish);
  }
  void deletewish(int idx) {
    if (idx >= 0 && idx < wlist.size()) {
      wlist.erase(wlist.begin() + idx);
    }
    return;
  }
  //void showwishlist() const;

  vector<Wish> getlockedwish() const;
  vector<Wish> getunlockedwish() const;

};

