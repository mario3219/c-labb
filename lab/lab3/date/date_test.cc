#include <iostream>
#include <iomanip> // for setw and setfill
#include "date.h"

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::setfill;

/*
 * Prints the date d in the format yyyy-mm-dd. You shall replace this
 * function with an overloaded operator<<, and add an overloaded operator>>.
 *
 */

template <typename T>
std::string toString(const T& object) {
	std::ostringstream buffer;
	buffer << object;

	return buffer.str();
}

template<typename T>
T string_cast(std::string s) {
	std::istringstream buffer(s);
	T t;
	buffer >> t;
	return t;
}

void print(const Date& d) {
	cout << setw(4) << setfill('0') << d.getYear() << '-';
	cout << setw(2) << setfill('0') << d.getMonth() << '-';
	cout << setw(2) << setfill('0') << d.getDay();
}


int main() {

	try {
		int i = string_cast<int>("123");
		double d = string_cast<double>("12.34");
		Date date = string_cast<Date>("2015-01-10");
		cout << "int:" << i << "\ndouble" << d << "\ndate" << date;
		} catch (std::invalid_argument& e) {
		cout << "Error: " << e.what() << endl;
	}

	cout << "Testing toString() template: " << "\n";
	double d = 1.23;
	Date date(2022,12,1);
	std::string sd = toString(d);
	std::string sdate = toString(date);
	cout << sd << "\n" << sdate << "\n";

		// Check 'next' by creating an object describing today's date, then
	// printing dates more than a month ahead
	cout << "--- Today and more than a month ahead:" << endl;
	Date d1;
	print(d1);
	cout << endl;
	for (int i = 1; i <= 35 ; ++i) {
		d1.next();
		print(d1);
		cout << endl;
	}
	
	// Check so 'next' functions correctly from one year to the next
	cout << "--- New Year's Eve and the next day:" << endl;
	Date d2(2013, 12, 31);
	print(d2);
	cout << endl;
	d2.next();
	print(d2);
	cout << endl;

	// Check input and output of dates. Uncomment the following when you 
	// have added operator>> and operator<<.
	bool cont = true;
	while (cont) {
		cout << "Type a date: ";
		Date aDate;
		cin >> aDate;
		if (cin.eof()) {
			cont = false;
		} else if (!cin.good()) {
			cout << "Wrong input format" << endl;
			// restore stream state and ignore the rest of the line
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else {
			cout << "Output: " << aDate << endl;
		}
	}
}
