#include "pch.h"
#include "CppUnitTest.h"
#include "../RemindProject/RemindProject.cpp"
#include "../RemindProject/BirthdayInfo.h"
#include "../RemindProject/BirthdayInfo.cpp"


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

		TEST_METHOD(TestStrToInt)
		{
			string actName("����� �.�.");
			string actDate("13.05.2003");

			BirthdayInfo info(actName, actDate);

			int day = info.getDayNum();
			int mounth = info.getMounthNum();

			Assert::IsTrue((13 == day),L"String to int day convertion incorrect");
			Assert::IsTrue((5 == mounth), L"String to int mounth convertion incorrect");
		}


	};
}
