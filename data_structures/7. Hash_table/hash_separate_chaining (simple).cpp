/*
* Created: 2025-10-29 10:46
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
class Hash{
    int size;  //no of buckets (size)
    vector<vector<int>> table; 
     
public:
    Hash(int bucketCount){
        this->size = bucketCount;
        table.resize(size);
    }
    
    //function to insert a key in a hesh table
    void insert(int key){
        int idx = getHeshIndex(key);  
        table[idx].push_back(key);
    }

    //function to delate a key from hash table
    void remove(int key){
        int idx = getHeshIndex(key);

        //find the key
        auto it = find(table[idx].begin(),table[idx].end(),key);
        
        //erase the key if found
        if(it != table[idx].end()){
            table[idx].erase(it);
        }else{
            cout<<"Value not found!";
        }
    }
    void display(){
        for (int i = 0; i < size; i++){
            cout<<i;
            for(auto x: table[i]){
                cout<<"--> "<<x<<' ';
            }
            cout<<'\n';
        }
    }    
private:
    //hash function to map key to index
    int getHeshIndex(int key){
        return key % size;
    }
}; 

int main(){
    vector<int> keys = {15,11,27,8};
    Hash h1(7);
    for(auto x : keys){
        h1.insert(x);
    }
    h1.display();
    
    h1.remove(11);
    cout<<"\nAfter remove value: \n";
    h1.display();

    return 0;
}
/*---------------------------------------------------------------------
Output:
0
1--> 15 --> 8
2
3
4--> 11
5
6--> 27

After remove value:
0
1--> 15 --> 8
2
3
4
5
6--> 27
-----------------------------------------------------------------------*/
