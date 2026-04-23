#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// LỚP THÍ SINH
// ==========================================
class cCandidate {
private:
    string ma;
    string ten;
    string ngaySinh;
    float diemToan, diemVan, diemAnh;

public:
    // Phương thức thiết lập (Constructor)
    cCandidate() {
        ma = ten = ngaySinh = "";
        diemToan = diemVan = diemAnh = 0.0;
    }

    void nhap() {
        cout << "  Nhap ma thi sinh: ";
        cin >> ws; // Xóa khoảng trắng và ký tự enter thừa trong bộ đệm
        getline(cin, ma);
        
        cout << "  Nhap ho ten: ";
        getline(cin, ten);
        
        cout << "  Nhap ngay sinh (dd/mm/yyyy): ";
        getline(cin, ngaySinh);
        
        cout << "  Nhap diem Toan - Van - Anh: ";
        cin >> diemToan >> diemVan >> diemAnh;
    }

    void xuat() const {
        cout << "[Ma: " << ma << " | Ten: " << ten << " | NS: " << ngaySinh
             << " | Diem: T(" << diemToan << ") V(" << diemVan << ") A(" << diemAnh
             << ") => TONG: " << tinhTongDiem() << "]\n";
    }

    float tinhTongDiem() const {
        return diemToan + diemVan + diemAnh;
    }
};

// ==========================================
// LỚP DANH SÁCH THÍ SINH
// ==========================================
class cListCandidate {
private:
    int n;
    vector<cCandidate> ds;

public:
    void nhap() {
        do {
            cout << "Nhap so luong thi sinh (n > 0): ";
            cin >> n;
        } while (n <= 0);

        ds.resize(n);
        for (int i = 0; i < n; i++) {
            cout << "--- Nhap thong tin thi sinh thu " << i + 1 << " ---\n";
            ds[i].nhap();
        }
    }

    // Xuất các thí sinh có tổng điểm > 15
    void xuatLonHon15() const {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (ds[i].tinhTongDiem() > 15) {
                ds[i].xuat();
                found = true;
            }
        }
        if (!found) {
            cout << "  -> Khong co thi sinh nao tong diem > 15.\n";
        }
    }

    // Cho biết thí sinh có tổng điểm cao nhất (Có thể có nhiều người cùng điểm Max)
    void inThiSinhDiemCaoNhat() const {
        if (n == 0) return;

        // B1: Tìm mức điểm max
        float maxDiem = ds[0].tinhTongDiem();
        for (int i = 1; i < n; i++) {
            if (ds[i].tinhTongDiem() > maxDiem) {
                maxDiem = ds[i].tinhTongDiem();
            }
        }

        // B2: In ra tất cả những người đạt mức điểm max này
        cout << "Diem cao nhat la " << maxDiem << " thuoc ve:\n";
        for (int i = 0; i < n; i++) {
            if (ds[i].tinhTongDiem() == maxDiem) {
                ds[i].xuat();
            }
        }
    }

    // Sắp xếp danh sách giảm dần theo tổng điểm (Sử dụng thuật toán Selection Sort)
    void sapXepGiamDan() {
        for (int i = 0; i < n - 1; i++) {
            int max_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (ds[j].tinhTongDiem() > ds[max_idx].tinhTongDiem()) {
                    max_idx = j;
                }
            }
            swap(ds[i], ds[max_idx]);
        }
    }

    // Hàm phụ trợ in toàn bộ danh sách
    void xuatToanBo() const {
        for (int i = 0; i < n; i++) {
            ds[i].xuat();
        }
    }
};

// ==========================================
// CHƯƠNG TRÌNH CHÍNH (TESTING)
// ==========================================
int main() {
    cListCandidate list;

    cout << "===== 1. NHAP DANH SACH THI SINH =====\n";
    list.nhap();

    cout << "\n===== 2. THI SINH CO TONG DIEM > 15 =====\n";
    list.xuatLonHon15();

    cout << "\n===== 3. THI SINH CO TONG DIEM CAO NHAT =====\n";
    list.inThiSinhDiemCaoNhat();

    cout << "\n===== 4. DANH SACH SAU KHI SAP XEP GIAM DAN =====\n";
    list.sapXepGiamDan();
    list.xuatToanBo();

    return 0;
}
