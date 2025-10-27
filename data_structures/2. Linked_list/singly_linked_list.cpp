/*
* Created: 2025-10-27 19:11
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
        this->next = NULL;
    }
};

class Operations {
private:
    Node* head = NULL;

public:
    // Insert at the front
    void insertAtFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at a specific position (1-based indexing)
    void insertAtPosition(int val, int position) {
        Node* newNode = new Node(val);

        if (position == 1) {  
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {  
            cout << "Error: Position is invalid!" << endl;
            delete newNode; 
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Print the list
    void print() {
        Node* tmp = head;
        while (tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Operations() {
        Node* tmp = head;
        while (tmp != NULL) {
            Node* nxtNode = tmp->next;
            delete tmp;
            tmp = nxtNode;
        }
    }
};

int main() {
    Operations op;

    // Insert at front
    op.insertAtFront(20);
    op.insertAtFront(60);
    op.insertAtFront(80);
    op.insertAtFront(120);

    // Insert at end
    op.insertAtEnd(5);
    op.insertAtEnd(10);

    // Insert at position
    op.insertAtPosition(999, 3);   
    op.insertAtPosition(555, 1);  
    op.insertAtPosition(777, 10);  

    op.print();

    return 0;
}
