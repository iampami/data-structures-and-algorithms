#include <iostream>
#include <fstream>
using namespace std;

void InterchangeSort(int *A, int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(A[i]>A[j])
                swap(A[i],A[j]);
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

    InterchangeSort(A,n);
    printArray(A, n);

    delete []A;
    return 0;
}