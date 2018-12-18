#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
//класс расписание
using namespace std;
class Schedule {
protected: 
	multimap<size_t, size_t> times; //прямое расписание
	multimap<size_t, size_t> rtimes; //обратное расписание
public:
	void RwriteToFile(ofstream& fout);
	void RreadFromFile(ifstream& fin);
	void writeToFile(ofstream& fout);
	void readFromFile(ifstream& fin);
	void addTime();
	void outPutTimes();
	Schedule() {}
	~Schedule() {}
	friend class Menu;
};