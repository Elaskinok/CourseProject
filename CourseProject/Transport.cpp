#include "Transport.h"
void Transport::addStation(Station station) {
	stations.insert(station);
	countOfStations++;
}
//запись остановки
void Transport::foow(const char* str) {
	ofstream fout;
	CreateDirectory(str, 0);
	CreateDirectory(string(str + string("\\") + nameOFTransport).c_str(), 0);
	fout.open(string(str + string("\\") + nameOFTransport + "\\" + nameOFTransport + ".txt").c_str());
	for (auto it = stations.begin(); it != stations.end(); ++it) {
		fout << (*it).nameOfStation << "\n";
		ofstream temp;
		temp.open(string(str + string("\\") + nameOFTransport + "\\" + nameOFTransport + "_" + (*it).nameOfStation + ".txt").c_str());
		it->schedule.writeToFile(temp);
		ofstream temp1;
		temp1.open(string(str + string("\\") + nameOFTransport + "\\" + "_" + nameOFTransport + "_" + (*it).nameOfStation + ".txt").c_str());
		it->schedule.RwriteToFile(temp1);
		temp.close();
		temp1.close();
	}
	fout.close();
}

//чтение остановки
void Transport::foor(const char* str) {
	ifstream fin;
	fin.open(string(str + string("\\") + nameOFTransport + "\\" + nameOFTransport + ".txt").c_str());
	for (auto i = 0; i < countOfStations; ++i) {
		char buff[80];
		fin.getline(buff, 79);
		string tmpStr = string(buff);
		ifstream temp;
		temp.open(string(str + string("\\") + nameOFTransport + "\\" + nameOFTransport + "_" + tmpStr + ".txt").c_str());
		Station tempStation;
		tempStation.nameOfStation = tmpStr;
		tempStation.schedule.readFromFile(temp);
		ifstream temp1;
		temp1.open(string(str + string("\\") + nameOFTransport + "\\" + "_" + nameOFTransport + "_" + tmpStr + ".txt").c_str());
		tempStation.schedule.RreadFromFile(temp1);
		stations.insert(tempStation);
		temp.close();
		temp1.close();
	}
	fin.close();
}

//добавление информации об остановке и запись
void Transport::writeToFile(ofstream& fout) {
	fout << this->nameOfRoute << ' ' << typeOfTransport << ' ' << this->nameOFTransport << ' ' << countOfStations;
	switch (typeOfTransport) {
	case Bus:
		foow("Bus");
		break;
	case Trolley:
		foow("Trolley");
		break;
	case Tram:
		foow("Tram");
		break;
	case Metro:
		foow("Metro");
		break;
	}
}

//чтение информации об остановке и запись
void Transport::readFromFile(ifstream& fin) {
	fin >> this->nameOfRoute;
	int num = 0; fin >> num; typeOfTransport = TYPE_Transports(num);
	fin >> this->nameOFTransport >> this->countOfStations;
	switch (typeOfTransport) {
	case Bus:
		foor("Bus");
		break;
	case Trolley:
		foor("Trolley");
		break;
	case Tram:
		foor("Tram");
		break;
	case Metro:
		foor("Metro");
		break;
	}
}