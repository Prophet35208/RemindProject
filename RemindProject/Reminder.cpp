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
	//todo добавить реализацию при разных датах
	return string("Ближайший день рождения будет 5 марта у " + this->info.getNameStr());
}
