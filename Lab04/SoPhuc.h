#ifndef SOPHUC_H
#define SOPHUC_H
#include <iostream>

class SoPhuc {
private:
    double thuc, ao;

public:
    // Phương thức thiết lập duy nhất với tham số mặc định
    SoPhuc(double thuc = 0, double ao = 0);

    // Toán tử toán học
    SoPhuc operator+(const SoPhuc& other) const;
    SoPhuc operator-(const SoPhuc& other) const;
    SoPhuc operator*(const SoPhuc& other) const;
    SoPhuc operator/(const SoPhuc& other) const;

    // Toán tử so sánh
    bool operator==(const SoPhuc& other) const;
    bool operator!=(const SoPhuc& other) const;

    // Toán tử xuất/nhập
    friend std::istream& operator>>(std::istream& is, SoPhuc& sp);
    friend std::ostream& operator<<(std::ostream& os, const SoPhuc& sp);
};

#endif//

