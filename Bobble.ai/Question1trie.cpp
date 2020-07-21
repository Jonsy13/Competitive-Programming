#include<bits/stdc++.h>
using namespace std;

struct trie2{
    bool isend;
    unordered_map<char,trie2*>mp;

    trie2(){
        isend = false;
    }
};

struct trie2 *root1;

//For second structure
//Insert
void insert2(string str){
    struct trie2* cur = root1;
    for(char ch:str){
        if(!cur->mp.count(ch)){
            cur->mp[ch] = new trie2;

        }
        cur = cur->mp[ch];
    }
    cur->isend = true;
}

//Search
bool search2(string str){
    struct trie2* cur = root1;
    for(char ch:str){
        if(!cur->mp.count(ch)){
            return false;
        }
        cur = cur->mp[ch];
    }


    return true;
}

int main(){
    int n,m;
    root1 = new trie2;
    fin.open("EnglishDictionary.csv");
    while(!fin.eof()){
        string line;
        fin>>line;
        insert2(str);
    }

    cout<<"Enter the no. of string to be searched : ";
    cin>>m;
    while(m--){
        cout<<"Enter the string to be searched : ";
        string str;
        cin>>str;
        if(search2(str)){
            cout<<str<<" found"<<endl;
        }
        else{
            cout<<str<<" Not found"<<endl;
        }
    }
}
