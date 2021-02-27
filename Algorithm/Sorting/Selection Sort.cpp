void SelectionSort() {

	int number_of_elements{};
	cin >> number_of_elements;
	
	vector<int> array(number_of_elements);
	
	for(int element {}; element < number_of_elements; ++element){
		cin >> array[element];		
	} 

	for(int initElement{}; initElement < number_of_elements - 1; ++initElement) {
		swap(array[initElement],*min_element(array.begin()+initElement, array.end()));
	}
	//max_element = non-increasing
	//min_element = non-decreasing 

	for(auto Element: array){
		cout << Element << " ";
	}
	cout << '\n';
	return;
}
/*
10/30/2020 mm/dd/yyyy
*/
