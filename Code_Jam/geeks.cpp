#include <iostream> 
#include <bits/stdc++.h> 
using namespace std; 

const int MAX = 100; 
int mat[MAX][MAX]; 

void fillRemaining(int i, int j, int n) 
{ 
	
	int x = 2; 
    for (int k = i + 1; k < n; k++) 
		mat[k][j] = x++; 
    for (int k = 0; k < i; k++) 
		mat[k][j] = x++; 
} 

int constructMatrix(int n,int k) 
{ 
	
	int right = n - 1, left = 0; 
	for (int i = 0; i < n; i++) 
	{ 
	
		if (i % 2 == 0) 
		{ 
			mat[i][right] = 1; 
            fillRemaining(i, right, n); 
            right--; 
		} 
		
		
		else
		{ 
			mat[i][left] = 1; 
            fillRemaining(i, left, n); 
            left++; 
		} 
	} 

    int sum = 0;
    for(int i=0;i<n;i++){
            sum +=mat[i][i];
    }
    
    if(sum != k){
        int right = n - 1, left = 0; 
        for (int i = 0; i < n; i++) 
	    { 
	
		    if (i % 2 == 0) 
		    { 
			    mat[i][left] = 1; 
                fillRemaining(i, left, n); 
                left++; 
		    } 
		    else
		    { 
			    mat[i][right] = 1; 
                fillRemaining(i, right, n); 
                right--; 
		    } 
	    } 

    }
    sum = 0;
    for(int i=0;i<n;i++){
            sum +=mat[i][i];
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
        int s = constructMatrix(N,K); 

        if(s==K){
            cout<<"Case #"<<n<<": POSSIBLE"<<endl;
            for (int i = 0; i < N; i++) 
	        { 
		       for (int j = 0; j < N; j++) 
		    	printf("%d ",mat[i][j]); 
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
