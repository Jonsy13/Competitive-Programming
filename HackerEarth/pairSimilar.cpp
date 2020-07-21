#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,ele;
    cin >> n;
    vector<int>v;
    for(int i=0;i<n;i++){
        cin>>ele;
        v.push_back(ele);
    }
    int count = 0;
    vector<pair<int,int>>finc;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[j]-v[i]==1 || v[i]-v[j]==1){
                count++;
                finc.push_back(make_pair(v[i],v[j]));
                break;
            }
        }
    }

    for(int i=0;i<finc.size();i++){
        for(int j=i+1;j<finc.size();j++){
            if(finc[j].first == finc[i].second && finc[j].second != finc[i].first ){
                count++;
                finc.push_back(make_pair(finc[i].first,finc[j].second));
            }
            else{
                if(finc[j].second == finc[i].first && finc[j].first != finc[i].second){
                    count++;
                    finc.push_back(make_pair(finc[i].second,finc[j].first));
                }
                else{
                    if(finc[j].second == finc[i].second && finc[j].first != finc[i].first){
                        count++;
                        finc.push_back(make_pair(finc[i].first,finc[j].first));
                    }
                    else if(finc[i].first == finc[j].first && finc[i].second != finc[j].second){
                        count++;
                        finc.push_back(make_pair(finc[i].second,finc[j].second));
                    }
                    else{
                        continue;
                    }
                    
                }
            }
        }
    }

    std::cout<<count<<endl;
    return 0;

}