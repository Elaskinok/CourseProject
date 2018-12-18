#include "Schedule.h"
#include "borderInputNums.cpp"

void Schedule::RwriteToFile(ofstream& fout) {
	for (auto it = rtimes.begin(); it != rtimes.end(); ++it) {
		fout << it->first << " " << it->second << endl;
	}
}

void Schedule::RreadFromFile(ifstream& fin) {
	while (!fin.eof()) {
		size_t str1, str2;
		fin >> str1;
		if (fin.eof()) break;
		fin >> str2;
		rtimes.insert(pair<size_t, size_t>(str1, str2));
	}
}

void Schedule::writeToFile(ofstream& fout) {
	for (auto it = times.begin(); it != times.end(); ++it) {
		fout << it->first << " " << it->second << endl;
	}
}

void Schedule::readFromFile(ifstream& fin) {
	while (!fin.eof()) {
		size_t str1, str2;
		fin >> str1;
		if (fin.eof()) break;
		fin >> str2;
		times.insert(pair<size_t, size_t>(str1, str2));
	}
}

//ввод пр€мого и обратного расписани€ на остановке
void Schedule::addTime() {
	size_t hour = borderInputNums(cin, "Right Schedule:\nHour: ", size_t(0), size_t(23));
	size_t minute = borderInputNums(cin, "Right Schedule:\nMinute: ", size_t(0), size_t(59));
	times.insert(pair<size_t, size_t>(hour, minute));
	size_t rhour = borderInputNums(cin, "Reverse Schedule:\nHour: ", size_t(0), size_t(23));
	size_t rminute = borderInputNums(cin, "Reverse Schedule:\nMinute: ", size_t(0), size_t(59));
	rtimes.insert(pair<size_t, size_t>(rhour, rminute));
}

void Schedule::outPutTimes() {
	cout << "Right Schedule:\n";
	for (auto it = times.begin(); it != times.end(); ++it) {
		cout << it->first << ":" << it->second << endl;
	}
	cout << "\nReverse Schedule:\n";
	for (auto it = rtimes.begin(); it != rtimes.end(); ++it) {
		cout << it->first << ":" << it->second << endl;
	}
}