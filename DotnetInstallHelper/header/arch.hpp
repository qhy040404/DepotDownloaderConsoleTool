//arch.hpp
//
#include <iostream>
int checkArch()
{
	void* number = 0;
	return sizeof(&number);
}