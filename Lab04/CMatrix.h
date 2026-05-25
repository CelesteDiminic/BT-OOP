#ifndef CMATRIX_H
#define CMATRIX_H
#include <iostream>
#include "CVector.h" // Nhúng thư viện Vector để tính tích ma trận - vector

class CMatrix {
private:
    int r, c; // r: rows (số dòng), c: cols (số cột)
    double** m; // Con trỏ 2 chiều biểu diễn ma trận

public:
    // Rule of Three
    CMatrix(int rows = 0, int cols = 0);
    CMatrix(const CMatrix& other);
    ~CMatrix();
    CMatrix& operator=(const CMatrix& other);

    // Toán tử toán học
    CMatrix operator+(const CMatrix& other) const;
    CMatrix operator-(const CMatrix& other) const;

    // Nhân 2 ma trận
    CMatrix operator*(const CMatrix& other) const;

    // Nhân ma trận với vector
    CVector operator*(const CVector& vec) const;

    // Toán tử xuất/nhập
    friend std::istream& operator>>(std::istream& is, CMatrix& mat);
    friend std::ostream& operator<<(std::ostream& os, const CMatrix& mat);
};

#endif
