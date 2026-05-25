#ifndef DATHUC_H
#define DATHUC_H
#include <iostream>
#include <cmath>

class DaThuc {
private:
    int bac;
    double* heSo;
public:
    DaThuc(int b = 0) : bac(b) {
        heSo = new double[bac + 1]();
    }
    DaThuc(const DaThuc& o) : bac(o.bac) {
        heSo = new double[bac + 1];
        for (int i = 0; i <= bac; ++i) heSo[i] = o.heSo[i];
    }
    ~DaThuc() { delete[] heSo; }
    DaThuc& operator=(const DaThuc& o) {
        if (this != &o) {
            delete[] heSo; bac = o.bac;
            heSo = new double[bac + 1];
            for (int i = 0; i <= bac; ++i) heSo[i] = o.heSo[i];
        }
        return *this;
    }
    DaThuc operator+(const DaThuc& o) const {
        int maxBac = std::max(bac, o.bac); DaThuc res(maxBac);
        for (int i = 0; i <= maxBac; ++i) {
            double a = (i <= bac) ? heSo[i] : 0;
            double b = (i <= o.bac) ? o.heSo[i] : 0;
            res.heSo[i] = a + b;
        }
        return res;
    }
    double Tinh(double x) const {
        double val = 0;
        for (int i = 0; i <= bac; ++i) val += heSo[i] * std::pow(x, i);
        return val;
    }
    friend std::ostream& operator<<(std::ostream& os, const DaThuc& dt) {
        for (int i = dt.bac; i >= 0; --i) {
            if (dt.heSo[i] != 0) {
                os << (dt.heSo[i] > 0 && i != dt.bac ? " + " : " ") << dt.heSo[i];
                if (i > 0) os << "x^" << i;
            }
        }
        return os;
    }
    friend std::istream& operator>>(std::istream& is, DaThuc& dt) {
        for (int i = 0; i <= dt.bac; ++i) {
            std::cout << "He so bac " << i << ": "; is >> dt.heSo[i];
        }
        return is;
    }
};
#endif
