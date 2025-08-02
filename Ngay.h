#pragma once

#include <iostream>
#include <iomanip>

class Ngay {
private:
    int day;
    int month;
    int year;

public:
    // Constructors
    Ngay();
    Ngay(int d, int m, int y);

    // Destructor
    ~Ngay();

    // Getter methods
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Setter methods
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    // Utility methods
    bool isValidDate() const;
    void display() const;
    std::string toString() const;

    // Friend functions for input/output
    friend std::istream& operator>>(std::istream& is, Ngay& date);
    friend std::ostream& operator<<(std::ostream& os, const Ngay& date);
};

