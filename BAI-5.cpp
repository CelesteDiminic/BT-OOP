#include <iostream>
#include <string>
#include <limits> // Thư viện hỗ trợ xóa bộ nhớ đệm an toàn

using namespace std;

struct HocSinh {
    string hoTen;
    float diemToan, diemVan;

    void nhap() {
        // 1. Validate Họ Tên: Bắt buộc phải nhập, không được để trống
        do {
            cout << "Nhap ho ten hoc sinh: ";
            getline(cin, hoTen);
            if (hoTen.empty()) {
                cout << "-> Loi: Ho ten khong duoc de trong. Vui long nhap lai!\n";
            }
        } while (hoTen.empty());

        // 2. Validate Điểm Toán: Phải là số và nằm trong khoảng [0, 10]
        do {
            cout << "Nhap diem Toan (0 - 10): ";
            cin >> diemToan;
            
            // Nếu cin bị lỗi (do nhập chữ) HOẶC điểm nằm ngoài khoảng 0-10
            if (cin.fail() || diemToan < 0 || diemToan > 10) {
                cout << "-> Loi: Diem khong hop le! Vui long nhap mot so tu 0 den 10.\n";
                cin.clear(); // Xóa cờ lỗi của cin để có thể nhập tiếp
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa sạch các ký tự sai còn kẹt trong bộ nhớ đệm
            } else {
                break; // Nhập đúng thì thoát vòng lặp
            }
        } while (true);

        // 3. Validate Điểm Văn: Tương tự điểm Toán
        do {
            cout << "Nhap diem Van (0 - 10): ";
            cin >> diemVan;
            
            if (cin.fail() || diemVan < 0 || diemVan > 10) {
                cout << "-> Loi: Diem khong hop le! Vui long nhap mot so tu 0 den 10.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        } while (true);
        
        // Xóa bộ nhớ đệm sau lần nhập số cuối cùng đề phòng người dùng nhập dư
        // (Rất hữu ích nếu sau này bạn mở rộng code để nhập nhiều học sinh)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    float tinhDiemTrungBinh() {
        return (diemToan + diemVan) / 2.0;
    }

    void xuat() {
        cout << "\n===============================" << endl;
        cout << "      THONG TIN HOC SINH       " << endl;
        cout << "===============================" << endl;
        cout << "- Ho ten: " << hoTen << endl;
        cout << "- Diem Toan: " << diemToan << endl;
        cout << "- Diem Van:  " << diemVan << endl;
        cout << "- Diem Trung Binh: " << tinhDiemTrungBinh() << endl;
        cout << "===============================\n" << endl;
    }
};

int main() {
    HocSinh hs;
    
    cout << "=== CHUONG TRINH QUAN LY HOC SINH ===\n";
    hs.nhap();
    hs.xuat();
    
    return 0;
}
