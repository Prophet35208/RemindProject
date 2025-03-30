#include "pch.h"
#include "CppUnitTest.h"
#include "../RemindProject/RemindProject.cpp"
#include "../RemindProject/BirthdayInfo.h"
#include "../RemindProject/BirthdayInfo.cpp"
#include "../RemindProject/Reminder.h"
#include "../RemindProject/Reminder.cpp"


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
		TEST_METHOD(TestStrToInt1)
		{
			string actName("Таран Д.В.");
			string actDate("13.05.2003");

			BirthdayInfo info(actName, actDate);

			int day = info.getDayNum();
			int mounth = info.getMounthNum();

			Assert::IsTrue((13 == day),L"String to int day convertion incorrect");
			Assert::IsTrue((5 == mounth), L"String to int mounth convertion incorrect");
		}

		TEST_METHOD(TestStrToInt2)
		{
			string actName("Юлия В.Д.");
			string actDate("05.03.2005");

			BirthdayInfo info(actName, actDate);

			int day = info.getDayNum();
			int mounth = info.getMounthNum();

			Assert::IsTrue((5 == day), L"String to int day convertion incorrect");
			Assert::IsTrue((3 == mounth), L"String to int mounth convertion incorrect");
		}

		// Проверка базового функционала
		// Мы даём приложению ФИО и дату рождения, программа возвращает сообщение о том, когда будет ближайший день рождения
		TEST_METHOD(BasicFunctionality1)
		{
			Reminder rem;
			rem.addNewDate("Юлия В.Д.", "05.03.2005");

			string nearDate = rem.getNearestDateMessage();

			Assert::IsTrue(("Ближайший день рождения будет 5 марта у Юлия В.Д." == nearDate), L"Message about nearest date is incorrect");

		}

		TEST_METHOD(BasicFunctionality2)
		{
			Reminder rem;
			rem.addNewDate("Таран Д.В.", "13.05.2003");

			string nearDate = rem.getNearestDateMessage();

			Assert::IsTrue(("Ближайший день рождения будет 13 мая у Таран Д.В." == nearDate), L"Message about nearest date is incorrect");

		}

		
		TEST_METHOD(TwoDates)
		{
			Reminder rem;
			rem.addNewDate("Юлия В.Д.", "05.07.2005");
			rem.addNewDate("Таран Д.В.", "13.05.2003");

			string nearDate = rem.getNearestDateMessage();
			Assert::IsTrue(("Ближайший день рождения будет 13 мая у Таран Д.В." == nearDate), L"Message about nearest date is incorrect");

		}

	};
}
