#include <iostream>
#include <cmath>
using namespace std;

// Hàm tìm UCLN để rút gọn phân số
int timUCLN(int a, int b) {
    a = abs(a); b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

struct PhanSo {
    int tu, mau;

    void nhap() {
        cout << "Nhap tu so: "; cin >> tu;
        do {
            cout << "Nhap mau so (khac 0): "; cin >> mau;
            if (mau == 0) cout << "Mau so phai khac 0. Vui long nhap lai!\n";
        } while (mau == 0);
    }

    void rutGon() {
        if (tu == 0) {
            mau = 1;
            return;
        }
        int ucln = timUCLN(tu, mau);
        tu /= ucln;
        mau /= ucln;
        // Đẩy dấu trừ lên tử số nếu mẫu âm
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }

    void xuat() {
        if (mau == 1) cout << tu;
        else if (tu == 0) cout << 0;
        else cout << tu << "/" << mau;
    }
};

// Bài 2: Tìm phân số lớn nhất
PhanSo timMax(PhanSo ps1, PhanSo ps2) {
    if (ps1.tu * ps2.mau > ps2.tu * ps1.mau) return ps1;
    return ps2;
}

// Bài 3: Các phép tính
PhanSo cong(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    kq.rutGon();
    return kq;
}

PhanSo tru(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    kq.rutGon();
    return kq;
}

PhanSo nhan(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.tu;
    kq.mau = ps1.mau * ps2.mau;
    kq.rutGon();
    return kq;
}

PhanSo chia(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.mau;
    kq.mau = ps1.mau * ps2.tu;
    kq.rutGon();
    return kq;
}

int main() {
    PhanSo ps1, ps2;

    cout << "Vui long nhap dung du lieu de co ket qua dung va khong bi loi chuong trinh"<< endl;
    cout << "=== NHAP PHAN SO 1 ===" << endl;
    ps1.nhap();
    ps1.rutGon();

    cout << "\n=== NHAP PHAN SO 2 ===" << endl;
    ps2.nhap();
    ps2.rutGon();

    // Bài 1: Xuất phân số đã rút gọn
    cout << "\n--- BAI 1: RUT GON PHAN SO ---" << endl;
    cout << "Phan so 1 sau khi rut gon: "; ps1.xuat(); cout << endl;
    cout << "Phan so 2 sau khi rut gon: "; ps2.xuat(); cout << endl;

    // Bài 2: Tìm phân số lớn nhất
    cout << "\n--- BAI 2: TIM PHAN SO LON NHAT ---" << endl;
    PhanSo psMax = timMax(ps1, ps2);
    cout << "Phan so lon nhat la: "; psMax.xuat(); cout << endl;

    // Bài 3: Tính toán
    cout << "\n--- BAI 3: TINH TONG, HIEU, TICH, THUONG ---" << endl;
    cout << "Tong = "; cong(ps1, ps2).xuat(); cout << endl;
    cout << "Hieu = "; tru(ps1, ps2).xuat(); cout << endl;
    cout << "Tich = "; nhan(ps1, ps2).xuat(); cout << endl;
    cout << "Thuong = "; chia(ps1, ps2).xuat(); cout << endl;

    return 0;
}
