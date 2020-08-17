#include <iostream>
using namespace std;

int bottom_up(int price[], int length[],int n, int t_len){

	int dp[n+1][t_len+1] = {0};

	for(int items = 0; items<=n;items++){
		for(int len= 0; len<=t_len;len++){
			if(items==0 || len == 0){
				dp[items][len] = 0;
			}
			else{

				int inc = 0, exc = 0;
				if(len >= length[items-1]){
					inc = price[items-1] + dp[items][len-length[items-1]];

				}
				exc = 0 + dp[items-1][len];

				dp[items][len] = max(inc, exc);
			}
		}
	}

  return dp[n][t_len];
}

int main()
{
	int price[]={1, 5, 8, 9, 10, 17, 17, 20};
	int length[]={ 1,2,3,4,5,6,7,8 };

	int n = 8; // no. of elements and total length of rod

	
	cout<<bottom_up(price,length,n,n);
	return 0;
}