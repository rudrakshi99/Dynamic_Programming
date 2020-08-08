#include <iostream>
using namespace std;


int bottom_up(int arr[],int n, int sum){ // subset sum problem

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

bool equal_sum(int arr[],int n){
   
   int sum = 0;
   for(int i=0;i<n;i++){
   	sum+=arr[i];
   }

   if(sum%2!=0){ // odd
   	return false;
   }
  
   else if(sum%2==0) // even
   	return bottom_up(arr,n,sum/2);
}

int main()
{
	int arr[]={2,3,11,5,1};



	int n = 5; //no.of elements
	
	if(equal_sum(arr,n))
    cout<<"true";
    else
    cout<<"false";
	return 0;
}