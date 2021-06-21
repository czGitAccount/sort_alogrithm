#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

const int BUCKET_NUM = 5;

// struct ListNode
// {
//     ListNode* next;
//     int val;
//     explicit ListNode(int i = 0) : val(i), next(nullptr) {};
// };

// // 插入操作，插入有序链表
// ListNode* insert(ListNode* head, int val) {
//     ListNode* dummyNode = new ListNode(0);
//     dummyNode->next = head;
//     ListNode* newNode = new ListNode(val);
//     ListNode* pre, *cur;
//     pre = dummyNode;
//     cur = head;
//     while (cur && cur->val <= val) {
//         pre = cur;
//         cur = cur->next;
//     }
//     newNode->next = cur;
//     pre->next = newNode;
//     return dummyNode->next;
// }

// // 桶排序
// void bucketSort(vector<int>& vec) {
//     vector<ListNode*> buckets(BUCKET_NUM, (ListNode*)(0));
//     int n = vec.size();
//     for (int i = 0; i < n; i++) {
//         // 桶编号
//         int idx = vec[i] / BUCKET_NUM;

//         ListNode *head = buckets.at(idx);
//         buckets.at(idx) = insert(head, vec[i]);
//     }

//     int k = 0;
//     // 按照桶编号，依次输出结果即可
//     for (int i = 0; i < BUCKET_NUM; i++) {
//         if (buckets[i]) {
//             ListNode* cur = buckets[i];
//             while (cur) {
//                 vec[k++] = cur->val;
//                 cur = cur->next;
//             }
//         }
//     }
// }



struct ListNode {
	int val;
	ListNode* next;
	ListNode(int i) : val(i), next(nullptr) {};
};

// 插入操作
ListNode* insert(ListNode* head, int val) {
	ListNode* dummyNode = new ListNode(0);
	dummyNode->next = head;
	ListNode* node = new ListNode(val);
	ListNode* cur = head;
	ListNode* pre = dummyNode;
	while (cur && cur->val <= val) {
		pre = cur;
		cur = cur->next;
	}
	node->next = cur;
	pre->next = node;
	return dummyNode->next;
}

void bucketSort(vector<int>& vec) {
	vector<ListNode*> buckets(BUCKET_NUM);
	for (const auto& v : vec) {
		int bIdx = v / BUCKET_NUM;
		ListNode* head = buckets[bIdx];
		buckets[bIdx] = insert(head, v);
	}
	int k = 0;
	for (int i = 0; i < BUCKET_NUM; i++) {
		if (buckets[i]) {
			ListNode* cur = buckets[i];
			while (cur) {
				vec[k++] = cur->val;
				cur = cur->next;
			}
		}
	}
}







int main() {
    vector<int> vec{1,2,3,5,14,3,2,17,2,8,6,9,4,12};
    for (const auto& v : vec) cout << v << ' ';
    cout << endl;
    bucketSort(vec);
    for (const auto& v : vec) cout << v << ' ';
    cout << endl;
    return 0;
}


