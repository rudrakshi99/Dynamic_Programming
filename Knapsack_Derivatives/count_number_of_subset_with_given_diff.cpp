// count number of subset with given sum or target sum
#include <iostream>
using namespace std;


int bottom_up(int arr[],int n, int sum){

	int dp[n+1][sum+1] ;

    // If sum is 0, then answer is 0 
    for (int i = 0; i <= n; i++) 
        dp[i][0] = 1; 
  
    
    for (int i = 1; i <= sum; i++) 
        dp[0][i] = 0; 
  

	for(int items = 1; items<=n;items++){
		for(int a = 1; a<=sum;a++){

				int inc , exc ;
				if(a >= arr[items-1]){
					inc = dp[items-1][a-arr[items-1]];

				}
				exc =  dp[items-1][a];

				dp[items][a] = inc + exc;
			
		}
	}

  return dp[n][sum];
}

int main()
{
	int arr[]={1, 1, 2, 3};
    int diff = 1;
    int  n = 4;
    int s = 0;
    for(int i=0;i<n;i++){
    	s+=arr[i];
    }
	int sum;
	
    sum = (diff + s)/2;


	
	
	cout<<bottom_up(arr,n,sum);
    
	return 0;
}