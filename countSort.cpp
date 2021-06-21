#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// pair<int, int> findMaxMinOfVec(const vector<int>& vec) {
// 	int min = INT_MAX;
// 	int max = INT_MIN;
// 	for (const auto& v : vec) {
// 		if (v > max) max = v;
// 		if (v < min) min = v;
// 	}
// 	return {max, min};
// }


// void countSort(vector<int>& vec) {
// 	int n = vec.size();
// 	pair<int, int> pa = findMaxMinOfVec(vec);
// 	int maxN = pa.first;
// 	int minN = pa.second;
// 	vector<int> freq(maxN - minN + 1);
// 	for (const auto& v : vec) {
// 		freq[v - minN]++;
// 	}
// 	int end = n - 1;
// 	for (int i = maxN - minN; i >= 0; i--) {
// 		while(freq[i] > 0) {
// 			vec[end--] = i + minN;
// 			freq[i]--;
// 		}
// 	}
// }







pair<int, int> findMaxMinOfVec(const vector<int>& vec) {
	int maxN = INT_MIN;
	int minN = INT_MAX;
	for (const auto& v : vec) {
		if (v > maxN) maxN = v;
		if (v < minN) minN = v;
	}
	return {maxN, minN};
}

void countSort(vector<int>& vec) {
	int n = vec.size();
	pair<int, int> pa = findMaxMinOfVec(vec);
	int maxN = pa.first;
	int minN = pa.second;
	vector<int> freq(maxN - minN + 1);
	for (const auto& v : vec) {
		freq[v - minN]++;
	}
	int end = n - 1;
	for (int i = maxN - minN; i >= 0; i--) {
		while (freq[i] > 0) {
			vec[end--] = i + minN;
			freq[i]--;
		}
	}
}



int main() {
	vector<int> vec{1,2,5,5,6,3,2,1,1,2,7,8,8,9,5,9};
	for (const auto& v : vec) cout << v << ' ';
	cout << endl;
	countSort(vec);
	for (const auto& v : vec) cout << v << ' ';
	cout << endl;	
	return 0;	
}