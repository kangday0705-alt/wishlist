#include <iostream>
#include <string>
#include "Wishlist.h"

using namespace std;

int main() {
  Wishlist manager;
  int choice = 0;

  while (true) {
    cout << "\n--- WISH LIST MANAGER ---" << endl;
    cout << "1. Show List" << endl;
    cout << "2. Add Wish" << endl;
    cout << "3. Save Money (Global)" << endl; // 전체 공통 저축으로 변경
    cout << "4. Delete Wish" << endl;
    cout << "5. Manage Checklist (NEW!)" << endl;
    cout << "6. Exit" << endl;
    cout << "Select: ";
    cin >> choice;

    if (choice == 6) {
      cout << "Exit Program. Bye!" << endl;
      break;
    }

    if (choice == 1) {
      cout << "\n[ My Wish List ]" << endl;
      manager.showwishlist();
    }
    else if (choice == 2) {
      string name;
      int balance;

      cout << "Wish Name: ";
      cin >> name;
      cout << "Target Balance: ";
      cin >> balance;

      Wish newWish(name);
      // 생성 및 추가 시 현재 매니저의 공통 잔액을 함께 전달합니다.
      newWish.setBalance(balance, manager.getcurrBalance());

      manager.addwish(newWish);
      cout << ">> Added successfully!" << endl;
    }
    else if (choice == 3) {
      int money;
      // 특정 위시의 인덱스를 받지 않고, 전체 지갑에 저축하도록 변경
      cout << "Current Total Balance: " << manager.getcurrBalance() << "元" << endl;
      cout << "Money to Save: ";
      cin >> money;

      // 매니저의 전체 공통 잔액을 갱신 (내부에서 전체 위시 해금 상태 자동 업데이트)
      manager.addcurrBalance(money);

      cout << ">> Saved successfully! Total Balance: " << manager.getcurrBalance() << "元" << endl;
    }
    else if (choice == 4) {
      int idx;
      cout << "Wish Index to Delete: ";
      cin >> idx;

      manager.deletewish(idx);
      cout << ">> Deleted successfully!" << endl;
    }
    else if (choice == 5) {
      int idx, subChoice;
      cout << "Select Wish Index: ";
      cin >> idx;

      Wish& target = manager.getwish(idx);

      cout << "\n[ " << target.name << " - Checklist Menu ]" << endl;
      cout << "1. Add Checklist Item" << endl;
      cout << "2. Complete Checklist Item" << endl;
      cout << "Select Sub Menu: ";
      cin >> subChoice;

      if (subChoice == 1) {
        string task;
        cout << "Enter Task Name: ";
        cin >> task;
        target.addchecklist(task);
        cout << ">> Task added!" << endl;
      }
      else if (subChoice == 2) {
        int taskIdx;
        cout << "Enter Task Index to Complete: ";
        cin >> taskIdx;

        // 체크리스트를 완료할 때도 현재 공통 잔액을 함께 넘겨주어 해금 판정을 유도합니다.
        target.completecheck(taskIdx, manager.getcurrBalance());
        cout << ">> Task completed!" << endl;
      }
    }
    else {
      cout << ">> Invalid choice. Try again." << endl;
    }
  }

  return 0;
}