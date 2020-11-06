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

int Paths(int& m,int& n);

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(0);
  
  int a;cin>>a;
  int b;int>>b;
  Paths(a,b);
  
  return 0;
}

int Paths(int& m,int& n) {
    vector<vector<int>> v(m+1 , vector<int> (n+1,0));      
    for(int i=1; i<=m; ++i) {
        for(int j=1; j<=n; ++j) {
            if(j==1) {v[i][j] = 1;continue;}//base case?
            v[i][j] = v[i-1][j] + v[i][j-1];                            
        }
    }
    return v[m][n];
}
