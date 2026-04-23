#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const float PI = 3.14159265359;

// ==========================================
// LỚP ĐIỂM (Hỗ trợ cho lớp Tam Giác)
// ==========================================
class cDiem {
private:
    float x, y;
public:
    cDiem(float x = 0, float y = 0) : x(x), y(y) {}
    
    void nhap() {
        cin >> x >> y;
    }
    
    void xuat() const {
        cout << "(" << x << ", " << y << ")";
    }
    
    float khoangCach(const cDiem& d) const {
        return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
    }
    
    void tinhTien(float dx, float dy) {
        x += dx;
        y += dy;
    }
    
    // Quay điểm quanh gốc tọa độ (0,0) một góc rad
    void quay(float gocRad) {
        float x_new = x * cos(gocRad) - y * sin(gocRad);
        float y_new = x * sin(gocRad) + y * cos(gocRad);
        x = x_new;
        y = y_new;
    }
    
    // Phóng to/thu nhỏ tọa độ điểm so với gốc tọa độ
    void scale(float k) {
        x *= k;
        y *= k;
    }
};

// ==========================================
// LỚP TAM GIÁC
// ==========================================
class cTamGiac {
private:
    cDiem A, B, C;

    // Hàm phụ trợ kiểm tra 2 số thực có bằng nhau không (tránh sai số float)
    bool isEqual(float a, float b) const {
        return abs(a - b) < 1e-4;
    }

public:
    // 1. Phương thức thiết lập
    cTamGiac() {} // Mặc định A, B, C sẽ gọi constructor mặc định của cDiem (0,0)
    
    cTamGiac(cDiem a, cDiem b, cDiem c) : A(a), B(b), C(c) {}
    
    // 2. Phương thức hủy bỏ
    ~cTamGiac() {
        // Không có cấp phát động (pointer/new) nên không cần giải phóng bộ nhớ
    }
    
    // 3. Nhập/Xuất
    void nhap() {
        cout << "Nhap toa do dinh A (x y): "; A.nhap();
        cout << "Nhap toa do dinh B (x y): "; B.nhap();
        cout << "Nhap toa do dinh C (x y): "; C.nhap();
    }
    
    void xuat() const {
        cout << "Tam giac tao boi 3 dinh: A"; A.xuat();
        cout << ", B"; B.xuat();
        cout << ", C"; C.xuat();
        cout << endl;
    }
    
    // 4. Kiểm tra loại tam giác
    string kiemTraLoai() const {
        float a = B.khoangCach(C);
        float b = A.khoangCach(C);
        float c = A.khoangCach(B);
        
        // Kiểm tra điều kiện tồn tại tam giác
        if (a + b <= c || a + c <= b || b + c <= a) {
            return "Khong phai tam giac hop le";
        }
        
        bool vuong = isEqual(a*a + b*b, c*c) || isEqual(a*a + c*c, b*b) || isEqual(b*b + c*c, a*a);
        bool can = isEqual(a, b) || isEqual(a, c) || isEqual(b, c);
        bool deu = isEqual(a, b) && isEqual(b, c);
        
        if (deu) return "Tam giac deu";
        if (vuong && can) return "Tam giac vuong can";
        if (vuong) return "Tam giac vuong";
        if (can) return "Tam giac can";
        return "Tam giac thuong";
    }
    
    // 5. Tính chu vi
    float tinhChuVi() const {
        float a = B.khoangCach(C);
        float b = A.khoangCach(C);
        float c = A.khoangCach(B);
        return a + b + c;
    }
    
    // 6. Tính diện tích (Công thức Heron)
    float tinhDienTich() const {
        float a = B.khoangCach(C);
        float b = A.khoangCach(C);
        float c = A.khoangCach(B);
        float p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    
    // 7. Tịnh tiến
    void tinhTien(float dx, float dy) {
        A.tinhTien(dx, dy);
        B.tinhTien(dx, dy);
        C.tinhTien(dx, dy);
    }
    
    // 8. Quay (quanh gốc tọa độ) - goc nhap vao la do (degree)
    void quay(float gocDo) {
        float gocRad = gocDo * PI / 180.0;
        A.quay(gocRad);
        B.quay(gocRad);
        C.quay(gocRad);
    }
    
    // 9. Phóng to
    void phongTo(float k) {
        if (k > 0) {
            A.scale(k); B.scale(k); C.scale(k);
        }
    }
    
    // 10. Thu nhỏ
    void thuNho(float k) {
        if (k > 0) {
            A.scale(1.0 / k); B.scale(1.0 / k); C.scale(1.0 / k);
        }
    }
    
    // 11. Vẽ tam giác (Mô phỏng)
    void ve() const {
        cout << "-> Dang ve tam giac tren man hinh tai cac vi tri: ";
        xuat();
    }
};

// ==========================================
// CHƯƠNG TRÌNH CHÍNH (TESTING)
// ==========================================
int main() {
    cout << "--- KIEM THU LOP TAM GIAC ---" << endl;
    
    cTamGiac tg;
    cout << "\n1. NHAP DU LIEU TAM GIAC" << endl;
    // Gợi ý test tam giác vuông: A(0,0), B(0,3), C(4,0)
    tg.nhap();
    
    cout << "\n2. THONG TIN TAM GIAC" << endl;
    tg.ve(); // Goi ham ve mo phong
    cout << "Loai tam giac: " << tg.kiemTraLoai() << endl;
    cout << "Chu vi: " << tg.tinhChuVi() << endl;
    cout << "Dien tich: " << tg.tinhDienTich() << endl;
    
    cout << "\n3. PHEP TINH TIEN (dx = 2, dy = 3)" << endl;
    tg.tinhTien(2, 3);
    tg.xuat();
    
    cout << "\n4. PHEP QUAY (goc 90 do)" << endl;
    tg.quay(90);
    tg.xuat();
    
    cout << "\n5. PHEP PHONG TO (He so k = 2)" << endl;
    tg.phongTo(2);
    tg.xuat();
    
    cout << "\n6. PHEP THU NHO (He so k = 2)" << endl;
    tg.thuNho(2);
    tg.xuat();

    return 0;
}
