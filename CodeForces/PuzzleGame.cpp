#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T>0){
        int count = 0;
        vector<vector<int>>v;
        for(int i=0;i<3;i++){
            int ele;
            vector<int>vin;
            for(int j=0;j<3;j++){
                cin>>ele;
                vin.push_back(ele);
            }
            v.push_back(vin);
        }
        
        while(1){
            int lc = count;
            for(int i=0;i<3;i++){
                for(int j=0;j<2;j++){
                    int sum = (v[i][j]+v[i][j+1]);
                    if(sum%2==0 || sum%3==0 || sum%5==0 || sum%7==0){
                        continue;
                    }
                    else{
                        if(v[i][j]>v[i][j+1]){
                            count++;
                            int temp = v[i][j];
                            v[i][j] = v[i][j+1];
                            v[i][j+1] = temp;
                        }
                    }
                }
            }

            if(v[0][0]==1 && v[0][1] == 2 && v[0][2]==3 && v[1][0]==4 && v[1][1]==5 && v[1][2]==6 && v[2][0]==7 && v[2][1]==8 && v[2][2]==9 ){
                break;
            }

            for(int i=0;i<2;i++){
                for(int j=0;j<3;j++){
                    int sum = (v[i][j]+v[i+1][j]);
                    if(sum == 1 || sum==2 || sum == 3 || sum == 5 || sum == 7 ){
                       // if(v[i][j]>v[i+1][j]){
                            count++;
                            int temp = v[i][j];
                            v[i][j] = v[i+1][j];
                            v[i+1][j] = temp;
                      //  }
                        
                    }
                    else if(sum%2!=0 && sum%3!=0 && sum%5!=0 && sum%7!=0){
                          //  if(v[i][j]>v[i+1][j]){
                                count++;
                                int temp = v[i][j];
                                v[i][j] = v[i+1][j];
                                v[i+1][j] = temp;
                           // }
                        }
                        else{
                            continue;
                        }
                }
            }
            if(v[0][0]==1 && v[0][1] == 2 && v[0][2]==3 && v[1][0]==4 && v[1][1]==5 && v[1][2]==6 && v[2][0]==7 && v[2][1]==8 && v[2][2]==9 ){
                break;
            }
            if(lc==count){
                break;
            }
        
        }

        cout<<count<<endl;
        for(auto i:v){
            for(int a:i){
                cout<<a<<" ";
            }
            cout<<endl;
        }
        T--;
    }

    return 0;
}