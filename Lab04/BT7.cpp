#ifndef CMATRIX_H
#define CMATRIX_H
#include <iostream>
#include "CVector.h"

class CMatrix {
private:
    int r, c;
    double** m;
public:
    CMatrix(int rows = 0, int cols = 0) : r(rows), c(cols) {
        m = new double*[r]; for (int i = 0; i < r; ++i) m[i] = new double[c]();
    }
    CMatrix(const CMatrix& o) : r(o.r), c(o.c) {
        m = new double*[r];
        for (int i = 0; i < r; ++i) {
            m[i] = new double[c];
            for (int j = 0; j < c; ++j) m[i][j] = o.m[i][j];
        }
    }
    ~CMatrix() { for (int i = 0; i < r; ++i) delete[] m[i]; delete[] m; }
    CMatrix& operator=(const CMatrix& o) {
        if (this != &o) {
            for (int i = 0; i < r; ++i) delete[] m[i]; delete[] m;
            r = o.r; c = o.c; m = new double*[r];
            for (int i = 0; i < r; ++i) {
                m[i] = new double[c];
                for (int j = 0; j < c; ++j) m[i][j] = o.m[i][j];
            }
        }
        return *this;
    }
    CVector operator*(const CVector& vec) const {
        CVector res(r);
        for (int i = 0; i < r; ++i) {
            double sum = 0; for (int j = 0; j < c; ++j) sum += m[i][j] * vec.Get(j);
            res.Set(i, sum);
        }
        return res;
    }
    CMatrix operator*(const CMatrix& o) const {
        CMatrix res(r, o.c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < o.c; ++j) {
                for (int k = 0; k < c; ++k) res.m[i][j] += m[i][k] * o.m[k][j];
            }
        }
        return res;
    }
    friend std::ostream& operator<<(std::ostream& os, const CMatrix& mat) {
        for (int i = 0; i < mat.r; ++i) {
            for (int j = 0; j < mat.c; ++j) os << mat.m[i][j] << " ";
            os << "\n";
        }
        return os;
    }
    friend std::istream& operator>>(std::istream& is, CMatrix& mat) {
        for (int i = 0; i < mat.r; ++i)
            for (int j = 0; j < mat.c; ++j) is >> mat.m[i][j];
        return is;
    }
};
#endif
