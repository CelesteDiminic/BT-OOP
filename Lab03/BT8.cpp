#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

// Cấu trúc hỗ trợ so sánh ngày tháng năm sinh
struct Date {
    int d, m, y;
    
    // Kiểm tra xem ngày hiện tại có sinh trước ngày "other" không
    bool sinhTruoc(const Date& other) const {
        if (y != other.y) return y < other.y;
        if (m != other.m) return m < other.m;
        return d < other.d;
    }
};

// ==========================================
// LỚP NHÂN VIÊN SẢN XUẤT
// ==========================================
class cNhanVienSX {
private:
    string maNV;
    string hoTen;
    string ngaySinh;
    int soSP;
    double donGia;

public:
    // 1. Constructors
    cNhanVienSX() {
        maNV = hoTen = ngaySinh = "";
        soSP = 0;
        donGia = 0.0;
    }

    cNhanVienSX(string ma, string ten, string ns, int sp, double gia) {
        maNV = ma;
        hoTen = ten;
        ngaySinh = ns;
        soSP = sp;
        donGia = gia;
    }

    // 2. Getters & Setters
    string getMaNV() const { return maNV; }
    void setMaNV(string ma) { maNV = ma; }

    string getHoTen() const { return hoTen; }
    void setHoTen(string ten) { hoTen = ten; }

    string getNgaySinh() const { return ngaySinh; }
    void setNgaySinh(string ns) { ngaySinh = ns; }

    int getSoSP() const { return soSP; }
    void setSoSP(int sp) { soSP = sp; }

    double getDonGia() const { return donGia; }
    void setDonGia(double gia) { donGia = gia; }

    // Tính lương = số sản phẩm * đơn giá
    double tinhLuong() const {
        return soSP * donGia;
    }

    // Tách chuỗi ngày sinh thành cấu trúc Date
    Date parseDate() const {
        Date date = {0, 0, 0};
        char sep;
        stringstream ss(ngaySinh);
        ss >> date.d >> sep >> date.m >> sep >> date.y;
        return date;
    }

    // 3. Nhập
    void nhap() {
        cout << "  Nhap ma NV: ";
        cin >> ws;
        getline(cin, maNV);
        
        cout << "  Nhap ho ten: ";
        getline(cin, hoTen);
        
        cout << "  Nhap ngay sinh (dd/mm/yyyy): ";
        getline(cin, ngaySinh);
        
        cout << "  Nhap so san pham da gia cong: ";
        cin >> soSP;
        
        cout << "  Nhap don gia 1 san pham: ";
        cin >> donGia;
    }

    // 4. Xuất
    void xuat() const {
        cout << "[Ma: " << maNV << " | Ten: " << hoTen << " | NS: " << ngaySinh
             << " | So SP: " << soSP << " | Don gia: " << donGia
             << " => Luong: " << fixed << setprecision(2) << tinhLuong() << "]\n";
    }
};

// ==========================================
// LỚP DANH SÁCH NHÂN VIÊN SẢN XUẤT
// ==========================================
class cDSNhanVienSX {
private:
    int n;
    vector<cNhanVienSX> ds;

public:
    void nhap() {
        do {
            cout << "Nhap so luong nhan vien san xuat (n > 0): ";
            cin >> n;
        } while (n <= 0);

        ds.resize(n);
        for (int i = 0; i < n; i++) {
            cout << "--- Nhap thong tin nhan vien thu " << i + 1 << " ---\n";
            ds[i].nhap();
        }
    }

    void xuat() const {
        for (int i = 0; i < n; i++) {
            ds[i].xuat();
        }
    }

    // Tìm nhân viên có lương THẤP NHẤT
    void timLuongThapNhat() const {
        if (n == 0) return;
        
        double minLuong = ds[0].tinhLuong();
        for (int i = 1; i < n; i++) {
            if (ds[i].tinhLuong() < minLuong) {
                minLuong = ds[i].tinhLuong();
            }
        }

        cout << "Nhung nhan vien co luong thap nhat (" << fixed << setprecision(2) << minLuong << ") la:\n";
        for (int i = 0; i < n; i++) {
            if (ds[i].tinhLuong() == minLuong) {
                ds[i].xuat();
            }
        }
    }

    // Tính tổng lương
    double tinhTongLuong() const {
        double tong = 0;
        for (int i = 0; i < n; i++) {
            tong += ds[i].tinhLuong();
        }
        return tong;
    }

    // Tìm nhân viên lớn tuổi nhất (Sinh trước nhất)
    void timNhanVienLonTuoiNhat() const {
        if (n == 0) return;
        
        int idxLonTuoiNhat = 0;
        Date oldestDate = ds[0].parseDate();

        for (int i = 1; i < n; i++) {
            Date currentDate = ds[i].parseDate();
            if (currentDate.sinhTruoc(oldestDate)) {
                oldestDate = currentDate;
                idxLonTuoiNhat = i;
            }
        }

        cout << "Nhan vien lon tuoi nhat la:\n";
        ds[idxLonTuoiNhat].xuat();
    }

    // Sắp xếp danh sách tăng dần theo lương (Dùng Bubble Sort)
    void sapXepTangDanTheoLuong() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (ds[j].tinhLuong() > ds[j + 1].tinhLuong()) {
                    swap(ds[j], ds[j + 1]);
                }
            }
        }
    }
};

// ==========================================
// CHƯƠNG TRÌNH CHÍNH (TESTING)
// ==========================================
int main() {
    cDSNhanVienSX xuongSX;

    cout << "===== 1. NHAP DANH SACH NHAN VIEN SAN XUAT =====\n";
    xuongSX.nhap();

    cout << "\n===== 2. DANH SACH NHAN VIEN =====\n";
    xuongSX.xuat();

    cout << "\n===== 3. THONG KE LUONG =====\n";
    xuongSX.timLuongThapNhat();
    cout << "\n-> Tong quy luong cong ty phai tra: "
         << fixed << setprecision(2) << xuongSX.tinhTongLuong() << endl;

    cout << "\n===== 4. THONG KE TUOI =====\n";
    xuongSX.timNhanVienLonTuoiNhat();

    cout << "\n===== 5. DANH SACH SAP XEP TANG DAN THEO LUONG =====\n";
    xuongSX.sapXepTangDanTheoLuong();
    xuongSX.xuat();

    return 0;
}
