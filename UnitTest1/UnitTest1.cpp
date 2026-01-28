#include "pch.h"
#include "CppUnitTest.h"

#include "../Voyage-Market V2/Header.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		std::string randStr;
		int randNum;
		TEST_METHOD_INITIALIZE(IsNumberTestIni)
		{
			randNum = rand() % 10000;
			randStr = std::to_string(randNum);
		}
		TEST_METHOD(IsNumberTest)
		{
			Assert::AreEqual(true, IsNumber("10"), L"IsNumber fail super easy");
			Assert::AreEqual(false, IsNumber("Á"), L"IsNumber fail string");
			Assert::AreEqual(false, IsNumber("9876543210"), L"IsNumber fail bigNumber");
			Assert::AreEqual(true, IsNumber(randStr), L"");
		}
	};
}
