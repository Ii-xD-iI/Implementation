/*
minimum cost to get to the top
*/

#include "bits/stdc++.h"
 
#define all(x)   (x).begin(), (x).end()
#define test     int t;cin>>t;while(t--)
//---------------------------------
#define len(x)   (int)(x).size()
#define elif     else if
//---------------------------------
using namespace std;

int Staircost(vector<int>& cost);

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(0);
  
  int a;cin>>a;
  vector<int> x(a);
  for(int i {};i<a;++i) cin>>v[i];
  Staircost(x);
  
  return 0;
}

int Stairscost(vector<int>& cost) {
    cost.push_back(0);
    int n = (int)(cost).size();
    for(int i = 2;i<=n;++i) {
        if( cost[i-1] < cost[i-2] ) cost[i] += cost[i-1];
        else cost[i] += cost[i-2];//apparently min function dosent even work in leet code -_-
    }
    return cost[n-1];
}
