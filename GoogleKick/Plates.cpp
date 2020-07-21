#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int T;
    cin>>T;
    int tc = 1;
    while(tc<=T){
        int N,K;
        cin>>N>>K;
        vector<string>strings;
        for(int i=0;i<N;i++){
            string s;
            cin>>s;
            strings.push_back(s);
        }

        sort(strings.begin(),strings.end());
        for(string s:strings){
            cout<<s<<endl;
        }

        vector<int>counts;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(strings[i]==strings[j]){
                    for(int k=0;k<)
                }
            }
        }
        tc++;
        
    }
    return 0;
    
}