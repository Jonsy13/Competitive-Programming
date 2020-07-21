#include <iostream> 
#include <bits/stdc++.h> 
using namespace std; 

void fillRemaining(vector<vector<int>> &vec, int i, int j, int n) 
{ 
	
	int x = 2; 
    for (int k = i + 1; k < n; k++) 
		vec[k][j] = x++; 
    for (int k = 0; k < i; k++) 
		vec[k][j] = x++; 
} 

int constructMatrix(vector<vector<int>> &vec,int n,int k) 
{ 
	
	int right = n - 1, left = 0; 
	for (int i = n-1; i >=0; i--) 
	{ 
	
		if (i % 2 == 0) 
		{ 
			vec[i][right] = 1; 
            fillRemaining(vec,i, right, n); 
            right--; 
		} 
		
		
		else
		{ 
			vec[i][left] = 1; 
            fillRemaining(vec,i, left, n); 
            left++; 
		} 
	} 

    int sum = 0;
    for(int i=0;i<n;i++){
            sum +=vec[i][i];
    }
    
    if(sum != k){
        int right = n - 1, left = 0; 
        for (int i = n-1; i >=0; i--) 
	    { 
	
		    if (i % 2 == 0) 
		    { 
			    vec[i][left] = 1; 
                fillRemaining(vec,i, left, n); 
                left++; 
		    } 
		    else
		    { 
			    vec[i][right] = 1; 
                fillRemaining(vec,i, right, n); 
                right--; 
		    } 
	    } 

    }
    sum = 0;
    for(int i=0;i<n;i++){
            sum +=vec[i][i];
    }
    return sum;

} 


int main() 
{ 
	int T,N,K;
    int n=1;
    cin>>T;
    while(n<=T){
        cin>>N>>K;
        vector<int>v(N,0);
        vector<vector<int>>vec(N,v);
        vector<vector<int>>vec1(N,v);
        int s = constructMatrix(vec,N,K); 

        if(s==K){
            cout<<"Case #"<<n<<": POSSIBLE"<<endl;
            for (int i = 0; i < N; i++) 
	        { 
		       for (int j = 0; j < N; j++) 
		    	printf("%d ",vec[i][j]); 
		       printf ("\n"); 
	        } 

        }
        else{
            cout<<"Case #"<<n<<": IMPOSSIBLE"<<endl;
        }
    n++;
    }
    return 0; 
} 
