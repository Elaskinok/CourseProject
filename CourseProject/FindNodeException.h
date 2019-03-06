#pragma once
#include <iostream>
#include "Exception.h"

//исключение поиска узла в дереве
class FindNodeException : public Exception {
	char description[80];
	char code[8];
public:
	FindNodeException(const char* description, const char* code) {
		strcpy_s(this->description, description);
		strcpy_s(this->code, code);
	}
	const char* what() const {
		return this->description;
	}
	const char* what_code() const {
		return this->description;
	}

	~FindNodeException() {}
};