#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

class KhachHang {
protected:
    string TenKhachHang;
    double SoLuong;
    double DonGia;
    double SoTienPhaiTra;
public:
    virtual ~KhachHang() {}
    
    virtual void DocFile(ifstream& in) {
        getline(in, TenKhachHang);
        in >> SoLuong >> DonGia;
        in.ignore();
    }
    
    virtual void TinhTien() = 0;
    
    virtual void GhiFile(ofstream& out) {
        out << TenKhachHang << endl;
        out << fixed << setprecision(0) << SoTienPhaiTra << endl;
    }
    
    double getSoTienPhaiTra() { return SoTienPhaiTra; }
};

class KhachHangA : public KhachHang {
public:
    void TinhTien() override {
        double tienHang = SoLuong * DonGia;
        SoTienPhaiTra = tienHang * 1.1; // Thêm 10% VAT
    }
};

class KhachHangB : public KhachHang {
private:
    int SoNamThanThiet;
public:
    void DocFile(ifstream& in) override {
        KhachHang::DocFile(in);
        in >> SoNamThanThiet;
        in.ignore();
    }
    void TinhTien() override {
        double phanTramKM = max(SoNamThanThiet * 0.05, 0.50);
        double tienHangTruocThue = (SoLuong * DonGia) * (1.0 - phanTramKM);
        SoTienPhaiTra = tienHangTruocThue * 1.1;
    }
};

class KhachHangC : public KhachHang {
public:
    void TinhTien() override {
        double tienHangTruocThue = (SoLuong * DonGia) * 0.5;
        SoTienPhaiTra = tienHangTruocThue * 1.1;
    }
};

int main() {
    ifstream inFile("XYZ.INP");
    ofstream outFile("XYZ.OUT");
    
    if (!inFile) {
        cout << "Loi: Khong tim thay file XYZ.INP!" << endl;
        return 1;
    }
    
    int x, y, z;
    inFile >> x >> y >> z;
    inFile.ignore();
    
    vector<KhachHang*> danhSachKH;
    
    for (int i = 0; i < x; i++) {
        KhachHang* kh = new KhachHangA();
        kh->DocFile(inFile); kh->TinhTien();
        danhSachKH.push_back(kh);
    }
    for (int i = 0; i < y; i++) {
        KhachHang* kh = new KhachHangB();
        kh->DocFile(inFile); kh->TinhTien();
        danhSachKH.push_back(kh);
    }
    for (int i = 0; i < z; i++) {
        KhachHang* kh = new KhachHangC();
        kh->DocFile(inFile); kh->TinhTien();
        danhSachKH.push_back(kh);
    }
    
    outFile << x << " " << y << " " << z << endl;
    double tongTienCongTy = 0;
    for (KhachHang* kh : danhSachKH) {
        kh->GhiFile(outFile);
        tongTienCongTy += kh->getSoTienPhaiTra();
    }
    outFile << fixed << setprecision(0) << tongTienCongTy << endl;
    
    for (KhachHang* kh : danhSachKH) delete kh;
    inFile.close(); outFile.close();
    cout << "Hoan thanh ghi du lieu vao file XYZ.OUT!" << endl;
    return 0;
}
