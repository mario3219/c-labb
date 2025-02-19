#include <ctime>  // time and localtime
#include "date.h"
#include <iostream>
#include <ostream>

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

std::ostream& operator<<(std::ostream& os, const Date date) {
	os << date.getYear() << "-" << date.getMonth() << "-" << date.getDay();
	return os;
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	day += 1;
	if (day > daysPerMonth[0]) {
		month += 1;
		day = 1;
	}
	if (month > 12) {
		year += 1;
		month = 1;
	}
}

