#include "pch.h"
#include "CppUnitTest.h"
#include "../lab1.4/Polynomial.h"
#include "..//lab1.4/Polynomial.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest14
{
	TEST_CLASS(UnitTest14)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Polynomial poly3;
			int coefficients3[] = { 5 };
			poly3.Init(0, coefficients3);
			Assert::AreEqual(poly3.getDegree(), 0);
			Assert:: AreEqual(poly3.getCoefficient(0), 5);
		}
	};
}
