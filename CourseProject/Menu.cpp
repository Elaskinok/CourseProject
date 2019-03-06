#include <stack>
#include "Menu.h"
#include <algorithm>

//проверка транспорта на наличие
bool Menu::Transport_isExist(Transport transport) {
	for (auto it = transports.transports.begin(); it != transports.transports.end(); ++it) {
		if (*it == transport) return true;
	}
	return false;
}

//проверка остановки на наличие
bool Menu::Station_isExist(Station station) {
	for (auto it = transport.stations.begin(); it != transport.stations.end(); ++it) {
		if (*it == station) return true;
	}
	return false;
}

//удаление всех данных и файлов связанных с остановкой
void Menu::removeStation(Station station) {
	for (auto it = transports.transports.begin(); it != transports.transports.end(); ++it)
		for (auto iter = it->stations.begin(); iter != it->stations.end(); ++iter)
			if (station == *iter) {
				string tempType;
				switch (it->typeOfTransport) {
				case Bus:
					tempType = string("Bus");
					break;
				case Trolley:
					tempType = string("Trolley");
					break;
				case Tram:
					tempType = string("Tram");
					break;
				case Metro:
					tempType = string("Metro");
					break;
				}
				remove(string(tempType + "\\" + it->nameOFTransport + "\\" + it->nameOFTransport + "_" + iter->nameOfStation + ".txt").c_str());
				remove(string(tempType + "\\" + it->nameOFTransport + "\\" + "_" + it->nameOFTransport + "_" + iter->nameOfStation + ".txt").c_str());
				break;
			}
}

//удаление всех данных и файлов связанных с транспортом
void Menu::removeTransport(Transport transport) {
	for (auto it = transports.transports.begin(); it != transports.transports.end(); ++it)
		if (*it == transport) {
			for (auto iter = it->stations.begin(); iter != it->stations.end(); ++iter) {
				removeStation(*iter);
			}
			string tempType;
			switch (it->typeOfTransport) {
			case Bus:
				tempType = string("Bus");
				break;
			case Trolley:
				tempType = string("Trolley");
				break;
			case Tram:
				tempType = string("Tram");
				break;
			case Metro:
				tempType = string("Metro");
				break;
			}
			remove(string(tempType + "\\" + it->nameOFTransport + "\\" + it->nameOFTransport + ".txt").c_str());
			RemoveDirectory(string(tempType + "\\" + it->nameOFTransport).c_str());
			break;
			
		}

}

void Menu::outPutTransports(Transports transports) { //вывод транспорта на экран
	int index = 1;

	for (auto it = transports.transports.begin(); it != transports.transports.end(); ++it, ++index) {
		switch (it->typeOfTransport) {
		case Bus:
			cout << '\t' << index << " - " << it->nameOFTransport << "(Bus)" << endl;
			break;
		case Trolley:
			cout << '\t' << index << " - " << it->nameOFTransport << "(Trolley)" << endl;
			break;
		case Tram:
			cout << '\t' << index << " - " << it->nameOFTransport << "(Tram)" << endl;
			break;
		case Metro:
			cout << '\t' << index << " - " << it->nameOFTransport << "(Metro)" << endl;
			break;
		}
	}
}

bool Menu::setTransport(Transports transports) { // выбор транспорта, с которым придётся рабоать
	while (1) {
		system("cls");
		cout << "Transports:\n";
		outPutTransports(transports);
		cout << "0 - return\n\nChoice: ";
		int Choice;
		cin >> Choice;
		if (Choice == 0) return false;
		if (cin.fail() || Choice < 0 || Choice > transports.transports.size()) { //проверка корректности ввода
			std::cout << "Incorrect Input. Value must be from 0 to " << transports.transports.size() << ".\nPress enter to try again...";
			cin.clear();
			std::cin.ignore(256, '\n');
			std::cin.get();
			continue;
		}
		int index = 1;
		//поиск выбранного транспорта
		for (auto it = transports.transports.begin(); it != transports.transports.end(); ++it, ++index)
			if (index == Choice) { 
				transport = *it;
				break;
			}
		break;
	}
	return true;
}

void Menu::outPutStations() { //вывод остановок выбранного транспорта
	int index = 1;
	cout << transport.nameOFTransport << ":\n";
	for (auto it = transport.stations.begin(); it != transport.stations.end(); ++it, index++)
		cout << '\t' << index << " - " << it->nameOfStation << endl;
}

bool Menu::setStation() { //выбор остановки
	while (1) {
		system("cls");
		outPutStations();
		cout << "0 - return\n\nChoice: ";
		int Choice;
		cin >> Choice;
		if (!Choice) return false;
		if (cin.fail() || Choice < 0 || Choice > transport.stations.size()) {
			std::cout << "Incorrect Input. Value must be from 0 to " << transport.stations.size() << ".\nPress enter to try again...";
			cin.clear();
			std::cin.ignore(256, '\n');
			std::cin.get();
			continue;
		}
		int index = 1;
		//поиск выбранной остановки
		for (auto it = transport.stations.begin(); it != transport.stations.end(); ++it, index++)
			if (index == Choice) {
				station = *it;
				break;
			}
		break;
	}
	return true;
}


