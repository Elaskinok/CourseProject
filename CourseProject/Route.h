#pragma once
#include "Stations.h"
//����� �������
class Route : public Stations {
protected:
	string nameOfRoute;
	size_t countOfStations;
public:
	Route() : nameOfRoute(""), countOfStations(0) {}
	~Route() {}
	friend class Menu;
};