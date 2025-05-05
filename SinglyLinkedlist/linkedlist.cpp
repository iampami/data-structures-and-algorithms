#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct tagNode{
    long Data;
    struct tagNode *next;
};

typedef tagNode *Node;
typedef struct tagList{
    Node head;
    Node tail;
}LinkedList;

void initLinkedList(LinkedList &l){
    l.head = l.tail = NULL;
}

int isEmpty(LinkedList l){
    return l.head==NULL;
}

int insertNode2Head(LinkedList &l, long x){
    Node p = new tagNode;
    if(!p) return 0;
    p->Data = x;
    p->next = NULL;
    if(isEmpty(l)){
        l.head=l.tail=p;
    }else{
        p->next = l.head;
        l.head = p;
    }
    return 1;
}

int insertNode2Tail(LinkedList &l, long x){
    Node p = new tagNode;
    if(!p) return 0;
    p->Data = x;
    p->next = NULL;
    if(isEmpty(l)){
        l.head=l.tail=p;
    } else{
        l.tail->next = p;
        l.tail = p;
    }
    return 1;
}

int insertNode2After(LinkedList &l, long x, Node q){
    Node p = new tagNode;
    if(!p) return 0; // tương đương if(p==NULL)
    p->Data = x;
    p->next = NULL;
    if(isEmpty(l)){
        l.head=l.tail=p;
    } else{
        p->next = q->next;
        q->next = p;
        if(q==l.tail) l.tail=p;
    }
    return 1;
}

int removeNodeAtHead(LinkedList &l){
    Node p = l.head;
    if(isEmpty(l)) return -1;
    l.head = p->next;
    if(!l.head) l.tail = NULL; //if(l.head==NULL)
    p->next = NULL;
    delete p;
    return 1;
}

int removeNodeAtTail(LinkedList &l){
    Node p = l.head;
    Node q = NULL;
    if (isEmpty(l)) return -1;

    while(p!=l.tail){     // Duyệt danh sách để tìm node trước node cuối (q) và node cuối (p)
        q = p;
        p = p->next;
    }
    
    if(q){
        //TH danh sách có hơn 1 node
        q->next = NULL;
        l.tail = q;
    }else{
        //TH danh sách chỉ có 1 node
        l.head = l.tail = NULL;
    }
    delete p;
    return 1;
}

int removeNode(LinkedList &l, int x){
    Node p = l.head;
    if(!p) return -1;
    if(p->Data != x && l.tail->Data != x){
        Node q = NULL;
        while(p && p->Data != x){
            q=p;
            p = p->next;
        }
        if(!p) return 0;
        q->next = p->next;
        p->next = NULL;
        delete p;
    } else {
        if(p->Data==x) removeNodeAtHead(l);
        if(l.tail->Data==x) removeNodeAtTail(l);
    }
    return 1;
}

Node searchNode(LinkedList l, long x){
    Node p = l.head;
    if(!p) return NULL;
    while(p){
        if(p->Data == x)
            return p;
        p = p->next;
    }
    return NULL;
}

void appendList(LinkedList &l1, LinkedList &l2){
    if(isEmpty(l1)) l1=l2;
    else{
        l1.tail->next = l2.head;
        if(isEmpty(l2)) l1.tail = l2.tail;
    }
}

void printGreaterThanK(LinkedList l, int k){
    Node p = l.head;
    while(p){
        if(p->Data>k){
            cout<<p->Data<<" "<<endl;
        }
        p = p->next;
    }
}

int Searchx(LinkedList l, int x){
    Node p = l.head;
    int position = 0;
    if(!p) return -1;
    while(p){
        if(p->Data==x){
            return position;
        }
        p = p->next;
        position++;
    }
    return -1;
}

int main() {
    LinkedList myList;
    initLinkedList(myList);

    // Thêm node vào đầu danh sách
    insertNode2Head(myList, 10);
    insertNode2Head(myList, 20);
    insertNode2Head(myList, 30);

    // Thêm node vào cuối danh sách
    insertNode2Tail(myList, 5);
    insertNode2Tail(myList, 1);

    // In ra các phần tử lớn hơn 10
    cout << "Cac gia tri lon hon 10:\n";
    printGreaterThanK(myList, 10);

    // Tìm kiếm giá trị
    int x = 5;
    int pos = Searchx(myList, x);
    if (pos != -1)
        cout << "Gia tri " << x << " nam o vi tri: " << pos << endl;
    else
        cout << "Khong tim thay gia tri " << x << endl;

    // Xóa node đầu, cuối và node có giá trị cụ thể
    removeNodeAtHead(myList);
    removeNodeAtTail(myList);
    removeNode(myList, 10);

    // In lại danh sách sau khi xóa
    cout << "Danh sach sau khi xoa:\n";
    Node p = myList.head;
    while (p) {
        cout << p->Data << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}
