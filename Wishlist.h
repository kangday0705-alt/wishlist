#pragma once
#include <ctime>
#include "Wishfunc.h"
using namespace std;

class Wishlist {
private:
  vector<Wish> wlist;
  int currBalance;

public:
  Wishlist() :currBalance(0) {}

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

  void saveToFile();
  void loadFromFile();

};

