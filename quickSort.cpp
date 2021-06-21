#include<iostream>
#include<vector>
using namespace std;

template<typename T> 
int partition(vector<T>& vec, int left, int right);

template<typename T>
void quickSort(vector<T>& vec, int left, int right) {
	if (left >= right) return;
	int pivot = partition(vec, left, right);
	quickSort(vec, left, pivot - 1);
	quickSort(vec, pivot + 1, right);
}
template<typename T> 
int partition(vector<T>& vec, int left, int right) {
	// 基准为最左侧
	T pivot = vec[left];
	while (left < right) {
		while (left < right && vec[right] >= pivot) --right;
		vec[left] = vec[right];
		while (left < right && vec[left] <= pivot) ++left;
		vec[right] = vec[left];
	}
	vec[left] = pivot;
	return left;
}
int main() {
	vector<int> vec{1,5,2,3,8,4,3,9,1,2,6};
	for (const auto& v : vec) cout << v << ' ';
	cout << endl;
	int right = vec.size() - 1;
	quickSort(vec, 0, right);
	for (const auto& v : vec) cout << v << ' ';
	cout << endl;	
	return 0;
}