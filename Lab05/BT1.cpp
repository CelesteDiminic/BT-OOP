#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class NhanVien {
protected:
    string HoTen;
    string NgaySinh;
    double Luong;
public:
    NhanVien() : Luong(0) {}
    virtual ~NhanVien() {}
    
    virtual void Nhap() {
        cin.ignore();
        cout << "Nhap ho ten: "; getline(cin, HoTen);
        cout << "Nhap ngay sinh (dd/mm/yyyy): "; getline(cin, NgaySinh);
    }
    
    virtual void Xuat() {
        cout << "Ho ten: " << HoTen << " | Ngay sinh: " << NgaySinh << " | Luong: " << Luong;
    }
    
    virtual void TinhLuong() = 0;
    double getLuong() { return Luong; }
    string getNgaySinh() { return NgaySinh; }
};

class NVSanXuat : public NhanVien {
private:
    double LuongCanBan;
    int SoSanPham;
public:
    void Nhap() override {
        NhanVien::Nhap();
        cout << "Nhap luong can ban: "; cin >> LuongCanBan;
        cout << "Nhap so san pham: "; cin >> SoSanPham;
    }
    void TinhLuong() override {
        Luong = LuongCanBan + SoSanPham * 5000;
    }
    void Xuat() override {
        NhanVien::Xuat(); cout << " [San Xuat]" << endl;
    }
};

class NVVanPhong : public NhanVien {
private:
    int SoNgayLamViec;
public:
    void Nhap() override {
        NhanVien::Nhap();
        cout << "Nhap so ngay lam viec: "; cin >> SoNgayLamViec;
    }
    void TinhLuong() override {
        Luong = SoNgayLamViec * 100000;
    }
    void Xuat() override {
        NhanVien::Xuat(); cout << " [Van Phong]" << endl;
    }
};
