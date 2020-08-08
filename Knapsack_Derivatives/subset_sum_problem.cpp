#include <iostream>
using namespace std;


bool bottom_up(int arr[],int n, int sum){

	bool dp[n+1][sum+1] ;

    // If sum is 0, then answer is true 
    for (int i = 0; i <= n; i++) 
        dp[i][0] = true; 
  
    // If sum is not 0 and set is empty, 
    // then answer is false 
    for (int i = 1; i <= sum; i++) 
        dp[0][i] = false; 
  

	for(int items = 1; items<=n;items++){
		for(int a = 1; a<=sum;a++){

				bool inc , exc ;
				if(a >= arr[items-1]){
					inc = dp[items-1][a-arr[items-1]];

				}
				exc =  dp[items-1][a];

				dp[items][a] = inc || exc;
			
		}
	}

  return dp[n][sum];
}

int main()
{
	int arr[]={2,3,7,8,10};


	int sum;
	cin>>sum;



	int n = 5; //no.of elements
	
	if(bottom_up(arr,n,sum))
    cout<<"true";
    else
    cout<<"false";
	return 0;
}