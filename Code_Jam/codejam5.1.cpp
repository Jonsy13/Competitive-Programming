#include<bits/stdc++.h>
using namespace std;

void fillremaining(vector<vector<int>>&vec,int i,int j,int N){
    int x = 2;
    for(int k = i+1;k<N;k++){
        vec[k][j] = x;
        x++;
    }

    for(int k = 0;k<i;k++){
        vec[k][j] = x;
        x++;
    } 
}

int main(){
    int T;
    cin>>T;
    int n=1;
    while(n<=T){
        int N,K;
        cin>>N>>K;
        int right = N-1,left = 0;
        vector<vector<int>>vec(N,vector<int>(N,0));
        for(int i=N-1;i>=0;i--){
            if(i%2==0){
                vec[i][right] = 1;
                fillremaining(vec,i,right,N);
                right--;
            }
            else{
                vec[i][left] = 1;
                fillremaining(vec,i,left,N);
                left++;
            }
        }
        int sum = 0;

        for(int i=0;i<N;i++){
            sum+=vec[i][i];
        }
        
        if(sum==K){

            cout<<"Case #"<<n<<": POSSIBLE"<<endl;
            for(auto a:vec){
                for(auto b:a){
                    cout<<b<<" "<<flush;
                    
                }
                cout<<endl;
            }
        }

        else{
            cout<<"Case #"<<n<<": IMPOSSIBLE"<<flush<<endl;
            
        }
        this_thread::sleep_for(chrono::seconds(1)); 
        n++;
    }

    return 0;
}