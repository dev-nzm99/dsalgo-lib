/*
* Created: 2025-10-28 09:50
* Author:
   __    __   ______    ________  __      __  __    __  __     
  /  |  /  | /      |  /       / /  |    /  |/  |  /  |/  |      
  $$ |  $$ |/$$$$$$  |$$$$$$$$/ $$  |   /$$ |$$ |  $$ |$$ |      
  $$$   $$ |$$ |__$$ |    /$$/  $$$    /$$$ |$$ |  $$ |$$ |      
  $$$$  $$ |$$    $$ |   /$$/   $$$$  /$$$$ |$$ |  $$ |$$ |      
  $$ $$ $$ |$$$$$$$$ |  /$$/    $$ $$ $$/$$ |$$ |  $$ |$$ |      
  $$ |$$$$ |$$ |  $$ | /$$/____ $$  $$$/ $$ |$$ |  $$ |$$ |_____ 
  $$ | $$$ |$$ |  $$ |/$$/     |$$   $/  $$ |$$    $$/ $$       |
  $$/   $$/ $$/   $$ /$$$$$$$$/ $$/      $$/  $$$$$$/  $$$$$$$$/ 
*/
#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    int* arr;
    int capacity;
    int currentSize;

public:
    /*O(1)
    Just initializes variables and allocates memory*/
    MyQueue(int capacity) {
        this->capacity = capacity;
        arr = new int[this->capacity];
        currentSize = 0;
    }
    bool isFull() {
        return currentSize == capacity;
    }
    bool isEmpty() {
        return currentSize == 0;
    }
    // O(1)
    void enQueue(int val) {
        if (isFull()) {
            cout << "Overflow condition occurred!\n";
            return;
        }
        arr[currentSize++] = val;
    }

    /*O(n)
    Shifts all elements one position left when removing front*/
    void deQueue() {
        if (isEmpty()) {
            cout << "Underflow condition occurred!\n";
            return;
        }
        for (int i = 1; i < currentSize; i++)
            arr[i - 1] = arr[i];
        currentSize--;
    }

    // O(1)
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[0];
    }
    int getSize() {
        return currentSize; 
    }
    ~MyQueue() {
        delete[] arr;
    }
};

int main() {
    MyQueue q(5);

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);

    cout << "Front element: " << q.front() << endl;

    q.deQueue();
    cout << "Front after dequeue: " << q.front() << endl;
    return 0;
}
