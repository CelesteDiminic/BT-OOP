#ifndef PHANSO_H
#define PHANSO_H
#include <iostream>
#include <cmath>

class PhanSo {
private:
    int iTu, iMau;
    int UCLN(int a, int b) const { return b == 0 ? std::abs(a) : UCLN(b, a % b); }
    void RutGon() {
        int u = UCLN(iTu, iMau); iTu /= u; iMau /= u;
        if (iMau < 0) { iTu = -iTu; iMau = -iMau; }
    }
public:
    PhanSo(int tu = 0, int mau = 1) : iTu(tu), iMau(mau) { RutGon(); }
    PhanSo operator+(const PhanSo& o) const { return PhanSo(iTu*o.iMau + o.iTu*iMau, iMau*o.iMau); }
    PhanSo operator-(const PhanSo& o) const { return PhanSo(iTu*o.iMau - o.iTu*iMau, iMau*o.iMau); }
    PhanSo operator*(const PhanSo& o) const { return PhanSo(iTu*o.iTu, iMau*o.iMau); }
    PhanSo operator/(const PhanSo& o) const { return PhanSo(iTu*o.iMau, iMau*o.iTu); }
    bool operator>(const PhanSo& o) const { return (iTu*o.iMau - o.iTu*iMau) > 0; }
    bool operator<(const PhanSo& o) const { return (iTu*o.iMau - o.iTu*iMau) < 0; }
    bool operator==(const PhanSo& o) const { return iTu == o.iTu && iMau == o.iMau; }
    friend std::ostream& operator<<(std::ostream& os, const PhanSo& ps) {
        os << ps.iTu; if (ps.iMau != 1 && ps.iTu != 0) os << "/" << ps.iMau;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, PhanSo& ps) {
        is >> ps.iTu >> ps.iMau; ps.RutGon(); return is;
    }
};
