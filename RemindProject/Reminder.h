#pragma once
#include "BirthdayInfo.h"

class Reminder
{
private:
	BirthdayInfo info;
public:
	Reminder();

	void addNewDate(string name, string date);
	string getNearestDateMessage();
};

