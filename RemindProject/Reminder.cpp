#include "Reminder.h"

Reminder::Reminder()
{

}

void Reminder::addNewDate(string name, string date)
{
	BirthdayInfo info(name, date);
	this->info = info;
}

string Reminder::getNearestDateMessage()
{
	string day;
	string mounth;
	int mounthNum;

	day = to_string(this->info.getDayNum());
	mounthNum = this->info.getMounthNum();

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

	return string("Ѕлижайший день рождени€ будет " + day + " " + mounth + " у " + this->info.getNameStr());
}
