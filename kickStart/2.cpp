#include<bits/stdc++.h>
using namespace std;

long long int solve(vector<long long int>vec,long long int a[],int n){
    long long int  ans;
    




    if(is_sorted(vec.begin(),vec.end())){
            ans =  vec[0];
        }
        else{
            for(int i = 1;i<n;i++){
                if(vec[i]<vec[i-1]){
                    vec[i-1] = vec[i-1] - a[i-1]; 
                    break;
                }
            }
            return solve(vec,a,n);

        }
    return ans;

}
int main(){
    int t;
    cin>>t;
    int k = 1;
    while(t--){
        int n;
        long long int d;
        cin>>n>>d;
        long long int* a  = new long long int [n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        vector<long long int>vec;
        for(int i=0;i<n;i++){
            vec.push_back((d/a[i]));
        }
        
        long long int ans = solve(vec,a,n);

        cout<<"Case #"<<k<<": "<<ans<<endl;
        k++;
    }
}