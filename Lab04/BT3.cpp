#ifndef CTIME_H
#define CTIME_H
#include <iostream>
#include <iomanip>

class CTime {
private:
    int gio, phut, giay;
    void ChuanHoa() {
        if (giay >= 60) { phut += giay / 60; giay %= 60; }
        while (giay < 0) { giay += 60; phut--; }
        if (phut >= 60) { gio += phut / 60; phut %= 60; }
        while (phut < 0) { phut += 60; gio--; }
        gio = (gio % 24 + 24) % 24;
    }
public:
    CTime(int h=0, int m=0, int s=0) : gio(h), phut(m), giay(s) { ChuanHoa(); }
    CTime operator+(int s) const { return CTime(gio, phut, giay + s); }
    CTime operator-(int s) const { return CTime(gio, phut, giay - s); }
    CTime& operator++() { giay++; ChuanHoa(); return *this; }
    CTime operator++(int) { CTime temp = *this; ++(*this); return temp; }
    CTime& operator--() { giay--; ChuanHoa(); return *this; }
    CTime operator--(int) { CTime temp = *this; --(*this); return temp; }
    friend std::ostream& operator<<(std::ostream& os, const CTime& t) {
        os << std::setfill('0') << std::setw(2) << t.gio << ":"
           << std::setw(2) << t.phut << ":" << std::setw(2) << t.giay;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, CTime& t) {
        is >> t.gio >> t.phut >> t.giay; t.ChuanHoa(); return is;
    }
};
