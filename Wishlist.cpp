#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include "Wishlist.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;


//임시
void Wishlist::showwishlist() const {

	for (int i = 0; i < wlist.size(); ++i) {
		if (!wlist[i].getIsCompleted()) {
			cout << i << ". " << wlist[i].name
				<< (wlist[i].getIsUnlocked() ? " 해금" : " 잠금") << endl;
		}
	}
	cout << endl << "--- 완료한 위시! ---" << endl;
	for (int i = 0; i < wlist.size(); ++i) {
		if (wlist[i].getIsCompleted()) {
			cout << i << ". " << wlist[i].name;
		}
	}
}

void Wishlist::saveToFile() {

	ofstream outFile("wishlist.json");
	if (!outFile.is_open()) {
		return;
	}
	json all;

	all["currbalance"] = currBalance;
	all["wishlist"] = json::array();

	for (Wish& wish : wlist) {
		all["wishlist"].push_back(wish.tojson());
	}
	outFile << all;
	outFile.close();
}

void Wishlist::loadFromFile() {
	ifstream inFile("wishlist.json");

	if (!inFile.is_open()) {
		return;
	}
	wlist.clear();

	json all;
	inFile >> all;

	currBalance = all["currbalance"];

	for (const json& item : all["wishlist"]) {
		Wish w;
		w.fromjson(item);
		wlist.push_back(w);
	}
	tryUnlockAllwish();
}
