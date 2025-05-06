#include <iostream>
#include <fstream>

using namespace std;

int LSearch(int *a, int n, int k, int t) {
    for (int j = t; j < n; j++) { // Duyệt từ vị trí t đến cuối mảng
        if (a[j] == k) {
            return j; // Trả về vị trí nếu tìm thấy phần tử
        }
    }
    return -1; // Không tìm thấy
}

void LSearchAll(int *a, int n, int k){
    int res, h = 0;


    cout << "Các vị trí của " << k << " trong dữ liệu: ";
    while (h < n && h != -1) {
        res = LSearch(a, n, k, h); // Tìm vị trí xuất hiện tiếp theo của k

        if (res != -1) {
            cout << res << " "; // In ra vị trí
            h = res + 1; // Tiếp tục tìm từ vị trí tiếp theo
        } else {
            break; // Nếu không tìm thấy nữa thì thoát vòng lặp
        }
    }

    if (h == 0) {
        cout << "Không tìm thấy phần tử " << k << " trong dữ liệu.";
    }

    cout << endl;
}

int main() {
    string file_path = "C:/Users/ADMIN/Documents/HK2 2024-2025/CTDLGT/data/1k/inputdata_type2_001.dat"; // Thư mục chứa dữ liệu
    ifstream file(file_path); // Mở file

    if (!file) {
        cerr << "Không thể mở file!\n";
        return 1;
    }

    // Đọc dữ liệu từ file vào mảng động
    int *a = new int[1000000]; // Giả sử file chứa tối đa 1000 số
    int n = 0, x, k;
    
    while (file >> x) { // Đọc từng số từ file
        a[n++] = x;   // Lưu vào mảng
    }
    file.close(); // Đóng file

    cout << "Nhập giá trị cần tìm: ";
    cin >> k;

    LSearchAll(a, n, k);

    // Giải phóng bộ nhớ động
    delete[] a;

    return 0;
}
