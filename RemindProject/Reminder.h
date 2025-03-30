#pragma once
#include "BirthdayInfo.h"
#include <vector>
#include <chrono>
#include <iomanip>

class Reminder
{
private:
	vector<BirthdayInfo> infoVect;
	
	int getSpanForMonth(int month, int nowMonth);
public:
	Reminder();

	void addNewDate(string name, string date);
	string getNearestDateMessage();
};

