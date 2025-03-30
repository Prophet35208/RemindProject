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
		mounth = "������";
		break;

	case 2:
		mounth = "�������";
		break;

	case 3:
		mounth = "�����";
		break;

	case 4:
		mounth = "������";
		break;
	case 5:
		mounth = "���";
		break;
	case 6:
		mounth = "����";
		break;
	case 7:
		mounth = "����";
		break;
	case 8:
		mounth = "�������";
		break;
	case 9:
		mounth = "��������";
		break;
	case 10:
		mounth = "�������";
		break;
	case 11:
		mounth = "������";
		break;
	case 12:
		mounth = "�������";
		break;
	}

	return string("��������� ���� �������� ����� " + day + " " + mounth + " � " + this->info.getNameStr());
}
