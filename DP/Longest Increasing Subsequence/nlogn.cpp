/*
Longest Increasing Subsequence 
O(nlogn)
*/
#include <bits/stdc++.h>
using namespace std;
#define len(Z) (int)(Z).size()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N;cin>>N;
    vector<int> V(N);
    for(int i {};i<N;++i) {
    	cin >> V[i];
    }
    vector<int> LIS{V[0]};
    for(int i=1;i<N; ++i) {
    	if(LIS[len(LIS)-1] < V[i]) LIS.push_back(V[i]);

    	else {
    		int Index = lower_bound(LIS.begin(), LIS.end(), V[i]) - LIS.begin();
    		LIS[Index] = V[i];
    	}
    }

    cout << len(LIS);
}
/*
5/5/2021 mm/dd/yyyy
4:13 am 
dread
*/
