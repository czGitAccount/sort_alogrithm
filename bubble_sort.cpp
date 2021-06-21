#include <iostream>
#include <vector>

using namespace std;
template<typename T>
void bubble_sort(vector<T>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
        	if (vec[j] > vec[j + 1]) {
        		swap(vec[j], vec[j + 1]);
        	}
        }
    }
}
int main() {
	vector<int> vec{1,2,5,8,9,6,4,5,2,1,4,4,1,2};
	for (const auto& v : vec) cout << v << " ";
	cout << endl;
	bubble_sort(vec);
	for (const auto& v : vec) cout << v << " ";
	cout << endl;
	return 0;
}