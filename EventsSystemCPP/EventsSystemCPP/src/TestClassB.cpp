#include "TestClassB.h"

#include <iostream>

void TestClassB::bfunc()
{
	std::cout << "bfunc" << std::endl;
}

void TestClassB::bfunc2(int a, int b, float f)
{
	std::cout << "bfunc2, values recieved: " <<a << " " << b << " " << " " << f << std::endl;
}
