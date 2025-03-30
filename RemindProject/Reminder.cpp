#include "Reminder.h"

Reminder::Reminder()
{

}

void Reminder::addNewDate(string name, string date)
{
	BirthdayInfo info(name, date);
	this->infoVect.push_back(info);
}


string Reminder::getNearestDateMessage()
{
	// todo реализовать дл€ n числа дат
	
	// ѕолучаем текущее врем€
	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	std::tm now_tm;
	localtime_s(&now_tm, &now_c);
	int currentDayNum = now_tm.tm_mday;
	int currentMounthNum = now_tm.tm_mon + 1;

	string day;
	string mounth;
	string name;
	int mounthNum;
	int mounthNum0;
	int dayNum0;
	int mounthNum1;
	int dayNum1;

	dayNum0 = this->infoVect[0].getDayNum();
	mounthNum0 = this->infoVect[0].getMounthNum();
	dayNum1 = this->infoVect[0].getDayNum();
	mounthNum1 = this->infoVect[0].getMounthNum();

	if (abs(currentMounthNum - mounthNum0) >= abs(currentMounthNum - mounthNum1))
		if (abs(currentMounthNum - mounthNum0) == abs(currentMounthNum - mounthNum1))
			if (abs(currentDayNum - dayNum0) >= abs(currentDayNum - dayNum1))
				if (abs(currentDayNum - dayNum0) == abs(currentDayNum - dayNum1))
				{
					day = to_string(this->infoVect[0].getDayNum());
					mounthNum = mounthNum0;
					name = this->infoVect[0].getNameStr();
				}
				else
				{
					day = to_string(this->infoVect[1].getDayNum());
					mounthNum = mounthNum0;
					name = this->infoVect[1].getNameStr();
				}
			else
			{
				day = to_string(this->infoVect[0].getDayNum());
				mounthNum = mounthNum0;
				name = this->infoVect[0].getNameStr();
			}
		else
		{
			day = to_string(this->infoVect[1].getDayNum());
			mounthNum = mounthNum1;
			name = this->infoVect[1].getNameStr();
		}
	else
	{
		day = to_string(this->infoVect[0].getDayNum());
		mounthNum = mounthNum0;
		name = this->infoVect[0].getNameStr();
	}
		


	switch (mounthNum)
	{
	case 1:
		mounth = "€нвар€";
		break;

	case 2:
		mounth = "феврал€";
		break;

	case 3:
		mounth = "марта";
		break;

	case 4:
		mounth = "апрел€";
		break;
	case 5:
		mounth = "ма€";
		break;
	case 6:
		mounth = "июн€";
		break;
	case 7:
		mounth = "июл€";
		break;
	case 8:
		mounth = "августа";
		break;
	case 9:
		mounth = "сент€бр€";
		break;
	case 10:
		mounth = "окт€бр€";
		break;
	case 11:
		mounth = "но€бр€";
		break;
	case 12:
		mounth = "декабр€";
		break;
	}

	return string("Ѕлижайший день рождени€ будет " + day + " " + mounth + " у " + name);
}
