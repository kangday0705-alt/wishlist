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

  int getcurrBalance() const {
    return currBalance;
  }
  void addcurrBalance(int bal) {
    currBalance += bal;
    updateAllwish();
  }
  void addwish(Wish newWish) {
    newWish.tryUnlock(currBalance);
    wlist.push_back(newWish);
  }
  void deletewish(int idx) {
    if (idx >= 0 && idx < wlist.size()) {
      wlist.erase(wlist.begin() + idx);
    }
    return;
  }
  
  void updateAllwish() {
    for (Wish& w : wlist) {
      w.tryUnlock(currBalance);
    }
  }

  Wish& getwish(int idx) {
    return wlist.at(idx);
  }

  void saveToFile();
  void loadFromFile();
  //юс╫ц
  void showwishlist() const;
};

