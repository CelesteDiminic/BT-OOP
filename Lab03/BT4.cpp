#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <climits> // Thư viện chứa INT_MAX

using namespace std;

// ==========================================
// LỚP MẢNG MỘT CHIỀU
// ==========================================
class cArray {
private:
    int* arr;
    int n;

    // Hàm phụ trợ ẩn (private): Kiểm tra số nguyên tố
    bool checkSNT(int val) const {
        if (val < 2) return false;
        for (int i = 2; i <= sqrt(val); i++) {
            if (val % i == 0) return false;
        }
        return true;
    }

public:
    // 1. Hàm thiết lập (Constructor) - Cấp phát bộ nhớ động
    cArray(int size) {
        n = (size > 0) ? size : 0;
        if (n > 0) {
            arr = new int[n];
        } else {
            arr = nullptr;
        }
    }

    // 2. Hàm hủy bỏ (Destructor) - Giải phóng bộ nhớ
    ~cArray() {
        if (arr != nullptr) {
            delete[] arr;
            arr = nullptr; // Tránh con trỏ lơ lửng (Dangling pointer)
        }
    }

    // 3. Tạo mảng ngẫu nhiên (Giá trị từ 0 đến 99)
    void taoMangNgauNhien() {
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100;
        }
    }

    // Hàm hỗ trợ nhập tay nếu không muốn random
    void nhapThuCong() {
        for(int i = 0; i < n; i++) {
            cout << "arr[" << i << "] = ";
            cin >> arr[i];
        }
    }

    // 4. Xuất các phần tử mảng
    void xuat() const {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // 5. Đếm số lần xuất hiện của giá trị x
    int demSoLanXuatHien(int x) const {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) count++;
        }
        return count;
    }

    // 6. Kiểm tra các phần tử mảng có tăng dần hay không
    bool kiemTraTangDan() const {
        if (n <= 1) return true;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) return false;
        }
        return true;
    }

    // 7. Tìm phần tử lẻ nhỏ nhất
    // Sử dụng tham chiếu int &ketQua để trả về giá trị, hàm trả về bool để báo xem có số lẻ hay không
    bool timLeNhoNhat(int &ketQua) const {
        bool found = false;
        int minLe = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) {
                if (!found || arr[i] < minLe) {
                    minLe = arr[i];
                    found = true;
                }
            }
        }
        if (found) ketQua = minLe;
        return found;
    }

    // 8. Tìm số nguyên tố lớn nhất
    bool timSNTLonNhat(int &ketQua) const {
        bool found = false;
        int maxSNT = -1;
        for (int i = 0; i < n; i++) {
            if (checkSNT(arr[i])) {
                if (!found || arr[i] > maxSNT) {
                    maxSNT = arr[i];
                    found = true;
                }
            }
        }
        if (found) ketQua = maxSNT;
        return found;
    }

    // 9. Sắp xếp tăng dần (Thuật toán Selection Sort)
    void sapXepTangDan() {
        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            // Đổi chỗ
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }

    // 10. Sắp xếp giảm dần (Thuật toán Insertion Sort)
    void sapXepGiamDan() {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
};

// ==========================================
// CHƯƠNG TRÌNH CHÍNH (TESTING)
// ==========================================
int main() {
    // Khởi tạo hạt giống random theo thời gian
    srand((unsigned int)time(NULL));

    int soLuong;
    cout << "Nhap kich thuoc mang: ";
    cin >> soLuong;

    cArray mang(soLuong);

    cout << "\n1. KHOI TAO DU LIEU\n";
    // Cậu có thể dùng mang.nhapThuCong() để test dữ liệu cứng thay vì random
    mang.taoMangNgauNhien();
    cout << "Mang ngau nhien vua tao: ";
    mang.xuat();

    cout << "\n2. KIEM TRA TINH CHAT\n";
    if (mang.kiemTraTangDan()) {
        cout << "-> Mang hien tai dang sap xep TANG DAN.\n";
    } else {
        cout << "-> Mang hien tai KHONG tang dan.\n";
    }

    cout << "\n3. TIM KIEM GIA TRI\n";
    int x;
    cout << "Nhap gia tri x can dem: ";
    cin >> x;
    cout << "-> So lan xuat hien cua " << x << " la: " << mang.demSoLanXuatHien(x) << " lan\n";

    int leMin;
    if (mang.timLeNhoNhat(leMin)) {
        cout << "-> Phan tu le nho nhat trong mang la: " << leMin << endl;
    } else {
        cout << "-> Mang khong chua so le nao.\n";
    }

    int sntMax;
    if (mang.timSNTLonNhat(sntMax)) {
        cout << "-> So nguyen to lon nhat trong mang la: " << sntMax << endl;
    } else {
        cout << "-> Mang khong chua so nguyen to nao.\n";
    }

    cout << "\n4. SAP XEP DU LIEU\n";
    mang.sapXepTangDan();
    cout << "Mang sau khi sap xep TANG DAN (Selection Sort): ";
    mang.xuat();

    mang.sapXepGiamDan();
    cout << "Mang sau khi sap xep GIAM DAN (Insertion Sort): ";
    mang.xuat();

    return 0; // Khi kết thúc main, Destructor (~cArray) tự động được gọi để dọn dẹp RAM
}
