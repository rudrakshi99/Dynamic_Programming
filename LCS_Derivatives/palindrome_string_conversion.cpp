// minimum number of deletion in a string to make it a palindrome
#include <iostream>
#include <cstring>
#include<algorithm> 
using namespace std;

int dp[100][100]= {0};

int bottomup(char s1[],char s2[],int m,int n){

	

	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){

			if(i==0 || j==0){
				dp[i][j] = 0;
			}
			else if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
			}

		}
	}

	return dp[m][n];
}


int main()
{

		
	char s1[] = "agbcba";
	char s2[20];
	int j=0;
	int m= strlen(s1);
	
      for (int i=m-1; i>=0; i--){ // reverse of string
            s2[j]=s1[i];
            j++;  
      }

	int n = m;
  

	cout<< m-bottomup(s1,s2,m,n);

    	return 0;
}