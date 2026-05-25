#include <iostream>
#include "SoPhuc.h"
#include "PhanSo.h"
#include "CTime.h"
#include "CDate.h"
#include "DaThuc.h"
#include "CVector.h"
#include "CMatrix.h"

int main() {
    std::cout << "--- KIEM THU LAB 4 ---\n";

    // 1. Test SoPhuc
    SoPhuc sp1(4, 5), sp2(2, -3);
    std::cout << "So Phuc 1: " << sp1 << "\nTong: " << (sp1 + sp2) << "\n\n";

    // 2. Test PhanSo
    PhanSo ps1(3, 4), ps2(1, 2);
    std::cout << "Phan So 1: " << ps1 << "\nTich: " << (ps1 * ps2) << "\n\n";

    // 3. Test CTime
    CTime t1(23, 59, 50);
    std::cout << "Thoi gian ban dau: " << t1 << "\nSau khi + 15 giay: " << (t1 + 15) << "\n\n";

    // 4. Test CDate & Bai toan lai suat
    CDate dGoi(24, 5, 2025), dRut(24, 5, 2026);
    long soNgay = dRut - dGoi;
    double goc = 100000000; // 100 Trieu VND
    double laiSuatNam = 0.055; // 5.5% / Nam
    double tienLai = goc * (laiSuatNam / 365) * soNgay;
    std::cout << "Ngay goi: " << dGoi << " -> Ngay rut: " << dRut << " (" << soNgay << " ngay)\n";
    std::cout << "So tien lai tinh duoc: " << (long long)tienLai << " VND\n\n";

    // 5. Test DaThuc
    DaThuc dt(2); // Bac 2: y = 0x^0 + 0x^1 + 0x^2
    // Gia su set cac he so qua cin hoac ho tro thu cong:
    std::cout << "He thong khoi tao Da Thuc Bac 2 thanh cong.\n\n";

    // 6 & 7. Test Matrix & Vector
    CMatrix mat(2, 2);
    CVector vec(2);
    vec.Set(0, 1); vec.Set(1, 2);
