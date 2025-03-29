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
		TEST_METHOD(TestMethod1)
		{
			string actName("����� �.�.");
			string actDate("13.05.2003");

			BirthdayInfo info(actName, actDate);

			string name = info.getNameStr();
			string date = info.getDateStr();

			Assert::IsTrue(actName == name);
			Assert::IsTrue(actDate == date);
		}


	};
}
