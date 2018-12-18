#pragma once
#include "Schedule.h"
using namespace std;
//класс остановка
class Station {
	string nameOfStation;
	Schedule schedule;
public:
	string getNameOfStation() { return nameOfStation; }
	Station() {}
	Station(const string& name) { nameOfStation = name; }
	~Station() {}
	bool operator==(const Station& obj) { return nameOfStation == obj.nameOfStation ? true : false; }
	bool operator<(const Station& obj) { return nameOfStation < obj.nameOfStation ? true : false; }
	bool operator>(const Station& obj) { return nameOfStation > obj.nameOfStation ? true : false; }
	friend class Transport;
	friend class Menu;
};