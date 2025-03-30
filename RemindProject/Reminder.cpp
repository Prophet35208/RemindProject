#include "Reminder.h"

/*
	* ћетод, наход€щий сколко осталось ждать мес€ц month, если сейчас мес€ц nowMonth
	* @param month первый аргумент, число от 1 до 12
	* @param nowMonth второй аргумент, число от 1 до 12
	* @return сколько мес€цев осталось ждать
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
	* ћетод, добавл€ющий дату в список дат
	* @param name первый аргумент, строка
	* @param date второй аргумент, строка
*/
void Reminder::addNewDate(string name, string date)
{
	BirthdayInfo info(name, date);
	this->infoVect.push_back(info);
}

/*
	* ћетод, который определ€ет 
	* @return строка сообщени€ о ближайшей дате
*/
string Reminder::getNearestDateMessage()
{
	// todo реализовать дл€ n числа дат
	
	// ѕолучаем текущее врем€
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
		month = "€нвар€";
		break;

	case 2:
		month = "феврал€";
		break;

	case 3:
		month = "марта";
		break;

	case 4:
		month = "апрел€";
		break;
	case 5:
		month = "ма€";
		break;
	case 6:
		month = "июн€";
		break;
	case 7:
		month = "июл€";
		break;
	case 8:
		month = "августа";
		break;
	case 9:
		month = "сент€бр€";
		break;
	case 10:
		month = "окт€бр€";
		break;
	case 11:
		month = "но€бр€";
		break;
	case 12:
		month = "декабр€";
		break;
	}

	return string("Ѕлижайший день рождени€ будет " + day + " " + month + " у " + name);
}
