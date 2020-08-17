// minimum number of coins to get the sum 
#include <iostream>
using namespace std;

int bottom_up( int coins[],int n, int sum){

	int dp[sum+1] = {0};
	dp[0] = 0; // when sum is zero then zero coin needed 
  
    
	for(int items = 0; items<n;items++){
		for(int j = 1; j<=sum;j++){

				int inc = 0;
				if(sum >= coins[items]){
					inc = 1 + dp[items][j-coins[items]];
					dp[items] = inc;

				}
		}	
		
	}

  return dp[n][sum];
}

int main()
{
	
	int coins[]={1,2,3};
	int sum = 5;

	int n = 3; // no. of elements and total length of rod

	
	cout<<bottom_up(coins,n,sum);
	return 0;
}