/*
can either climb 1 or 2 steps.
In how many distinct ways can you climb to the top?
*/

#include "bits/stdc++.h"
 
#define all(x)   (x).begin(), (x).end()
#define test     int t;cin>>t;while(t--)
//---------------------------------
#define len(x)   (int)(x).size()
#define elif     else if
//---------------------------------
using namespace std;

int Stairs(int& n);

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(0);
  
  int x;cin>>x;
  Stairs(x);
  
  return 0;
}

int Stairs(int& n) {
  vector<int> dp(n+1,-1);
  dp[0]=1;
  dp[1]=1;
  for(int i=2;i<=n;++i) {
     dp[i] = dp[i-1] + dp[i-2]; 
  }
  return dp[n];
}
