/*
 classDiagram
     class SoPhuc {
         -float iThuc
         -float iAo
         +Nhap() void
         +Xuat() void
         +Tong(SoPhuc) SoPhuc
         +Hieu(SoPhuc) SoPhuc
         +Tich(SoPhuc) SoPhuc
         +Thuong(SoPhuc) SoPhuc
     }
*/
#include <iostream>
using namespace std;

class SoPhuc {
private:
    float iThuc, iAo;

public:
    void Nhap() {
        cout << "Nhap phan thuc va phan ao: ";
        cin >> iThuc >> iAo;
    }

    void Xuat() {
        if (iAo >= 0) cout << iThuc << " + " << iAo << "i" << endl;
        else cout << iThuc << " - " << -iAo << "i" << endl;
    }

    SoPhuc Tong(SoPhuc sp) {
        SoPhuc kq;
        kq.iThuc = this->iThuc + sp.iThuc;
        kq.iAo = this->iAo + sp.iAo;
        return kq;
    }

    SoPhuc Hieu(SoPhuc sp) {
        SoPhuc kq;
        kq.iThuc = this->iThuc - sp.iThuc;
        kq.iAo = this->iAo - sp.iAo;
        return kq;
    }

    SoPhuc Tich(SoPhuc sp) {
        SoPhuc kq;
        // (a + bi)(c + di) = (ac - bd) + (ad + bc)i
        kq.iThuc = this->iThuc * sp.iThuc - this->iAo * sp.iAo;
        kq.iAo = this->iThuc * sp.iAo + this->iAo * sp.iThuc;
        return kq;
    }

    SoPhuc Thuong(SoPhuc sp) {
        SoPhuc kq;
        // (a + bi)/(c + di) = [(ac + bd) + (bc - ad)i] / (c^2 + d^2)
        float mauSo = sp.iThuc * sp.iThuc + sp.iAo * sp.iAo;
        if (mauSo == 0) {
            cout << "Loi chia cho 0!" << endl;
            kq.iThuc = 0; kq.iAo = 0;
            return kq;
        }
        kq.iThuc = (this->iThuc * sp.iThuc + this->iAo * sp.iAo) / mauSo;
        kq.iAo = (this->iAo * sp.iThuc - this->iThuc * sp.iAo) / mauSo;
        return kq;
    }
};

int main() {
    SoPhuc sp1, sp2;
    cout << "--- Bai 3: So Phuc ---\n";
    cout << "So phuc 1:\n"; sp1.Nhap();
    cout << "So phuc 2:\n"; sp2.Nhap();

    cout << "\nTong: "; sp1.Tong(sp2).Xuat();
    cout << "Hieu: "; sp1.Hieu(sp2).Xuat();
    cout << "Tich: "; sp1.Tich(sp2).Xuat();
    cout << "Thuong: "; sp1.Thuong(sp2).Xuat();

    return 0;
}
