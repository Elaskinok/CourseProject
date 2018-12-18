#pragma once
//базовый класс исключения
class Exception {
public:
	virtual const char* what() const {
		return "Unknown Exception!";
	}
	virtual const char* what_code() const {
		return "E00000";
	}
	Exception() {}
	~Exception() {}
};