// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TestClassA.h"
#include "TestClassB.h"

int main()
{
	TestClassA A;
	TestClassB B;

	auto boundFunction = std::bind(&TestClassB::bfunc, &B);
	auto boundFunction2 = std::bind(&TestClassB::bfunc2, &B, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);

	observe::Observer observer = A.eventB.createObserver(boundFunction2);

	A.eventA.connect(boundFunction);
	A.FireEventA();
	A.FireEventB(1, 2, 3.22f);
	observer.reset();
	A.FireEventB(10, 20, 30.22f);
	observer.observe(A.eventB, boundFunction2);
	A.FireEventA();
	A.FireEventB(100, 200, 300.22f);

}
