#include<bits/stdc++.h>
using namespace std;

// #define long long ll;
// struct Trie{
//     struct Trie *child[26];
//     bool isend;
//     Trie(){
//         memset(child,0,sizeof(child));
//         isend = false;
//     }

// };
// struct Trie *root;


struct trie2{
    bool isend;
    unordered_map<char,trie2*>mp;

    trie2(){
        isend = false;
    }
};

struct trie2 *root1;

//For second structure
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


// //For First structure
// void insert(string str){
//     struct Trie *cur = root;
//     for(char ch:str){
//         int idx = ch-'a';
//         if(cur->child[idx] == NULL){
//             cur->child[idx] = new Trie;
//         }
//         cur = cur->child[idx];
//     }
//     cur->isend = true;
// }

// bool issearch(string str){
//     struct Trie *cur = root;
//     for(char ch:str){
//         int idx = ch-'a';
//         if(cur->child[idx]==NULL){
//             return false;
//         }
//         cur = cur->child[idx];
//     }
//     return cur->isend;
// }

int main(){
    int n,m;
    // freopen("input.txt","r",stdin);
    // root = new Trie;
    root1 = new trie2;
    cout<<"Enter the number of strings to be inserted : ";
    cin>>n;
    while(n--){
        string str;
        cin>>str;
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
