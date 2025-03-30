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
		TEST_METHOD(TestStr)
		{
			string actName("Таран Д.В.");
			string actDate("13.05.2003");

			BirthdayInfo info(actName, actDate);

			string name = info.getNameStr();
			string date = info.getDateStr();

			Assert::IsTrue(actName == name);
			Assert::IsTrue(actDate == date);
		}

		// Проверяем, правильно ли происходит перевод из строкового представления в числовой

		TEST_METHOD(TestStrToInt)
		{
			string actName("Таран Д.В.");
			string actDate("13.05.2003");

			BirthdayInfo info(actName, actDate);

			int day = info.getDayNum();
			int mounth = info.getMounthNum();

			Assert::IsTrue((13 == day),L"String to int day convertion incorrect");
			Assert::IsTrue((5 == mounth), L"String to int mounth convertion incorrect");
		}


	};
}
