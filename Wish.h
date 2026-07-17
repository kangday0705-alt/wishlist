#pragma once
#include <vector>
#include <string>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class Date {
public:
  int year;
  int month;
  int day;
};

class Checklist {
private:
  bool isCheckAchieved = false;

public:
  string check;
  bool getisCheckAchieved() {
    return isCheckAchieved;
  }
  void setisCheckAchieved(bool b) {
    isCheckAchieved = b;
  }
  json tojson() {
    json j;
    j["check"] = check;
    j["ischeck"] = isCheckAchieved;
    return j;
  }
};

class Wish {
private:
  int Balance;
  vector<Checklist> checklist;
  Date date;
  bool isUnlocked;
  bool isCompleted;

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
  vector<Checklist>& getChecklist() {
    return checklist;
  }

  void addChecklist(string cont){
    Checklist temp;
    temp.check = cont;
    checklist.push_back(temp);
  }
  void achieveChecklist(int idx, bool, int);
  void tryUnlock(int currBalance);

  json tojson() {
    json j;

    j["name"] = name;
    j["balance"] = Balance;
    j["year"] = date.year;
    j["month"] = date.month;
    j["day"] = date.day;
    j["isunlocked"] = isUnlocked;
    j["iscompleted"] = isCompleted;

    json arr=json::array();

    for (Checklist c : checklist) {
      arr.push_back(c.tojson());
    }
    j["checklist"] = arr;

    return j;
  }

  void fromjson(json j) {
    name = j["name"];
    Balance = j["balance"];
    date.year = j["year"];
    date.month = j["month"];
    date.day = j["day"];
    isUnlocked = j["isunlocked"];
    isCompleted = j["iscompleted"];

    checklist.clear();

    for (json i : j["checklist"]) {
      Checklist c;
      c.check = i["check"];
      c.setisCheckAchieved(i["ischeck"]);
      checklist.push_back(c);
    }
  }

  void buyWish() {
    if (isUnlocked) {
      isCompleted = true;
    }
  }

};
