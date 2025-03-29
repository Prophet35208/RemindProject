#pragma once
#include <string>
using namespace std;

class BirthdayInfo
{
private:
	string name;
	string date;

public:
	BirthdayInfo();
	BirthdayInfo(string name, string date);

	string getNameStr();
	string getDateStr();

};

