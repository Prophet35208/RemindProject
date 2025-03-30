#pragma once
#include "BirthdayInfo.h"
#include <vector>
#include <chrono>
#include <iomanip>

class Reminder
{
private:
	vector<BirthdayInfo> infoVect;
	
public:
	Reminder();

	void addNewDate(string name, string date);
	string getNearestDateMessage();
};

