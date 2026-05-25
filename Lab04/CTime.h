#ifndef CTIME_H
#define CTIME_H
#include <iostream>

class CTime {
private:
    int gio, phut, giay;
    void ChuanHoa();

public:
    CTime(int h = 0, int m = 0, int s = 0);

    // Cộng/trừ với số nguyên giây
    CTime operator+(int s) const;
    CTime operator-(int s) const;

    // Toán tử thêm/bớt 1 giây (Tiền tố và Hậu tố)
    CTime& operator++();       // Tiền tố (++time)
    CTime operator++(int);     // Hậu tố (time++)
    CTime& operator--();       // Tiền tố (--time)
    CTime operator--(int);     // Hậu tố (time--)

    // Toán tử xuất/nhập
    friend std::istream& operator>>(std::istream& is, CTime& t);
    friend std::ostream& operator<<(std::ostream& os, const CTime& t);
};

#endif
