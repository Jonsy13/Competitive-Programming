#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int T;
    cin>>T;
    int tc = 1;
    while(tc<=T){
        long int N,Bug;
        cin>>N>>Bug;
        int ele;
        vector<int>vec;
        for(int i=0;i<N;i++){
            cin>>ele;
            vec.push_back(ele);
        }
        
        sort(vec.begin(),vec.end());
        int sum = 0;
        int count = 0;
        for(int i=0;i<N;i++){
            if(sum+vec[i]<=Bug){
                sum = sum+vec[i];
                count++;
            }
        }
        cout<<"Case #"<<tc<<":"<<" "<<count<<endl;
        tc++;
        
    }
    return 0;
    
}