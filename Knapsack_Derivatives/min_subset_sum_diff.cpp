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

  int diff = INT_MAX;

  for (int j=sum/2; j>=0; j--) 
    { 
        // Find the  
        if (dp[n][j] == true) 
        { 
            diff = sum-2*j; 
            break; 
        } 
    } 
    return diff; 

}

int main()
{
	int arr[]={1,3,7};
    int n =3;
    int sum = 0;
     for(int i=0;i<n;i++){
        sum+=arr[i];
     }
	cout<<bottom_up(arr,n,sum);
    
	return 0;
}