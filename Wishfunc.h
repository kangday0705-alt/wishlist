#pragma once
#include <ctime>
#include <vector>
#include <sstream>
using namespace std;

class Date {
public:
  int year;
  int month;
  int day;
};

class Checklist {
private:
  
  bool isCheckAchieved = false;  // 체크리스트 달성

public:
  string check;
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

  string content() {
    stringstream con;
    con << name << ";"
      << Balance << ";"
      << date.year << ";"
      << date.month << ";"
      << date.day << ";"
      << isUnlocked << ";"
      << isCompleted << ";"
      << checklist.size() << ";";

    for (Checklist& c : checklist) {
      con << c.check << ";" << c.getisCheckAchieved() << ";";
    }

    return con.str();
  }

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
