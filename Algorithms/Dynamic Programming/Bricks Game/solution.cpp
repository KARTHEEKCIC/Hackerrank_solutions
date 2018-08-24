#include <iostream>

using namespace std;

typedef long long LL;

int main() {
	int t; //no of test cases
	cin>>t;
	int n; // no of bricks in the game
	for(int i=0;i<t;i++) {
		cin>>n;
		LL stack[n]; //stack containing the bricks score
		LL dp[n];
		LL sum[n] = {};
		for(int j=n-1;j>=0;j--) {
			cin>>stack[j];
		}
		for(int j=0;j<n;j++) {
			if(j == 0) {
				dp[j] = stack[j];
				sum[j] = stack[j];
			} else if(j==1) {
				dp[j] = stack[j] + stack[j-1];
				sum[j] = sum[j-1] + stack[j];
			}
			else if(j==2) {
				dp[j] = stack[j] + stack[j-1] + stack[j-2];
				sum[j] = sum[j-1] + stack[j];
			}
			else {
				sum[j] = sum[j-1] + stack[j]; // calculating the sum of scores of all the bricks upto j
				// calculating the optimal solution if the player starts playing from jth brick i.e, dp[j]
				dp[j] = (sum[j-1] - dp[j-1]) + stack[j]; 		
				if(dp[j] < (sum[j-2] - dp[j-2]) + stack[j-1] + stack[j]) 
					dp[j] = (sum[j-2] - dp[j-2]) + stack[j-1] + stack[j];
				if(dp[j] < (sum[j-3] - dp[j-3]) + stack[j-2] + stack[j-1] + stack[j])
					dp[j] = (sum[j-3] - dp[j-3]) + stack[j-2] + stack[j-1] + stack[j];
			}		
		}	
		cout<<dp[n-1]<<endl;
	}
	return 0;
}

