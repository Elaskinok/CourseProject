#pragma once
#include "Route.h"
//���� ����������
enum TYPE_Transports { Bus, Trolley, Tram, Metro }; 
//�������� ����� � ����������
#define FILENAME_List_of_routes "list_of_routes.txt"
//����� ���������
class Transport : public Route {
protected:
	TYPE_Transports typeOfTransport;
	string nameOFTransport;
public:
	void addStation(Station station);
	void foow(const char* str);
	void foor(const char* str);
	void writeToFile(ofstream& fout);
	void readFromFile(ifstream& fin);
	bool operator==(const Transport& obj) {
		if (nameOfRoute == obj.nameOfRoute && nameOFTransport == obj.nameOFTransport && typeOfTransport == obj.typeOfTransport)
			return true;
		return false;
	}
	bool operator>(const Transport& obj) {
		if (typeOfTransport > obj.typeOfTransport) return true;
		false;
	}
	Transport() : nameOFTransport(""), typeOfTransport(Bus) {}
	~Transport() {}
	friend class Menu;
};