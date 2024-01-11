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

	// observers will remove themselves from the event on destroy or reset
	observe::Observer observer = A.eventB.createObserver(boundFunction2);
	// connect will always trigger when an event is triggered
	A.eventA.connect(boundFunction);

	// call emit to trigger all observers
	A.FireEventA();
	A.FireEventB(1, 2, 3.22f);

	// to remove an observer without destroying the object, call reset
	observer.reset();

	A.FireEventB(10, 20, 30.22f);

	//observe::Observer can store any type of observer, previous observers will be removed
	observer.observe(A.eventB, boundFunction2);

	A.FireEventA();
	A.FireEventB(100, 200, 300.22f);

}
