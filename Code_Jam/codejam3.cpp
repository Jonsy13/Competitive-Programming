#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    
    int n=1;
    cin>>T;
    while(T>0){
        int A,S,E;
        int flag = 0;
        cin>>A;
        vector<pair<int,int>>vec;
        for(int i=0;i<A;i++){
            cin>>S>>E;
            vec.push_back(make_pair(S,E));
        }

        int C = 0,J = 0;
        pair<int,int>CA = {0,0};
        pair<int,int>JA = {0,0};
        string Str = "";
        for(auto a:vec){
            if(a.first >= C){
                C = a.second;
                Str = Str + "C";
                CA.first = a.first;
                CA.second = a.second;
            }
            else{
                if(a.first >= J){
                    J = a.second;
                    Str = Str + "J";
                    JA.first = a.first;
                    JA.second = a.second;
                }
                 else
                    {   if(a.first < CA.first && a.second < CA.second){
                            CA.second = a.second;
                            Str = Str + "C";
                            CA.first = a.first;

                        }
                        else if(a.first < JA.first && a.second < JA.second){
                            JA.first = a.first;
                            JA.second = a.second;
                            Str = Str + "J";
                        }
                        else {
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        cout<<"Case #"<<n<<": ";
        if(flag == 1){
            cout<<"IMPOSSIBLE"<<flush<<endl;
            this_thread::sleep_for(chrono::seconds(1)); 
        }

        else{
            cout<<Str<<flush<<endl;
            this_thread::sleep_for(chrono::seconds(1)); 
        }
        n++;
        T--;
    }

    return 0;
}