void Menu::outPutSchedule() { //вывод расписания выбранного транспорта на выбранной остановке
	system("cls");
	std::cout << "Schedule of " << transport.nameOFTransport << " on " << station.nameOfStation << ":\n";
	station.schedule.outPutTimes();
}

bool Menu::User() {
	//проверка на существование транспорта
	if (transports.transports.size() == 0) {
		std::cout << "Schedule ins't exist!";
		system("pause > nul");
		return true;
	}
	int select;
	while (1) {
		system("COLOR 34");
		select = borderInputNums(cin, "What do you want to find ? \n\n1 - Transport\n2 - Station\n\n3 - return\n\n0 - exit\n\nChoice ",
			int(0), int(3));
		if (!select) return false;
		if (select == 3) return true;
		switch (select) {
		case 1: //поиск по транспорту
			while (1) {
				if (!setTransport(transports)) break;
				while (1) {
					if (!setStation()) break;
					outPutSchedule();
					system("pause > nul");
				}
			}
			break;
		case 2: // поиск по остановке
			while (1) {
				string temp;
				system("cls");
				std::cout << "Enter name of station: ";
				std::cin >> temp; //ввод названия искомой остановки
				Transports tempTransports;
				bool flag = false;
				//поиск остановки
				for (auto it = transports.transports.begin(); it != transports.transports.end(); ++it)
					for (auto iter = it->stations.begin(); iter != it->stations.end(); ++iter)
						if (iter->nameOfStation == temp) {
							tempTransports.transports.push_back(*it);
							flag = true;
							break;
						}
				if (!flag) { //проверка на существование остановки
					if (borderInputNums(cin, "Station isn't exist!\nDo you want to try again ?\n1 - Yes\n0 - No\n\nChoice: ",
						0, 1)) continue;
					else break;
				}
				if (!setTransport(tempTransports)) break;
				station = transport.findStation(temp);
				outPutSchedule();
				system("pause > nul");
				break;
			}
			break;
		}
	}
}

