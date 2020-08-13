//Longest common substring

#include <iostream>
#include <cstring>
using namespace std;


int bottomup(char s1[],char s2[],int m,int n){

	int dp[100][100]= {0};

	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){

			if(i==0 || j==0){
				dp[i][j] = 0;
			}
			else if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = 0; // for discontinuity
			}

		}
	}

	return dp[m][n];
}


int main()
{

		
	char s1[] = "AGGTAB";
	char s2[] = "GXTXAAB";

	int m= strlen(s1);

	int n = strlen(s2);

	int dp[100][100];
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			dp[i][j]=-1;
		}
	}

	cout<<bottomup(s1,s2,m,n);
	return 0;
}