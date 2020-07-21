#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono; 

bool compare(pair<string,int>p1,pair<string,int>p2){
    return p1.second>p2.second;
}

int search(vector<pair<string,int>>vec,string s,int indx){
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

    //ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fstream fin;
    map<int,vector<pair<string,int>>>mp;
    fin.open("EnglishDictionary.csv");
    while(!fin.eof()){
        string line;
        fin>>line;
        string str,freq;
        stringstream s(line);
        getline(s,str,',');
        getline(s,freq,',');
        int indx = (int)str[0];
        mp[indx].push_back(make_pair(str,stoi(freq)));
    }
    
    string s;
    char ch;
    while(cin>>ch){
        s = s+ch;
        int indx = (int)s[0];
        if(s.length()==1){
            sort(mp[indx].begin(),mp[indx].end(),compare);
        }
        if(ch=='#'){
            cout<<"Exiting!!!"<<"\n";
            return 0;
        }
        
        auto start = high_resolution_clock::now(); 
        int check = search(mp[indx],s,indx);
        auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<microseconds>(stop - start);

        if(check==0){
            cout<<"No Match Found!!"<<" ";
            cout << duration.count() << " μs"<<endl; 
            cout<<"Exiting!!!"<<endl;
            return 0;
        }
        cout << duration.count() << " μs"; 
        cout<<"\n";
    }
  
    return 0;
}