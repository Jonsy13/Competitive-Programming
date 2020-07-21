#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
   
    cin>>T;
    while(T>0){
        int N,ele;
        cin>>N;
        vector<vector<int>>vec;
        for(int i=0;i<N;i++){
            vector<int>vec2;
            for(int j=0;j<N;j++){
                cin>>ele;
                vec2.push_back(ele);
            }
            vec.push_back(vec2);
        }
        int sum = 0;
        for(int i=0;i<N;i++){
            sum +=vec.at(i).at(i);
        }
        int flag = 0;
        for(int i=0;i<N;i++){
            auto it = std::unique(vec.at(i).begin(), vec.at(i).end());
            flag =  ((it == vec.at(i).end()) ? 0 : ++flag);  
        }

        cout<<"No. of rows having duplicates : "<<flag<<endl;
        T--;
    };
}
