// Elephant Puzzle.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"


using namespace std;
void move(int num) {
	if (num == 1) {
		cout << "Turn." << endl;
	}
	else if (num % 2 == 0) {
		cout << "Slide right." << endl << "Turn." << endl;
		move(num - 1);
	}
	else if (num % 2 == 1) {
		cout << "Slide left." << endl << "Turn." << endl;
		move(num - 1);
	}
}

void slideRight(char *a, int ele) {
	char *tmp = new char [sizeof(a)];
	tmp[0] = NULL;
	for (int i(1); i <= sizeof(a); i++) {
		tmp[i] = a[i - 1];
	}
	a = tmp;

	for (int i(0); i < sizeof(a); i++) {
		cout << a[i];
	}
	cout << endl;
	//return ;
}

void slideLeft(char *a, int ele) {
	char *tmp = new char[sizeof(a)];
	for (int i(0); i < sizeof(tmp); i++) {			// safe because there's extra space in the array
		tmp[i] = a[i + 1];
	}
	a = tmp;
	for (int i(0); i < sizeof(a); i++) {
		cout << a[i];
	}
	cout << endl;
}

int main() {
	int ele;

	cout << "How many elephants are there?" << endl;
	cin >> ele;

	while (ele < 1) {
		cout << "There have to be a positive number of elephants!\nHow many elephants are there?" << endl;
		cin >> ele;
	}

	char *elephants = new char [ele * 2];
	int t = ele;
	int s = ele + 1;

	for (int i(0); i < ele; i++) {
		elephants[i] = 'v';
	}
	for (int i(ele); i < sizeof(elephants); i++) {
		elephants[i] = NULL;
	}

	cout << elephants << endl;
	slideRight(elephants, ele);
	slideLeft(elephants, ele);

	return 0;
}