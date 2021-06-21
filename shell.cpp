#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void shellSort(vector<T>& vec) {
    int n = vec.size();
    for (int step = n / 2; step > 0; step /= 2) {
        for (int i = step; i < n - 1; i++) {
            T key = vec[i];
            int j = i;
            while (j >= step && vec[j - step] > key) {
                vec[j] = vec[j - step];
                j -= step;
            }
            vec[j] = key;
        }
    }
}
int main() {
    vector<double> vec{1.2,2.2,5.8,3.1,6.1,2.1,17.0,4.8,2.9,8.0,9.7};
    for (const auto& v : vec) cout << v << ' ';
	cout << endl;
	shellSort(vec);
	for (const auto& v : vec) cout << v << ' ';
	cout << endl;	
	return 0;
}