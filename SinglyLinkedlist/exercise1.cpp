#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    int isPrime(int n) {
        if (n==2) return 1;
        if(n<2 || n%2==0) return 0;
        for (int i = 3; i < sqrt(n)+1; i+=2) {
            if (n % i == 0) return 0;
        }
        return 1;
    }

    bool isPalindrome(int n) {
        int original = n, reversed = 0;
        if(n<0) original = abs(n);
        while (n > 0) {
            reversed = reversed * 10 + n % 10;
            n /= 10;
        }
        return original == reversed;
    }

    int countPrimes() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            if (isPrime(temp->data)) count++;
            temp = temp->next;
        }
        return count;
    }

    int sumOddNumbers() {
        int sum = 0;
        Node* temp = head;
        while (temp) {
            if (temp->data % 2 != 0) sum += temp->data;
            temp = temp->next;
        }
        return sum;
    }

    double averagePalindromes() {
        int sum = 0, count = 0;
        Node* temp = head;
        while (temp) {
            if (isPalindrome(temp->data)) {
                sum += temp->data;
                count++;
            }
            temp = temp->next;
        }
        return count == 0 ? 0 : (double)sum / count;
    }

    int countNegativeDivBy5() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            if (temp->data < 0 && temp->data % 5 == 0) count++;
            temp = temp->next;
        }
        return count;
    }

    void sortList() {
        vector<int> negatives, positives;
        Node* temp = head;

        while (temp) {
            if (temp->data < 0)
                negatives.push_back(temp->data);
            else
                positives.push_back(temp->data);
            temp = temp->next;
        }

        sort(negatives.rbegin(), negatives.rend()); // Descending order for negatives
        sort(positives.begin(), positives.end()); // Ascending order for positives

        temp = head;
        for (int num : negatives) {
            temp->data = num;
            temp = temp->next;
        }
        for (int num : positives) {
            temp->data = num;
            temp = temp->next;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.insert(19);
    list.insert(7);
    list.insert(4);
    list.insert(-10);
    list.insert(-5);
    list.insert(-101);
    
    cout << "Original list: ";
    list.display();
    
    cout << "Prime numbers count: " << list.countPrimes() << endl;
    cout << "Sum of odd numbers: " << list.sumOddNumbers() << endl;
    cout << "Average of palindromic numbers: " << list.averagePalindromes() << endl;
    cout << "Negative numbers divisible by 5: " << list.countNegativeDivBy5() << endl;
    
    list.sortList();
    cout << "Sorted list: ";
    list.display();
    
    return 0;
}
