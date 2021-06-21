#include <iostream>

using namespace std;

struct TreeNode
{	
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
	TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {};
};

TreeNode* builtTree() {
	int val;
	cin >> val;
	if (val == 0) return nullptr;
	TreeNode* node = new TreeNode(val);
	node->left = builtTree();
	node->right = builtTree();
	return node;
}
void preOrder(TreeNode* root) {
	if (!root) {
		cout << "nullptr" << ' ';
		return;
	}
	cout << root->val << ' ';
	preOrder(root->left);
	preOrder(root->right);
}

int main() {
	TreeNode* root = builtTree();
	cout << "- - - - -" << endl;
	preOrder(root);
	return 0;
}