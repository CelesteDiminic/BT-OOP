#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NhanVienHC {
protected:
    string MaNV, HoTen, Email;
    int Tuoi;
    double LuongCoBan, LuongThuc;
public:
    virtual void Nhap() {
        cin.ignore();
        cout << "Ma NV: "; getline(cin, MaNV);
        cout << "Ho ten: "; getline(cin, HoTen);
        cout << "Email: "; getline(cin, Email);
        cout << "Tuoi: "; cin >> Tuoi;
        cout << "Luong co ban: "; cin >> LuongCoBan;
    }
    virtual void TinhLuong() = 0;
    virtual void Xuat() {
        cout << "Ma: " << MaNV << " | Ten: " << HoTen << " | Luong thuc nhan: " << LuongThuc << endl;
    }
    double getLuong() { return LuongThuc; }
};

class LapTrinhVien : public NhanVienHC {
private:
    int SoGioOvertime;
public:
    void Nhap() override {
        NhanVienHC::Nhap();
        cout << "So gio overtime: "; cin >> SoGioOvertime;
    }
    void TinhLuong() override {
        LuongThuc = LuongCoBan + SoGioOvertime * 200000;
    }
};

class KiemChungVien : public NhanVienHC {
private:
    int SoLoi;
public:
    void Nhap() override {
        NhanVienHC::Nhap();
        cout << "So loi: "; cin >> SoLoi;
    }
    void TinhLuong() override {
        LuongThuc = LuongCoBan + SoLoi * 50000;
    }
};
