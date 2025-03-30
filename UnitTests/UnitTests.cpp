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
	// � ������ ������������ ��, ��� ��������� ������ � ���� ���������� � ���� �������� � ������ BirthdayInfo
	TEST_CLASS(UnitTests)
	{
	public:
		
		// ��������� ��, ����� �� ������������ � ������������ ������ � ��� � ����
		TEST_METHOD(TestStr)
		{
			string actName("����� �.�.");
			string actDate("13.05.2003");

			BirthdayInfo info(actName, actDate);

			string name = info.getNameStr();
			string date = info.getDateStr();

			Assert::IsTrue(actName == name);
			Assert::IsTrue(actDate == date);
		}

		// ���������, ��������� �� ���������� ������� �� ���������� ������������� � ��������
		TEST_METHOD(TestStrToInt1)
		{
			string actName("����� �.�.");
			string actDate("13.05.2003");

			BirthdayInfo info(actName, actDate);

			int day = info.getDayNum();
			int mounth = info.getMounthNum();

			Assert::IsTrue((13 == day),L"String to int day convertion incorrect");
			Assert::IsTrue((5 == mounth), L"String to int mounth convertion incorrect");
		}

		TEST_METHOD(TestStrToInt2)
		{
			string actName("���� �.�.");
			string actDate("05.03.2005");

			BirthdayInfo info(actName, actDate);

			int day = info.getDayNum();
			int mounth = info.getMounthNum();

			Assert::IsTrue((5 == day), L"String to int day convertion incorrect");
			Assert::IsTrue((3 == mounth), L"String to int mounth convertion incorrect");
		}

		// �������� �������� �����������
		// �� ��� ���������� ��� � ���� ��������, ��������� ���������� ��������� � ���, ����� ����� ��������� ���� ��������
		TEST_METHOD(BasicFunctionality1)
		{
			Reminder rem;
			rem.addNewDate("���� �.�.", "05.03.2005");

			string nearDate = rem.getNearestDateMessage();

			Assert::IsTrue(("��������� ���� �������� ����� 5 ����� � ���� �.�." == nearDate), L"Message about nearest date is incorrect");

		}

		TEST_METHOD(BasicFunctionality2)
		{
			Reminder rem;
			rem.addNewDate("����� �.�.", "13.05.2003");

			string nearDate = rem.getNearestDateMessage();

			Assert::IsTrue(("��������� ���� �������� ����� 13 ��� � ����� �.�." == nearDate), L"Message about nearest date is incorrect");

		}

		
		TEST_METHOD(TwoDates)
		{
			Reminder rem;
			rem.addNewDate("���� �.�.", "05.07.2005");
			rem.addNewDate("����� �.�.", "13.05.2003");

			string nearDate = rem.getNearestDateMessage();
			Assert::IsTrue(("��������� ���� �������� ����� 13 ��� � ����� �.�." == nearDate), L"Message about nearest date is incorrect");

		}

	};
}
