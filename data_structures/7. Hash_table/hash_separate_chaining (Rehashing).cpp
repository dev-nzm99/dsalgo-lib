/*
* Created: 2025-11-26 19:31
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
const double Threshold_value = 0.5;

class Hash{
    int bucketCount;
    int numOfElements;
    vector<vector<int>> table;

public:
    Hash(int buckets){
        this->bucketCount = buckets;
        numOfElements = 0;
        table.resize(bucketCount);
    }

    void insert(int key){
        if (getLoadFactor() > Threshold_value){
            rehash();
        }
        int idx = getHashIndex(key);
        table[idx].push_back(key);
        ++numOfElements;
    }

    void remove(int key){
        int idx = getHashIndex(key);
        auto it = find(table[idx].begin(), table[idx].end(), key);
        if (it != table[idx].end()){
            table[idx].erase(it);
            --numOfElements;
        }
    }

    void display(){
        for (int i = 0; i < bucketCount; ++i){
            cout << i;
            for (const auto &key : table[i]){
                cout << " -->" << key;
            }
            cout << '\n';
        }
    }

private:
    int getHashIndex(int key){
        return key % bucketCount;
    }

    double getLoadFactor(){
        return (double)numOfElements / bucketCount;
    }

    void rehash(){
        vector<vector<int>> oldTable = table;
        bucketCount *= 2;
        table.clear();
        table.resize(bucketCount);
        numOfElements = 0;
        for (const auto &bucket : oldTable){
            for (const auto &key : bucket){
                insert(key);
            }
        }
    }
};

int main(){
    vector<int> keys = {15, 11, 27};

    Hash hashTable(5);
    for (const auto &x : keys){
        hashTable.insert(x);
    }
    hashTable.remove(11);
    hashTable.display();

    hashTable.insert(19);
    hashTable.insert(89);
    hashTable.insert(56);
    hashTable.insert(133);

    cout << "\nAfter rehashing: \n";
    hashTable.display();

    return 0;
}
/*-----------------------------------------------------------------
Output:
0 -->15
1
2 -->27
3
4

After rehashing: 
0
1
2
3 -->133
4
5 -->15
6 -->56
7 -->27
8
9 -->19 -->89
-------------------------------------------------------------------*/
