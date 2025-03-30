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
	//todo добавить настоящую реализацию
	return 13;
}

int BirthdayInfo::getMounthNum()
{
	//todo добавить настоящую реализацию
	return 5;
}
