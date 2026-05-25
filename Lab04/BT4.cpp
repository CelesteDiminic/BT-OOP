#ifndef CDATE_H
#define CDATE_H
#include <iostream>

class CDate {
private:
    int ngay, thang, nam;
    bool IsNhuan(int y) const { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }
    int DaysInMonth(int m, int y) const {
        int d[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return (m == 2 && IsNhuan(y)) ? 29 : d[m];
    }
    long ToDays() const {
        long total = ngay;
        for (int y = 1; y < nam; ++y) total += IsNhuan(y) ? 366 : 365;
        for (int m = 1; m < thang; ++m) total += DaysInMonth(m, nam);
        return total;
    }
    void FromDays(long totalDays) {
        int y = 1;
        while (totalDays > (IsNhuan(y) ? 366 : 365)) { totalDays -= IsNhuan(y) ? 366 : 365; y++; }
        nam = y; int m = 1;
        while (totalDays > DaysInMonth(m, nam)) { totalDays -= DaysInMonth(m, nam); m++; }
        thang = m; ngay = totalDays;
    }
public:
    CDate(int d=1, int m=1, int y=1) : ngay(d), thang(m), nam(y) {}
    CDate operator+(int d) const { CDate res; res.FromDays(this->ToDays() + d); return res; }
    CDate operator-(int d) const { CDate res; res.FromDays(this->ToDays() - d); return res; }
    long operator-(const CDate& o) const { return this->ToDays() - o.ToDays(); }
    friend std::ostream& operator<<(std::ostream& os, const CDate& d) {
        os << d.ngay << "/" << d.thang << "/" << d.nam; return os;
    }
    friend std::istream& operator>>(std::istream& is, CDate& d) {
        is >> d.ngay >> d.thang >> d.nam; return is;
    }
};
#endif
