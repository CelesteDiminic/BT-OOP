/* Mô tả class
classDiagram
    class NgayThangNam {
        -int iNgay
        -int iThang
        -int iNam
        +Nhap() void
        +Xuat() void
        +NgayThangNamTiepTheo() void
        -KiemTraNamNhuan(int) bool
        -SoNgayTrongThang(int, int) int
    }
*/

#include <iostream>
using namespace std;

class NgayThangNam {
private:
    int iNgay, iThang, iNam;

    bool KiemTraNamNhuan(int nam) {
        return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
    }

    int SoNgayTrongThang(int thang, int nam) {
        switch (thang) {
            case 4: case 6: case 9: case 11: return 30;
            case 2: return KiemTraNamNhuan(nam) ? 29 : 28;
            default: return 31;
        }
    }

public:
    void Nhap() {
        cout << "Nhap ngay, thang, nam: ";
        cin >> iNgay >> iThang >> iNam;
    }

    void Xuat() {
        cout << iNgay << "/" << iThang << "/" << iNam << endl;
    }

    void NgayThangNamTiepTheo() {
        iNgay++;
        if (iNgay > SoNgayTrongThang(iThang, iNam)) {
            iNgay = 1;
            iThang++;
            if (iThang > 12) {
                iThang = 1;
                iNam++;
            }
        }
    }
};

int main() {
    NgayThangNam date;
    cout << "--- Bai 1: Ngay Thang Nam ---\n";
    date.Nhap();
    cout << "Ngay vua nhap: ";
    date.Xuat();
    
    date.NgayThangNamTiepTheo();
    cout << "Ngay tiep theo: ";
    date.Xuat();
    
    return 0;
}
