/*
* Created: 2025-11-01 10:03
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

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class MyQueue {
private:
    int currSize;
    Node* front;
    Node* rear;
public:
    MyQueue() {
        currSize = 0;
        front = NULL;
        rear = NULL;    
    }
    bool isEmpty() {
        return front == NULL;
    }
    void enqueue(int n) {
        Node* newN = new Node(n);
        if(isEmpty()) {
            front = rear = newN;
        } else {
            rear->next = newN;
            rear = newN;
        }
        currSize++;
    }
    void dequeue() {
        if(isEmpty()) {
            cout << "Queue underflow!\n";
            return;
        }
        Node* tmp = front;
        front = front->next;
        delete tmp;
        if(front == NULL) rear = NULL;
        currSize--;
    }
    int getFront() {
        if(isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return front->data;
    }
    int getSize() {
        return currSize;
    }
    ~MyQueue() {   //destructor
        while (!isEmpty()) {
            dequeue();
        }
    }
};
int main() {
    MyQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.getFront() << endl;
    cout << "Queue size: " << q.getSize() << endl;

    q.dequeue();
    cout << "After dequeue, front element: " << q.getFront() << endl;
    cout << "Queue size: " << q.getSize() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}
