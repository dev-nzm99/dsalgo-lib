/*
* Created: 2025-11-20 9:17
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

class Node{
public:
   int data;
   Node *naxt;
   Node(int data){
      this->data = data;
      this->naxt = NULL;
   }
};

class MyStack{
   Node *top; // Pointer to top node
   int count;

public:
   MyStack(){
      top = NULL;
      count = 0;
   }
   void push(int val){
      Node *newNode = new Node(val);
      newNode->naxt = top;
      top = newNode;
      count++;
   }
   void pop(){
      if (top == NULL){
         cout << "Stack Underflow!" << "\n";
         return;
      }
      Node *tmp = top;
      top = top->naxt;
      count--;
      delete tmp;
   }
   int peek(){
      if (top == NULL){
         cout << "Stack is empty!" << "\n";
         return -1;
      }
      return top->data;
   }
   bool isEmpty(){
      return top == NULL;
   }
   int size(){
      return count;
   }
};
int main(){
   MyStack st;
   st.push(1);
   st.push(2);
   st.push(3);
   st.push(4);
   st.push(5);

   st.pop();
   cout << "Top element: " << st.peek() << "\n";
   cout << "Is stack empty: " << (st.isEmpty() ? "Yes" : "No") << "\n";
   cout << "Current size: " << st.size() << endl;
   return 0;
}
