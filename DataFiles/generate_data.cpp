// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <cstdlib>
// #include <ctime>
// #include <filesystem>
// #include <iomanip>

// // thay đổi số lượng phần tử ở num_elements
// void generate_data_files(int num_files = 100, int num_elements = 1000, double min_val = -100.0, double max_val = 100.0, const std::string& output_dir = "C:/Users/ADMIN/Documents/HK2 2024-2025/CTDLGT/data/1K") {
//     std::filesystem::create_directory(output_dir); // Tạo thư mục nếu chưa tồn tại
//     std::srand(std::time(nullptr));
    
//     for (int i = 0; i < num_files; ++i) {
//         std::ostringstream filename;
//         filename << output_dir << "/inputdata_type2_" << std::setw(3) << std::setfill('0') << (i + 1) << ".dat";
//         std::ofstream file(filename.str());
        
//         if (file.is_open()) {
//             for (int j = 0; j < num_elements; ++j) {
//                 double value = min_val + static_cast<double>(std::rand()) / RAND_MAX * (max_val - min_val);
//                 file << value << "\n";
//             }
//             file.close();
//         }
//     }
    
//     std::cout << "Đã tạo " << num_files << " file dữ liệu trong thư mục '" << output_dir << "'\n";
// }

// int main() {
//     generate_data_files();
//     return 0;
// }


#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <iomanip>

using namespace std;

void createRandomFiles(int num_files, int num_elements, int min_val, int max_val, const string& output_dir) {
    // Tạo thư mục nếu chưa tồn tại
    if (!filesystem::create_directories(output_dir) && !filesystem::exists(output_dir)) {
        cerr << "Lỗi: Không thể tạo thư mục '" << output_dir << "'" << endl;
        return;
    }


    // Khởi tạo seed cho random
    srand(time(nullptr));

    for (int i = 1; i <= num_files; ++i) {
        // Tạo tên file theo định dạng "/inputdata_type2_001.dat", ..., "/inputdata_type2_100.dat"
        ostringstream filename;
        filename << output_dir << "/inputdata_type5_" << setw(3) << setfill('0') << i << ".dat";

        // Mở file để ghi dữ liệu
        ofstream file(filename.str());
        if (file.is_open()) {
            // Tạo mảng một chiều chứa số nguyên ngẫu nhiên
            int *arr = new int[num_elements];

            for (int j = 0; j < num_elements; ++j) {
                arr[j] = min_val + rand() % (max_val - min_val + 1);
                file << arr[j] << " "; // Ghi số vào file, cách nhau bởi dấu cách
            }

            file.close();
            delete[] arr; // Giải phóng bộ nhớ động
            cout << "Đã tạo file: " << filename.str() << endl;
        } else {
            cerr << "Lỗi: Không thể tạo file " << filename.str() << endl;
        }
    }
}

int main() {
    int num_files = 100;    // Số file cần tạo (001 -> 100)
    int num_elements = 1000000; // Số phần tử trong mỗi mảng (mỗi file)
    int min_val = -200;     // Giá trị nhỏ nhất
    int max_val = 200;      // Giá trị lớn nhất
    string output_dir = "C:/Users/ADMIN/Documents/HK2 2024-2025/CTDLGT/data/1000k"; 

    createRandomFiles(num_files, num_elements, min_val, max_val, output_dir);
    return 0;
}
