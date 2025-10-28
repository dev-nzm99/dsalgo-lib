/*
* Created: 2025-10-30 11:20
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
    int front;
    int currentSize;

public:
    //O(1)
    MyQueue(int capacity) {
        this->capacity = capacity;
        arr = new int[this->capacity];
        front = 0;
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
        //computes the rear index dynamically using modulo arithmetic,
        int rear = (front+currentSize) % capacity;
        arr[rear] = val;
        currentSize++;
    }

    //O(1)
    void deQueue() {
        if (isEmpty()) {
            cout << "Underflow condition occurred!\n";
            return;
        }
        front = (front+1)%capacity;
        currentSize--;   
    }

    // O(1)
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[front];
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

    cout << "Front element: " << q.getFront() << endl;

    q.deQueue();
    cout << "Front after dequeue: " << q.getFront() << endl;
    return 0;
}
