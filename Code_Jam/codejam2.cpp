#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    int n = 1;
    cin>>T;
    while(n<=T){
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

        cout<<"Case #"<<n<<":"<<" "<<sum<<" ";
        int flag = 0;
        for(int i=0;i<N;i++){
            set<int> s(vec.at(i).begin(), vec.at(i).end());
            if(s.size() != vec.at(i).size()){
                flag++;
            }
        }

        cout<<flag<<" ";


        flag = 0;

        for(int i=0;i<N;i++){
            set<int>s;
            for(int j=0;j<N;j++){
                s.insert(vec.at(j).at(i));
                }
                if(s.size() != vec.at(i).size()){
                    flag++;
                }
        }
        cout<<flag<<endl;
        n++;
    }

}