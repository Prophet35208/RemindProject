#include "Reminder.h"

/*
	* �����, ��������� ������ �������� ����� ����� month, ���� ������ ����� nowMonth
	* @param month ������ ��������, ����� �� 1 �� 12
	* @param nowMonth ������ ��������, ����� �� 1 �� 12
	* @return ������� ������� �������� �����
*/
int Reminder::getSpanForMonth(int month, int nowMonth)
{
	int delta = month - nowMonth;
	if (delta < 0)
		delta += 12;
	return delta;
}

Reminder::Reminder()
{

}

/*
	* �����, ����������� ���� � ������ ���
	* @param name ������ ��������, ������
	* @param date ������ ��������, ������
*/
void Reminder::addNewDate(string name, string date)
{
	BirthdayInfo info(name, date);
	this->infoVect.push_back(info);
}

/*
	* �����, ������� ���������� 
	* @return ������ ��������� � ��������� ����
*/
string Reminder::getNearestDateMessage()
{
	// todo ����������� ��� n ����� ���
	
	// �������� ������� �����
	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	std::tm now_tm;
	localtime_s(&now_tm, &now_c);
	int currentDayNum = now_tm.tm_mday;
	int currentMonthNum = now_tm.tm_mon + 1;

	string day;
	string month;
	string name;

	int monthNum;
	int dayNum;
	int nextMonthNum;
	int nextDayNum;

	monthNum = this->infoVect[0].getMounthNum();
	dayNum = this->infoVect[0].getDayNum();

	if (this->infoVect.size() > 1) 
	{
		for (auto it = this->infoVect.begin() + 1; it != this->infoVect.end(); ++it) {

			nextMonthNum = (*it).getMounthNum();
			nextDayNum = (*it).getDayNum();

			if (getSpanForMonth(monthNum, currentMonthNum) >= getSpanForMonth(nextMonthNum, currentMonthNum))
				if (getSpanForMonth(monthNum, currentMonthNum) == getSpanForMonth(nextMonthNum, currentMonthNum))
					if (dayNum >=  nextDayNum)
						if (dayNum ==  nextDayNum)
							;
						else
						{
							day = to_string(this->infoVect[1].getDayNum());
							monthNum = nextMonthNum;
							name = (*it).getNameStr();
						}
					else;
				else
				{
					day = to_string(this->infoVect[1].getDayNum());
					monthNum = nextMonthNum;
					name = (*it).getNameStr();
				}

		}
	}
	switch (monthNum)
	{
	case 1:
		month = "������";
		break;

	case 2:
		month = "�������";
		break;

	case 3:
		month = "�����";
		break;

	case 4:
		month = "������";
		break;
	case 5:
		month = "���";
		break;
	case 6:
		month = "����";
		break;
	case 7:
		month = "����";
		break;
	case 8:
		month = "�������";
		break;
	case 9:
		month = "��������";
		break;
	case 10:
		month = "�������";
		break;
	case 11:
		month = "������";
		break;
	case 12:
		month = "�������";
		break;
	}

	return string("��������� ���� �������� ����� " + day + " " + month + " � " + name);
}
