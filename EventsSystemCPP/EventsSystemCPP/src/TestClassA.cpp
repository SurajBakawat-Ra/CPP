#include "TestClassA.h"

void TestClassA::FireEventA()
{
	eventA.emit();
}

void TestClassA::FireEventB(int a, int b, float f)
{
	eventB.emit(a,b,f);
}
