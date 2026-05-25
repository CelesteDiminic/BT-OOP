#ifndef CVECTOR_H
#define CVECTOR_H
#include <iostream>

class CVector {
private:
    int n;
    double* v;
public:
    CVector(int size = 0) : n(size) { v = new double[n](); }
    CVector(const CVector& o) : n(o.n) {
        v = new double[n]; for (int i = 0; i < n; ++i) v[i] = o.v[i];
    }
    ~CVector() { delete[] v; }
    CVector& operator=(const CVector& o) {
        if (this != &o) {
            delete[] v; n = o.n; v = new double[n];
            for (int i = 0; i < n; ++i) v[i] = o.v[i];
        }
        return *this;
    }
    int GetN() const { return n; }
    double Get(int i) const { return v[i]; }
    void Set(int i, double val) { v[i] = val; }

    CVector operator+(const CVector& o) const {
        CVector res(n); for (int i = 0; i < n; ++i) res.v[i] = v[i] + o.v[i];
        return res;
    }
    double operator*(const CVector& o) const {
        double dot = 0; for (int i = 0; i < n; ++i) dot += v[i] * o.v[i];
        return dot;
    }
    friend std::ostream& operator<<(std::ostream& os, const CVector& vec) {
        os << "("; for (int i = 0; i < vec.n; ++i) os << vec.v[i] << (i == vec.n-1 ? "" : ", ");
        os << ")"; return os;
    }
    friend std::istream& operator>>(std::istream& is, CVector& vec) {
        for (int i = 0; i < vec.n; ++i) is >> vec.v[i]; return is;
    }
};
#endif
