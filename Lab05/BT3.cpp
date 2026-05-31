#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SinhVien {
protected:
    string MSSV, HoTen, DiaChi;
    int TongTinChi;
    double DTB;
public:
    virtual void Nhap() {
        cin.ignore();
        cout << "Nhap MSSV: "; getline(cin, MSSV);
        cout << "Nhap Ho ten: "; getline(cin, HoTen);
        cout << "Nhap Dia chi: "; getline(cin, DiaChi);
        cout << "Tong tin chi: "; cin >> TongTinChi;
        cout << "DTB: "; cin >> DTB;
    }
    virtual void Xuat() {
        cout << "MSSV: " << MSSV << " | Ho ten: " << HoTen << " | DTB: " << DTB;
    }
    virtual bool KiemTraTotNghiep() = 0;
    double getDTB() { return DTB; }
    virtual string getLoai() = 0;
};

class SinhVienCD : public SinhVien {
private:
    double DiemThiTotNghiep;
public:
    void Nhap() override {
        SinhVien::Nhap();
        cout << "Diem thi tot nghiep: "; cin >> DiemThiTotNghiep;
    }
    void Xuat() override { SinhVien::Xuat(); cout << " | He: Cao Dang\n"; }
    bool KiemTraTotNghiep() override {
        return (TongTinChi >= 120 && DTB >= 5 && DiemThiTotNghiep >= 5);
    }
    string getLoai() override { return "CD"; }
};

class SinhVienDH : public SinhVien {
private:
    string TenLuanVan;
    double DiemLuanVan;
public:
    void Nhap() override {
        SinhVien::Nhap();
        cin.ignore();
        cout << "Ten luan van: "; getline(cin, TenLuanVan);
        cout << "Diem luan van: "; cin >> DiemLuanVan;
    }
    void Xuat() override { SinhVien::Xuat(); cout << " | He: Dai hoc\n"; }
    bool KiemTraTotNghiep() override {
        return (TongTinChi >= 170 && DTB >= 5 && DiemLuanVan >= 5);
    }
    string getLoai() override { return "DH"; }
};
