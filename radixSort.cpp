#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// int maxbit(const vector<int>& vec) {
//     int n = vec.size();
//     int maxLen = 0;
//     for (const auto& v : vec) {
//         int len = to_string(v).size();
//         if (len > maxLen) maxLen = len;
//     }
//     return maxLen;
// }
// void radixSort(vector<int>& vec) {
//     int n = vec.size();
//     int d = maxbit(vec);
//     vector<int> temp(n);
//     int count[10]; // 统计被分配到 0 1 2 ... 9 的次数
//     int radix = 1;
//     for (int i = 1; i <= d; i++) {
//         memset(count, 0, sizeof(count));
//         for (int j = 0; j < n; j++) {
//             int k = (vec[j] / radix) % 10;
//             count[k]++;
//         }
//         // 根据每个桶的大小，分配区间位置，从小到大分配
//         for (int j = 1; j < 10; j++) {
//             count[j] = count[j - 1] + count[j];
//         }
//         for (int j = n - 1; j >= 0; j--) {
//             int k = (vec[j] / radix) % 10;
//             // 反向插入
//             temp[count[k] - 1] = vec[j];
//             count[k]--; // 向前移动
//         }
//         vec = temp; // 赋值
//         radix *= 10;
//     }
// }


int maxbit(const vector<int>& vec) {
	int maxLen = 0;
	for (const auto& v : vec) {
		int len = to_string(v).size();
		if (len > maxLen) maxLen = len;
	}
	return maxLen;
	// 也可以通过除法
	// for (const auto& v : vec) {
	// 		int len = 0;
	// 		while (v) {
	// 			v /= 10;
	// 			len++;
	// 		}
	// 		if (len > maxLen) maxLen = len;
	// }
}


void radixSort(vector<int>& vec) {
	int n = vec.size();
	int d = maxbit(vec);
	vector<int> temp(n);
	int count[10];
	int radix = 1;
	for (int i = 1; i <= d; i++) {
		memset(count, 0, sizeof(count));
		for (const auto& v : vec) {
			int k = (v / radix) % 10;
			count[k]++;
		}
		for (int j = 1; j < 10; j++) {
			count[j] = count[j - 1] + count[j];
		}
		for (int j = n - 1; j >= 0; j--) {
			int k = (vec[j] / radix) % 10;
			temp[count[k] - 1] = vec[j];
			count[k]--;
		}
		vec = temp;
		radix *= 10;
	}
}



int main() {
    vector<int> vec{1,20,51,6,78,9,30,41,2,3,54,12,13,18,81,75,94,9,64,82,37,42};
    for (const auto& v : vec) cout << v << ' ';
    cout << endl;
    radixSort(vec);
    for (const auto& v : vec) cout << v << ' ';
    cout << endl;
    return 0;
}