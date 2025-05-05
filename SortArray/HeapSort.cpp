#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

void InsertHeap(int *A, int l, int r){
    int p = 2*l+1;// Con trai

    if(p>r) //Neu khong co con thi dung lai
        return;
    
    if(p<=r && A[p]<A[p+1]){ //Chon con lon hon giua p va p+1
        p = p+1; //Chon con phai neu lon hon
    }

    if(A[l]<A[p]){
        swap(A[l], A[p]); //Doi cho cha voi con lon hon
        InsertHeap(A,p,r); //Goi de quy xuong nhanh duoi
    }
}

void CreateHeap(int *A, int n){
    for(int k = (n-1)/2; k>=0; k--){ //Duyet nguoc tu n-1 ->0
        InsertHeap(A,k,n-1); //Dieu chinh tung nut thanh MaxHeap
    }
}

void HeapSort(int *A, int n){
    CreateHeap(A, n); 
    for(int k=n-1; k>0; k--){
        swap(A[0], A[k]);
        InsertHeap(A, 0, k-1);
    }
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main(){
    string file_path = "C:/Users/ADMIN/Documents/HK2 2024-2025/CTDLGT/data/1k/inputdata_type2_001.dat";
    ifstream file(file_path);

    if(!file){
        cerr<<"Khong the mo file";
        return 1;
    }

    int *a = new int[1000000]; // Giả sử file chứa tối đa 1000 số
    int n = 0, x, k;
    
    while (file >> x) { // Đọc từng số từ file
        a[n++] = x;   // Lưu vào mảng
    }
    file.close(); // Đóng file

    HeapSort(a, n);
    printArray(a, n);

    delete []a;
    return 0;
}