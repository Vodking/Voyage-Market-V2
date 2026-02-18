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
		TEST_METHOD_INITIALIZE(TestIni)
		{
			randNum = rand() % 10000;
			randStr = std::to_string(randNum);
			std::string randLogin{}, randPass{};
		}
		TEST_METHOD(IsNumberTest)
		{
			Assert::AreEqual(true, IsNumber("10"), L"IsNumber fail super easy");
			Assert::AreEqual(false, IsNumber("Á"), L"IsNumber fail string");
			Assert::AreEqual(false, IsNumber("9876543210"), L"IsNumber fail bigNumber");
			Assert::AreEqual(true, IsNumber(randStr), L"Random num fail");
		}
		TEST_METHOD(LoginPassTest)
		{
			Assert::AreEqual(false, CheckLogin(generate_random_string(8)), L"Random login fail");
			Assert::AreEqual(false, CheckLogin("kfweklwekwefkwefkefwkfwekwefkwefik"), L"Too long login fail");
			Assert::AreEqual(false, CheckLogin("l"), L"login too small");

			Assert::AreEqual(false, CheckPass(generate_random_string(8)), L"Random pass fail");
			Assert::AreEqual(false, CheckPass("sksksksksksksksksksksksksksksksksks"), L"Pass too long fail");
			Assert::AreEqual(false, CheckPass("k"), L"pass too short fail");
		}
	};
}
