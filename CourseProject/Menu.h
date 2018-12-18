#pragma once
#include "borderInputNums.cpp"
#include "Transports.h"
//класс меню
class Menu {
	Transports transports;
	Transport transport;
	Station station;
	void outPutTransports(Transports transports);
	bool setTransport(Transports transports);
	void outPutStations();
	bool setStation();
	void outPutSchedule();
	void removeStation(Station station);
	void removeTransport(Transport transport);
	bool Transport_isExist(Transport transport);
	bool Station_isExist(Station station);
public:
	bool User();
	bool Admin();
	Menu() { transports.initFromFile(); }
	~Menu() {}
};