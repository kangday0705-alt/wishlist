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
  string getcheck() const { return check;}
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
  

  vector<Checklist> checklist; // 체크리스트 목록
  Date date;                   // 목표날짜

  bool isUnlocked;           // 해금 여부
  bool isCompleted;          // 완료 여부

public:
  string name;          // 위시 이름

  Wish(string namee = " ")
    : name(namee),
    Balance(0),
    isUnlocked(false),
    isCompleted(false),
    date{ 0000, 00, 00 } { }

  void setBalance(int bal, int currBalance) {
    Balance = bal;
    TryUnlock(currBalance);
  }

  void setDate(Date dt, int currBalance) {
    date = dt;
    TryUnlock(currBalance);
  }
 
  bool getIsUnlocked()const {
    return isUnlocked; 
  }
  bool getIsCompleted() {
    return isCompleted;
  }

  vector<Checklist>& getchecklist() {
    return checklist;
  }
  void addchecklist(string);
  void completecheck(int idx, int);
  void TryUnlock(int currBalance);
};

class Wishlist {
private:
  vector<Wish> wlist;
  int currBalance;

public:
  Wishlist():currBalance(0){}

  int getcurrBalance() const { return currBalance; }
  void addcurrBalance(int bal) {
    currBalance += bal;
    updateAllwish();
  }
  void addwish(Wish newWish) {
    newWish.TryUnlock(currBalance);
    wlist.push_back(newWish);
  }
  void deletewish(int idx) {
    if (idx >= 0 && idx < wlist.size()) {
      wlist.erase(wlist.begin() + idx);
    }
    return;
  }
  void showwishlist() const;

  void updateAllwish() {
    for (Wish& w : wlist) {
      w.TryUnlock(currBalance);
    }
  }

  Wish& getwish(int idx) {
    if (0 <= idx && idx < wlist.size()) {
      return wlist[idx];
    }
  }
  vector<Wish> getlockedwish() const;
  vector<Wish> getunlockedwish() const;

  //void saveToFile();
  //void loadFromFile();

};

