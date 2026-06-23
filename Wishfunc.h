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
 
  int Balance;          //저축조건액
  int currBalance;

  vector<Checklist> checklist; // 체크리스트 목록
  Date date;                   // 목표날짜
  int requiredCount;
  bool isUnlocked;           // 해금 여부
  bool isCompleted;          // 완료 여부

public:
  string name;          // 위시 이름

  Wish(string namee = " ", int count = 0)
    : name(namee),
    requiredCount(count),
    Balance(0),
    currBalance(0),
    isUnlocked(false),
    isCompleted(false),
    date{ 9999, 12, 31 } {
    WishUnlock();
  }
  void setBalance(int bal) {
    Balance = bal;
    WishUnlock();
  }
  void setcurrBalance(int bal) {
    currBalance = bal;
    WishUnlock();
  }
  void setDate(Date dt) {
    date = dt;
    WishUnlock();
  }
  void setrequiredCount(int c) {
    requiredCount = c;
    WishUnlock();
  }
  bool getIsUnlocked()const {
    return isUnlocked; 
  }
  bool getIsCompleted() {
    return isCompleted;
  }
  //string getname() {
  //  return name;
  //}

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
  void showwishlist() const;

  Wish& getwish(int idx) {
    return wlist[idx];
  }
  vector<Wish> getlockedwish() const;
  vector<Wish> getunlockedwish() const;

  //void saveToFile();
  //void loadFromFile();

};

