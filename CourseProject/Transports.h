#pragma once
#include "Transport.h"
//класс всего транспорта
class Transports {
	list<Transport> transports;
public:
	void initFromFile() {
		ifstream file(FILENAME_List_of_routes);
		if (!file.is_open()) return;
		while (!file.eof()) {
			Transport temp;
			temp.readFromFile(file);
			transports.push_back(temp);
			if (file.eof()) break;
		}
		file.close();
	}
	void writeToFile() {
		ofstream file(FILENAME_List_of_routes);
		for (auto it = transports.begin(); it != transports.end(); ++it) {
			it->writeToFile(file);
			list<Transport>::iterator temp = it;
			if (++temp == transports.end()) break;
			file << endl;
		}
		file.close();
	}
	Transports() {}
	~Transports() {}
	friend class Menu;
};