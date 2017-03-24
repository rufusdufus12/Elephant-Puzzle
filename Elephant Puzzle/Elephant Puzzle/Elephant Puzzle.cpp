// Elephant Puzzle.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <vector>

using namespace std;

int c = 1;
// have the elephant turn
vector<char> turn(vector<char> a, int tPos) {
	if (a[tPos] == 'h') {
		a[tPos] = 'v';
	}
	else if (a[tPos] == 'v') {
		a[tPos] = 'h';
	}

	cout << c++ << ". Turn." << endl;
	return a;
}

// slides everything all the way to the right
vector<char> slideRight(vector<char> a, int tPos) {
	vector<char>::iterator it = a.begin();
	if (a[tPos + 1] != 'v') {
		cout << c++ << ". Slide right." << endl;
		a.insert(it, ' ');
		return slideRight(a, tPos);
	}
	else {
		a = turn(a, tPos);
		return a;
	}
}

// slides everything all the way to the left
vector<char> slideLeft(vector<char> a, int tPos) {
	vector<char>::iterator it = a.begin();
	if (a[0] == ' ') {
		cout << c++ << ". Slide left." << endl;
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

	cout << "All steps are single changes." << endl;

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
	/*for (int i(0); i < elephants.size(); i++) {
		cout << elephants[i];
	}
	cout << endl;*/

	return 0;
}