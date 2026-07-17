#pragma once
#include "Wish.h"
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
    tryUnlockAllwish();
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
  
  void tryUnlockAllwish() {
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
  void buyWish(int idx) {
    wlist[idx].buyWish();
  }
};

