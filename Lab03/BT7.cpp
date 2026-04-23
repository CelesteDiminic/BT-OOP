
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

// Cấu trúc hỗ trợ bóc tách và so sánh ngày tháng năm
struct Date {
    int d, m, y;
    
    // Hàm kiểm tra xem ngày hiện tại có "sinh trước" ngày other không (tức là lớn tuổi hơn)
    bool sinhTruoc(const Date& other) const {
        if (y != other.y) return y < other.y; // So sánh năm
        if (m != other.m) return m < other.m; // Nếu cùng năm, so sánh tháng
        return d < other.d;                   // Nếu cùng tháng, so sánh ngày
    }
};

// ==========================================
// LỚP NHÂN VIÊN VĂN PHÒNG
// ==========================================
class cNhanVienVP {
private:
    string maNV;
    string hoTen;
    string ngaySinh;
    double luong;

public:
    // 1. Constructors
    cNhanVienVP() {
        maNV = hoTen = ngaySinh = "";
        luong = 0.0;
    }

    cNhanVienVP(string ma, string ten, string ns, double l) {
        maNV = ma;
        hoTen = ten;
        ngaySinh = ns;
        luong = l;
    }

    // 2. Getters & Setters
    string getMaNV() const { return maNV; }
    void setMaNV(string ma) { maNV = ma; }

    string getHoTen() const { return hoTen; }
    void setHoTen(string ten) { hoTen = ten; }

    string getNgaySinh() const { return ngaySinh; }
    void setNgaySinh(string ns) { ngaySinh = ns; }

    double getLuong() const { return luong; }
    void setLuong(double l) { luong = l; }

    // Hàm phụ trợ chuyển chuỗi "dd/mm/yyyy" thành struct Date
    Date parseDate() const {
        Date date = {0, 0, 0};
        char sep; // Ký tự phân cách '/'
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
        
        cout << "  Nhap muc luong: ";
        cin >> luong;
    }

    // 4. Xuất
    void xuat() const {
        // Sử dụng fixed và setprecision để in lương định dạng đẹp, không bị lỗi khoa học (e+)
        cout << "[Ma: " << maNV << " | Ten: " << hoTen << " | NS: " << ngaySinh
             << " | Luong: " << fixed << setprecision(2) << luong << "]\n";
    }
};

// ==========================================
// LỚP DANH SÁCH NHÂN VIÊN VĂN PHÒNG
// ==========================================
class cDSNhanVienVP {
private:
    int n;
    vector<cNhanVienVP> ds;

public:
    // Nhập danh sách
    void nhap() {
        do {
            cout << "Nhap so luong nhan vien (n > 0): ";
            cin >> n;
        } while (n <= 0);

        ds.resize(n);
        for (int i = 0; i < n; i++) {
            cout << "--- Nhap thong tin nhan vien thu " << i + 1 << " ---\n";
            ds[i].nhap();
        }
    }

    // Xuất danh sách
    void xuat() const {
        for (int i = 0; i < n; i++) {
            ds[i].xuat();
        }
    }

    // Tìm nhân viên có lương cao nhất
    void timLuongCaoNhat() const {
        if (n == 0) return;
        double maxLuong = ds[0].getLuong();
        for (int i = 1; i < n; i++) {
            if (ds[i].getLuong() > maxLuong) {
                maxLuong = ds[i].getLuong();
            }
        }

        cout << "Nhung nhan vien co luong cao nhat (" << fixed << setprecision(2) << maxLuong << ") la:\n";
        for (int i = 0; i < n; i++) {
            if (ds[i].getLuong() == maxLuong) {
                ds[i].xuat();
            }
        }
    }

    // Tính tổng lương
    double tinhTongLuong() const {
        double tong = 0;
        for (int i = 0; i < n; i++) {
            tong += ds[i].getLuong();
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
        // Có thể mở rộng quét vòng lặp lại nếu muốn tìm những người sinh cùng ngày
        // Ở đây lấy đại diện 1 người lớn tuổi nhất đầu tiên tìm được
        ds[idxLonTuoiNhat].xuat();
    }

    // Sắp xếp danh sách tăng dần theo lương (Bubble Sort)
    void sapXepTangDanTheoLuong() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (ds[j].getLuong() > ds[j + 1].getLuong()) {
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
    cDSNhanVienVP congTy;

    cout << "===== 1. NHAP DANH SACH NHAN VIEN =====\n";
    congTy.nhap();

    cout << "\n===== 2. DANH SACH NHAN VIEN =====\n";
    congTy.xuat();

    cout << "\n===== 3. THONG KE LUONG =====\n";
    congTy.timLuongCaoNhat();
    cout << "\n-> Tong quy luong cong ty phai tra: "
         << fixed << setprecision(2) << congTy.tinhTongLuong() << endl;

    cout << "\n===== 4. THONG KE TUOI =====\n";
    congTy.timNhanVienLonTuoiNhat();

    cout << "\n===== 5. DANH SACH SAP XEP TANG DAN THEO LUONG =====\n";
    congTy.sapXepTangDanTheoLuong();
    congTy.xuat();

    return 0;
}
