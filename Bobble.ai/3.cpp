#include <bits/stdc++.h> 
using namespace std; 
unordered_set<string> st; 
vector<pair<string,int>>sol;


int distance(std::string p_string1, std::string p_string2)
{
    int l_string_length1 = p_string1.length();
    int l_string_length2 = p_string2.length();
    int d[l_string_length1+1][l_string_length2+1];

    int i;
    int j;
    int l_cost;

    for (i = 0;i <= l_string_length1;i++)
    {
        d[i][0] = i;
    }
    for(j = 0; j<= l_string_length2; j++)
    {
        d[0][j] = j;
    }
    for (i = 1;i <= l_string_length1;i++)
    {
        for(j = 1; j<= l_string_length2; j++)
        {
            if( p_string1[i-1] == p_string2[j-1] )
            {
                l_cost = 0;
            }
            else
            {
                l_cost = 1;
            }
            d[i][j] = std::min(
            d[i-1][j] + 1,                 
            std::min(d[i][j-1] + 1,         
            d[i-1][j-1] + l_cost)           
            );
            if( (i > 1) && 
            (j > 1) && 
            (p_string1[i-1] == p_string2[j-2]) && 
            (p_string1[i-2] == p_string2[j-1])
            ) 
            {
            d[i][j] = std::min(
            d[i][j],
             d[i-2][j-2] + l_cost   
            );
            }
        }
    }
    return d[l_string_length1][l_string_length2];
}

bool compare(pair<pair<string,int>,int>p1,pair<pair<string,int>,int>p2){
    if(p1.second<p2.second){
        return true;
    }
    else if(p1.second == p2.second && p1.first.second > p2.first.second){
        return true;
    }
    return false;
    
}

bool compare1(pair<string,int>p1,pair<string,int>p2){

    return p1.second>p2.second;
}



int main() 
{   cin.tie(NULL);
	string s;
    cin>>s;
    cin.tie(NULL);
    fstream fin;
    map<int,vector<pair<string,int>>>mp;
    fin.open("EnglishDictionary.csv");
    while(!fin.eof()){
        string line;
        fin>>line;
        string str,freq;
        stringstream s(line);
        getline(s,str,',');
        getline(s,freq,',');
        int indx = (int)str[0];
        mp[indx].push_back(make_pair(str,stoi(freq)));
    }

    int q = s.size();

    int indx = (int)s[0];
    

    vector<pair<string,int>>temp;
    for(int i = 0;i<mp[indx].size();i++){
        string s = mp[indx][i].first;
        int freq = mp[indx][i].second;
        temp.push_back(make_pair(s,freq));
    }

    vector<pair<pair<string,int>,int>>v;

    sort(temp.begin(),temp.end(),compare1);
    for(auto a:temp){
        int d = distance(a.first,s);
        string s = a.first;
        int  freq = a.second;
        pair<string,int>p(s,freq);
        v.push_back(make_pair(p,d));
    }
    sort(v.begin(),v.end(),compare);
    cout<<"EXPECTED WORDS : ";
    for(int i = 0;i<5;i++){
        cout<<v[i].first.first<<" ";
    }

    return 0; 
} 

