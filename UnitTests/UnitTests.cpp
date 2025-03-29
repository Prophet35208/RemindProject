#include "pch.h"
#include "CppUnitTest.h"
#include "../RemindProject/RemindProject.cpp"
#include "../RemindProject/BirthdayInfo.h"
#include "../RemindProject/BirthdayInfo.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	// В начале протестируем то, как программа хранит в себе информацию о днях рождения в классе BirthdayInfo
	TEST_CLASS(UnitTests)
	{
	public:
		
		// Проверяем то, верно ли записываются и возвращаются данные о ФИО и дате
		TEST_METHOD(TestMethod1)
		{
			string actName("Таран Д.В.");
			string actDate("13.05.2003");

			BirthdayInfo info(actName, actDate);

			string name = info.getNameStr();
			string date = info.getDateStr();

			Assert::IsTrue(actName == name);
			Assert::IsTrue(actDate == date);
		}


	};
}
