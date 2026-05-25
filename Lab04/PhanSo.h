#ifndef PHANSO_H
#define PHANSO_H
#include <iostream>

class PhanSo {
private:
    int iTu, iMau;
    
    int UCLN(int a, int b) const;
    void RutGon();

public:
    // Phương thức thiết lập duy nhất (sử dụng số nguyên như phân số có mẫu = 1)
    PhanSo(int tu = 0, int mau = 1);

    // Toán tử toán học
    PhanSo operator+(const PhanSo& other) const;
    PhanSo operator-(const PhanSo& other) const;
    PhanSo operator*(const PhanSo& other) const;
    PhanSo operator/(const PhanSo& other) const;

    // Toán tử so sánh
    bool operator>(const PhanSo& other) const;
    bool operator<(const PhanSo& other) const;
    bool operator==(const PhanSo& other) const;

    // Toán tử xuất/nhập
    friend std::istream& operator>>(std::istream& is, PhanSo& ps);
    friend std::ostream& operator<<(std::ostream& os, const PhanSo& ps);
};

#endif
