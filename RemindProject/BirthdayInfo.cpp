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
	//todo �������� ��������� ����������
	return 13;
}

int BirthdayInfo::getMounthNum()
{
	//todo �������� ��������� ����������
	return 5;
}
