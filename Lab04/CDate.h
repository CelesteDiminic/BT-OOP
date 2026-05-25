#ifndef CDATE_H
#define CDATE_H
#include <iostream>

class CDate {
private:
    int ngay, thang, nam;

    bool IsNhuan(int y) const;
    int DaysInMonth(int m, int y) const;
    long ToDays() const;
    void FromDays(long totalDays);

public:
    CDate(int d = 1, int m = 1, int y = 1);

    // Cộng/trừ với số nguyên ngày
    CDate operator+(int d) const;
    CDate operator-(int d) const;
    
    // Khoảng cách giữa 2 ngày (tính bằng ngày)
    long operator-(const CDate& other) const;

    // Toán tử thêm/bớt 1 ngày (Tiền tố và Hậu tố)
    CDate& operator++();
    CDate operator++(int);
    CDate& operator--();
    CDate operator--(int);

    // Toán tử xuất/nhập
    friend std::istream& operator>>(std::istream& is, CDate& d);
    friend std::ostream& operator<<(std::ostream& os, const CDate& d);
};

#endif
