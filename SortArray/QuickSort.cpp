#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

void QuickSort(int *A, int l, int r){
    if(l>=r) return; //Dieu kien dung khi chi con 1 hoac 0 phan tu

    int x=A[(l+r)/2]; // Chọn phần tử chốt là phần tử giữa
    int i = l, j = r;

    while(i<=j){ //Lặp lại đến khi 2 phần tử gặp nhau
        while(A[i]<x) i++; //Duyệt từ trái qua, tìm phần tử >=x
        while(A[j]>x) j--; //Duyệt từ phải
        if(i<=j){
            swap(A[i], A[j]); //Đổi về đúng vị trí
            i++;
            j--;
        }
    }

    //Gọi đệ quy với nửa trái và nửa phải
    if(l<j) QuickSort(A,l,j);// Đệ quy phần bên trái
    if(i<r) QuickSort(A,i,r);// Đệ quy phần bên phải
}

void input(int a[], int &n)
{
	cout << "nhap n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "nhap a[" << i << "]: ";
		cin >> a[i];
	}
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout <<a[i]<< " ";
}

int main(){
    string file_path = "C:/Users/ADMIN/Documents/HK2 2024-2025/CTDLGT/data/100/inputdata_type1_001.dat"; // Thư mục chứa dữ liệu
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


    // int a[100],n;

    // input(a, n);
    QuickSort(a, 0, n-1);
    output(a,n);
}