/* Mô tả class
 classDiagram
     class PhanSo {
         -int iTu
         -int iMau
         +Nhap() void
         +Xuat() void
         +RutGon() void
         +Tong(PhanSo) PhanSo
         +Hieu(PhanSo) PhanSo
         +Tich(PhanSo) PhanSo
         +Thuong(PhanSo) PhanSo
         +SoSanh(PhanSo) int
         -TimUCLN(int, int) int
     }
 */

#include <iostream>
#include <cmath>
using namespace std;

class PhanSo {
private:
    int iTu, iMau;

    int TimUCLN(int a, int b) {
        a = abs(a); b = abs(b);
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

public:
    void Nhap() {
        cout << "Nhap tu so va mau so: ";
        cin >> iTu >> iMau;
        while (iMau == 0) {
            cout << "Mau so phai khac 0. Nhap lai mau so: ";
            cin >> iMau;
        }
    }

    void RutGon() {
        int ucln = TimUCLN(iTu, iMau);
        iTu /= ucln;
        iMau /= ucln;
        if (iMau < 0) { // Đẩy dấu trừ lên tử số
            iTu = -iTu;
            iMau = -iMau;
        }
    }

    void Xuat() {
        RutGon();
        if (iMau == 1 || iTu == 0) cout << iTu << endl;
        else cout << iTu << "/" << iMau << endl;
    }

    PhanSo Tong(PhanSo ps) {
        PhanSo kq;
        kq.iTu = this->iTu * ps.iMau + ps.iTu * this->iMau;
        kq.iMau = this->iMau * ps.iMau;
        kq.RutGon();
        return kq;
    }

    PhanSo Hieu(PhanSo ps) {
        PhanSo kq;
        kq.iTu = this->iTu * ps.iMau - ps.iTu * this->iMau;
        kq.iMau = this->iMau * ps.iMau;
        kq.RutGon();
        return kq;
    }

    PhanSo Tich(PhanSo ps) {
        PhanSo kq;
        kq.iTu = this->iTu * ps.iTu;
        kq.iMau = this->iMau * ps.iMau;
        kq.RutGon();
        return kq;
    }

    PhanSo Thuong(PhanSo ps) {
        PhanSo kq;
        kq.iTu = this->iTu * ps.iMau;
        kq.iMau = this->iMau * ps.iTu;
        kq.RutGon();
        return kq;
    }

    int SoSanh(PhanSo ps) {
        // Trả về 1 nếu lớn hơn, -1 nếu nhỏ hơn, 0 nếu bằng
        float val1 = (float)iTu / iMau;
        float val2 = (float)ps.iTu / ps.iMau;
        if (val1 > val2) return 1;
        if (val1 < val2) return -1;
        return 0;
    }
};

int main() {
    PhanSo ps1, ps2;
    cout << "--- Bai 2: Phan So ---\n";
    cout << "Phan so 1:\n"; ps1.Nhap();
    cout << "Phan so 2:\n"; ps2.Nhap();

    cout << "\nTong: "; ps1.Tong(ps2).Xuat();
    cout << "Hieu: "; ps1.Hieu(ps2).Xuat();
    cout << "Tich: "; ps1.Tich(ps2).Xuat();
    cout << "Thuong: "; ps1.Thuong(ps2).Xuat();

    int ss = ps1.SoSanh(ps2);
    if (ss == 1) cout << "Phan so 1 > Phan so 2\n";
    else if (ss == -1) cout << "Phan so 1 < Phan so 2\n";
    else cout << "Hai phan so bang nhau\n";

    return 0;
}
