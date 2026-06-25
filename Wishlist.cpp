#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Wishlist.h"
using namespace std;

//임시
void Wishlist::showwishlist() const {
	for (int i = 0; i < wlist.size(); ++i) {
		cout << i << ". " << wlist[i].name
			<< (wlist[i].getIsUnlocked() ? " 해금" : " 잠금") << endl;
	}
}

void Wishlist::saveToFile() {
	ofstream outFile("wishlist.txt");
	if (!outFile.is_open()) {
		return;
	}
	outFile << currBalance << endl;

	for (Wish& wish : wlist) {
		outFile << wish.content() << endl;
	}
	outFile.close();
}

void Wishlist::loadFromFile() {
	ifstream inFile("wishlist.txt");

	if (!inFile.is_open()) {
		return;
	}
	wlist.clear();

	inFile >> currBalance;
	inFile.ignore();

	string line;
	while (getline(inFile, line)) {
		stringstream con(line);
		Wish twish;
		twish.getcont(con);
		wlist.push_back(twish);
	}
	updateAllwish();
}