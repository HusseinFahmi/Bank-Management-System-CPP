#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
#include "String.h" 

using namespace std;

class Date {
public:
    enum DateStatus { before = -1, equal = 0, after = 1 };

private:
    short _year;
    short _month;
    short _day;

    // ==========================================
    // --- Private Helper Methods ---
    // ==========================================

    static bool isLeapYear(short year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    static short daysInMonth(short month, short year) {
        if (month > 12 || month < 1) return 0;
        short days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        if (month == 2 && isLeapYear(year)) return 29;
        return days[month - 1];
    }

    static short getWeekdayIndex(short day, short month, short year) {
        int a = (14 - month) / 12;
        int y = year - a;
        int m = month + 12 * a - 2;
        int d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
        return d;
    }

    static string getMonthName(short month) {
        string months[] {
            "January","February","March","April","May","June",
            "July","August","September","October","November","December"
        };
        return months[month - 1];
    }

    static void printMonthHeader(short month) {
        cout << "========== " << getMonthName(month) << " ==========\n";
        string days[] = { "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa" };
        for (const string& d : days) {
            cout << setw(4) << d;
        }
        cout << "\n";
    }

    static int dateToDays(const Date& date) {
        short day = date._day;
        short month = date._month;
        short year = date._year;

        year--;
        int totDays = year * 365 + year / 4 + year / 400 - year / 100;

        for (short i = 1; i < month; i++) {
            totDays += daysInMonth(i, date._year);
        }

        totDays += day;
        return totDays;
    }

    Date getSystemDate() {
        time_t t = time(0);
        tm* now = localtime(&t);
        _year = now->tm_year + 1900;
        _month = now->tm_mon + 1;
        _day = now->tm_mday;
        return *this;
    }

    static string repl(string s, string replFrom, string replTo) {
        size_t pos = 0;
        while ((pos = s.find(replFrom, pos)) != string::npos) {
            s.replace(pos, replFrom.length(), replTo);
            pos += replTo.length();
        }
        return s;
    }

    static short minNum(short a, short b) {
        return (a < b) ? a : b;
    }

public:
    // ==========================================
    // --- Constructors ---
    // ==========================================

    Date() {
        *this = getSystemDate();
    }

    Date(const char* date) {
        string delim = "/";
        String d = date; 
        vector<string> dateVector = d.split(delim);

        _day = stoi(dateVector.at(0));
        _month = stoi(dateVector.at(1));
        _year = stoi(dateVector.at(2));
    }

    Date(short day, short month, short year) {
        this->_day = day;
        this->_month = month;
        this->_year = year;
    }

    Date(short numOfDays, short year) {
        short month = 1;
        short days = 0;

        while (numOfDays > (days = daysInMonth(month, year))) {
            numOfDays -= days;
            month++;
        }

        _day = numOfDays;
        _month = month;
        _year = year;
    }

    // ==========================================
    // --- Getters & Setters ---
    // ==========================================
    
    void setDay(short day) { _day = day; }
    short getDay() const { return _day; }

    void setMonth(short month) { _month = month; }
    short getMonth() const { return _month; }

    void setYear(short year) { _year = year; }
    short getYear() const { return _year; }


    // ==========================================
    // --- Validation & Counters ---
    // ==========================================

    static bool isValidDate(short day, short month, short year) {
        short days = daysInMonth(month, year);
        if (day > days || day <= 0) return false;
        if (month > 12 || month < 1) return false;
        return true;
    }

    bool isValidDate() {
        return isValidDate(_day, _month, _year);
    }

    static bool isValidDate(const Date &date){
        return isValidDate(date._day,date._month, date._year);
    }

    bool isLeapYear() {
        return isLeapYear(_year);
    }

    static short getDaysInYear(short year) {
        return isLeapYear(year) ? 366 : 365;
    }
    short getDaysInYear() { return getDaysInYear(_year); }

    static short getHoursInYear(short year) { return getDaysInYear(year) * 24; }
    short getHoursInYear() { return getHoursInYear(_year); }

    static int getMinutesInYear(short year) { return getHoursInYear(year) * 60; }
    int getMinutesInYear() { return getMinutesInYear(_year); }

    static int getSecondsInYear(short year) { return getMinutesInYear(year) * 60; }
    int getSecondsInYear() { return getSecondsInYear(_year); }

    short daysInMonth() { return daysInMonth(_month, _year); }

    static void swap(Date &d1 , Date &d2){
        Date temp = d1;
        d1 = d2;
        d2 = temp;
    }

    void swap(Date &date){
        swap(*this,date);
    }

    // ==========================================
    // --- Day Information ---
    // ==========================================

    static int getWeekdayIndex(Date date) {
        return getWeekdayIndex(date._day, date._month, date._year);
    }
    int getWeekdayIndex() { return getWeekdayIndex(*this); }

    static string getDayName(int dayNumber) {
        string days[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
        return days[dayNumber];
    }
    string getDayName() { return getDayName(getWeekdayIndex()); }

    static short getDayOfYear(Date date) {
        int sum = 0;
        for (int i = 1; i < date._month; i++) sum += daysInMonth(i, date._year);
        sum += date._day;
        return sum;
    }
    short getDayOfYear() { return getDayOfYear(*this); }

    static bool isLastDay(Date date) {
        return date._day == daysInMonth(date._month, date._year);
    }
    bool isLastDay() { return isLastDay(*this); }

    static bool isLastMonth(short month) { return month == 12; }
    bool isLastMonth() { return isLastMonth(_month); }

    static bool isEndOfWeek(Date date) { return getWeekdayIndex(date) == 6; }
    bool isEndOfWeek() { return isEndOfWeek(*this); }

    static bool isWeekend(Date date) {
        int index = getWeekdayIndex(date);
        return index == 5 || index == 6;
    }
    bool isWeekend() { return isWeekend(*this); }

    static bool isBusinessDay(Date date) { return !isWeekend(date); }
    bool isBusinessDay() { return isBusinessDay(*this); }

    static short daysUntilTheEndOfWeek(Date date) { return 6 - getWeekdayIndex(date); }
    short daysUntilTheEndOfWeek() { return daysUntilTheEndOfWeek(*this); }

    static short daysUntilEndOfMonth(Date date) { return daysInMonth(date._month, date._year) - date._day; }
    short daysUntilEndOfMonth() { return daysUntilEndOfMonth(*this); }

    static short daysUntilEndOfYear(Date date) { return getDaysInYear(date._year) - getDayOfYear(date); }
    short daysUntilEndOfYear() { return daysUntilEndOfYear(*this); }

    // ==========================================
    // --- Calendars Printing ---
    // ==========================================

    static void printMonthCalendar(short month, short year) {
        short current = getWeekdayIndex(1, month, year);
        short days = daysInMonth(month, year);

        printMonthHeader(month);
        short col;

        for (col = 0; col < current; col++) cout << setw(4) << " ";

        for (short day = 1; day <= days; day++) {
            cout << setw(4) << day;
            if (++col == 7) {
                col = 0;
                cout << endl;
            }
        }
        cout << endl;
    }

    void printMonthCalendar() {
        printMonthCalendar(_month, _year);
    }

    static void printYearCalender(short year) {
        for (int i = 1; i <= 12; i++) {
            printMonthCalendar(i, year);
            cout << "\n";
        }
    }

    void printYearCalender() {
        printYearCalender(_year);
    }

    // ==========================================
    // --- Date Manipulations ---
    // ==========================================

    static Date increaseDateByOneDay(Date date) {
        if (isLastDay(date) && isLastMonth(date._month)) {
            date._year++;
            date._day = 1;
            date._month = 1;
        }
        else if (isLastDay(date)) {
            date._month++;
            date._day = 1;
        }
        else {
            date._day++;
        }
        return date;
    }
    void increaseDateByOneDay() { *this = increaseDateByOneDay(*this); }

    static Date decreaseDateByOneDay(Date date) {
        if (date._day == 1 && date._month == 1) {
            date._year--;
            date._month = 12;
            date._day = 31;
        }
        else if (date._day == 1) {
            date._month--;
            date._day = daysInMonth(date._month, date._year);
        }
        else {
            date._day--;
        }
        return date;
    }
    void decreaseDateByOneDay() { *this = decreaseDateByOneDay(*this); }

    static Date increaseDateByXDay(Date date, short numOfDays) {
        for (short i = 0; i < numOfDays; i++) date = increaseDateByOneDay(date);
        return date;
    }
    void increaseDateByXDay(short numOfDays) { *this = increaseDateByXDay(*this, numOfDays); }

    static Date decreaseDateByXDay(Date date, short numOfDays) {
        for (short i = 0; i < numOfDays; i++) date = decreaseDateByOneDay(date);
        return date;
    }
    void decreaseDateByXDay(short numOfDays) { *this = decreaseDateByXDay(*this, numOfDays); }

    static Date increaseDateByOneWeek(Date date) { return increaseDateByXDay(date, 7); }
    void increaseDateByOneWeek() { *this = increaseDateByOneWeek(*this); }

    static Date decreaseDateByOneWeek(Date date) { return decreaseDateByXDay(date, 7); }
    void decreaseDateByOneWeek() { *this = decreaseDateByOneWeek(*this); }

    static Date increaseDateByXWeek(Date date, short weeksNum) {
        for (short i = 0; i < weeksNum; i++) date = increaseDateByOneWeek(date);
        return date;
    }
    void increaseDateByXWeek(short weeksNum) { *this = increaseDateByXWeek(*this, weeksNum); }

    static Date decreaseDateByXWeek(Date date, short weeksNum) {
        for (short i = 0; i < weeksNum; i++) date = decreaseDateByOneWeek(date);
        return date;
    }
    void decreaseDateByXWeek(short weeksNum) { *this = decreaseDateByXWeek(*this, weeksNum); }

    static Date increaseDateByOneMonth(Date date) {
        if (isLastMonth(date._month)) {
            date._month = 1;
            date._year++;
        }
        else {
            date._month++;
        }
        date._day = minNum(date._day, daysInMonth(date._month, date._year));
        return date;
    }
    void increaseDateByOneMonth() { *this = increaseDateByOneMonth(*this); }

    static Date decreaseDateByOneMonth(Date date) {
        if (date._month == 1) {
            date._month = 12;
            date._year--;
        }
        else {
            date._month--;
        }
        date._day = minNum(date._day, daysInMonth(date._month, date._year));
        return date;
    }
    void decreaseDateByOneMonth() { *this = decreaseDateByOneMonth(*this); }

    static Date increaseDateByXMonth(Date date, short monthsNum) {
        for (short i = 0; i < monthsNum; i++) date = increaseDateByOneMonth(date);
        return date;
    }
    void increaseDateByXMonth(short monthsNum) { *this = increaseDateByXMonth(*this, monthsNum); }

    static Date decreaseDateByXMonth(Date date, short monthsNum) {
        for (short i = 0; i < monthsNum; i++) date = decreaseDateByOneMonth(date);
        return date;
    }
    void decreaseDateByXMonth(short monthsNum) { *this = decreaseDateByXMonth(*this, monthsNum); }

    static Date increaseDateByOneYear(Date date) {
        date._year++;
        date._day = minNum(date._day, daysInMonth(date._month, date._year));
        return date;
    }
    void increaseDateByOneYear() { *this = increaseDateByOneYear(*this); }

    static Date decreaseDateByOneYear(Date date) {
        date._year--;
        date._day = minNum(date._day, daysInMonth(date._month, date._year));
        return date;
    }
    void decreaseDateByOneYear() { *this = decreaseDateByOneYear(*this); }

    static Date increaseDateByXYear(Date date, short yearsNum) {
        date._year += yearsNum;
        date._day = minNum(date._day, daysInMonth(date._month, date._year));
        return date;
    }
    void increaseDateByXYear(short yearsNum) { *this = increaseDateByXYear(*this, yearsNum); }

    static Date decreaseDateByXYear(Date date, short yearsNum) {
        date._year -= yearsNum;
        date._day = minNum(date._day, daysInMonth(date._month, date._year));
        return date;
    }
    void decreaseDateByXYear(short yearsNum) { *this = decreaseDateByXYear(*this, yearsNum); }

    static Date increaseDateByOneDecade(Date date) { return increaseDateByXYear(date, 10); }
    void increaseDateByOneDecade() { *this = increaseDateByOneDecade(*this); }

    static Date decreaseDateByOneDecade(Date date) { return decreaseDateByXYear(date, 10); }
    void decreaseDateByOneDecade() { *this = decreaseDateByOneDecade(*this); }

    static Date increaseDateByXDecade(Date date, short decadesNum) { return increaseDateByXYear(date, decadesNum * 10); }
    void increaseDateByXDecade(short decadesNum) { *this = increaseDateByXDecade(*this, decadesNum); }

    static Date decreaseDateByXDecade(Date date, short decadesNum) { return decreaseDateByXYear(date, decadesNum * 10); }
    void decreaseDateByXDecade(short decadesNum) { *this = decreaseDateByXDecade(*this, decadesNum); }

    static Date increaseDateByOneCentury(Date date) { return increaseDateByXYear(date, 100); }
    void increaseDateByOneCentury() { *this = increaseDateByOneCentury(*this); }

    static Date decreaseDateByOneCentury(Date date) { return decreaseDateByXYear(date, 100); }
    void decreaseDateByOneCentury() { *this = decreaseDateByOneCentury(*this); }

    static Date increaseDateByOneMillennium(Date date) { return increaseDateByXYear(date, 1000); }
    void increaseDateByOneMillennium() { *this = increaseDateByOneMillennium(*this); }

    // ==========================================
    // --- Dates Differences & Comparisons ---
    // ==========================================

    static int differntBetweenToDates(Date currDate, Date bDate) {
        return dateToDays(currDate) - dateToDays(bDate);
    }
    int differntBetweenToDates(Date bDate) {
        return differntBetweenToDates(*this, bDate);
    }

    static int ageInDays(Date currDate, Date bDate) {
        return differntBetweenToDates(currDate, bDate);
    }
    int ageInDays(Date bDate) {
        return ageInDays(*this, bDate);
    }

    DateStatus compare(const Date& date2) const {
        if (*this == date2) return DateStatus::equal;
        if (*this > date2) return DateStatus::after;
        return DateStatus::before;
    }

    static DateStatus compareDates(Date date1, Date date2) {
        return date1.compare(date2);
    }

    // ==========================================
    // --- Vacations ---
    // ==========================================

    static short vacationDays(Date startDate, Date endDate) {
        short totDays = 0;
        while (!(startDate == endDate)) {
            if (isBusinessDay(startDate)) totDays++;
            startDate = increaseDateByOneDay(startDate);
        }
        return totDays;
    }
    short vacationDays(Date endDate) { return vacationDays(*this, endDate); }

    static Date getVacationEndDate(Date startDate, int vacationDays) {
        Date endDate = startDate;
        while (vacationDays > 0) {
            if (isBusinessDay(endDate)) vacationDays--;
            if (vacationDays) endDate = increaseDateByOneDay(endDate);
        }
        return endDate;
    }
    void getVacationEndDate(int vacationDays) { *this = getVacationEndDate(*this, vacationDays); }

    // ==========================================
    // --- String Formatting ---
    // ==========================================

    static string toString(const Date& date) {
        return to_string(date._day) + "/" + to_string(date._month) + "/" + to_string(date._year);
    }
    string toString() { return toString(*this); }

    static string formatDate(Date date, string format = "dd/mm/yyyy") {
        string formattedDateString = format;
        string day = (date._day < 10 ? "0" : "") + to_string(date._day);
        string month = (date._month < 10 ? "0" : "") + to_string(date._month);
        string year = to_string(date._year);

        formattedDateString = repl(formattedDateString, "yyyy", year);
        formattedDateString = repl(formattedDateString, "mm", month);
        formattedDateString = repl(formattedDateString, "dd", day);

        return formattedDateString;
    }
    string formatDate(string format = "dd/mm/yyyy") { return formatDate(*this, format); }

    void printDate() {
        cout << toString() << endl;
    }

    // ==========================================
    // --- Operator Overloading ---
    // ==========================================

    bool operator==(const Date& date) const {
        return _year == date._year && _month == date._month && _day == date._day;
    }

    bool operator<(const Date& date) const {
        if (_year != date._year) return _year < date._year;
        if (_month != date._month) return _month < date._month;
        return _day < date._day;
    }

    bool operator>(const Date& date) const {
        if (_year != date._year) return _year > date._year;
        if (_month != date._month) return _month > date._month;
        return _day > date._day;
    }

    bool operator>=(const Date& date) const {
        return (*this > date) || (*this == date);
    }

    bool operator<=(const Date& date) const {
        return (*this < date) || (*this == date);
    }
};