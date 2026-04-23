#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// ==========================================
// LỚP ĐA THỨC
// ==========================================
class cDaThuc {
private:
    int bac;
    vector<double> heSo; // heSo[i] lưu hệ số của x^i

    // Hàm phụ trợ xử lý trường hợp bậc cao nhất bị triệt tiêu (vd: 2x^2 - 2x^2)
    void chuanHoa() {
        while (bac > 0 && heSo[bac] == 0) {
            heSo.pop_back();
            bac--;
        }
    }

public:
    // 1. Khởi tạo một đa thức có bậc bằng 0 (P(x) = 0)
    cDaThuc() {
        bac = 0;
        heSo.push_back(0);
    }

    // 2. Khởi tạo đa thức bậc n
    cDaThuc(int n) {
        bac = (n >= 0) ? n : 0;
        heSo.resize(bac + 1, 0.0); // Khởi tạo tất cả hệ số bằng 0
    }

    // 3. Nhập đa thức
    void nhap() {
        cout << "Nhap bac cua da thuc: ";
        cin >> bac;
        heSo.resize(bac + 1);
        
        // Nhập từ bậc cao nhất xuống bậc 0 cho thuận mắt người dùng
        for (int i = bac; i >= 0; i--) {
            cout << "  He so cua x^" << i << ": ";
            cin >> heSo[i];
        }
        chuanHoa(); // Đề phòng người dùng cố tình nhập hệ số bậc cao nhất = 0
    }

    // 4. Xuất đa thức
    void xuat() const {
        bool isFirst = true; // Dùng để quản lý dấu + / - ở đầu chuỗi
        for (int i = bac; i >= 0; i--) {
            if (heSo[i] != 0) {
                // Xử lý in dấu
                if (heSo[i] > 0 && !isFirst) cout << " + ";
                else if (heSo[i] < 0) cout << (isFirst ? "-" : " - ");
                
                double absVal = abs(heSo[i]);
                // Chỉ in giá trị hệ số nếu nó khác 1 (tránh in 1x^2), ngoại trừ hệ số tự do
                if (absVal != 1 || i == 0) cout << absVal;

                // In phần biến x^i
                if (i > 0) {
                    cout << "x";
                    if (i > 1) cout << "^" << i;
                }
                isFirst = false;
            }
        }
        // Trường hợp tất cả hệ số bằng 0
        if (isFirst) cout << "0";
        cout << endl;
    }

    // 5. Tính giá trị đa thức khi biết x
    double tinhGiaTri(double x) const {
        double kq = 0;
        for (int i = 0; i <= bac; i++) {
            kq += heSo[i] * pow(x, i);
        }
        return kq;
    }

    // 6. Cộng hai đa thức
    cDaThuc cong(const cDaThuc& dt) const {
        int maxBac = max(bac, dt.bac);
        cDaThuc kq(maxBac);
        
        for (int i = 0; i <= maxBac; i++) {
            double a = (i <= bac) ? heSo[i] : 0;       // Lấy hệ số của đa thức A
            double b = (i <= dt.bac) ? dt.heSo[i] : 0; // Lấy hệ số của đa thức B
            kq.heSo[i] = a + b;
        }
        kq.chuanHoa();
        return kq;
    }

    // 7. Trừ hai đa thức
    cDaThuc tru(const cDaThuc& dt) const {
        int maxBac = max(bac, dt.bac);
        cDaThuc kq(maxBac);
        
        for (int i = 0; i <= maxBac; i++) {
            double a = (i <= bac) ? heSo[i] : 0;
            double b = (i <= dt.bac) ? dt.heSo[i] : 0;
            kq.heSo[i] = a - b;
        }
        kq.chuanHoa();
        return kq;
    }
};

// ==========================================
// CHƯƠNG TRÌNH CHÍNH (TESTING)
// ==========================================
int main() {
    cout << "===== CHUONG TRINH XU LY DA THUC =====\n";
    
    cDaThuc P, Q;
    
    cout << "\n--- Nhap da thuc P(x) ---\n";
    P.nhap();
    
    cout << "\n--- Nhap da thuc Q(x) ---\n";
    Q.nhap();
    
    cout << "\n1. HIEN THI DA THUC\n";
    cout << "P(x) = "; P.xuat();
    cout << "Q(x) = "; Q.xuat();
    
    cout << "\n2. TINH GIA TRI DA THUC\n";
    double x;
    cout << "Nhap gia tri x: "; cin >> x;
    cout << "P(" << x << ") = " << P.tinhGiaTri(x) << endl;
    cout << "Q(" << x << ") = " << Q.tinhGiaTri(x) << endl;
    
    cout << "\n3. PHEP TOAN TREN DA THUC\n";
    cDaThuc tong = P.cong(Q);
    cout << "P(x) + Q(x) = "; tong.xuat();
    
    cDaThuc hieu = P.tru(Q);
    cout << "P(x) - Q(x) = "; hieu.xuat();

    return 0;
}
