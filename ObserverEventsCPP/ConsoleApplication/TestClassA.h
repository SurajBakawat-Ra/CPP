#pragma once
#include "observe/event.h"

class TestClassA
{
public:
	observe::Event<> eventA;
	observe::Event<int, int, float> eventB;
	void FireEventA();
	void FireEventB(int a, int b, float f);
};