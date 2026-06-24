#include <iostream>
#include <string>
#include "Wishlist.h"

using namespace std;

int main() {
  Wishlist manager;

  // [중요] 프로그램이 켜지자마자 저장된 파일 정보를 자동으로 불러옵니다!
  manager.loadFromFile();

  int choice = 0;

  while (true) {
    cout << "\n--- WISH LIST MANAGER ---" << endl;
    cout << "1. Show List" << endl;
    cout << "2. Add Wish" << endl;
    cout << "3. Save Money (Global)" << endl;
    cout << "4. Delete Wish" << endl;
    cout << "5. Manage Checklist (NEW!)" << endl;
    cout << "6. Exit" << endl;
    cout << "Select: ";
    cin >> choice;

    if (choice == 6) {
      // 종료하기 직전에도 안전하게 최종 저장을 수행합니다.
      manager.saveToFile();
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
      newWish.setBalance(balance, manager.getcurrBalance());

      manager.addwish(newWish);
      cout << ">> Added successfully!" << endl;

      // [추가] 위시가 새로 추가되었으므로 즉시 파일에 저장합니다.
      manager.saveToFile();
    }
    else if (choice == 3) {
      int money;
      cout << "Current Balance: " << manager.getcurrBalance() << "元" << endl;
      cout << "Money to Save: ";
      cin >> money;

      manager.addcurrBalance(money);
      cout << ">> Saved successfully! Total Balance: " << manager.getcurrBalance() << "元" << endl;

      // [추가] 잔액이 변동되었으므로 즉시 파일에 저장합니다.
      manager.saveToFile();
    }
    else if (choice == 4) {
      int idx;
      cout << "Wish Index to Delete: ";
      cin >> idx;

      manager.deletewish(idx);
      cout << ">> Deleted successfully!" << endl;

      // [추가] 위시가 삭제되었으므로 즉시 파일에 저장합니다.
      manager.saveToFile();
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

        // [추가] 체크리스트 변경사항 저장
        manager.saveToFile();
      }
      else if (subChoice == 2) {
        int chkIdx;
        cout << "Enter Checklist Index to Complete: ";
        cin >> chkIdx;
        target.completecheck(chkIdx, manager.getcurrBalance());
        cout << ">> Task completed!" << endl;

        // [추가] 체크리스트 완료 상태 변경사항 저장
        manager.saveToFile();
      }
    }
  }

  return 0;
}