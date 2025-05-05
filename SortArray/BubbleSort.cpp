#include <iostream>
#include <fstream>
using namespace std;

void BubbleSort(int *A, int n){
    for(int i=0; i<n-1; i++){
        for(int j=n-1; j>i; j--){
            if(A[j]>A[j-1])
                swap(A[j], A[j-1]);
        }
    }
}

void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){
    string file_path = "C:/Users/ADMIN/Documents/HK2 2024-2025/CTDLGT/data/100/inputdata_type1_002.dat";
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

    BubbleSort(A,n);
    printArray(A, n);

    delete []A;
    return 0;
}