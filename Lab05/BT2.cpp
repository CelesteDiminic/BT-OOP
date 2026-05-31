#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GiaoDich {
protected:
    string MaGD, NgayGD;
    double DonGia, DienTich, ThanhTien;
public:
    virtual void Nhap() {
        cin.ignore();
        cout << "Nhap Ma GD: "; getline(cin, MaGD);
        cout << "Nhap Ngay GD (dd/mm/yyyy): "; getline(cin, NgayGD);
        cout << "Nhap Don Gia: "; cin >> DonGia;
        cout << "Nhap Dien Tich: "; cin >> DienTich;
    }
    virtual void Xuat() {
        cout << "Ma GD: " << MaGD << " | Ngay: " << NgayGD << " | Dien tich: " << DienTich << " | Thanh Tien: " << ThanhTien << endl;
    }
    virtual void TinhThanhTien() = 0;
    string getNgayGD() { return NgayGD; }
    double getThanhTien() { return ThanhTien; }
    virtual string getLoai() = 0;
};

class GiaoDichDat : public GiaoDich {
private:
    string LoaiDat;
public:
    void Nhap() override {
        GiaoDich::Nhap();
        cout << "Nhap Loai Dat (A/B/C): "; cin >> LoaiDat;
    }
    void TinhThanhTien() override {
        if (LoaiDat == "A") ThanhTien = DienTich * DonGia * 1.5;
        else ThanhTien = DienTich * DonGia;
    }
    string getLoai() override { return "Dat"; }
};

class GiaoDichNhaPho : public GiaoDich {
private:
    string LoaiNha, DiaChi;
public:
    void Nhap() override {
        GiaoDich::Nhap();
        cin.ignore();
        cout << "Nhap Loai Nha (cao cap/thuong): "; getline(cin, LoaiNha);
        cout << "Nhap Dia Chi: "; getline(cin, DiaChi);
    }
    void TinhThanhTien() override {
        if (LoaiNha == "cao cap") ThanhTien = DienTich * DonGia;
        else ThanhTien = DienTich * DonGia * 0.9;
    }
    string getLoai() override { return "NhaPho"; }
};

class GiaoDichChungCu : public GiaoDich {
private:
    string MaCan;
    int ViTriTang;
public:
    void Nhap() override {
        GiaoDich::Nhap();
        cout << "Nhap Vi Tri Tang: "; cin >> ViTriTang;
    }
    void TinhThanhTien() override {
        if (ViTriTang == 1) ThanhTien = DienTich * DonGia * 2;
        // Tang >= 15 giam hoặc tăng theo đề bài quy định hệ số 1.2
        else if (ViTriTang >= 15) ThanhTien = DienTich * DonGia * 1.2;
        else ThanhTien = DienTich * DonGia;
    }
    string getLoai() override { return "ChungCu"; }
};