bool Menu::Admin() {
	stack<Transports> trStack;
	while (1) {
		system("COLOR E4");
		trStack.push(transports);
		int choice = borderInputNums(cin, "Choose action:\n1 - Add\n2 - remove\n3 - change\n4 - cancel prev action\n\n5 - return\n\n0 - exit\n\nChoice: ", 0, 5);
		string tempString;
		switch (choice) {
		case 0: //конец работы программы
			if (transports.transports.size() == 0) {
				remove(FILENAME_List_of_routes);
				return false;
			}
			transports = trStack.top();
			transports.writeToFile();
			return false;
			break;
		case 5: //возврат к выбору меню
			if (transports.transports.size() == 0) {
				remove(FILENAME_List_of_routes);
				return true;
			}
			transports = trStack.top();
			transports.writeToFile();
			return true;
			break;
		case 1: //добавление транспорта
			system("CLS");
			char buff[80];
			std::cout << "Enter name of Route(name must begins from nums): ";
			cin.ignore(80, '\n');
			do {
				cin.getline(buff, 79);
			} while (buff[0] < '0' || buff[0] > '9');
			transport.nameOfRoute = string(buff);
			std::cout << "Enter name of Transport(name must begins from nums): ";
			do {
				cin.getline(buff, 79);
			} while (buff[0] < '0' || buff[0] > '9');
			transport.nameOFTransport = string(buff);
			switch (borderInputNums(cin, "Choose Type:\n1 - Bus\n2 - Trolley\n3 - Tram\n4 - Metro\n\nChoice: ", 0, 4)) {
			case 1:
				transport.typeOfTransport = Bus;
				break;
			case 2:
				transport.typeOfTransport = Trolley;
				break;
			case 3:
				transport.typeOfTransport = Tram;
				break;
			case 4:
				transport.typeOfTransport = Metro;
				break;
			}
			if (Transport_isExist(transport)) {
				cout << "Transport is exist!!!";
				system("pause > nul");
				break;
			}
			while (1) { //добавление остановок
				if (!borderInputNums(cin, "Choose action:\n1 - add Station\n0 - return\n\nChoice: ", 0, 1)) break;
				else {
					std::cout << "Enter name of Station: ";
					cin.ignore(80, '\n');
					cin.getline(buff, 79);
					station.nameOfStation = string(buff);
					if (Station_isExist(station)) {
						cout << "Station is exist!!!";
						system("pause > nul");
						break;
					}
					while (1) { //добавление расписания
						if (!borderInputNums(cin, "Choose action:\n1 - add time\n0 - return\n\nChoice: ", 0, 1)) break;
						else {
							station.schedule.addTime();
						}
					}
					transport.addStation(station);
				}
			}
			transports.transports.push_back(transport);
			trStack.push(transports);
			break;
		case 2: //удаление
			choice = borderInputNums(cin, "What do you want to remove?\n1 - transport\n2 - station of transport\n0 - retun\n\nChoice: ", 0, 2);
			cout << "Choose Transport:\n";
			if (!setTransport(transports)) break;
			for (auto it = transports.transports.begin(); it != transports.transports.end(); ++it)
				if (*it == transport) {
					if (choice == 1) {
						removeTransport(*it);
						transports.transports.erase(it); //удаление траспорта
					}
					else if (choice == 2) {
						if (!setStation()) break;
						Tree<Station>::iterator tempIter;
						for (auto iter = it->stations.begin(); iter != it->stations.end(); ++iter)
							if (*iter == station) {
								tempIter = iter;
							}
						it->stations.remove(*tempIter); //удаление остановки
						it->countOfStations--;
					}
					break;
				}
			trStack.push(transports);
			break;
		case 3: //редактирование данных 
			while (1) {
				string tempStr;
				choice = borderInputNums(cin, "Select object:\n1 - Transport\n2 - Station\n\n0 - return\n\nChoice: ", 0, 2);
				if (!choice) break;
				switch (choice) {
				case 1: //редактирование транспорта
					if (!setTransport(transports)) continue;
					choice = borderInputNums(cin, "What do you want to change?\n1 - name of route\n2 - name of transport\n3 - type of transport\n4 - add station\n\n0 - return\n\nChoice: ", 0, 4);
					if (!choice) continue;
					switch (choice) {
					case 1:
						cout << "Enter new name of Route: ";
						cin >> tempStr;
						for (auto it = transports.transports.begin(); it != transports.transports.end(); ++it)
							if (*it == transport) {
								it->nameOfRoute = tempStr;
								break;
							}
						break;
					case 2:
						cout << "Enter new name of Transport: ";
						cin >> tempStr;
						for (auto it = transports.transports.begin(); it != transports.transports.end(); ++it)
							if (*it == transport) {
								it->nameOFTransport = tempStr;
								break;
							}
						break;
					case 3:
						for (auto it = transports.transports.begin(); it != transports.transports.end(); ++it)
							if (*it == transport) {
								choice = borderInputNums(cin, "Choose type:\n1 - Bus\n2 - Trolley\n3 - Tram\n4 - Metro", 1, 4);
								switch (choice) {
								case 1:
									it->typeOfTransport = TYPE_Transports(Bus);
									break;
								case 2:
									it->typeOfTransport = TYPE_Transports(Trolley);
									break;
								case 3:
									it->typeOfTransport = TYPE_Transports(Tram);
									break;
								case  4:
									it->typeOfTransport = TYPE_Transports(Metro);
									break;
								}
							}
						break;
					case 4:
						for (auto it = transports.transports.begin(); it != transports.transports.end(); ++it) {
							if (*it == transport) {
								cout << "Enter name of new station: ";
								cin.ignore(256, '\n');
								cin.getline(buff, 79);
								Station tempStation;
								tempStation.nameOfStation = string(buff);
								while (1) {
									choice = borderInputNums(cin, "Schedule:\n1 - add\n0 - return\n\nChoice: ", 0, 1);
									if (!choice) break;
									tempStation.schedule.addTime();
								}
								it->addStation(tempStation);
							}
						}
						break;
					}
					break;
				case 2: //редактирование остановки
					if (!setTransport(transports)) break;
					if (!setStation()) continue;
					for (auto it = transports.transports.begin(); it != transports.transports.end(); ++it) {
						if (*it == transport) {
							for (auto iter = it->stations.begin(); iter != it->stations.end(); ++iter) {
								if (*iter == station) {
									choice = borderInputNums(cin, "What do you want to change?\n1 - name of Station\n2 - Schedule\n0 - return\n\nChoice: ", 0, 2);
									if (!choice) break;
									switch (choice) {
									case 1:
										cout << "Enter new name of station: ";
										cin >> tempStr;
										iter->nameOfStation = tempStr;
										break;
									case 2:
										while (1) {
											choice = borderInputNums(cin, "1 - add\n0 - return\n\nChoice: ", 0, 1);
											if (!choice) break;
											iter->schedule.addTime();
										}
										break;
									}
								}
							}
							break;
						}
					}
					break;
				}
			}
			trStack.push(transports);
			break;
		case 4:
			system("cls");
			if (trStack.size() != 1) {
				if (borderInputNums(cin, "Are you sure?\n1 - Yes\n0 - No\n\nChoice: ", 0, 1))
					trStack.pop();
			}
			else {
				cout << "Actions, which must be cancel, aren't exist!";
				system("pause > nul");
			}
			break;
		}
	}
}