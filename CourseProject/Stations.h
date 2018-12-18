#pragma once
#include <Windows.h>
#include <list>
#include "Station.h"
#include "Tree.cpp"
#include "Iterator.cpp"

//класс остановок
class Stations {
protected:
	Tree<Station> stations;
public:
	Station findStation(string name) {
		treeNode<Station>* temp = stations.find(Station(name));
		if(!temp) return *stations.end();
		else return temp->getData();
	}
	Stations() {}
	~Stations() {}
	friend class Menu;
};