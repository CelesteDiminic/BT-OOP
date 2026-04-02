/*
 classDiagram
     class GioPhutGiay {
         -int iGio
         -int iPhut
         -int iGiay
         +Nhap() void
         +Xuat() void
         +TinhCongThemMotGiay() void
     }
 */
#include <iostream>
#include <iomanip>
using namespace std;

class GioPhutGiay {
private:
    int iGio, iPhut, iGiay;

public:
    void Nhap() {
        cout << "Nhap gio, phut, giay: ";
        cin >> iGio >> iPhut >> iGiay;
        
        // Chuẩn hóa nếu nhập quá 60 hoặc âm (basic validation)
        while(iGio < 0 || iGio > 23 || iPhut < 0 || iPhut > 59 || iGiay < 0 || iGiay > 59) {
            cout << "Thoi gian khong hop le. Nhap lai (Gio 0-23, Phut 0-59, Giay 0-59): ";
            cin >> iGio >> iPhut >> iGiay;
        }
    }

    void Xuat() {
        // Dùng setfill và setw để in định dạng HH:MM:SS đẹp mắt
        cout << setfill('0') << setw(2) << iGio << ":"
             << setfill('0') << setw(2) << iPhut << ":"
             << setfill('0') << setw(2) << iGiay << endl;
    }

    void TinhCongThemMotGiay() {
        iGiay++;
        if (iGiay >= 60) {
            iGiay = 0;
            iPhut++;
            if (iPhut >= 60) {
                iPhut = 0;
                iGio++;
                if (iGio >= 24) {
                    iGio = 0; // Sang ngày mới
                }
            }
        }
    }
};

int main() {
    GioPhutGiay time;
    cout << "--- Bai 4: Gio Phut Giay ---\n";
    time.Nhap();
    
    cout << "Thoi gian hien tai: ";
    time.Xuat();
    
    time.TinhCongThemMotGiay();
    cout << "Sau khi cong them 1 giay: ";
    time.Xuat();
    
    return 0;
}
