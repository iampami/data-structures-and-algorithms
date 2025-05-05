#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

//Bai toan nay chi dung sap xep so duong
int Digit(int n, int k) {
    int value = 1;
    for (int i = 0; i < k; i++) {
        value *= 10;
    }
    return (n / value) % 10;
}

int getMax(int *A, int n){
    int maxVal = A[0];
    for( int i=1; i<n; i++){
        if(A[i]>maxVal){
            maxVal=A[i];
        }
    }
    return maxVal;
}

void RadixSort(int *A, int n){
    int maxVal = getMax(A, n);
    int *B = new int[n];

    for(int k=0; maxVal/(int)pow(10,k)>0; k++){
        int count[10]={0};
        
        for(int i=0; i<n; i++){
            int digit = Digit(A[i], n);
            count[digit]++;
        }
        
        for(int i=0; i<10; i++){
            count[i] += count[i-1];
        }

        for(int i=n-1; i>=0; i--){
            int digit = Digit(A[i], k);
            B[count[digit]-1] = A[i];
            count[digit]--;
        }

        for(int i=0; i<n; i++){
            A[i] = B[i];
        }
    }
    delete []B;
}

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout <<a[i]<< " ";
}

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

    RadixSort(A, n);

    cout << "Mang sau khi sap xep: ";
    printArray(A, n);

    return 0;
}
