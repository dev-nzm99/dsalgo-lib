/*
* Created: 2025-10-27 19:17
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
#include<bits/stdc++.h>
using namespace std;

class MyStack{
    private:
    
    int *arr;       // array to store elements 
    int capacity;   // maximum size of stack
    int top;        // index of top element

    public:
    MyStack(int cap){
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }
    void push(int val){
        if(top == capacity-1){
            cout<<"Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }
    void pop(){
        if(top == -1){
            cout<<"Stack Underflow\n";
            return;
        }
        --top;
    }
    int peek(){
        if(top == -1){
            cout<<"Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top == capacity-1;
    }
    ~MyStack(){        //Free the memory (to avoid memory leak):
        delete[] arr;
    }
};
int main(){
    MyStack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    st.pop();
    cout<<"Top element: "<<st.peek()<<"\n";
    cout << "Is stack empty: " << (st.isEmpty() ? "Yes" : "No") << "\n";
    cout << "Is stack full: " << (st.isFull() ? "Yes" : "No") << "\n";
    return 0;
}
