#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const float PI = 3.14159265359;

// ==========================================
// LỚP ĐIỂM (Đã bổ sung Getter)
// ==========================================
class cDiem {
private:
    float x, y;
public:
    cDiem(float x = 0, float y = 0) : x(x), y(y) {}
    
    void nhap() { cin >> x >> y; }
    void xuat() const { cout << "(" << x << ", " << y << ")"; }
    
    float khoangCach(const cDiem& d) const {
        return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
    }
    
    void tinhTien(float dx, float dy) { x += dx; y += dy; }
    
    void quay(float gocRad) {
        float x_new = x * cos(gocRad) - y * sin(gocRad);
        float y_new = x * sin(gocRad) + y * cos(gocRad);
        x = x_new;
        y = y_new;
    }
    
    void scale(float k) { x *= k; y *= k; }

    // Getter để hỗ trợ tính diện tích Đa Giác
    float getX() const { return x; }
    float getY() const { return y; }
};

// ==========================================
// LỚP ĐA GIÁC
// ==========================================
class cDaGiac {
private:
    int soDinh;
    vector<cDiem> tapDinh; // Sử dụng vector để quản lý danh sách đỉnh an toàn

public:
    // 1. Phương thức thiết lập
    cDaGiac() {
        soDinh = 0;
    }
    
    // 2. Phương thức hủy bỏ
    ~cDaGiac() {
        tapDinh.clear(); // Giải phóng vector (thực ra vector tự động dọn dẹp khi hết scope)
    }
    
    // 3. Nhập/Xuất
    void nhap() {
        do {
            cout << "Nhap so dinh cua da giac (n >= 3): ";
            cin >> soDinh;
        } while (soDinh < 3);

        tapDinh.resize(soDinh);
        for (int i = 0; i < soDinh; i++) {
            cout << "Nhap toa do dinh thu " << i + 1 << " (x y): ";
            tapDinh[i].nhap();
        }
    }
    
    void xuat() const {
        cout << "Da giac co " << soDinh << " dinh: ";
        for (int i = 0; i < soDinh; i++) {
            tapDinh[i].xuat();
            if (i < soDinh - 1) cout << " - ";
        }
        cout << endl;
    }
    
    // 4. Tính chu vi
    float tinhChuVi() const {
        float chuVi = 0;
        for (int i = 0; i < soDinh; i++) {
            int j = (i + 1) % soDinh; // Đỉnh kế tiếp (đỉnh cuối nối về đỉnh 0)
            chuVi += tapDinh[i].khoangCach(tapDinh[j]);
        }
        return chuVi;
    }
    
    // 5. Tính diện tích (Công thức Shoelace)
    float tinhDienTich() const {
        float dienTich = 0;
        for (int i = 0; i < soDinh; i++) {
            int j = (i + 1) % soDinh;
            dienTich += (tapDinh[i].getX() * tapDinh[j].getY()) - (tapDinh[j].getX() * tapDinh[i].getY());
        }
        return abs(dienTich) / 2.0;
    }
    
    // 6. Tịnh tiến
    void tinhTien(float dx, float dy) {
        for (int i = 0; i < soDinh; i++) {
            tapDinh[i].tinhTien(dx, dy);
        }
    }
    
    // 7. Quay
    void quay(float gocDo) {
        float gocRad = gocDo * PI / 180.0;
        for (int i = 0; i < soDinh; i++) {
            tapDinh[i].quay(gocRad);
        }
    }
    
    // 8. Phóng to
    void phongTo(float k) {
        if (k > 0) {
            for (int i = 0; i < soDinh; i++) tapDinh[i].scale(k);
        }
    }
    
    // 9. Thu nhỏ
    void thuNho(float k) {
        if (k > 0) {
            for (int i = 0; i < soDinh; i++) tapDinh[i].scale(1.0 / k);
        }
    }
    
    // 10. Vẽ (Mô phỏng)
    void ve() const {
        cout << "-> Dang ve da giac tren man hinh tai cac vi tri: ";
        xuat();
    }
};

// ==========================================
// CHƯƠNG TRÌNH CHÍNH (TESTING)
// ==========================================
int main() {
    cout << "--- KIEM THU LOP DA GIAC ---" << endl;
    
    cDaGiac dg;
    cout << "\n1. NHAP DU LIEU DA GIAC" << endl;
    // Gợi ý test hình vuông: 4 đỉnh: (0,0), (4,0), (4,4), (0,4)
    dg.nhap();
    
    cout << "\n2. THONG TIN DA GIAC" << endl;
    dg.ve();
    cout << "Chu vi: " << dg.tinhChuVi() << endl;
    cout << "Dien tich: " << dg.tinhDienTich() << endl;
    
    cout << "\n3. PHEP TINH TIEN (dx = 1, dy = 1)" << endl;
    dg.tinhTien(1, 1);
    dg.xuat();
    
    cout << "\n4. PHEP QUAY (goc 90 do)" << endl;
    dg.quay(90);
    dg.xuat();
    
    cout << "\n5. PHEP PHONG TO (He so k = 2)" << endl;
    dg.phongTo(2);
    dg.xuat();

    return 0;
}
