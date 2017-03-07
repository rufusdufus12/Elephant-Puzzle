// Elephant Puzzle.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <vector>
#include "stdafx.h"


using namespace std;
/*void move(int num) {
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
}*/

/*int slid = 5;
vector<char> turn(int pos, vector<char> a) {
	cout << "Turn" << endl;
	if (a[pos] == 'v') {
		a[pos] = 'h';
	}
	else if (a[pos] == 'h')
	{
		a[pos] = 'v';
	}
	return a;
}

vector<char> slide(int slidePos, int pos, vector<char> a) {
	cout << "slide" << endl;
	//int slid = 5;
	if (slid == slidePos) {
		a = turn(pos, a);
	}
	else
	{
		if (slid < slidePos) slid = (slid + 5 < slidePos) ? slid + 5 : slidePos;
		else slid = (slid - 5 < slidePos) ? slid - 5 : slidePos;
		///some missing stuff here
		a = slide(slidePos, pos, a);
	}

	return a;
}

vector<char> move(int pos, vector<char> a) {
	cout << "move" << endl;
	if (pos == 0) {
		a = slide(5+32*pos, pos, a);
	}
	else if (a[pos - 1] == 'h') {
		a = move(pos - 1, a);
	}
	else
	{
		int i;
		for (i = pos - 2; i >= 0 && a[i] == 'h'; i--);
		if (i >= 0) {
			a = move(i, a);
		}
		else a = slide(5+32*pos, pos, a);
	}
	return a;
}*/

vector<char> turn(vector<char> a, int tPos) {
	if (a[tPos] == 'h') {
		a[tPos] = 'v';
	}
	else if (a[tPos] == 'v') {
		a[tPos] = 'h';
	}

	cout << "Turn." << endl;
	return a;
}

vector<char> slideRight(vector<char> a, int tPos) {
	vector<char>::iterator it = a.begin();
	if (a[tPos + 1] != 'v') {
		cout << "Slide right." << endl;
		a.insert(it, ' ');
		return slideRight(a, tPos);
	}
	else if (a[tPos+1] == 'v') {
		a = turn(a, tPos);
		return a;
	}
}

vector<char> slideLeft(vector<char> a, int tPos) {
	vector<char>::iterator it = a.begin();
	if (a[0] == ' ') {
		cout << "Slide left." << endl;
		a.erase(it);
		return slideLeft(a, tPos);
	}
	else {
		a = turn(a, tPos);
		return a;
	}
}

vector<char> move(vector<char> a, int tPos, vector<char> correct) {	
	if (a == correct) {
		cout << "The elephants are all lined up!" << endl;
		return a;
	}
	else if (a[0] != ' ') {
		a = slideRight(a, tPos);
		return move(a, tPos, correct);
	}
	else {
		a = slideLeft(a, tPos);
		return move(a, tPos, correct);
	}
}

int main() {
	int ele;

	cout << "How many elephants are there?" << endl;
	cin >> ele;

	while (ele < 1) {
		cout << "There have to be a positive number of elephants!\nHow many elephants are there?" << endl;
		cin >> ele;
	}

	vector<char> elephants, correct;
	int tPos = ele - 1;

	// build feeding area for the elephants
	for (int i(0); i < ele; i++) {
		elephants.push_back('v');
		correct.push_back('h');
	}
	elephants.push_back(' ');
	correct.push_back(' ');

	if (ele % 2 == 1) {
		elephants = turn(elephants, tPos);
	}
	
	elephants = move(elephants, tPos, correct);

	// let's see the pretty elephants
	for (int i(0); i < elephants.size(); i++) {
		cout << elephants[i];
	}
	cout << endl;

	return 0;
}