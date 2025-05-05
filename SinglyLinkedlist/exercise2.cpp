#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

//Dinh nghia cau truc Node
typedef struct Complex{
    int img;
    int real;
    struct Complex* next;
}Complex;

typedef struct List{
    Complex* head;
    Complex* tail;
}LinkedList;

void initLinkedList(LinkedList &l){
    l.head = l.tail = NULL;
}

void addComplex(LinkedList &l, int real, int img){
    Complex* newcomplex = new Complex{real, img, NULL};
    if(!l.head){
        l.head = l.tail = newcomplex;
    } else {
        l.tail -> next = newcomplex;
        l.tail = newcomplex;
    }
}

long isPrime(long n){
    if(n==2) return 1;
    if(n<2 || n%2 == 0) return 0;
    for(int i = 3; i<sqrt(n)+1; i+=2){
        if(n%i == 0) return 0; 
    }
    return 1;
}

long AvgSumofImg(LinkedList l){
    int count = 0;
    long sum = 0;
    Complex* p = l.head;

    while(p){
        if(isPrime(p->real)){
            sum += p->img;
            count++;
        }
        p = p->next;
    }

    return (count == 0)?0: (long)sum/count;
}

int countDevisibleBy3(LinkedList l) {
    int count = 0;
    Complex* p = l.head;

    while(p){
        if((p->real + p->img)%3 == 0){
            count ++;
        }
        p = p->next;
    }
    return count;
}

int main(){
    LinkedList l;
    initLinkedList(l);

    addComplex(l, 5, 2);
    addComplex(l, 4, 11);
    addComplex(l, 7, 6);

    cout << "Trung bình phần ảo khi phần thực là số nguyên tố: " << AvgSumofImg(l) << endl;
    cout << "Số lượng số phức có tổng phần thực + phần ảo chia hết cho 3: " << countDevisibleBy3(l) << endl;
}