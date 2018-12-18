#pragma once

#include <iostream>
#include "InputException.h"
/*left and right Values is inclusive*/
template <class Type> Type borderInputNums(std::istream& stream, const char* message, Type left_Value, Type right_Value);