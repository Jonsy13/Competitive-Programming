#include<bits/stdc++.h>
using namespace std;
long long int mx = 1000000000;

int main(){
    int t;
    cin>>t;
    int tc = 1;
    while(t--){
        string s;
        cin>>s;
        // long long int i = 1,j = 1;
        // int m = 2;
        int times = 0;
        string o_str;
        for(int k = 0;s.size();k++){
            string st;
            if(2<=(int)s[k]<=9){
                times = (int)s[k];
                k++;
                while(s[k]!=')'){
                    st = st + s[k];
                    k++;
                }
                k++;
                for(int l = 0;l<times;l++){
                    o_str = o_str + st;
                
                }
            }
            else{
                o_str = o_str + s[k];

            }
        }
        cout<<o_str<<endl;


        //cout<<"Case #"<<k<<": "<<endl;
        tc++;
    }
}