#ifndef DATHUC_H
#define DATHUC_H
#include <iostream>

class DaThuc {
private:
    int bac;
    double* heSo; // Cấp phát động để biểu diễn bậc bất kỳ

public:
    // Cấu trúc ba hàm cơ bản (Rule of Three) cho con trỏ động
    DaThuc(int b = 0);
    DaThuc(const DaThuc& other);
    ~DaThuc();
    DaThuc& operator=(const DaThuc& other);

    // Toán tử toán học
    DaThuc operator+(const DaThuc& other) const;
    DaThuc operator-(const DaThuc& other) const;
    DaThuc operator*(const DaThuc& other) const;

    // Tính giá trị đa thức tại x
    double Tinh(double x) const;

    // Toán tử xuất/nhập
    friend std::istream& operator>>(std::istream& is, DaThuc& dt);
    friend std::ostream& operator<<(std::ostream& os, const DaThuc& dt);
};

#endif
