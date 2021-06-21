#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void mergeSortRecur(vector<T>& vec, vector<T>& temp, int left, int right);

template<typename T>
void mergeSort(vector<T>& vec) {
	int n = vec.size();
	vector<T> temp(n);
	mergeSortRecur(vec, temp, 0, n - 1);
}
template<typename T>
void mergeSortRecur(vector<T>& vec, vector<T>& temp, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSortRecur(vec, temp, left, mid);
		mergeSortRecur(vec, temp, mid + 1, right);
		int i = left;
		int j = mid + 1;
		int k = 0;
		while (i <= mid && j <= right) {
			temp[k++] = vec[i] <= vec[j] ? vec[i++] : vec[j++];
		}
		while (i <= mid) temp[k++] = vec[i++];
		while (j <= right) temp[k++] = vec[j++];
		for (int l = 0; l < k; l++) vec[left + l] = temp[l];
	}
}


int main() {
	vector<int> vec{1,5,2,3,8,4,3,9,1,2,6};
	for (const auto& v : vec) cout << v << ' ';
	cout << endl;
	mergeSort(vec);
	for (const auto& v : vec) cout << v << ' ';
	cout << endl;	
	return 0;
}