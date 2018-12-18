#include "borderInputNums.h"
//������� ������������� ����� �����
template <class Type> Type borderInputNums(std::istream& stream, const char* message, Type left_Value, Type right_Value) {
	Type data = Type(0);
	while (1) {
		system("CLS");
		try {
			std::cout << message << "(from " << left_Value << " to " << right_Value << "): ";
			stream >> data;
			//�������� ������������, ������������� ����������
			if (data < left_Value || data > right_Value || stream.fail()) throw InputException("Incorrect input!", "EI0001");
			break;
		}
		catch (InputException exc) { //��������� ����������
			std::cout << exc.what() << " Try to enter again! Value must be from " << left_Value << " to " << right_Value
				<< "\nPress Enter to continue...";
			stream.clear();
			stream.ignore(256, '\n');
			std::cin.get();
			continue;
		}
		stream.ignore(256, '\n');
	}
	return data;
}
