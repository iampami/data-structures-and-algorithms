#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;


void Merge1 (int *A, int left, int mid, int right){
    int i = left;
    int j = mid+1;
    int k=0;
    int n = right - left+1;
    int *B = new int[n];
    while(i<mid+1 && j<right+1){
        if(A[i]<A[j]){
            B[k]=A[i];
            k++;
            i++;
        } else {
            B[k]=A[j];
            k++;
            j++;
        }
    }
    while(i<mid+1){
        B[k]=A[i];
        k++; i++;
    }
    while(j<right+1){
        B[k]=A[j];
        k++; j++;
    }
    i=left;
    for(k=0; k<n; k++){
        A[i]=B[k];
        i++;
    }
    delete[] B;
}

void MergeSort1(int *A, int left, int right){
    if(left<right){
        int mid = (left+right)/2;
        MergeSort1(A, left, mid);
        MergeSort1(A, mid+1, right);
        Merge1(A, left, mid, right);
    }
}

// Hàm trộn hai nửa đã sắp xếp của mảng A
void Merge(int A[], int l, int mid, int r) {
    int n1 = mid - l + 1;  // Số phần tử của nửa trái
    int n2 = r - mid;      // Số phần tử của nửa phải

    // Tạo mảng tạm để lưu hai nửa
    int *left = new int[n1];
    int *right = new int[n2];

    // Copy dữ liệu vào mảng tạm
    for (int i = 0; i < n1; i++)
        left[i] = A[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = l; // i duyệt mảng trái, j duyệt mảng phải, k duyệt mảng chính

    // Trộn hai mảng con vào mảng chính
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) { 
            A[k] = left[i]; // Chèn phần tử nhỏ hơn vào mảng chính
            i++; // Tiến đến phần tử tiếp theo trong left[]
        } else {
            A[k] = right[j]; // Chèn phần tử nhỏ hơn từ right[]
            j++; // Tiến đến phần tử tiếp theo trong right[]
        }
        k++; // Di chuyển vị trí tiếp theo trong mảng chính
    }

    // Sao chép phần còn lại của mảng left nếu có
    while (i < n1) {
        A[k] = left[i];
        i++;
        k++;
    }

    // Sao chép phần còn lại của mảng right nếu có
    while (j < n2) {
        A[k] = right[j];
        j++;
        k++;
    }

    // Giải phóng bộ nhớ tạm
    delete[] left;
    delete[] right;
}

// Hàm MergeSort chính
void MergeSort(int A[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;  // Chia mảng thành hai phần

        MergeSort(A, l, mid);    // Sắp xếp nửa trái
        MergeSort(A, mid + 1, r);// Sắp xếp nửa phải
        Merge(A, l, mid, r);     // Trộn hai nửa đã sắp xếp
    }
}

// Hàm in mảng
void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

// Chương trình chính
int main() {
    string file_path = "C:/Users/ADMIN/Documents/HK2 2024-2025/CTDLGT/data/100/inputdata_type1_001.dat"; // Thư mục chứa dữ liệu
    ifstream file(file_path); // Mở file

    if (!file) {
        cerr << "Không thể mở file!\n";
        return 1;
    }

    // Đọc dữ liệu từ file vào mảng động
    int *A = new int[1000000]; // Giả sử file chứa tối đa 1000 số
    int n = 0, x, k;
    
    while (file >> x) { // Đọc từng số từ file
        A[n++] = x;   // Lưu vào mảng
    }
    file.close(); // Đóng file

    cout << "Mang truoc khi sap xep: ";
    printArray(A, n); 

    MergeSort1(A, 0, n - 1);

    cout << "Mang sau khi sap xep: ";
    printArray(A, n);

    return 0;
}
