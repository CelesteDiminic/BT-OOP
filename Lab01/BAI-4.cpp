#include <iostream>
using namespace std;

struct Ngay {
    int d, m, y;
    
    void nhap() {
        cout << "Nhap ngay: "; cin >> d;
        cout << "Nhap thang: "; cin >> m;
        cout << "Nhap nam: "; cin >> y;
    }
    
    void xuat() {
        cout << d << "/" << m << "/" << y << endl;
    }
};

bool laNamNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int soNgayTrongThang(int thang, int nam) {
    switch (thang) {
        case 4: case 6: case 9: case 11: return 30;
        case 2: return laNamNhuan(nam) ? 29 : 28;
        default: return 31;
    }
}

Ngay timNgayKeTiep(Ngay hienTai) {
    Ngay keTiep = hienTai;
    keTiep.d++; // Tăng thêm 1 ngày

    // Nếu số ngày vượt quá số ngày tối đa của tháng hiện tại
    if (keTiep.d > soNgayTrongThang(keTiep.m, keTiep.y)) {
        keTiep.d = 1;
        keTiep.m++;
        // Nếu tháng vượt quá 12 thì sang năm mới
        if (keTiep.m > 12) {
            keTiep.m = 1;
            keTiep.y++;
        }
    }
    return keTiep;
}

int main() {
    Ngay homNay;

    cout << "=== NHAP NGAY HIEN TAI ===" << endl;
    homNay.nhap();

    // Kiểm tra tính hợp lệ cơ bản của ngày nhập vào
    if (homNay.y < 1 || homNay.m < 1 || homNay.m > 12 || homNay.d < 1 || homNay.d > soNgayTrongThang(homNay.m, homNay.y)) {
        cout << "Ngay thang nam khong hop le!" << endl;
        return 1; // Kết thúc chương trình với lỗi
    }

    Ngay ngayMai = timNgayKeTiep(homNay);

    cout << "\n--- KET QUA ---" << endl;
    cout << "Ngay ban vua nhap: "; homNay.xuat();
    cout << "Ngay ke tiep la: "; ngayMai.xuat();

    return 0;
}
