#include "Ngay.h"
#include <sstream>
#pragma execution_character_set( "utf-8" )

// Default constructor
Ngay::Ngay() {
    day = 1;
    month = 1;
    year = 2024;
}

//  constructor
Ngay::Ngay(int d, int m, int y) {
    setDay(d);
    setMonth(m);
    setYear(y);
}

// Destructor
Ngay::~Ngay() {
    // No dynamic memory to clean up
}

// Getter
int Ngay::getDay() const {
    return day;
}

int Ngay::getMonth() const {
    return month;
}

int Ngay::getYear() const {
    return year;
}

// Setter methods with validation
void Ngay::setDay(int d) {
    if (d >= 1 && d <= 31) {
        day = d;
    }
    else {
        day = 1;
    }
}

void Ngay::setMonth(int m) {
    if (m >= 1 && m <= 12) {
        month = m;
    }
    else {
        month = 1;
    }
}

void Ngay::setYear(int y) {
    if (y >= 1900) {
        year = y;
    }
    else {
        year = 2024;
    }
}

// Check if date is valid
bool Ngay::isValidDate() const {
    if (month < 1 || month > 12) return false;
    if (day < 1) return false;

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Check for leap year
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        daysInMonth[1] = 29;
    }

    return day <= daysInMonth[month - 1];
}

// Display date
void Ngay::display() const {
    std::cout << std::setfill('0') << std::setw(2) << day << "/"
        << std::setw(2) << month << "/" << year;
}

// Convert to string
std::string Ngay::toString() const {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << day << "/"
        << std::setw(2) << month << "/" << year;
    return oss.str();
}

// Input operator
std::istream& operator>>(std::istream& is, Ngay& date) {
    int d, m, y;
    char slash1, slash2;
    is >> d >> slash1 >> m >> slash2 >> y;
    date.setDay(d);
    date.setMonth(m);
    date.setYear(y);
    return is;
}

// Output operator
std::ostream& operator<<(std::ostream& os, const Ngay& date) {
    os << std::setfill('0') << std::setw(2) << date.day << "/"
        << std::setw(2) << date.month << "/" << date.year;
    return os;
}
