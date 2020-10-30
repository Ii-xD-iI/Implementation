#include "bits/stdc++.h"
 
#define all(x)   (x).begin(), (x).end()
#define test     int t;cin>>t;while(t--)
//---------------------------------
#define len(x)   (int)(x).size()
#define elif     else if
//---------------------------------
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

	int number_of_elements{};
	cin >> number_of_elements;
	
	vector<int> array(number_of_elements);
	
	for(int element {}; element < number_of_elements; ++element){
		cin >> array[element];		
	} 

	for(int initElement{}; initElement < number_of_elements - 1; ++initElement) {
		swap(array[initElement],*min_element(array.begin()+initElement,array.end()));
	}
	//max_element = non-increasing
	//min_element = non-decreasing 

	for(auto Element: array){
		cout << Element << " ";
	}
	cout << '\n';
	return 0;
}
/*
10/30/2020 mm/dd/yyyy
*/
