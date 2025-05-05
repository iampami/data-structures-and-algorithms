#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void SelectionSort(int *A, int n){
    for(int i=0; i<n-1; i++){
        int min=i;// Gia su A[i] la nho nhat
        for(int j=i+1; j<n; j++){
            if(A[j]<A[min]){ //Tim phan tu nho hon
                min=j;
            }
        }
        if(A[i]!=A[min]) //Hoan doi A[i] voi A[min] neu can thiet
            swap(A[i], A[min]);
    }
}

void input(int *A, int &n){
    cout<<"Nhap n";
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<"Nhap A["<<i<<"]";
        cin>>A[i];
    }
}

void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){
    string file_path = "C:/Users/ADMIN/Documents/HK2 2024-2025/CTDLGT/data/1000k/inputdata_type5_001.dat";
    ifstream file(file_path);

    if(!file){
        cerr<<"Khong the mo file"<<endl;
        return 1;
    }

    int *A = new int[1000000];
    int n=0, x, k;

    while(file>>x){
        A[n++]=x;
    }
    file.close();

    // int A[100], n;
    // input(A,n);

    SelectionSort(A,n);
    printArray(A, n);

    delete []A;
    return 0;
}