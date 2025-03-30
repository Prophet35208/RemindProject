#include "BirthdayInfo.h"

BirthdayInfo::BirthdayInfo()
{
}

BirthdayInfo::BirthdayInfo(string name, string date)
{
	this->name = name;
	this->date = date;
}

string BirthdayInfo::getNameStr()
{
	return this->name;
}

string BirthdayInfo::getDateStr()
{
	return this->date;
}


int BirthdayInfo::getDayNum()
{
	stringstream date(this->date);
	int day;
	date >> day;
	return day;
}

int BirthdayInfo::getMounthNum()
{
	stringstream date(this->date);
	int day, mounth;
	char dot;
	date >> day >> dot >> mounth;
	return mounth;

}
