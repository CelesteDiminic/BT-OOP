#ifndef CVECTOR_H
#define CVECTOR_H
#include <iostream>

class CVector {
private:
    int n; // Số chiều
    double* v; // Các thành phần vector

public:
    // Rule of Three
    CVector(int size = 0);
    CVector(const CVector& other);
    ~CVector();
    CVector& operator=(const CVector& other);

    // Getters / Setters
    int GetN() const;
    double Get(int i) const;
    void Set(int i, double val);

    // Toán tử toán học
    CVector operator+(const CVector& other) const;
    CVector operator-(const CVector& other) const;
    
    // Tích vô hướng (trả về 1 số thực)
    double operator*(const CVector& other) const;

    // Toán tử xuất/nhập
    friend std::istream& operator>>(std::istream& is, CVector& vec);
    friend std::ostream& operator<<(std::ostream& os, const CVector& vec);
};

#endif
