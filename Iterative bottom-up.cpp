#include "bits/stdc++.h"
 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define elif else if
#define test int t;cin>>t;while(t--)
#define len(x) (int)(x).size()
#define int_min INT_MIN
#define int_max INT_MAX
using namespace std;

int main(){

	int n;cin>>n;
	vector<int> dp(10,-1);
	int i=2;
	dp[0] = 0;
	dp[1] = 1;
	for(;i<n;i++){
		dp[i] = dp[i-1]+dp[i-2];
	}
	cout << dp[n-1] << '\n';
	return 0;
}
//taskkill /IM "main.exe" /F
/*
10/18/2020
*/
