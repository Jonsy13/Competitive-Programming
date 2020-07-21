#include<bits/stdc++.h>
using namespace std;

// void findWords(string s){
    
// }

int main(){
    string s;
    char c;
    vector<pair<string,int>>file;
    fstream fin; 
    string temp,line;
    // Open an existing file 
    fin.open("EnglishDictionary.csv", ios::in);
   
    while(fin>>temp){
        getline(fin,line);
        string str;
        string freq;
        stringstream s(line);
        getline(s,str,',');
        // getline(s,freq,',');
        cout<<str<<endl;
        
    } 

    // while(cin>>c){
    //     s = s+c;
    //     findWords(s);
    // }
    return 0;
}