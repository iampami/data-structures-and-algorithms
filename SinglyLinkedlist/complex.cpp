#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct{
    int imaginary_number;
    int real_number;
}Complex;

Complex createComplex(int a, int b){
    Complex c;
    c.real_number = a;
    c.imaginary_number = b;
    return c;
}

int getRealNumber(Complex c){
    return c.real_number;
}

int getImaginaryNumber(Complex c){
    return c.imaginary_number;
}

Complex addComplex(Complex c1, Complex c2){
    int r1 = getRealNumber(c1);
    int r2 = getRealNumber(c2);
    int i1 = getImaginaryNumber(c1);
    int i2 = getImaginaryNumber(c2);
    return createComplex(r1+r2, i1+i2);
}

Complex multiplyComplex(Complex c1, Complex c2){
    int r1 = getRealNumber(c1);
    int r2 = getRealNumber(c2);
    int i1 = getImaginaryNumber(c1);
    int i2 = getImaginaryNumber(c2);

    int real_part = (r1*r2)-(i1*i2);
    int img_part = (r1*i2)+(r2*i1);
    
    return createComplex(real_part, img_part);
}

void printComplex(Complex c) {
    cout << c.real_number << " + " << c.imaginary_number << "i" << endl;
}

int main() {
    Complex c1 = createComplex(3, 4);
    Complex c2 = createComplex(1, -2);
    Complex sum = addComplex(c1, c2);
    Complex multiply = multiplyComplex(c1, c2);

    cout << "Số phức 1: ";
    printComplex(c1);
    cout << "Số phức 2: ";
    printComplex(c2);
    cout << "Tổng hai số phức: ";
    printComplex(sum);
    cout << "Tich hai số phức: ";
    printComplex(multiply);

    return 0;
}