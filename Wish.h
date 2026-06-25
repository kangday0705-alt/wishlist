#pragma once
#include <ctime>
#include <vector>
#include <sstream>
#include <string>
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
  void setisCheckAchieved(bool b) {
    isCheckAchieved = b;
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
  string name;

  //이름으로 생성. 해금x완료x
  Wish(string namee = " ")
    : name(namee),
    Balance(0),
    isUnlocked(false),
    isCompleted(false),
    date{ 0000, 00, 00 } { }

  void setBalance(int bal, int currBalance) {
      Balance = bal;
      tryUnlock(currBalance);
    }
  void setDate(Date dt, int currBalance) {
    date = dt;
    tryUnlock(currBalance);
  }

  bool getIsUnlocked()const {
    return isUnlocked; 
  }
  bool getIsCompleted()const {
    return isCompleted;
  }
  vector<Checklist>& getchecklist() {
    return checklist;
  }

  void addchecklist(string cont){
    Checklist temp;
    temp.check = cont;
    checklist.push_back(temp);
  }
  void completeCheck(int idx, bool, int);
  void tryUnlock(int currBalance);


  //위시의 전체 정보가 담긴 문자열
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
  //위시의 전체정보 문자열 읽기
  void getcont(stringstream& con) {
    string temp;
    getline(con, name, ';');
    getline(con, temp, ';'); Balance = stoi(temp);
    getline(con, temp, ';'); date.year = stoi(temp);
    getline(con, temp, ';'); date.month = stoi(temp);
    getline(con, temp, ';'); date.day = stoi(temp);
    getline(con, temp, ';'); isUnlocked = stoi(temp);
    getline(con, temp, ';'); isCompleted = stoi(temp);
    getline(con, temp, ';');
    int size = stoi(temp);

    checklist.clear();
    for (int i = 0; i < size; i++) {
      Checklist c;
      getline(con, c.check, ';'); //이름읽기
      getline(con, temp, ';'); //isAchived
      c.setisCheckAchieved(stoi(temp));
      checklist.push_back(c);
    }
  }

  void buyWish() {
    if (isUnlocked) {
      isCompleted = true;
    }
  }

};
