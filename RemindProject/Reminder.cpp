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
	//todo �������� ���������� ��� ������ �����
	return string("��������� ���� �������� ����� 5 ����� � " + this->info.getNameStr());
}
