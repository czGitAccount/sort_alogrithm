#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void max_heap(vector<T>& vec, int start, int end) {
	// 记录父节点索引
	int parent = start;
	// 记录子节点索引开始位置
	int son = 2 * parent + 1;
	while (son <= end) {
		// 选择两个孩子节点中，最大的一个孩子，记录其索引
		if (son + 1 <= end && vec[son] < vec[son + 1]) {
			son++;
		}
		if (vec[parent] >= vec[son]) {
			// 如果父节点已经大于所有子节点了，则直接返回
			return ;
		} else {
			// 否则交换父子节点
			swap(vec[parent], vec[son]);
			// 父亲索引改为其子节点索引
			parent = son;
			// 其子节点索引在指向孙节点继续相同的比较
			son = parent * 2 + 1;
		}

	}
}
template <typename T>
void heapSort(vector<T>& vec) {
	int len = vec.size();
	// 初始化调整：从最后一个父节点找起
	for (int i = len / 2 - 1; i >= 0; i--) {
		max_heap(vec, i, len - 1);
	}// 获得最大堆

	// 先将第一个元素和已经排好的元素前一位做交换，
	// 再重新调整(刚调整的元素之前的元素)，知道排序完毕
	// 注：vec[0] 为堆顶，即为最大值

	for (int i = len - 1; i > 0; i--) {
		swap(vec[0], vec[i]);
		max_heap(vec, 0, i - 1);
	}
}

int main() {
	vector<int> vec{3, 5, 8, 6, 1, 6, 4, 9, 4, 7, 8, 9, 7, 3, 5, 7, 4, 0, 2, 6};
	for (const auto& v : vec) cout << v << ' ';
	cout << endl;
	int right = vec.size() - 1;
	heapSort(vec);
	for (const auto& v : vec) cout << v << ' ';
	cout << endl;	
	return 0;
}