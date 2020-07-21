#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono; 

bool compare(pair<string,int>p1,pair<string,int>p2){
    return p1.second>p2.second;
}

int search(vector<pair<string,int>>vec,string s){
    int size = vec.size();
    int cl = s.size();
    int flag = 0;
    int count = 0;
    for(int i = 0;i<size;i++){
        if(count==5){
            break;
        }
        if(vec[i].first.substr(0, cl).compare(s) == 0){
            count++;
            flag = 1;
            cout<<vec[i].first<<" ";
        }
        
    }
    if(flag == 0){
        return 0;
    }
    return 1;
}

int main(){
    fstream fin;
    int count = 0;
    vector<pair<string,int>>vec;
    fin.open("EnglishDictionary.csv");
    while(!fin.eof()){
        string line;
        fin>>line;
        string str,freq;
        stringstream s(line);
        getline(s,str,',');
        getline(s,freq,',');
        vec.push_back(make_pair(str,stoi(freq)));
        count++;
    }


    sort(vec.begin(),vec.end(),compare);

    string s;
    char ch;
    while(cin>>ch){
      
        if(ch=='#'){
            cout<<"Exiting!!!"<<endl;
            return 0;
        }
        s = s+ch;
        auto start = high_resolution_clock::now(); 
        int check = search(vec,s);
        auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<microseconds>(stop - start);

        if(check==0){
            cout<<"No Match Found!!"<<" ";
            cout << duration.count() << " μs"<<endl; 
            cout<<"Exiting!!!"<<endl;
            return 0;
        }
        cout << duration.count() << " μs"; 
        cout<<endl;
    }
  
    return 0;
}