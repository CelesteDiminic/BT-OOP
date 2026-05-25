#ifndef SOPHUC_H
#define SOPHUC_H
#include <iostream>

class SoPhuc {
private:
    double thuc, ao;
public:
    SoPhuc(double thuc = 0, double ao = 0) : thuc(thuc), ao(ao) {}
    SoPhuc operator+(const SoPhuc& o) const { return SoPhuc(thuc + o.thuc, ao + o.ao); }
    SoPhuc operator-(const SoPhuc& o) const { return SoPhuc(thuc - o.thuc, ao - o.ao); }
    SoPhuc operator*(const SoPhuc& o) const { return SoPhuc(thuc*o.thuc - ao*o.ao, thuc*o.ao + ao*o.thuc); }
    SoPhuc operator/(const SoPhuc& o) const {
        double m = o.thuc*o.thuc + o.ao*o.ao;
        return SoPhuc((thuc*o.thuc + ao*o.ao)/m, (ao*o.thuc - thuc*o.ao)/m);
    }
    bool operator==(const SoPhuc& o) const { return thuc == o.thuc && ao == o.ao; }
    bool operator!=(const SoPhuc& o) const { return !(*this == o); }
    friend std::ostream& operator<<(std::ostream& os, const SoPhuc& sp) {
        os << sp.thuc << (sp.ao >= 0 ? " + " : " - ") << std::abs(sp.ao) << "i";
        return os;
    }
    friend std::istream& operator>>(std::istream& is, SoPhuc& sp) {
        is >> sp.thuc >> sp.ao; return is;
    }
};
